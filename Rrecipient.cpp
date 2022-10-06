#include "Rrecipient.h"
using namespace std;

void Rrecipient::list_for_recipient()
{
    cout << "*****************************Services_For_Recipient*******************************" << endl
        << "*                            [1]  Update her data                                *" << endl
        << "*                            [2]  Delete account                                 *" << endl
        << "*                            [3]  Search for the availability of blood type      *" << endl
        << "*                            [4]  Display all blood data                         *" << endl
        << "*                            [5]  Request the blood type and quantity            *" << endl;
    int choice;
    cout << "Enter Your Choice : "; cin >> choice;
    if (choice == 1)
        Update();
    else if (choice == 2)
        Delete();
    else if (choice == 3)
    {
        string bloodtype;
        int quantity;
        cout << "Enter The Blood Type You Want To Search For (A+ / O+ / B+ / AB+ / A- / B- / O- / AB-) : "; cin >> bloodtype;
        cout << "Enter The Amount Of Blood You Want To Search For : "; cin >> quantity;
        searchAvailabilityOfBloodType(bloodtype, quantity);
    }
    else if (choice == 4)
        displayAllbloodData();
    else if (choice == 5)
    {
        Request();
        WriteFromFileData();
    }
}

int Rrecipient:: checkAcc()
{
    string mail, pass;
    cout << "Enter Your Mail : "; cin >> mail;
    cout << "Enter Your Password : "; cin >> pass;
    for (int i = 0; i < vRegister.size(); i++)
    {
        if (vRegister[i].mail == mail)
        {
            if (vRegister[i].password == pass)
            {
                return i;
            }
        }
    }
    return -1;
}

void Rrecipient::Login()
{
    int check = checkAcc();
    if (check != -1)
    {
        cout << "you're logged in successfully \n";
        list_for_recipient();
    }
    else
    {
        int i = 0; char choice1;
        while (check == -1)
        {
            if (i == 3)
                break;
            cout << "invalid mail Try again please\n";
            i++;
            Login();
        }
        cout << "invalid mail\n" << "Do you want back to List of Recipient? [y/n]\n" << "Enter Your Choice : "; 
        cin >> choice1;
        if (choice1 == 'y')
            list_for_recipient();
        else
        {
            cout << "Thank You." << endl;
            WriteFromFileAcc();
            WriteFromFileData();
            exit(1);
        }
    }
}

void Rrecipient::  Update()
{
    int index = checkAcc();
    if (index == -1) { cout << "Sorry Invaild Email !" << endl; }
    else {
        int choice;
        char choice1;
        {
            cout << "To Update your Name press 1" << endl
                << "To Update your Mail press 2" << endl
                << "To Update your PassWord press 3" << endl
                << "To Update your Gender press 4" << endl
                << "To Update your Age press 5" << endl
                << "To Update your Blood Type press 6" << endl
                << "To Update Hospital press 7" << endl
                << "To Update your Doctor of Case press 8" << endl
                << "Entre Your choice : "; cin >> choice;
            string newValue;
            string oldPassword;
            int counter = 0;
            switch (choice)
            {
            case 1:
                cout << "Please Enter new Name" << endl;
                cin >> newValue;
                vRegister[index].name = newValue;
                break;
            case 2:
                cout << "Please Enter new Mail" << endl;
                cin >> newValue;
                vRegister[index].mail = newValue;
                break;
            case 3:
                while (counter < 3)
                {
                    cout << "Please Enter old Password" << endl;
                    cin >> oldPassword;
                    if (oldPassword == vRegister[index].password) {
                        cout << "Please Enter new Password" << endl;
                        cin >> newValue;
                        vRegister[index].password = newValue;
                        break;
                    }
                    cout << "Sorry invaild password try again" << endl;
                    counter++;
                }
                break;
            case 4:
                cout << "Please Enter Gender" << endl;
                cin >> newValue;
                vRegister[index].gender = newValue;
                break;
            case 5:
                cout << "Please Enter Age" << endl;
                cin >> newValue;
                vRegister[index].age = newValue;
                break;
            case 6:
                cout << "Please Enter blood type" << endl;
                cin >> newValue;
                vRegister[index].bloodType = newValue;
                break;
            case 7:
                cout << "Please Enter Hospital name" << endl;
                cin >> newValue;
                vRegister[index].hospital = newValue;
                break;
            case 8:
                cout << "Please Enter Doctor Name" << endl;
                cin >> newValue;
                vRegister[index].drOfTheCase = newValue;
                break;
            default:
                cout << "Sorry invaild option " << endl;
                break;
            }
        }
        cout << "Your Update has finished\n" << "Do you want back to List of Recipient? [y/n]\n" << "Enter Your Choice : "; cin >> choice1;
        if (choice1 == 'y')
            list_for_recipient();
        else
        {
            cout << "Thank You." << endl;
            WriteFromFileAcc();
            WriteFromFileData();
            exit(1);
        }
    }
}

