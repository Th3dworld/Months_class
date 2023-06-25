//This program shows the utilization of the Months class
#include<iostream>
#include<string>
#include"Months.h"
using namespace std;

/*
*This program is menu driven program that will alllow its user to explore the different capabilities of the
* Months class;
*/

int main()
{
	//Declare variables
	char choice = NULL;
	string month_name;
	int month_number;

	//Display instructions to user and take input
	cout << "This program will allow you to explore the month class!\n";
	cout << "To get started, please input the month number:";
	cin >> month_number;
	cout << "\n";


	//Display output depenting on user input
	cout << "Great!\n";
	
	//Instantialize class
	Months objct_one(month_number);

	cout << "\n";

	//Display menu
	while(choice != 'Q')
	{
		cout << "What you would like to do next?\n";
		cout << "A. Display Month Name\n";
		cout << "B. Display Month Number\n";
		cout << "C. Move to Next Month\n";
		cout << "D. Move to Previous Month\n";
		cout << "E. Display Month Number and Name\n";
		cout << "Q. Quit\n";
		cout << "Selection:";
		cin >> choice;
		choice = toupper(choice);

		//Input validation
		while ((choice < 'A' || choice > 'E') && choice != 'Q')
		{
			cout << "!Error! You can only choose from the list below.\n";
			cout << "A. Display Month Name\n";
			cout << "B. Display Month Number\n";
			cout << "C. Move to Next Month\n";
			cout << "D. Move to Previous Month\n";
			cout << "E. Display Month Number and Name\n";
			cout << "Q. Quit\n";
			cout << "Please select a valid option:";
			cin >> choice;
			choice = toupper(choice);
		}

		//Use switch statement to determin output
		switch (choice)
		{
			case 'A':
			{
				cout << objct_one.get_monthName() << endl;
				break;
			}
			case 'B':
			{
				cout << objct_one.get_monthNumber() << endl;
				break;
			}
			case 'C':
			{
				objct_one++;
				break;
			}
			case 'D':
			{
				objct_one--;
				break;
			}
			case 'E':
			{
				cout << objct_one;
				break;
			}
			case 'Q':
			{
				break;
			}
			cout << "\n";
		}

	}

	return 0;
}
