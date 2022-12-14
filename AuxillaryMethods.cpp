#include "AuxillaryMethods.h"

string AuxillaryMethods::conversionFromIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();

    return str;
}

int AuxillaryMethods::conversionFromStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

double AuxillaryMethods::conversionFromStringToDouble(string number)
{
    if(number.length() == 0)
    {
        number = "0";
    }
    for(int i = 0; i <= number.length()-1; i++)
    {
        if(number[i] == ',')
            number[i] = '.';
        if(number[i] == ' ')
            number.replace(i,1,"");
    }
    double numberDouble;
    istringstream iss(number);
    iss >> numberDouble;

    return numberDouble;
}

string AuxillaryMethods::conversionFromDoubleToString(double number)
{
    ostringstream ss;
    ss.precision(15);
    ss << number;
    string str = ss.str();

    return str;
}

int AuxillaryMethods::conversionDateFromStringToIntWithoutDash(string date)
{
    for(int i = 0; i <= date.length()-1; i++)
    {
        if(date[i] == '-')
            date.replace(i,1,"");
    }
    int dateInt = conversionFromStringToInt(date);

    return dateInt;
}

string AuxillaryMethods::loadLine()
{
    string input = "";
    getline(cin, input);

    return input;
}

char AuxillaryMethods::loadChar()
{
    string input = "";
    char character  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "This is not a single character. Enter again." << endl;
    }
    return character;
}
