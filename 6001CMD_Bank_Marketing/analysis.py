"""
6001CMD Machine Learning - UCI Bank Marketing reproducibility script

Dataset:
https://archive.ics.uci.edu/dataset/222/bank+marketing

Expected file:
bank-additional-full.csv

The script reproduces the descriptive statistics, data-quality checks,
figures, feature engineering, and a leakage-aware baseline preprocessing
pipeline discussed in the assignment report.
"""

from pathlib import Path
import argparse

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

from sklearn.compose import ColumnTransformer
from sklearn.impute import SimpleImputer
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import (
    accuracy_score,
    balanced_accuracy_score,
    classification_report,
    confusion_matrix,
    f1_score,
    precision_score,
    recall_score,
    roc_auc_score,
    average_precision_score,
)
from sklearn.pipeline import Pipeline
from sklearn.preprocessing import OneHotEncoder, StandardScaler


DATASET_URL = "https://archive.ics.uci.edu/dataset/222/bank+marketing"


def load_data(csv_path: Path) -> pd.DataFrame:
    """Load UCI bank-additional-full.csv."""
    df = pd.read_csv(csv_path, sep=";")
    print("=== BASIC DATA CHECK ===")
    print("Shape:", df.shape)
    print("Total NaN values:", int(df.isna().sum().sum()))
    print("Exact duplicate rows:", int(df.duplicated().sum()))
    print()
    return df


def audit_unknown_categories(df: pd.DataFrame) -> pd.DataFrame:
    """Count literal 'unknown' values in categorical columns."""
    rows = []
    for col in df.select_dtypes(include="object").columns:
        count = int(df[col].astype(str).str.lower().eq("unknown").sum())
        if count:
            rows.append(
                {
                    "feature": col,
                    "unknown_count": count,
                    "unknown_pct": 100 * count / len(df),
                }
            )
    result = pd.DataFrame(rows).sort_values("unknown_pct", ascending=False)
    print("=== LITERAL 'UNKNOWN' VALUES ===")
    print(result.to_string(index=False, formatters={"unknown_pct": "{:.2f}".format}))
    print()
    return result


def target_summary(df: pd.DataFrame) -> pd.DataFrame:
    counts = df["y"].value_counts()
    pct = df["y"].value_counts(normalize=True).mul(100)
    result = pd.DataFrame({"count": counts, "percent": pct})
    print("=== TARGET DISTRIBUTION ===")
    print(result.to_string(formatters={"percent": "{:.2f}".format}))
    print()
    return result


def numeric_quality_summary(df: pd.DataFrame) -> pd.DataFrame:
    num_cols = df.select_dtypes(include=np.number).columns
    rows = []
    for col in num_cols:
        s = df[col].dropna()
        q1 = s.quantile(0.25)
        q3 = s.quantile(0.75)
        iqr = q3 - q1
        lower = q1 - 1.5 * iqr
        upper = q3 + 1.5 * iqr
        outliers = int(((s < lower) | (s > upper)).sum())

        rows.append(
            {
                "feature": col,
                "mean": s.mean(),
                "std": s.std(),
                "min": s.min(),
                "q1": q1,
                "median": s.median(),
                "q3": q3,
                "max": s.max(),
                "skewness": s.skew(),
                "iqr_outliers": outliers,
                "outlier_pct": 100 * outliers / len(df),
            }
        )

    result = pd.DataFrame(rows)
    print("=== NUMERICAL QUALITY SUMMARY ===")
    print(
        result[
            ["feature", "mean", "median", "max", "skewness", "iqr_outliers", "outlier_pct"]
        ].to_string(
            index=False,
            formatters={
                "mean": "{:.3f}".format,
                "median": "{:.3f}".format,
                "max": "{:.3f}".format,
                "skewness": "{:.3f}".format,
                "outlier_pct": "{:.2f}".format,
            },
        )
    )
    print()
    return result


def correlation_summary(df: pd.DataFrame) -> pd.DataFrame:
    numeric = df.select_dtypes(include=np.number)
    corr = numeric.corr()

    pairs = []
    cols = list(corr.columns)
    for i, a in enumerate(cols):
        for b in cols[i + 1 :]:
            pairs.append((a, b, corr.loc[a, b], abs(corr.loc[a, b])))

    pairs_df = pd.DataFrame(
        pairs, columns=["feature_1", "feature_2", "r", "abs_r"]
    ).sort_values("abs_r", ascending=False)

    print("=== STRONGEST NUMERIC CORRELATIONS ===")
    print(
        pairs_df.head(10)[["feature_1", "feature_2", "r"]].to_string(
            index=False, formatters={"r": "{:.3f}".format}
        )
    )
    print()
    return corr


