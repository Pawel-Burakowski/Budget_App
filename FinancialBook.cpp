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

char KsiazkaAdresowa::chooseOptionFromUserMenu()
{
    userManager.chooseOptionFromUserMenu();
}

void KsiazkaAdresowa::userRegistration()
{
    userManager.userRegistration();
}

int KsiazkaAdresowa::logowanieUzytkownika()
{
    userManager.userLoggingIn();
    userManager.checkIfUserIsLoged();
    //if (userManager.czyUzytkownikJestZalogowany())
    //{
    //    adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, userManager.pobierzIdZalogowanegoUzytkownika());
    //}
}

int KsiazkaAdresowa::userLoggingOut()
{
    userManager.userLoggingOut();
    // delete adresatMenedzer;
    //adresatMenedzer = NULL;
}

void KsiazkaAdresowa::changePasswordOfLoggedUser()
{
    userManager.changePasswordOfLoggedUser();
}

void KsiazkaAdresowa::showAllUsers()
{
    userManager.showAllUsers();
}

bool KsiazkaAdresowa::checkIfUserIsLoged()
{
    userManager.checkIfUserIsLoged();
}
