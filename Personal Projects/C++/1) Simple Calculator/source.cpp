/*
Project Name:
Simple Calculator

Project Description:
Create a console-based calculator that can perform basic arithmetic operations (Addition, Subtraction, Division and Multiplication)
Include Zero Error Handling
*/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

//changes decimal formatting for cout

void changeFormat(int decimalPlaces)
{
	cout << setprecision(decimalPlaces) << fixed;
	return;
}

const int ignore_chars = 20;
const int default_num = -1;

/*
Brief:
Gets a number from the user

Parameters:
(in) upperBound (highest value the user can enter)
(in) lowerBound (lowest value the user can enter)

(out) user's entered number
*/
int GetNumber(int lowerBound = 0, int upperBound = 0, bool restrictBounds = false)
{
	int num = default_num;

	while (cin.fail() || (num < lowerBound || num > upperBound))
	{
		cout << "Please enter a number: ";
		cin >> num;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(ignore_chars, '\n');
			cout << "Must be a number!" << endl;
		}
		else if (!restrictBounds)
			return num;
	}

	return num;
}

/*
Brief:
Returns a given string into lowercase.

Parameter:
(in) s (sentence to change to lowercase)

(out) lower (original sentence changed to lowercase)
*/
string ToLower(string& s)
{
	string lower = "";
	for (auto x : s)
	{
		lower += tolower(x);
	}
	return lower;
}

/*
Brief:
Asks the user for a true or false response to a question

Parameters:
(in) question (Default: blank string) (Question the user is asked)

(out) userChoice (user's answer returned as a boolean)
*/
bool GetBool(string question = "blank")
{
	string userChoice = "";

	cout << question << endl;

	while (userChoice != "y" && userChoice != "n")
	{
		cout << "Please enter y or n (Yes or no): " << endl;
		cin >> userChoice;

		userChoice = ToLower(userChoice);
	}

	return (userChoice) == "y" ? true : false;
}

// Vector containing all menu options
static vector<string> menuOptions =
{
	"1) Addition",
	"2) Subtraction",
	"3) Division",
	"4) Multiplication"
};

const int menuLow = 1;
const int menuMax = menuOptions.size() - 1;

const int addChoice = 1;
const int subChoice = 2;
const int divChoice = 3;
const int multChoice = 4;

// Main Menu
int main()
{
	cout << "C++ Practice: Simple Calculator" << endl;

	changeFormat(2);


	// Displays the menu options
	for (string& option : menuOptions)
	{
		cout << option << endl;
	}
	
	int userChoice = GetNumber(menuLow, menuMax, true);

	bool solved = false;
	string equation = "";
	int timesUsed = 0;
	double total = 0.0;
	int userNum = 0;

	switch (userChoice)
	{
		// Addition Section
		case(addChoice):
		{
			while (!solved)
			{
				system("cls");

				cout << timesUsed << endl;
				cout << "Addition Calculator" << endl;
				if (timesUsed >= 2)
				{
					equation[equation.length() - 2] = '=';

					cout << equation << " " << total << endl;

					solved = GetBool("Is your calculation done?: ");
					
					if (!solved)
					{
						equation[equation.length() - 2] = '+';
					}
				}

				userNum = GetNumber();
				total += userNum;
				equation += to_string(userNum) + " + ";
				timesUsed++;
			}
			break;
		}

		// Subtraction Section
		case(subChoice):
		{
			while (!solved)
			{
				system("cls");
				cout << "Subtraction Calculator" << endl;
				if (timesUsed == 0)
				{
					cout << "Please enter starting value:" << endl;
					total = GetNumber();
					equation += to_string(total) + " - ";
				}
				else
				{
					cout << "Please enter a number to subtract by:" << endl;
					userNum = GetNumber();

					equation += to_string(userNum) + " - ";

					total -= userNum;

					equation[equation.length() - 2] = '=';

					cout << equation << " " << total << endl;

					solved = GetBool("Is your calculation done?: ");

					if (!solved)
					{
						equation[equation.length() - 2] = '-';
					}
				}

				timesUsed++;
			}
			break;
		}

		// Division Section
		case(divChoice):
		{
			break;
		}

		// Multiplication Section
		case(multChoice):
		{
			break;
		}

		// Else
		default:
		{
			cout << "Invalid Option" << endl;
			system("clear");
		}
	}

	return 0;
}