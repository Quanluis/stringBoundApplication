// stringBoundApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <conio.h>

using namespace std;

class bCheckString {

	private:

		string userInput;

		vector<int> x;
	
		void intro();

		void checkString();

		void validate();

		//Exception class 

		class BoundsException {};

	public:

	void driver();


};

/*****************************Method Definitions*****************************/

//order of execution

void bCheckString::intro() {

	cout << "This program demonstrates bounds checking on string objects." << endl;

}

void bCheckString::checkString() {

	cout << "Enter a string: ";

	cin >> userInput;

	for (int i = 0; i <= userInput.length(); i++) {

		x.push_back(i);

	}

	cout << endl;

	cout << "Legitimate string positions are " << x.front() << "..." << x.back() - 1 << endl;

}

void bCheckString::validate() {

	int i = 0;

	cout << "Enter an integer describing a position inside or outside the string: ";

	int inputPosition;

	cin >> inputPosition;

	try {

		if (inputPosition < userInput.length()) {
			cout << "position is in range." << endl;

			cout << "The character at position " << inputPosition << " is " << userInput[inputPosition] << endl;
			validate();
		}
		else
			throw BoundsException();
	}
	catch (BoundsException) {

		cout << "Access violation in the string." << endl;

	}

}

void bCheckString::driver() {

	intro();
	checkString();
	validate();

}

int main()
{
	
	bCheckString bCheckString;

	bCheckString.driver();

	return 0;

};

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
