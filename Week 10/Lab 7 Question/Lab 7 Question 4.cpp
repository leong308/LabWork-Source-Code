// Lab 7 Question 4
// LEONG ZI QI

#include <iostream>
using namespace std;

// 2 parameters only
int calcAverageGrade(int, int);

int main()
{
	int sumOfScore, totalStudent, averageMark;
	char grade;
	
	cout << "Enter the number of students\n";
	cin >> totalStudent;
	// return averageMark
	averageMark = calcAverageGrade(0, totalStudent);
	
	if(averageMark >= 90)
		grade = 'A';
	else if(averageMark >= 80)
		grade = 'B';
	else if(averageMark >= 70)
		grade = 'C';
	else if(averageMark >= 60)
		grade = 'D';
	else
		grade = 'F';
		
	cout << "The grade is " << grade << endl;
	
	return 0;
	
}

int calcAverageGrade(int sumOfScore, int totalStudent)
{
	int score;
	int averageMark;
	
	for(int i = 0; i < totalStudent; i++){
		do{
			cout << "Enter a numeric grade between 0-100\n";
			cin >> score;
			
			if(score < 0 || score > 100)
				cout << "Invalid Input.\n";
		}
		while(score < 0 || score > 100);
		
		sumOfScore += score;
	}
	
	averageMark = sumOfScore / totalStudent;
	
	return averageMark;
}
