#include "FileWithIncomes.h"

bool FileWithIncomes::addIncomeToFile(Income income)
{
    CMarkup xml;

    bool fileExists = xml.Load(XML_FILE_NAME);

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("Date", income.getStringDate());
    xml.AddElem("UserID", income.getUserId());
    xml.AddElem("Amount", income.getAmount());
    xml.AddElem("Description", income.getDescription());

    xml.Save( XML_FILE_NAME );
    return true;
}

void FileWithIncomes::addAllIncomesToFile(vector <Income> &incomes)
{
    CMarkup xml;

    xml.Load(XML_FILE_NAME);
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("Income"))
    {
        xml.RemoveElem();
    }
    for (vector <Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        xml.AddElem("Income");
        xml.IntoElem();
        xml.AddElem("Date", itr -> getStringDate());
        xml.AddElem("UserID", itr -> getUserId());
        xml.AddElem("Amount", itr -> getAmount());
        xml.AddElem("Description", itr -> getDescription());
        xml.OutOfElem();
    }
    xml.Save(XML_FILE_NAME );
}

vector <Income> FileWithIncomes::getIncomesOfLoggedUserFromFile(int ID_OF_LOGGED_USER)
{
    Income income;
    vector <Income> incomes;
    CMarkup xml;

    xml.Load(XML_FILE_NAME);
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("Income"))
    {
        xml.IntoElem();
        xml.FindElem("Date");
        income.setStringDate(xml.GetData());
        income.setIntDate(AuxillaryMethods::conversionDateFromStringToIntWithoutDash(income.getStringDate()));
        xml.FindElem("UserID");
        income.setUserId(atoi( MCD_2PCSZ(xml.GetData())));
        xml.FindElem("Amount");
        income.setAmount(atoi( MCD_2PCSZ(xml.GetData())));
        xml.FindElem("Description");
        income.setDescription(xml.GetData());
        xml.OutOfElem();

        if (ID_OF_LOGGED_USER == income.getUserId())
            incomes.push_back(income);
    }
    return incomes;
}