def semantic_checks(df: pd.DataFrame) -> None:
    pdays_999 = int(df["pdays"].eq(999).sum())
    previous_zero = int(df["previous"].eq(0).sum())

    duration_bins = [0, 60, 120, 180, 300, 600, 1200, np.inf]
    labels = ["0-59", "60-119", "120-179", "180-299", "300-599", "600-1199", "1200+"]
    temp = df[["duration", "y"]].copy()
    temp["duration_band"] = pd.cut(
        temp["duration"], bins=duration_bins, labels=labels, right=False
    )
    duration_rate = (
        temp.assign(y_yes=temp["y"].eq("yes").astype(int))
        .groupby("duration_band", observed=False)["y_yes"]
        .agg(["count", "sum", "mean"])
    )
    duration_rate["yes_pct"] = duration_rate["mean"] * 100

    print("=== SEMANTIC / LEAKAGE CHECKS ===")
    print(
        f"pdays = 999: {pdays_999:,} rows ({100*pdays_999/len(df):.2f}%)"
    )
    print(
        f"previous = 0: {previous_zero:,} rows ({100*previous_zero/len(df):.2f}%)"
    )
    print("Subscription rate by call-duration band:")
    print(
        duration_rate[["count", "sum", "yes_pct"]].rename(columns={"sum": "yes"}).to_string(
            formatters={"yes_pct": "{:.2f}".format}
        )
    )
    print()


def save_figures(
    df: pd.DataFrame,
    numeric_summary: pd.DataFrame,
    corr: pd.DataFrame,
    output_dir: Path,
) -> None:
    output_dir.mkdir(parents=True, exist_ok=True)

    # Target distribution
    target = df["y"].value_counts().reindex(["no", "yes"])
    fig, ax = plt.subplots(figsize=(6.5, 4.2))
    ax.bar(target.index, target.values)
    ax.set_title("Target class distribution")
    ax.set_ylabel("Records")
    for i, value in enumerate(target.values):
        ax.text(i, value, f"{value:,}\n({100*value/len(df):.2f}%)", ha="center", va="bottom")
    fig.tight_layout()
    fig.savefig(output_dir / "target_distribution.png", dpi=200)
    plt.close(fig)

    # Outlier percentage
    out = numeric_summary.sort_values("outlier_pct", ascending=False)
    fig, ax = plt.subplots(figsize=(8.2, 4.8))
    ax.bar(out["feature"], out["outlier_pct"])
    ax.set_title("IQR-flagged observations by numeric feature")
    ax.set_ylabel("Outlier percentage (%)")
    ax.tick_params(axis="x", rotation=55)
    fig.tight_layout()
    fig.savefig(output_dir / "iqr_outlier_percent.png", dpi=200)
    plt.close(fig)

    # Correlation heatmap
    fig, ax = plt.subplots(figsize=(9.0, 7.2))
    sns.heatmap(corr, annot=True, fmt=".2f", cmap="coolwarm", center=0, ax=ax)
    ax.set_title("Pearson correlation among numerical predictors")
    fig.tight_layout()
    fig.savefig(output_dir / "correlation_heatmap.png", dpi=200)
    plt.close(fig)

    # Duration-band subscription rate (descriptive only; duration is leakage pre-call)
    duration_bins = [0, 60, 120, 180, 300, 600, 1200, np.inf]
    labels = ["0-59", "60-119", "120-179", "180-299", "300-599", "600-1199", "1200+"]
    temp = df[["duration", "y"]].copy()
    temp["duration_band"] = pd.cut(
        temp["duration"], bins=duration_bins, labels=labels, right=False
    )
    rate = (
        temp.assign(y_yes=temp["y"].eq("yes").astype(int))
        .groupby("duration_band", observed=False)["y_yes"]
        .mean()
        .mul(100)
    )
    fig, ax = plt.subplots(figsize=(8.0, 4.5))
    ax.bar(rate.index.astype(str), rate.values)
    ax.set_title("Subscription rate by call-duration band")
    ax.set_ylabel("Yes (%)")
    ax.set_xlabel("Call duration (seconds)")
    ax.tick_params(axis="x", rotation=35)
    fig.tight_layout()
    fig.savefig(output_dir / "duration_band_subscription_rate.png", dpi=200)
    plt.close(fig)


