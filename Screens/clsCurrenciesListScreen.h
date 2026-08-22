#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>

class clsCurrenciesListScreen :protected clsScreen
{

private:

    static void PrintCurrencyRecordLine(clsCurrency Currency)
    {
                cout << left << setw(8)  << ""
             << "| " << left << setw(30) << Currency.Country();
        cout << "| " << left << setw(8)  << Currency.CurrencyCode();
        cout << "| " << left << setw(45) << Currency.CurrencyName();
        cout << "| " << left << setw(10) << Currency.Rate();

    }

public:

    static void ShowCurrenciesListScreen()
    {
        vector <clsCurrency> vCurrencys = clsCurrency::GetCurrenciesList();
        string Title = "\t  Currencies List Screen";
        string SubTitle = "\t    (" + to_string(vCurrencys.size()) + ") Currency.";

        _DrawScreenHeader(Title, SubTitle);
        cout << left << setw(8) << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

        cout << left << setw(8) << "" 
             << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8)   << "Code";
        cout << "| " << left << setw(45) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";
        cout << left << setw(8) << "" << "\n\t_______________________________________________________";
       
        cout << "_______________________________________________\n" << endl;
        if (vCurrencys.size() == 0)
            cout << "\t\t\t\tNo Currencies Available In the System!";
        else

            for (clsCurrency Currency : vCurrencys)
            {

                PrintCurrencyRecordLine(Currency);
                cout << endl;
            }

        cout << left << setw(8) << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;
    }
};