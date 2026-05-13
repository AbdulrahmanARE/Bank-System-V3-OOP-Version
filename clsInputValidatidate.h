#pragma once
#include <iostream>
#include "clsDate.h"

using namespace std;

class clsInputValidatidate 
{
public :
	static bool IsNumberBetween(int num,int from,int to) {
		return (num >= from && num <= to);

	}

	static bool IsNumberBetween(double num, double from, double to) {
		return (num >= from && num <= to);

	}

	static bool IsNumberBetween(clsDate Date, clsDate Datefrom, clsDate Dateto) {
		if (!clsDate::IsDate1BeforeDate2(Datefrom, Dateto))
		{
			clsDate::SwapDates(Datefrom, Dateto);
		}
		return ( (clsDate::IsDate1AfterDate2(Date, Datefrom) || clsDate::IsDate1EqualDate2(Date, Datefrom) )
			&& (clsDate::IsDate1BeforeDate2(Date, Dateto) || clsDate::IsDate1EqualDate2(Date, Dateto)));
	}

	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		int Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static int ReadIntNumberBetween(int from, int to, string ErrorMessage) {

		int num = ReadIntNumber();
		
		while (!IsNumberBetween(num, from, to)) {
			cout << ErrorMessage;
			num = ReadIntNumber();
		}
		return num;
	}

	static short ReadShortNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		short Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		int Number = ReadShortNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadShortNumber();
		}
		return Number;
	}

	static double ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		float Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static double ReadFloatNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		float Number = ReadFloatNumber();

		while (!IsNumberBetween(Number, From, To)) {
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}
		return Number;
	}
	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		double Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static double ReadDblNumberBetween(double from, double to, string ErrorMessage) {

		double num = ReadDblNumber();
		
		while (!IsNumberBetween(num, from, to)) {
			cout << ErrorMessage;
			num = ReadDblNumber();
		}
		return num;
	}
	static bool IsValideDate(clsDate Date) {
		clsDate::IsValidDate(Date);
	}
	static string ReadString()
	{
		string  S1 = "";
		getline(cin >> ws, S1);

		return S1;
	}

};