void Rrecipient:: Delete()
{
    int index = checkAcc(), choice1;
    if (index == -1) { cout << "Sorry Invaild Email !" << endl; }
    else {
        vRegister.erase(vRegister.begin() + index); //Remove element at this index
        cout << "Account is deleted !\n" << "Thank You." << endl;
        WriteFromFileAcc();
        WriteFromFileData();
        exit(1);
    }
    cout << "Do you want back to List of Recipient? [y/n]\n" << "Enter Your Choice : "; cin >> choice1;
    if (choice1 == 'y')
        list_for_recipient();
    else
    {
        cout << "Thank You." << endl;
        WriteFromFileAcc();
        WriteFromFileData();
        exit(1);
    }
}

void Rrecipient:: WriteFromFileAcc()
{
    fstream FileRecipient;
    FileRecipient.open("RecipientRegister.txt", ios::out);
    if (!FileRecipient) { cout << "File doesn’t exist."; }
    else
    {
        int i = 0;
        while (i < vRegister.size())
        {
            if (vRegister[i].hospital == "")
            {
                i++;
                continue;
            }
            else
            {
                FileRecipient << vRegister[i].id << endl;
                FileRecipient << vRegister[i].name << endl;
                FileRecipient << vRegister[i].mail << endl;
                FileRecipient << vRegister[i].password << endl;
                FileRecipient << vRegister[i].age << endl;
                FileRecipient << vRegister[i].gender << endl;
                FileRecipient << vRegister[i].bloodType << endl;
                FileRecipient << vRegister[i].hospital << endl;
                FileRecipient << vRegister[i].drOfTheCase << endl;
                i++;
            }
        }
        FileRecipient.close();
    }
}

void Rrecipient:: WriteFromFileData()
{
    ofstream Bread;
    Bread.open("BloodData.txt");
    if (!Bread) {cout << "File doesn’t exist.";}
    else {
        int i = 0;
        while (i < bloodD.size())
        {
            if (bloodD[i].Type == "")
            {
                i++;
                continue;
            }
            Bread << bloodD[i].Type << endl;
            Bread << bloodD[i].Quantity << endl;
            Bread << bloodD[i].dayR << endl;
            Bread << bloodD[i].monthR << endl;
            Bread << bloodD[i].yearR << endl;
            Bread << bloodD[i].dayEX << endl;
            Bread << bloodD[i].monthEX << endl;
            Bread << bloodD[i].yearEX << endl;
            i++;
        }
        Bread.close();
    }
}

void Rrecipient::ReadFromFileAcc()
{
    fstream FileRecipient;
    FileRecipient.open("RecipientRegister.txt", ios::in);
    if (!FileRecipient) { cout << "File doesn’t exist."; }
    else {
        int i = 0;
        while (!FileRecipient.eof())
        {
            Recipient recipientt;
            getline(FileRecipient, recipientt.id);
            getline(FileRecipient, recipientt.name);
            getline(FileRecipient, recipientt.mail);
            getline(FileRecipient, recipientt.password);
            getline(FileRecipient, recipientt.age);
            getline(FileRecipient, recipientt.gender);
            getline(FileRecipient, recipientt.bloodType);
            getline(FileRecipient, recipientt.hospital);
            getline(FileRecipient, recipientt.drOfTheCase);
            vRegister.push_back(recipientt);
            i++;
        }
    }
    FileRecipient.close();
}

void Rrecipient::ReadFromFileData()
{
    ifstream Bread;
    Bread.open("BloodData.txt");
    if (!Bread) {
        cout << "File doesn’t exist.";
    }
    else {
        int i = 0;
        while (!Bread.eof())
        {
            BloodData blood;
            getline(Bread, blood.Type);
            getline(Bread, blood.Quantity);
            getline(Bread, blood.dayR);
            getline(Bread, blood.monthR);
            getline(Bread, blood.yearR);
            getline(Bread, blood.dayEX);
            getline(Bread, blood.monthEX);
            getline(Bread, blood.yearEX);
            bloodD.push_back(blood);
            i++;
        }
    }
    Bread.close();
}

