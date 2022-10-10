#ifndef AUXILLARYMETHODS_H
#define AUXILLARYMETHODS_H

#include <iostream>
#include <windows.h>
#include <sstream>
#include <algorithm>
#include <ctime>

using namespace std;

class AuxillaryMethods
{

public:
    static double conversionFromStringToDouble(string number);
    static string conversionFromDoubleToString(double number);
    static string conversionFromIntToString(int number);
    static int conversionFromStringToInt(string number);
    static string getNumber(string text, int charPosition);
    static string loadLine();
    static char loadChar();
    static string changeFirstLetterToUpperAndNextLettersToLower(string text);
    static int loadInteger();
    static string getTodaysDate();
    static int conversionDateFromStringToIntWithoutDash(string date);
};

#endif
