// Name: Andrew Pinkerton
// Program Description: Midterm Exam
// Date: 10/9/2023

#include <iostream>
#include <string>
#include <fstream>


using namespace std;

struct person {
	string fName, lName;
};

int main()
{
	person atu[10];

	ifstream iFile;
	iFile.open("input.txt");
	if (!iFile.is_open())
	{
		cout << "File not found" << endl;
		exit(1);
	}

	int counter = 0;

	while (!iFile.eof())
	{
		iFile >> atu[counter].fName;
		iFile >> atu[counter].lName;
		counter++;
	}
	string temp;

	for (int a = 0; a < counter; a++)
	{
		for (int b = 0; b < counter - 1; b++)
		{
			if (atu[b].lName > atu[b + 1].lName)
			{
				temp = atu[b].lName;
				atu[b].lName = atu[b + 1].lName;
				atu[b + 1].lName = temp;

				temp = atu[b].fName;
				atu[b].fName = atu[b + 1].fName;
				atu[b + 1].fName = temp;



			}
		}
	}

	for (int a = 0; a < counter; a++)
	{
		cout << "Name: " << atu[a].fName << " " << atu[a].lName << endl;
	}

	iFile.close();

}