def engineer_features(df: pd.DataFrame) -> pd.DataFrame:
    """
    Create a deployable pre-call modelling table.

    duration is deliberately removed because it is only known after a call has
    occurred. pdays=999 is converted into an explicit previous-contact flag.
    """
    model_df = df.drop_duplicates().copy()
    model_df = model_df.drop(columns=["duration"])

    model_df["was_previously_contacted"] = (model_df["pdays"] != 999).astype(int)
    model_df["pdays_recency"] = model_df["pdays"].replace(999, np.nan)
    model_df = model_df.drop(columns=["pdays"])

    return model_df


def fit_leakage_aware_baseline(model_df: pd.DataFrame) -> None:
    """
    Chronological 80/20 holdout because the UCI full file is ordered by date.
    All fitted preprocessing remains inside the sklearn pipeline.
    """
    X = model_df.drop(columns=["y"])
    y = model_df["y"].map({"no": 0, "yes": 1})

    split_idx = int(len(model_df) * 0.80)
    X_train, X_test = X.iloc[:split_idx], X.iloc[split_idx:]
    y_train, y_test = y.iloc[:split_idx], y.iloc[split_idx:]

    categorical_cols = X.select_dtypes(include="object").columns.tolist()
    numeric_cols = X.select_dtypes(include=np.number).columns.tolist()

    numeric_pipe = Pipeline(
        steps=[
            ("imputer", SimpleImputer(strategy="median")),
            ("scaler", StandardScaler()),
        ]
    )

    categorical_pipe = Pipeline(
        steps=[
            # Literal 'unknown' is deliberately retained as a category.
            ("imputer", SimpleImputer(strategy="most_frequent")),
            ("onehot", OneHotEncoder(handle_unknown="ignore")),
        ]
    )

    preprocess = ColumnTransformer(
        transformers=[
            ("num", numeric_pipe, numeric_cols),
            ("cat", categorical_pipe, categorical_cols),
        ]
    )

    model = Pipeline(
        steps=[
            ("preprocess", preprocess),
            (
                "classifier",
                LogisticRegression(
                    max_iter=2000,
                    class_weight="balanced",
                    random_state=42,
                ),
            ),
        ]
    )

    model.fit(X_train, y_train)
    pred = model.predict(X_test)
    prob = model.predict_proba(X_test)[:, 1]

    print("=== LEAKAGE-AWARE BASELINE (CHRONOLOGICAL 80/20 HOLDOUT) ===")
    print("Accuracy:", round(accuracy_score(y_test, pred), 4))
    print("Balanced accuracy:", round(balanced_accuracy_score(y_test, pred), 4))
    print("Precision:", round(precision_score(y_test, pred, zero_division=0), 4))
    print("Recall:", round(recall_score(y_test, pred, zero_division=0), 4))
    print("F1:", round(f1_score(y_test, pred, zero_division=0), 4))
    print("ROC-AUC:", round(roc_auc_score(y_test, prob), 4))
    print("PR-AUC:", round(average_precision_score(y_test, prob), 4))
    print("Confusion matrix:")
    print(confusion_matrix(y_test, pred))
    print(classification_report(y_test, pred, digits=4, zero_division=0))


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--csv",
        type=Path,
        default=Path("bank-additional-full.csv"),
        help="Path to the UCI bank-additional-full.csv file",
    )
    parser.add_argument(
        "--output-dir",
        type=Path,
        default=Path("outputs"),
        help="Directory for generated figures",
    )
    parser.add_argument(
        "--skip-model",
        action="store_true",
        help="Run only the EDA/data-quality analysis",
    )
    args = parser.parse_args()

    print("Dataset URL:", DATASET_URL)
    print("CSV path:", args.csv.resolve())
    print()

    df = load_data(args.csv)
    audit_unknown_categories(df)
    target_summary(df)
    numeric_summary = numeric_quality_summary(df)
    corr = correlation_summary(df)
    semantic_checks(df)
    save_figures(df, numeric_summary, corr, args.output_dir)

    model_df = engineer_features(df)
    print("=== MODELLING TABLE AFTER LEAKAGE-SAFE ENGINEERING ===")
    print("Shape:", model_df.shape)
    print("duration present:", "duration" in model_df.columns)
    print("pdays present:", "pdays" in model_df.columns)
    print("New features:", ["was_previously_contacted", "pdays_recency"])
    print()

    if not args.skip_model:
        fit_leakage_aware_baseline(model_df)


if __name__ == "__main__":
    main()
