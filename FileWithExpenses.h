#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>

#include "Expense.h"
#include "XmlFile.h"
#include "Markup.h"
#include "AuxillaryMethods.h"

using namespace std;

class FileWithExpenses : public XmlFile
{
public:
    FileWithExpenses(string fileName) : XmlFile(fileName) {};
    bool addExpenseToFile(Expense expense);
    void addAllExpensesToFile(vector <Expense> &expenses);
    vector <Expense> getExpensesOfLoggedUserFromFile(int ID_OF_LOGGED_USER);

};

#endif
