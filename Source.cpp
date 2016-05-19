#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
void heading();
string translateHours(int);
string translateMinutesMM(int);
string translateMinutesM(int);
string meridiem(int);

void heading()
{
	cout << "**********************************************************\n";
	cout << "Osi Otugo\n";
	cout << "@02662492\n";
	cout << "November 5, 2015\n";
	cout << "Assignment 9\n";
	cout << "Print out time in english!\n";
	cout << "**********************************************************\n";
}

int main()
{
	int hour, minutes, minutesMM = 0, minutesM = 0; //Variables used to store values
	ifstream myFile;
	myFile.open("infile.txt");
	myFile >> hour >> minutes; //Store value from infile into variables
	while (myFile) //Priming read
	{
		minutesMM = minutes / 10; //Used to get the "M" in format: Hr:Mm
		minutesM = minutes % 10; //used to get the "m" in format: Hr: Mm
		cout << "Numeric Time: " << hour << " "; //Output the numeric line from the infile
		if (minutes < 1) //Account for the extra 0 in the infile so it can appear in output
			cout << 0;
		cout << minutes << endl; //Output the remaining infile data
		cout << "English Time: "; //Output line for military to english
		//The following else if's are to account for special cases such as noon and midnight
		if ((hour == 12) && (minutes == 0))
			cout << "Noon" << endl << endl;
			else if ((hour == 0) && (minutes == 0))
				cout << "Midnight" << endl << endl;
				else if ((hour == 24) && (minutes = 0))
					cout << "Midnight" << endl << endl;
					else //If there are no other special cases then excute the following:
						if ((minutes > 9) && (minutes < 20)) //Accounts for minutes in the "teens"
							cout << translateHours(hour) + " " << translateMinutesMM(minutes)
								<< " " + meridiem(hour) << endl << endl;
				//If the minutes are not in the teens then call the respective functions	
							else 
								cout << translateHours(hour) + " " 
								<< translateMinutesMM(minutesMM) + " " 
								<< translateMinutesM(minutesM) << " " + meridiem(hour)
								<< endl << endl;
		myFile >> hour >> minutes; //Store value from infile into variables to begin the next loop
	}
	system("pause");
}
//Converts the numerical value of hours into english
string translateHours(int hour)
{
	//Look at the hour and depending on its value, it will return its respective english word
	switch (hour)
	{
	case 0:
	case 12:
	case 24:
		return "Twelve";
	case 1:
	case 13:
		return "One";
	case 2:
	case 14:
		return "Two";
	case 3:
	case 15:
		return "Three";
	case 4:
	case 16:
		return "Four";
	case 5:
	case 17:
		return "Five";
	case 6:
	case 18:
		return "Six";
	case 7:
	case 19:
		return "Seven";
	case 8:
	case 20:
		return "Eight";
	case 9:
	case 21:
		return "Nine";
	case 10:
	case 22:
		return "Ten";
	case 11:
	case 23:
		return "Eleven";
	}
}
//Converts the numerical value of "M" minutes (Mm) into english
string translateMinutesMM(int minMM)
{
	//Depending on the amount of minutes ("M" in (Mm)), return its respective word in english
	switch (minMM)
	{
		case 10:
			return "ten";
		case 11:
			return "eleven";
		case 12:
			return "twelve";
		case 13:
			return "thirteen";
		case 14:
			return "fourteen";
		case 15:
			return "fifteen";
		case 16:
			return "sixteen";
		case 17:
			return "seventeen";
		case 18:
			return "eighteen";
		case 19:
			return "ninteen";
		case 2:
			return "twenty";
		case 3:
			return "thirty";
		case 4:
			return "forty";
		case 5:
			return "fifty";
		default:
			return "";
	}
}
////Converts the numerical value of "m" minutes (Mm) into english
string translateMinutesM(int minM)
{
	////Depending on the amount of minutes ("m" in (Mm)), return its respective word in english
	switch (minM)
	{
		case 0:
			return "";
		case 1:
			return "one";
		case 2:
			return "two";
		case 3:
			return "three";
		case 4:
			return "four";
		case 5:
			return "five";
		case 6:
			return "six";
		case 7:
			return "seven";
		case 8:
			return "eight";
		case 9:
			return "nine";
	}
}
//Function used to determine whether to output PM or AM
string meridiem(int hour)
{
	////If the hour is greater than 11 but not equal to 24, time will be in PM
	if ((hour > 11) && (hour != 24)) 
		return "PM";
		else //Otherwise, return AM
			return "AM";
}
/*
Numeric Time: 6 44
English Time: Six forty four AM

Numeric Time: 0 00
English Time: Midnight

Numeric Time: 18 11
English Time: Six eleven PM

Numeric Time: 2 2
English Time: Two  two AM

Numeric Time: 5 7
English Time: Five  seven AM

Numeric Time: 12 00
English Time: Noon

Numeric Time: 8 35
English Time: Eight thirty five AM

Numeric Time: 20 25
English Time: Eight twenty five PM

Numeric Time: 23 11
English Time: Eleven eleven PM

Press any key to continue . . .
*/