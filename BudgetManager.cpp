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
    do
    {
        date = AuxillaryMethods::loadLine();
    }
    while(checkIfDateIsCorrect(date) == false);

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
    do
    {
        date = AuxillaryMethods::loadLine();
    }
    while(checkIfDateIsCorrect(date) == false);

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

void BudgetManager::showBalanceFromTheCurrentMonth()
{
    int numberOfIncomes = 0;
    int numberOfExpenses = 0;
    string date = dates.getTodaysDate();
    string year = date.substr(0,4);
    string month = date.substr(5,2);
    double incomesSum = 0;
    double expensesSum = 0;

    system("cls");
    if (!incomes.empty())
    {
        sort(incomes.begin(), incomes.end(),greater<Income>());

        cout << "             >>> INCOMES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            string dateOfIncome = itr -> getStringDate();
            string yearOfIncome = dateOfIncome.substr(0,4);
            string monthOfIncome = dateOfIncome.substr(5,2);
            if ( year == yearOfIncome && month == monthOfIncome)
            {
                showDataOfIncome(*itr);
                incomesSum = incomesSum + itr -> getAmount();
                numberOfIncomes++;
            }
        }
        displayTheNumberOfSearchedIncomesAndSum(numberOfIncomes, incomesSum);
        cout << endl;
    }
    else
    {
        cout << endl << "There are no incomes in a selected period." << endl << endl;
    }
    if (!expenses.empty())
    {
        sort(expenses.begin(), expenses.end(),greater<Expense>());

        cout << "             >>> EXPENSES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            string dateOfExpense = itr -> getStringDate();
            string yearOfExpense = dateOfExpense.substr(0,4);
            string monthOfExpense = dateOfExpense.substr(5,2);
            if ( year == yearOfExpense && month == monthOfExpense)
            {
                showDataOfExpense(*itr);
                expensesSum = expensesSum + itr -> getAmount();
                numberOfExpenses++;
            }
        }
        displayTheNumberOfSearchedExpensesAndSumAndTotalSum(numberOfExpenses, incomesSum, expensesSum);
    }
    else
    {
        cout << endl << "There are no expenses in a selected period." << endl << endl;
    }

    system("pause");
}

void BudgetManager::showBalanceFromThePreviousMonth()
{
    int numberOfIncomes = 0;
    int numberOfExpenses = 0;
    string date = dates.getTodaysDate();
    string year = date.substr(0,4);
    string month = date.substr(5,2);
    int monthInt = AuxillaryMethods::conversionFromStringToInt(month) - 1;
    double incomesSum = 0;
    double expensesSum = 0;

    system("cls");
    if (!incomes.empty())
    {
        sort(incomes.begin(), incomes.end(),greater<Income>());

        cout << "             >>> INCOMES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            string dateOfIncome = itr -> getStringDate();
            string yearOfIncome = dateOfIncome.substr(0,4);
            string monthOfIncome = dateOfIncome.substr(5,2);
            int monthOfIncomeInt = AuxillaryMethods::conversionFromStringToInt(monthOfIncome);
            if ( year == yearOfIncome && monthInt == monthOfIncomeInt)
            {
                showDataOfIncome(*itr);
                incomesSum = incomesSum + itr -> getAmount();
                numberOfIncomes++;
            }
        }
        displayTheNumberOfSearchedIncomesAndSum(numberOfIncomes, incomesSum);
        cout << endl;
    }
    else
    {
        cout << endl << "There are no incomes in a selected period." << endl << endl;
    }
    if (!expenses.empty())
    {
        sort(expenses.begin(), expenses.end(),greater<Expense>());

        cout << "             >>> EXPENSES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            string dateOfExpense = itr -> getStringDate();
            string yearOfExpense = dateOfExpense.substr(0,4);
            string monthOfExpense = dateOfExpense.substr(5,2);
            int monthOfExpenseInt = AuxillaryMethods::conversionFromStringToInt(monthOfExpense);
            if ( year == yearOfExpense && monthInt == monthOfExpenseInt)
            {
                showDataOfExpense(*itr);
                expensesSum = expensesSum + itr -> getAmount();
                numberOfExpenses++;
            }
        }
        displayTheNumberOfSearchedExpensesAndSumAndTotalSum(numberOfExpenses, incomesSum, expensesSum);
    }
    else
    {
        cout << endl << "There are no expenses in a selected period." << endl << endl;
    }

    system("pause");
}

