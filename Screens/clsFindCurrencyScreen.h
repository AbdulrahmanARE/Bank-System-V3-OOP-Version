#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsFindCurrencyScreen : protected clsScreen
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
	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrency(Currency);
		}
		else
		{
			cout << "\nCurrency Was not Found :-(\n";
		}
	}
public:
	static void ShowFindCurrencyScreen() {
		_DrawScreenHeader("\t Find Currency Screen");

		cout << "\n\nFind By: [1] Code or [2] country ? ";
		short Answer;
		cin >> Answer;
		if (Answer == 1) {
			cout << "\n\nPlease Enter Currency Code: ";
			clsCurrency Currency = clsCurrency::FindByCode(clsInputValidate::ReadString());
			_ShowResults(Currency);

		}

		else {
			cout << "\n\nPlease Enter Country Name :";
			clsCurrency Currency = clsCurrency::FindByCountry(clsInputValidate::ReadString());
			_ShowResults(Currency);
		}

	}
};

