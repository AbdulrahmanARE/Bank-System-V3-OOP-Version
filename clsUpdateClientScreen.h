#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidatidate.h"

class clsUpdateClientScreen : protected clsScreen
{
private:

    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidatidate::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidatidate::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidatidate::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidatidate::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidatidate::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidatidate::ReadFloatNumber();
    }

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

public:


    static void ShowUpdateClientScreen() {

        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
        {
            return;
		}
        _DrawScreenHeader("\t Update Client Screen");
        string AccountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidatidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is Already Used, Choose another one: ";
            AccountNumber = clsInputValidatidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        _PrintClient(Client1);

        cout << "\nAre you sure you want to update this client y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            cout << "\n\nUpdate Client Info:";
            cout << "\n____________________\n";

            _ReadClientInfo(Client1);

            clsBankClient::enSaveResults SaveResult;

            SaveResult = Client1.Save();

            switch (SaveResult)
            {
            case  clsBankClient::enSaveResults::svSucceeded:
            {
                cout << "\nAccount Updated Successfully :-)\n";

                _PrintClient(Client1);
                break;
            }
            case clsBankClient::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError account was not saved because it's Empty";
                break;

            }

            }

        }

    }
};

