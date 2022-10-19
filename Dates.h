#ifndef DATES_H
#define DATES_H

//#include <bits/stdc++.h>
#include <iostream>
#include <windows.h>

#include "AuxillaryMethods.h"

using namespace std;

class Dates
{
    int calculateTheNumberOfDaysInAMonth(int month, int year);

public:
    string getTodaysDate();
    bool checkIfDateIsCorrect(string date);
};

#endif
