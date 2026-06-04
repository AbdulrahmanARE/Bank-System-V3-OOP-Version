#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{

private:

    static bool _Login()
    {
        bool LoginFailed = false;
        short FailedLoginCount = 0;

        string Username, Password;

        do
        {
            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFailed = CurrentUser.IsEmpty();

            if (LoginFailed)
            {
                FailedLoginCount++;

                cout << "\nInvalid Username/Password!";
                cout << "\nYou have "
                    << (3 - FailedLoginCount)
                    << " trial(s) to login.\n\n";
            }

            if (FailedLoginCount == 3)
            {
                cout << "\nYou are locked after 3 failed trials.\n\n";
                return false;
            }

        } while (LoginFailed);
        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
        
        return true;
    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();

    }

};
