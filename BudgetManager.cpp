#include "BudgetManager.h"

int BudgetManager::addIncome()
{
    Income income;

    char choice;

    while(1)
    {
        system("cls");
        cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
        choice = chooseOptionFromIncomeMenu();

        switch (choice)
        {
        case '1':
            income = setDataOfTodayIncome();
            incomes.push_back(income);
            if (fileWithIncomes.addIncomeToFile(income))
                cout << "The new income has been added" << endl;
            else
                cout << "Error. It was not possible to add a new income to the file." << endl;
            system("pause");
            break;

        case '2':
            income = setDataOfAnotherDayIncome();
            incomes.push_back(income);
            if (fileWithIncomes.addIncomeToFile(income))
                cout << "The new income has been added" << endl;
            else
                cout << "Error. It was not possible to add a new income to the file." << endl;
            system("pause");
            break;

        case '3':
            return 0;
            break;

        default:
            cout << endl << "There is no option on the menu!" << endl << endl;
            break;
        }
    }
    return 0;
}

Income BudgetManager::setDataOfTodayIncome()
{
    Income income;

    string date, amount, description;
    int dateInt;
    double amountDouble;

    income.setUserId(ID_OF_LOGGED_USER);
    date = AuxillaryMethods::getTodaysDate();
    dateInt = AuxillaryMethods::conversionDateFromStringToIntWithoutDash(date);

    cout << "Give the amount of income: ";
    amount = AuxillaryMethods::loadLine();
    amountDouble = AuxillaryMethods::conversionFromStringToDouble(amount);

    cout << "Write the description: ";
    description = AuxillaryMethods::loadLine();

    income.setStringDate(date);
    income.setIntDate(dateInt);
    income.setAmount(amountDouble);
    income.setDescription((description));
    return income;
}

Income BudgetManager::setDataOfAnotherDayIncome()
{
    Income income;

    string date, amount, description;
    int dateInt;
    double amountDouble;

    income.setUserId(ID_OF_LOGGED_USER);

    cout << "Give the date in rrrr-mm-dd format: ";
    date = AuxillaryMethods::loadLine();
    while(checkIfDateIsCorrect(date) == false)
    {
        date = AuxillaryMethods::loadLine();
    }
    dateInt = AuxillaryMethods::conversionDateFromStringToIntWithoutDash(date);

    cout << "Give the amount of income: ";
    amount = AuxillaryMethods::loadLine();
    amountDouble = AuxillaryMethods::conversionFromStringToDouble(amount);

    cout << "Write the description: ";
    description = AuxillaryMethods::loadLine();

    income.setStringDate(date);
    income.setIntDate(dateInt);
    income.setAmount(amountDouble);
    income.setDescription((description));

    return income;
}

int BudgetManager::addExpense()
{
    Expense expense;

    char choice;

    while(1)
    {
        system("cls");
        cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;
        choice = chooseOptionFromExpenseMenu();

        switch (choice)
        {
        case '1':
            expense = setDataOfTodayExpense();
            expenses.push_back(expense);
            if (fileWithExpenses.addExpenseToFile(expense))
                cout << "The new expense has been added" << endl;
            else
                cout << "Error. It was not possible to add a new expense to the file." << endl;
            system("pause");
            break;

        case '2':
            expense = setDataOfAnotherDayExpense();
            expenses.push_back(expense);
            if (fileWithExpenses.addExpenseToFile(expense))
                cout << "The new expense has been added" << endl;
            else
                cout << "Error. It was not possible to add a new expense to the file." << endl;
            system("pause");
            break;

        case '3':
            return 0;
            break;

        default:
            cout << endl << "There is no option on the menu!" << endl << endl;
            break;
        }
    }
    return 0;
}