void Rrecipient::Register()
{
    Recipient r;
    cout << "Enter Your ID : "; cin >> r.id;
    cout << "Enter Your Name : "; cin >> r.name;
    cout << "Enter Your Mail : "; cin >> r.mail;
    cout << "Enter Your Password : "; cin >> r.password;
    cout << "Enter Your Age : "; cin >> r.age;
    cout << "Enter Your Gender : "; cin >> r.gender;
    cout << "Enter Your BloodType (A+ / O+ / B+ / AB+ / A- / B- / O- / AB-) : "; cin >> r.bloodType;
    cout << "Enter Your Hospital : "; cin >> r.hospital;
    cout << "Enter Your DrOfTheCase : "; cin >> r.drOfTheCase;
    vRegister.push_back(r);
    cout << "---------------------------------------------------------------" << endl;
    cout << "-Your Registration has been successfully completed, thank you- " << endl; /////////
    cout << "---------------------------------------------------------------" << endl;
}

bool Rrecipient::searchAvailabilityOfBloodType(string bloodtype, int quantity)
{
    bloodQuantity();
    char choice;
    if (quantitymp[bloodtype] >= quantity)
    {
        cout << " your blood type quantity is Avaliable.\n";
        WriteFromFileAcc();
        WriteFromFileData();
        return true;
    }
    else
        cout << "Blood Type quantity is Unavaliable.\n";
    cout << "Do You Want to go Back To List For Recipient? [y/n] \n"
        << "Enter Your Choice : "; cin >> choice;
    if (choice == 'y')
        list_for_recipient();
    else
    {
        cout << "Thank You.\n";
        WriteFromFileAcc();
        WriteFromFileData();
        return false;
    }
} 

void Rrecipient::bloodQuantity()
{
    int day, year, month;
    cout << "Enter today's date (day / month / year)" << endl; cin >> day >> month >> year;
    for (int i = 0; i < bloodD.size(); i++)
    {
        if (bloodD[i].yearEX == to_string(year))
        {
            if (bloodD[i].monthEX < to_string(month))
                bloodD.erase(bloodD.begin()+ i);
        }
        else if (bloodD[i].yearEX > to_string(year))
        {
            bloodD.erase(bloodD.begin() + i);
        }
    }
    for (int i = 0; i < bloodD.size(); i++) {
        if (bloodD[i].Type == "")
        {
            i++;
            continue;
        }
        else
        {
            quantitymp[bloodD[i].Type] += stoi(bloodD[i].Quantity);
        }
    }
} 

void Rrecipient::displayAllbloodData()
{
    for (int i = 0; i < bloodD.size(); i++) {
        if (bloodD[i].Type == "")
        {
            i++;
            continue;
        }
        else
        {
            cout << "The blood type is " << bloodD[i].Type << endl;
            cout << "Quantity of type " << bloodD[i].Type << " is " << bloodD[i].Quantity << " packet" << endl;
            cout << "the Received date is : " << bloodD[i].dayR << " / " << bloodD[i].monthR << " / " << bloodD[i].yearR << endl;
            cout << "the Expiry date is : " << bloodD[i].dayEX << " / " << bloodD[i].monthEX << " / " << bloodD[i].yearEX << endl;
        }
    }
    char choice;
    cout << "Do You Want to go Back To List For Recipient? [y/n] \n"
        << "Enter Your Choice : "; cin >> choice;
    if (choice == 'y')
        list_for_recipient();
    else
    {
        cout << "Thank You.\n";
        WriteFromFileAcc();
        WriteFromFileData();
        exit(1);
    }
}

void Rrecipient::Request()
{
    string bloodtype;
    int quantity;
    cout << "Enter The Blood Type You Want To request (A+ / O+ / B+ / AB+ / A- / B- / O- / AB-) : "; cin >> bloodtype;
        cout << "Enter The Amount Of Blood You Want To request : "; cin >> quantity;
    bool flag = searchAvailabilityOfBloodType(bloodtype, quantity);
    if (flag)
    {
        quantitymp[bloodtype] -= quantity;
        int i = 0;
        while (quantity != 0)
        {
            if (bloodD[i].Type == bloodtype)
            {
                if (stoi(bloodD[i].Quantity) < quantity && stoi(bloodD[i].Quantity) != 0)
                { // A+ 3                 5
                    quantity -= stoi(bloodD[i].Quantity);
                    bloodD[i].Quantity = '0';
                }
                else
                {
                    bloodD[i].Quantity = to_string(stoi(bloodD[i].Quantity) - quantity);
                    quantity = 0;
                }
            }
            i++;
        }
    }
    else
    {
        cout << " Sorry but we don't have that quantity" << endl;
        cout << "Do you want to make another one ?" << endl;
        cout << "0 for NO & 1 for YES" << endl;
        int N_request;
        cin >> N_request;
        if (N_request == 1) {
            Request();
        }
        else {
            cout << "your request is Rejected " << endl;
            list_for_recipient();
        }
    }
}
