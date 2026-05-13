#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>

class clsClientListScreen:protected clsScreen
{

private:
   static void PrintClientRecordLine(clsBankClient Client)
    {

        cout << setw(8)  << "" << "| " << setw(15)  << Client.AccountNumber();
        cout << "| " << setw(20) << Client.FullName();
        cout << "| " << setw(12) << Client.Phone;
        cout << "| " << setw(20) << Client.Email;
        cout << "| " << setw(10) << Client.PinCode;
        cout << "| " << setw(12) << Client.AccountBalance;

    }

public:
  

   static void ShowClientsList()
    {
       if (!CheckAccessRights(clsUser::enPermissions::pListClients))
       {
           return;
       }
           vector <clsBankClient> vClients = clsBankClient::GetClientsList();
           string Title = "\t  Client List Screen";
           string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

           _DrawScreenHeader(Title, SubTitle);


           cout << setw(8) << "" << "\n\t_______________________________________________________";
           cout << "_________________________________________\n" << endl;

           cout << setw(8) << "" << "| " << setw(15) << "Accout Number";
           cout << "| " << setw(20) << "Client Name";
           cout << "| " << setw(12) << "Phone";
           cout << "| " << setw(20) << "Email";
           cout << "| " << setw(10) << "Pin Code";
           cout << "| " << setw(12) << "Balance";
           cout << setw(8) << "" << "\n\t_______________________________________________________";
           cout << "_________________________________________\n" << endl;

           if (vClients.size() == 0)
               cout << "\t\t\t\tNo Clients Available In the System!";
           else

               for (clsBankClient Client : vClients)
               {

                   PrintClientRecordLine(Client);
                   cout << endl;
               }

           cout << setw(8) << "" << "\n\t_______________________________________________________";
           cout << "_________________________________________\n" << endl;
       }

};
