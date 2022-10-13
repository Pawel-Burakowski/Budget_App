#include "FinancialBook.h"

char FinancialBook::chooseOptionFromMainMenu()
{
    char choice;

    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout << "   WELCOME TO THE BUDGET APP" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    cout << endl;
    cout << "     >>> MAIN  MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Login" << endl;
    cout << "9. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxillaryMethods::loadChar();

    return choice;
}

char FinancialBook::chooseOptionFromUserMenu()
{
    userManager.chooseOptionFromUserMenu();
}

void FinancialBook::userRegistration()
{
    userManager.userRegistration();
}

int FinancialBook::userLoggingIn()
{
    userManager.userLoggingIn();
    if (userManager.checkIfUserIsLogged())
    {
        budgetManager = new budgetManager(NAME_OF_FILE_WITH_INCOMES, NAME_OF_FILE_WITH_EXPENSES, userManager.getIdOfLoggedUser());
    }
}

int FinancialBook::userLoggingOut()
{
    userManager.userLoggingOut();
    delete budgetManager;
    budgetManager = NULL;
}

void FinancialBook::changePasswordOfLoggedUser()
{
    userManager.changePasswordOfLoggedUser();
}

void FinancialBook::showAllUsers()
{
    userManager.showAllUsers();
}

bool FinancialBook::checkIfUserIsLoged()
{
    userManager.checkIfUserIsLogged();
}

int FinancialBook::addIncome()
{
    budgetManager -> addIncome();
}

int FinancialBook::addExpense()
{
    budgetManager -> addExpense();
}

void FinancialBook::showBalanceFromTheCurrentMonth()
{
    budgetManager -> showBalanceFromTheCurrentMonth();
}

void FinancialBook::showBalanceFromThePreviousMonth()
{
    budgetManager -> showBalanceFromThePreviousMonth();
}
