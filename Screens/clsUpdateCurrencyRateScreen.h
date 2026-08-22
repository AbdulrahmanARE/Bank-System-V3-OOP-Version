#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsString.h"
#include "clsInputValidate.h"

class clsUpdateCurrencyRateScreen :protected clsScreen
{
private:
	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n";

	}
public:
	static void ShowUpdateCurrencyRateScreen()
	{
		_DrawScreenHeader("\t Update currency Screen");
		cout << "\n\nPlease Enter Currency Code: ";
		string CurrencyCode = clsInputValidate::ReadString();
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			CurrencyCode = clsInputValidate::ReadString();
			Currency = clsCurrency::FindByCode(CurrencyCode);
		}
		_PrintCurrency(Currency);
		char Answer;
		cout << "\n\nAre you sure you want to update the rate of this Currency y/n? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			float Rate;
			cout << "\n\nUpdate Currency Rate: \n --------------------\n";
			cout << "\nEnter New Rate: ";
			cin >> Rate;
			Currency.UpdateRate(Rate);
			cout << "\n\nCerrancy Rate Updated Successfully :-)\n\n";
			_PrintCurrency(Currency);
		}

	}
};

