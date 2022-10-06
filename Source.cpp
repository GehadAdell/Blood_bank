#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include "Donor.h"
#include "Rrecipient.h"
using namespace std;

void Main_Menu();

int main() {
    Main_Menu();
    return 0;
}
void Main_Menu()
{
    int choice;
    Rrecipient res; Donor don;
    system("color 0B");
    cout << "****************************** Main menu *****************************\n"
        << "*                              [1] If You Donor                       *\n"
        << "*                              [2] If You Recipient                   *\n"
        << "*                              [3] Exit                               *\n"
        << "***********************************************************************\n"
        << "Enter Your Choice : "; cin >> choice;
    if (choice == 1)
    {
        res.ReadFromFileData();
        don.ReadFromFileAcc();
        cout << "*                            [1]  Register                                       *" << endl
            << "*                            [2]  Login                                          *" << endl;
        cout << "Enter Your Choice : "; cin >> choice;
        if (choice == 1)
        {
            don.Register();
            don.Login();
        }
        else if (choice == 2)
            don.Login();
    }
    else if (choice == 2)
    {
        res.ReadFromFileData();
        res.ReadFromFileAcc();
        cout << "*                            [1]  Register                                       *" << endl
            << "*                            [2]  Login                                          *" << endl;
        cout << "Enter Your Choice : "; cin >> choice;
        if (choice == 1)
        {
            res.Register();
            res.Login();
        }
        else if (choice == 2)
            res.Login();
    }
    else if (choice == 3)
    {
        res.WriteFromFileData();
        res.WriteFromFileData();
        res.WriteFromFileAcc();
        exit(1);
    }
}