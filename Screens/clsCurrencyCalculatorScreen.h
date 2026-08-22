#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsCurrencyCalculatorScreen :protected clsScreen
{
private:
	static float _ReadAmount()
	{
		cout << "\n\nEnter Amount to Exchange: ";
		short Amount = clsInputValidate::ReadNumber<short>();
		return Amount;
	}

	static clsCurrency _GetCurrency(string Message)
	{
		cout << Message;
		string CurrencyCode = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is not found, choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return Currency;
	}

	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n_____________________________\n\n";

	}
	static void _PrintCalculationsResults(clsCurrency Currency1, clsCurrency Currency2, short Amount){
		cout << "\nConvert From:\n";
		_PrintCurrencyCard(Currency1);
		float AmountInUSD = Currency1.ConvertTOUSD(Amount);

		cout << Amount << " " << Currency1.CurrencyCode()
			<< " = " << AmountInUSD << " USD\n";

		if (Currency2.CurrencyCode() == "USD")
		{
			return;
		}
		cout << "\nTo:\n";
		_PrintCurrencyCard(Currency2);

		float AmountInCurrency2 = Currency1.ConvertBetweenCurrency(Currency2, Amount);

		cout << Amount << " " << Currency1.CurrencyCode()
			<< " = " << AmountInCurrency2 << " " << Currency2.CurrencyCode();
		cout << "";
	}

public:
	static void ShowCurrencyCalculatorScreen()
	{
		char Continue = 'y';

		while (Continue == 'y' || Continue == 'Y')
		{
		system("cls");
		_DrawScreenHeader("\t Update Currency Screen");

		clsCurrency Currency1 = _GetCurrency("\n\nPlease Enter currency1 Code: ");
		clsCurrency Currency2 = _GetCurrency("\n\nPlease Enter currency2 Code: ");
	     short Amount = _ReadAmount();

		_PrintCalculationsResults(Currency1, Currency2, Amount);

		cout << "\n\nDo you want to perform another calculation? y/n ? ";
		cin >> Continue;

		}
	}
};