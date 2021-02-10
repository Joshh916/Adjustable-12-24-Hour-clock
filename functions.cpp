/*
 * functions.cpp file used to store functions for Main.cpp
 * By Joshua Hampton
 * Date: 1/21/21
 */


#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <windows.h>

using namespace std;

//returns current time as a string
const string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%X", &tstruct);

    return buf;
}

//Function to print the menu with formatting
void PrintMenu() {
	cout << string(100, '\n');
	cout << "      " << setw(26) << setfill('*') << "*" << endl;
	cout << "      *  1 - Add One Hour      *" << endl;
	cout << "      *  2 - Add One Minute    *" << endl;
	cout << "      *  3 - Add One Second    *" << endl;
	cout << "      *  4 - Exit Program      *" << endl;
	cout << "      " << setw(26) << setfill('*') << "*" << "\n\n" << endl;
}

void PrintTime(int& hourOffset, int& minuteOffset, int& secondOffset) {
	//declares variables and instantiates time variables with the current time
	string amPm;
	int twelveHour;
	int timeHour = stoi(currentDateTime().substr(0, 2));
	int timeMinute = stoi(currentDateTime().substr(3, 2));
	int timeSecond = stoi(currentDateTime().substr(6, 2));

	//converts the time into a 12 hour format and stores it in variable twelveHour
	if (timeHour > 12) {
		twelveHour = timeHour - 12;
	}
	else {
		twelveHour = timeHour;
	}

	//Checks the current time and if it is after twelve it sets the variable amPm to PM
	if (timeHour >= 12) {
		amPm = " P M";
	}
	else {
		amPm = " A M";
	}

	//clears the screen by adding 100 new lines
	cout << string(100, '\n');

	//Prints formatted 12 and 24 hour clock, adding time offset
	cout << setw(26) << setfill('*') << "*" << "     " << setw(26) << setfill('*') << "*" << endl;
	cout << "*      12-HourClock      *     *      24-HourClock      *" << endl;
	cout << "*      " << setw(2) << setfill('0') << (twelveHour + hourOffset) << ":"
			<< setw(2) << setfill('0') << (timeMinute + minuteOffset) << ":"
			<< setw(2) << setfill('0') << (timeSecond + secondOffset) << amPm << "      *";
	cout << "     *        " << setw(2) << setfill('0') << (timeHour + hourOffset) << ":"
			<< setw(2) << setfill('0') << (timeMinute + minuteOffset) << ":"
			<< setw(2) << setfill('0') << (timeSecond + secondOffset) << "        *" << endl;
	cout << setw(26) << setfill('*') << "*" << "     " << setw(26) << setfill('*') << "*" << endl;
	cout << "\n\t\tPress escape key to see options.\n\n"  << endl;
}



