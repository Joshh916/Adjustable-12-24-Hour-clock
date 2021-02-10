/*
 * Main.cpp starting point for the program to run main()
 * By Joshua Hampton
 * Date: 1/21/21
 */

//defines libraries to be included in main.cpp
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <cctype>
#include "functions.h"

using namespace std;

int main() {
	//Setup variables and initialize variables
	const int SLEEP_TIME = 1000;
	char userInput = '0';
	int hourOffset = 0;
	int minuteOffset = 0;
	int secondOffset = 0;

	while (userInput != '4') {
		//Calls PrintTime function from functions.cpp
		PrintTime(hourOffset, minuteOffset, secondOffset);

		//If statement to listen for escape key to pause the loop
		if (GetAsyncKeyState(VK_ESCAPE)) {
			PrintMenu();

			//exception block to catch invalid entries like characters instead of numbers
			try {
				cin >> userInput;
				if (isdigit(static_cast<int>(userInput))) {

					//switch statement which increments the current timeOffset variables if the user enters a value
					switch (userInput) {
						case '1':
							hourOffset += 1;
							break;
						case '2':
							minuteOffset += 1;
							break;
						case '3':
							secondOffset += 1;
							break;
						case '4':
							goto exit;
							break;
						default:
							cout << "Invalid Selection. Please try again.";
							Sleep(SLEEP_TIME);
							break;
					}
				}
				else {
					//defines error to be thrown if an invalid character is entered
					throw runtime_error("Invalid selection.");
				}
			}
			catch (runtime_error& excpt) {
				cout << excpt.what() << endl;
				cout << "Please enter a valid number 1-4." << endl;
				Sleep(SLEEP_TIME);

			}
		}
		//Pauses for one second before restarting the loop
		Sleep(SLEEP_TIME);
	}
	exit:
	return 0;
}