void FinancialManager::showBalanceFromTheSelectedPeriod()
{
    int numberOfIncomes = 0;
    int numberOfExpenses = 0;
    string firstDay, lastDay;
    int firstDayInt, lastDayInt;
    double incomesSum = 0;
    double expensesSum = 0;

    cout << "Give first day in rrrr-mm-dd format: ";
    do
    {
        firstDay = AuxillaryMethods::loadLine();
    }
    while(checkIfDateIsCorrect(firstDay) == false);
    firstDayInt = AuxillaryMethods::conversionDateFromStringToIntWithoutDash(firstDay);

    cout << "Give last day in rrrr-mm-dd format: ";
    do
    {
        lastDay = AuxillaryMethods::loadLine();
    }
    while(checkIfDateIsCorrect(lastDay) == false);
    lastDayInt = AuxillaryMethods::conversionDateFromStringToIntWithoutDash(lastDay);

    system("cls");
    if (!incomes.empty())
    {
        sort(incomes.begin(), incomes.end(),greater<Income>());

        cout << "             >>> INCOMES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            string dateOfIncome = itr -> getStringDate();
            int dateOfIncomeInt = AuxillaryMethods::conversionDateFromStringToIntWithoutDash(dateOfIncome);
            if ( dateOfIncomeInt >= firstDayInt && dateOfIncomeInt <= lastDayInt)
            {
                showDataOfIncome(*itr);
                incomesSum = incomesSum + itr -> getAmount();
                numberOfIncomes++;
            }
        }
        displayTheNumberOfSearchedIncomesAndSum(numberOfIncomes, incomesSum);
        cout << endl;
    }
    else
    {
        cout << endl << "There are no incomes in a selected period." << endl << endl;
    }
    if (!expenses.empty())
    {
        sort(expenses.begin(), expenses.end(),greater<Expense>());

        cout << "             >>> EXPENSES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            string dateOfExpense = itr -> getStringDate();
            int dateOfExpenseInt = AuxillaryMethods::conversionDateFromStringToIntWithoutDash(dateOfExpense);
            if ( dateOfExpenseInt >= firstDayInt && dateOfExpenseInt <= lastDayInt)
            {
                showDataOfExpense(*itr);
                expensesSum = expensesSum + itr -> getAmount();
                numberOfExpenses++;
            }
        }
        displayTheNumberOfSearchedExpensesAndSumAndTotalSum(numberOfExpenses, incomesSum, expensesSum);
    }
    else
    {
        cout << endl << "There are no expenses in a selected period." << endl << endl;
    }

    system("pause");
}

void BudgetManager::displayTheNumberOfSearchedIncomesAndSum(int numberOfIncomes, double incomesSum)
{
    if (numberOfIncomes == 0)
        cout << endl << "There are no incomes in a selected period." << endl;
    else
        cout << endl << "The amount of incomes in a selected period is: " << numberOfIncomes << endl;
    cout << "The Sum of incomes: " << setprecision(15) << incomesSum << endl << endl;
}

void BudgetManager::displayTheNumberOfSearchedExpensesAndSumAndTotalSum(int numberOfExpenses, double incomesSum, double expensesSum)
{
    if (numberOfExpenses == 0)
        cout << endl << "There are no expenses in a selected period." << endl;
    else
        cout << endl << "The amount of expenses in a selected period is: " << numberOfExpenses << endl;
    cout << "The Sum of Expenses: " << setprecision(15) << expensesSum << endl << endl;
    cout << "TOTAL INCOME IN THE SELECTED PERIOD: " << setprecision(15) << incomesSum + expensesSum;
    cout << endl << endl;
}

void BudgetManager::showDataOfIncome(Income income)
{
    cout << endl << "Date:                 " << income.getStringDate() << endl;
    cout << "Amount:                " << setprecision(15) << income.getAmount() << endl;
    cout << "Description:           " << income.getDescription() << endl;
}

void BudgetManager::showDataOfExpense(Expense expense)
{
    cout << endl << "Date:                 " << expense.getStringDate() << endl;
    cout << "Amount:                " << setprecision(15) << expense.getAmount() << endl;
    cout << "Description:           " << expense.getDescription() << endl;
}

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
