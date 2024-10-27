// DaysInMonth.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// This program asks the user to enter the month (an integer in the range of 1 through 12) and the year.
// The program then displays the number of days in that month. The calculations accounts for the leap year.
// 
// Programmer: Aslihan Celik
//
// Date: 10/26/2024

#include <iostream>
using namespace std;

//Function to determine if the year is leap year
bool isLeapYear(int year);

//Function to calculate the number of days in a specified month of a given year
int getDaysInMonth(int month, int year);

int main()
{

    int month, year, daysInMonth;

    cout << "Please enter a number for the month (ex: 1- 12):" << endl;
    cin >> month;

	cout << "Please enter a number for the month (ex: 1- 12):" << endl;
	cin >> year;

	//find the days in a month
	daysInMonth = getDaysInMonth(month, year);

	cout << "The number of days in this month is: " << daysInMonth << endl;

    return 0;
}

// Determine if the year is leap year
bool isLeapYear(int year) {

	// All years which are perfectly divisible by 4 are leap years except for 
	// century years (years ending with 00), which are leap years only if they
	// are perfectly divisible by 400.

		   //if true is a leap year , if false not a leap year
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);


	/*
	//This is what is exactly mentioned in the question but I am leaving the more optimal way to find it as above.

	// Check if the year is divisible by 100
    if (year % 100 == 0) {
        // If it is, check if it's also divisible by 400
        return (year % 400 == 0); // Leap year only if divisible by 400
    } else {
        // If it is not divisible by 100, check if it's divisible by 4
        return (year % 4 == 0); // Leap year if divisible by 4
    }
	*/

}
//Calculates the number of days in a specified month of a given year
int getDaysInMonth(int month, int year)
{
	// Check if the month is February (2)
	if (month == 2) {
		// If it's February, return 29 if it's a leap year, otherwise return 28
		return isLeapYear(year) ? 29 : 28;
	}
	// For months January to July (1 to 7)
	else if (month <= 7)
	{
		// Return 30 days for even months (4, 6) and 31 days for odd months (1, 3, 5, 7)
		return month % 2 == 0 ? 30 : 31;
	}
	// For months August to December (8 to 12)
	else
	{
		// Return 31 days for even months (8, 10, 12) and 30 days for odd months (9, 11)
		return month % 2 == 0 ? 31 : 30;

	}

}