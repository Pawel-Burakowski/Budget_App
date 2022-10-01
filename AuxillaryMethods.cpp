#include "AuxillaryMethods.h"

string AuxillaryMethods::conversionFromIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();

    return str;
}

int AuxillaryMethods::coversionFromStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

string AuxillaryMethods::getNumber(string text, int charPosition)
{
    string number = "";
    while(isdigit(text[charPosition]) == true)
    {
        number += text[charPosition];
        charPosition ++;
    }

    return number;
}

string AuxillaryMethods::loadLine()
{
    string entry = "";
    getline(cin, entry);

    return entry;
}

char AuxillaryMethods::loadChar()
{
    string entry = "";
    char character  = {0};

    while (true)
    {
        getline(cin, entry);

        if (entry.length() == 1)
        {
            character = entry[0];
            break;
        }
        cout << "This is not a single character. Enter again." << endl;
    }
    return character;
}

string AuxillaryMethods::changeFirstLetterToUpperAndNextLettersToLower(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

int AuxillaryMethods::loadInteger()
{
    string entry = "";
    int number = 0;

    while (true)
    {
        getline(cin, entry);

        stringstream myStream(entry);
        if (myStream >> entry)
            break;
        cout << "This is not a number. Enter again." << endl;
    }
    return number;
}
