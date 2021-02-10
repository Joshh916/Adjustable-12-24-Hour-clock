/*
 * Header file to declare functions in functions.cpp
 * By Joshua Hampton
 * Date: 1/21/21
 */

//ifndef defines safeguards to prevent libraries files from being imported multiple times
#ifndef PRINTFUNCTS_H
#define PRINTFUNCTS_H

using namespace std;

void PrintMenu();

void PrintTime(int& timeSecond, int& timeMinute, int& timeHour);

void ChangeTime(int& timeSecond, int& timeMinute, int& timeHour);

const string currentDateTime();

#endif
