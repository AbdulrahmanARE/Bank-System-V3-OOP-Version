#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>

class clsTransferLogScreen :protected clsScreen
{
    private:
        static void _PrintTransferRegisterRecordLine(clsBankClient::stTransferLogRecord TransferRegisterRecord)
        {

            cout << left << setw(8) << ""
                 << "| " << left << setw(22) << TransferRegisterRecord.DateTime;
            cout << "| " << left << setw(8)  << TransferRegisterRecord.SourceAccNum;
            cout << "| " << left << setw(8)  << TransferRegisterRecord.DestinationAccNum;
            cout << "| " << left << setw(8)  << TransferRegisterRecord.Amount;
            cout << "| " << left << setw(10) << TransferRegisterRecord.SourceBalance;
            cout << "| " << left << setw(10) << TransferRegisterRecord.DestinationBalance;
            cout << "| " << left << setw(8)  << TransferRegisterRecord.UserName;

        }

    public:

        static void ShowTransferRegisterList()
        {
            if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
            {
                return;
            }
            vector <clsBankClient::stTransferLogRecord> vTransferLogRecord = clsBankClient::GetTransferLogList();

            string Title = "\t  Transfer Log  List Screen";
            string SubTitle = "\t    (" + to_string(vTransferLogRecord.size()) + ") Record(s).";

            _DrawScreenHeader(Title, SubTitle);

            cout << left << setw(8) << "" << "\n\t_______________________________________________________";
            cout << "______________________________________________\n" << endl;

            cout << left << setw(8) << ""
                << "| " << left << setw(22) << "Date/Time";
            cout << "| " << left << setw(8) << "S.Acct";
            cout << "| " << left << setw(8) << "D.Acct";
            cout << "| " << left << setw(8) << "Amount";
            cout << "| " << left << setw(10) << "S.Balance";
            cout << "| " << left << setw(10) << "D.Balance";
            cout << "| " << left << setw(8) << "UserName";
            cout << left << setw(8) << "" << "\n\t_______________________________________________________";
            cout << "______________________________________________\n" << endl;

            if (vTransferLogRecord.size() == 0)
                cout << "\t\t\t\tNo Transfers Available In the System!";
            else

                for (clsBankClient::stTransferLogRecord TransferRegisterRecord : vTransferLogRecord)
                {

                    _PrintTransferRegisterRecordLine(TransferRegisterRecord);
                    cout << endl;
                }

            cout << left << setw(8) << "" << "\n\t_______________________________________________________";
            cout << "______________________________________________\n" << endl;
        }

    };
