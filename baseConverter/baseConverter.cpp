/*******************************************************************************************************
Program Name: Base Converter - baseConverter.cpp
Description: This program will accept input from a .txt file; the first integer accepted will be the 
				decimal to be converted, and the second number will be the base the first int will be
				converted to. This problem will be solved recursively.
Author: Caleb Manor
Due Date: 2/6/19
*******************************************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

/*******************************************************************************************************
Function: remainderConverter
Description: This function assumes that the given parameter is between 10 and 15 and will convert
				the remainder into the proper form.
*******************************************************************************************************/
void remainderConverter(int remainder) {
	if (remainder == 10)
		cout << 'A';
	else if (remainder == 11)
		cout << 'B';
	else if (remainder == 12)
		cout << 'C';
	else if (remainder == 13)
		cout << 'D';
	else if (remainder == 14)
		cout << 'E';
	else if (remainder == 15)
		cout << 'F';
}

/*******************************************************************************************************
Function: baseConverter
Description: This function will accept two integers; the first integer will be a decimal number that
				will in turn be converted to the base specified by the second integer. If a remainder
				is found that is between 10 and 15, a second function will be called to convert the
				remainder appropriately. 
*******************************************************************************************************/
void baseConverter(int num, int base) {
	if (num == 0)
		return;

	else {
		baseConverter(num / base, base);

		int remainder = num % base;

		if (remainder >= 10 && remainder <= 15) 
			remainderConverter(remainder);
		else
			cout << remainder;
	}
}

void main() {

	/***************************************************************************************************   
	includes variable definitions, constants, and establishes numbers.txt as the input file
	***************************************************************************************************/
	const int MIN = 0;
	const int MAX = 1000000000;
	ifstream fin;
	int num, base;
	fin.open("numbers.txt");

	/***************************************************************************************************
	Accepts first two integers from numbers.txt
	***************************************************************************************************/
	fin >> num >> base;

	/**************************************************************************************************
	While statement checks to see if decimal is negative or not
	First if statement inside will check to ensure the decimal is within the range of 0 and 1 billion
	Second if statement will check for whether or not the decimal is 0. If it is, it will bypass the 
		recursive function and output 0 as the conversion

	The loop will continue by retrieving the next set of integers from numbers.txt until a negative
		integer is found
	**************************************************************************************************/
	while (num >= MIN) {
		if (num >= MIN && num <= MAX) {
			if (num == MIN)
				cout << num << " in base " << base << " is " << "0\n";
			else {
				cout << num << " in base " << base << " is ";
				baseConverter(num, base);
				cout << endl;
			}
		}
		else
			cout << "Decimal number too large for this program\n";

		fin >> num >> base;
	}
	system("pause");
}