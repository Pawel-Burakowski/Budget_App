#ifndef FINANCIALBOOK_H
#define FINANCIALBOOK_H

#include <iostream>

#include "UserManager.h"
#include "BudgetManager.h"
#include "AuxillaryMethods.h"

using namespace std;

class FinancialBook
{
    UserManager userManager;

public:
    FinancialBook(string nameOfFileWithUsers)
        : userManager(nameOfFileWithUsers)
    {

    };

    void userRegistration();
    int userLoggingIn();
    int userLoggingOut();
    void changePasswordOfLoggedUser();
    void showAllUsers();
    char chooseOptionFromMainMenu();
    char chooseOptionFromUserMenu();
    bool checkIfUserIsLoged();
};

#endif
