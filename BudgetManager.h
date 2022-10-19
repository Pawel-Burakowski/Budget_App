#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <iomanip>
#include <algorithm>

#include "FileWithExpenses.h"
#include "FileWithIncomes.h"
#include "Income.h"
#include "Expense.h"
#include "AuxillaryMethods.h"
#include "Dates.h"

using namespace std;

class BudgetManager
{
    const int ID_OF_LOGGED_USER;
    vector <Income> incomes;
    vector <Expense> expenses;
    FileWithExpenses fileWithExpenses;
    FileWithIncomes fileWithIncomes;
    Dates dates;

    Income setDataOfTodayIncome();
    Income setDataOfAnotherDayIncome();
    Expense setDataOfTodayExpense();
    Expense setDataOfAnotherDayExpense();


    void showDataOfIncome(Income income);
    void showDataOfExpense(Expense expense);

    void displayTheNumberOfSearchedIncomesAndSum(int numberOfIncomes, double incomesSum);
    void displayTheNumberOfSearchedExpensesAndSumAndTotalSum(int numberOfExpenses, double incomesSum, double expensesSum);

    char chooseOptionFromIncomeMenu();
    char chooseOptionFromExpenseMenu();

public:
    BudgetManager(string nameOfFileWithIncomes, string nameOfFileWithExpenses, int idOfLoggedUser)
        : fileWithIncomes(nameOfFileWithIncomes), fileWithExpenses(nameOfFileWithExpenses), ID_OF_LOGGED_USER(idOfLoggedUser)
    {
        incomes = fileWithIncomes.getIncomesOfLoggedUserFromFile(ID_OF_LOGGED_USER);
        expenses = fileWithExpenses.getExpensesOfLoggedUserFromFile(ID_OF_LOGGED_USER);
    };
    int addIncome();
    int addExpense();

    void showBalanceFromTheCurrentMonth();
    void showBalanceFromThePreviousMonth();
    void showBalanceFromTheSelectedPeriod();

};

#endif