Expense BudgetManager::setDataOfTodayExpense()
{
    Expense expense;

    string date, amount, description;
    int dateInt;
    double amountDouble;

    expense.setUserId(ID_OF_LOGGED_USER);
    date = AuxillaryMethods::getTodaysDate();
    dateInt = AuxillaryMethods::conversionDateFromStringToIntWithoutDash(date);

    cout << "Give the amount of expense: ";
    amount = AuxillaryMethods::loadLine();
    if(amount[0] != '-')
        amount = '-' + amount;
    amountDouble = AuxillaryMethods::conversionFromStringToDouble(amount);

    cout << "Write the description: ";
    description = AuxillaryMethods::loadLine();

    expense.setStringDate(date);
    expense.setIntDate(dateInt);
    expense.setAmount(amountDouble);
    expense.setDescription((description));

    return expense;
}

Expense BudgetManager::setDataOfAnotherDayExpense()
{
    Expense expense;

    string date, amount, description;
    int dateInt;
    double amountDouble;

    expense.setUserId(ID_OF_LOGGED_USER);

    cout << "Give the date in rrrr-mm-dd format: ";
    date = AuxillaryMethods::loadLine();
    while(checkIfDateIsCorrect(date) == false)
    {
        date = AuxillaryMethods::loadLine();
    }
    dateInt = AuxillaryMethods::conversionDateFromStringToIntWithoutDash(date);

    cout << "Give the amount of expense: ";
    amount = AuxillaryMethods::loadLine();
    if(amount[0] != '-')
        amount = '-' + amount;
    amountDouble = AuxillaryMethods::conversionFromStringToDouble(amount);

    cout << "Write the description: ";
    description = AuxillaryMethods::loadLine();

    expense.setStringDate(date);
    expense.setIntDate(dateInt);
    expense.setAmount(amountDouble);
    expense.setDescription((description));

    return expense;
}

/*
void BudgetManager::showBalanceFromTheCurrentMonth()
{
    system("cls");
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void BudgetManager::displayTheNumberOfSearchedIncomes(int numberOfIncomes)
{
    if (iloscAdresatow == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
}

void BudgetManager::displayTheNumberOfSearchedExpenses(int numberOfExpenses)
{
    if (iloscAdresatow == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
}

void BudgetManager::showDataOfIncome(Income income)
{
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

void BudgetManager::showDataOfExpense(Expense expense)
{
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}
*/
bool BudgetManager::checkIfDateIsCorrect(string date)
{
    for(int i = 0; i <= date.length()-1; i++)
    {
        if((date[i] < 48 || date[i] > 57) && date[i] != '-')
        {
            cout << "Wrong date format. Enter the date again!" << endl;
            return false;
        }
    }
    if( date.length() == 10 && date[4] == '-' && date[7] == '-' )
    {
        string year = date.substr(0,4);
        string month = date.substr(5,2);
        string day = date.substr(8,2);
        int yearInt = AuxillaryMethods::conversionFromStringToInt(year);
        int monthInt = AuxillaryMethods::conversionFromStringToInt(month);
        int dayInt = AuxillaryMethods::conversionFromStringToInt(day);
        if (yearInt > 0 && monthInt > 0 && monthInt <= 12 && dayInt > 0 && dayInt <= 31)
        {
            cout << "The date entered correctly." << endl;
            return true;
        }
        else
        {
            cout << "bad date values. Enter the date again!" << endl;
            return false;
        }
    }
    else
    {
        cout << "Wrong date format. Enter the date again!" << endl;
        return false;
    }
}

char BudgetManager::chooseOptionFromIncomeMenu()
{
    char choice;

    cout << "---------------------------" << endl;
    cout << "1 - Today's income" << endl;
    cout << "2 - Income from another day" << endl;
    cout << "3 - Exit " << endl;
    cout << endl << "Your choice: ";
    choice = AuxillaryMethods::loadChar();

    return choice;
}

char BudgetManager::chooseOptionFromExpenseMenu()
{
    char choice;

    cout << "---------------------------" << endl;
    cout << "1 - Today's expense" << endl;
    cout << "2 - Expense from another day" << endl;
    cout << "3 - Exit " << endl;
    cout << endl << "Your choice: ";
    choice = AuxillaryMethods::loadChar();

    return choice;
}
