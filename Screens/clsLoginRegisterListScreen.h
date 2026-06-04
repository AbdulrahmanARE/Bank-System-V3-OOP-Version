#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>

class clsLoginRegisterListScreen :protected clsScreen
{

private:
    static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
    {

        cout << left << setw(8) << ""
             << "| " << left << setw(25) << LoginRegisterRecord.DateTime;
        cout << "| " << left << setw(12) << LoginRegisterRecord.UserName;
        cout << "| " << left << setw(10) << LoginRegisterRecord.Password;
        cout << "| " << left << setw(12) << LoginRegisterRecord.Permissions;

    }

public:

    static void ShowLoginRegisterList()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
        {
            return;
        }
        vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();

        string Title = "\t  User List Screen";
        string SubTitle = "\t    (" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << left << setw(8) << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << left << setw(8) << "" 
             << "| " << left << setw(25) << "Date/Time";
        cout << "| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << left << setw(8) << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vLoginRegisterRecord.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsUser::stLoginRegisterRecord & LoginRegisterRecord : vLoginRegisterRecord)
            {

                _PrintLoginRegisterRecordLine(LoginRegisterRecord);
                cout << endl;
            }

        cout << left << setw(8) << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }

};
