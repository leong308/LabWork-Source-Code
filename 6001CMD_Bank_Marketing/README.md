# 6001CMD Bank Marketing Analysis

Reproducibility code for the 6001CMD Machine Learning individual assignment using the UCI **Bank Marketing** dataset.

## Dataset

Official UCI page:

https://archive.ics.uci.edu/dataset/222/bank+marketing

Download **bank-additional.zip**, extract it, and place `bank-additional-full.csv` next to `analysis.py`.

The report uses the **bank-additional-full.csv** version: 41,188 records, 20 input variables, and target `y`.

## Run

```bash
python -m venv .venv
# Windows:
.venv\Scripts\activate
# macOS/Linux:
# source .venv/bin/activate

pip install -r requirements.txt
python analysis.py --csv bank-additional-full.csv
```

For the data-quality analysis only:

```bash
python analysis.py --csv bank-additional-full.csv --skip-model
```

Generated figures are written to `outputs/`.

## What the script reproduces

- dataset shape, NaNs and duplicate rows
- literal `unknown` category counts
- target-class imbalance
- numerical descriptive statistics and skewness
- 1.5 x IQR outlier flags
- numerical correlations
- `pdays=999` semantic check
- call-duration leakage illustration
- leakage-safe feature engineering
- chronological train/test split
- one-hot encoding and standardisation inside a scikit-learn pipeline
- class-weighted logistic-regression baseline

## Important modelling decision

`duration` is removed before the deployable model because it is only known after a marketing call has taken place. It can be analysed descriptively, but using it to decide whom to call would introduce data leakage.
