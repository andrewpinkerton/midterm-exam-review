// Name: Andrew Pinkerton
// Program Description: Midterm Exam
// Date: 10/9/2023

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

struct person {
	string jobTitle;
	int mWorked;
	double wage;
};

void fileCheck(ifstream& iFile)
{
	if (!iFile.is_open())
	{
		cout << "File not found! Exiting." << endl;
		exit(1);
	}

}

int getData(ifstream& iFile, vector<person>& workplace)
{
	int counter = 0;

	while (!iFile.eof())
	{
		person temp;

		getline(iFile, temp.jobTitle);
		iFile >> temp.mWorked;
		iFile >> temp.wage;

		workplace.push_back(temp);
		iFile.ignore();
		counter++;
	}

	return counter;
}

void sort(vector<person>& workplace, int counter, int choice, ofstream& oFile)
{
	string sTemp;
	int iTemp, COL1 = 23, COL2 = 5;
	double dTemp;


	for (int a = 0; a < counter; a++)
	{
		for (int b = 0; b < counter - 1; b++)
		{
			if (choice == 1)
			{
				if (workplace[b].jobTitle > workplace[b + 1].jobTitle)
				{
					sTemp = workplace[b].jobTitle;
					workplace[b].jobTitle = workplace[b + 1].jobTitle;
					workplace[b + 1].jobTitle = sTemp;

					iTemp = workplace[b].mWorked;
					workplace[b].mWorked = workplace[b + 1].mWorked;
					workplace[b + 1].mWorked = iTemp;

					dTemp = workplace[b].wage;
					workplace[b].wage = workplace[b + 1].wage;
					workplace[b + 1].wage = dTemp;
				}
			}
			else if (choice == 2)
			{
				if (workplace[b].mWorked > workplace[b + 1].mWorked)
				{
					sTemp = workplace[b].jobTitle;
					workplace[b].jobTitle = workplace[b + 1].jobTitle;
					workplace[b + 1].jobTitle = sTemp;

					iTemp = workplace[b].mWorked;
					workplace[b].mWorked = workplace[b + 1].mWorked;
					workplace[b + 1].mWorked = iTemp;

					dTemp = workplace[b].wage;
					workplace[b].wage = workplace[b + 1].wage;
					workplace[b + 1].wage = dTemp;
				}
			}
			else if (choice == 3)
			{
				if (workplace[b].wage > workplace[b + 1].wage)
				{
					sTemp = workplace[b].jobTitle;
					workplace[b].jobTitle = workplace[b + 1].jobTitle;
					workplace[b + 1].jobTitle = sTemp;

					iTemp = workplace[b].mWorked;
					workplace[b].mWorked = workplace[b + 1].mWorked;
					workplace[b + 1].mWorked = iTemp;

					dTemp = workplace[b].wage;
					workplace[b].wage = workplace[b + 1].wage;
					workplace[b + 1].wage = dTemp;
				}
			}
		}
	}

	for (int a = 0; a < counter; a++)
	{
		cout << left << showpoint << setprecision(4);
		cout << "Title: " << setw(COL1) << workplace[a].jobTitle  << "Months: " << setw(COL2) << workplace[a].mWorked << "Wage: $" << setw(COL2) << workplace[a].wage << endl;
		oFile << left << showpoint << setprecision(4);
		oFile << "Title: " << setw(COL1) << workplace[a].jobTitle << "Months: " << setw(COL2) << workplace[a].mWorked << "Wage: $" << setw(COL2) << workplace[a].wage << endl;
	}

}

int highest(vector<person>& workplace, int counter, int choice)
{
	int highest = 0;

	if (choice == 4)
	{
		for (int i = 0;i < counter - 1; i++)
		{
			if (workplace[i].wage < workplace[i + 1].wage)
			{
				highest = i + 1;
			}
		}
	}
	else if (choice == 5)
	{
		for (int i = 0;i < counter - 1; i++)
		{
			if (workplace[i].mWorked < workplace[i + 1].mWorked)
			{
				highest = i + 1;
			}
		}
	}

	return highest;
}

void menu(vector<person>& workplace, int counter, ofstream& oFile)
{
	int choice = 0;
	int display = 0;

	cout << "Sort by: " << endl;
	cout << "1 - Job Title" << endl;
	cout << "2 - Months on Job" << endl;
	cout << "3 - Hourly Wage" << endl << endl;
	cout << "Display: " << endl;
	cout << "4 - Highest Earning Employee" << endl;
	cout << "5 - Employee working there the longest" << endl << endl;

	do {
		cout << "Enter what you like to sort by or display (1, 2, 3, 4, or 5)" << endl;
		cin >> choice;

		if (!cin || choice < 1 || choice > 6) {
			cout << "You entered an invalid input. Please try again." << endl << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	} while ((!cin || choice < 1 || choice >= 6));

	switch (choice)
	{
	case 1:
		{
			system("CLS");
			cout << "Sorted by Job Title: " << endl << endl;
			oFile << "Sorted by Job Title: " << endl << endl;
			sort(workplace, counter, choice, oFile);

			break;
		}
	case 2:
		{
			system("CLS");
			cout << "Sorted by Months Worked: " << endl << endl;
			oFile << "Sorted by Months Worked: " << endl << endl;
			sort(workplace, counter, choice, oFile);

			break;
		}
	case 3:
		{
			system("CLS");
			cout << "Sorted by Wage: " << endl << endl;
			oFile << "Sorted by Wage: " << endl << endl;
			sort(workplace, counter, choice, oFile);

			break;
		}
	case 4: 
		{
			system("CLS");
			cout << "Displaying Highest Earning Employee: " << endl << endl;
			oFile << "Displaying Highest Earning Employee: " << endl << endl;
			display = highest(workplace, counter, choice);
			cout << left << showpoint << setprecision(4);
			cout << "Title: " << setw(23) << workplace[display].jobTitle << "Months: " << setw(5) << workplace[display].mWorked << "Wage: $" << setw(5) << workplace[display].wage << endl << endl;
			oFile << left << showpoint << setprecision(4);
			oFile << "Title: " << setw(23) << workplace[display].jobTitle << "Months: " << setw(5) << workplace[display].mWorked << "Wage: $" << setw(5) << workplace[display].wage << endl << endl;
			break;
		}
	case 5:
		{
			system("CLS");
			cout << "Displaying Longest Working: " << endl  << endl;
			oFile << "Displaying Longest Working: " << endl << endl;
			display = highest(workplace, counter, choice);
			cout << left << showpoint << setprecision(4);
			cout << "Title: " << setw(23) << workplace[display].jobTitle << "Months: " << setw(5) << workplace[display].mWorked << "Wage: $" << setw(5) << workplace[display].wage << endl;
			oFile << left << showpoint << setprecision(4);
			oFile << "Title: " << setw(23) << workplace[display].jobTitle << "Months: " << setw(5) << workplace[display].mWorked << "Wage: $" << setw(5) << workplace[display].wage << endl << endl;
			break;
		}
	}

}

int main()
{
	vector<person> workplace;

	ifstream iFile;
	ofstream oFile;
	iFile.open("input.txt");
	oFile.open("output.txt");

	fileCheck(iFile);
	int counter = getData(iFile, workplace);
	int input = 0;
	

	do {
		menu(workplace, counter, oFile);
		cout << endl << "Would you like to sort or display anything else? (1 - Yes) (2 - Exit)" << endl;
		cin >> input;

		if (input == 1)
		{
			system("CLS");
			oFile << endl << "---------------- New Sort/Display -----------------" << endl << endl;
		}

	} while (input == 1);
	

	iFile.close();
	oFile.close();

	return 0;
}