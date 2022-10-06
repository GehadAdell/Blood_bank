#include "Donor.h"

Rrecipient rec;

void Donor::list_for_donor() {
    cout << "*****************************Services_For_Donor**********************************" << endl
        << "*                            [1]  Donation Request                               *" << endl
        << "*                            [2]  Update her data                                *" << endl
        << "*                            [3]  Delete account                                 *" << endl
        << "*                                                                                *" << endl;
    int choice;
    cout << "Enter Your Choice : "; cin >> choice;
    switch (choice) {
    case 1:
        donationRequestDonor();
        break;
    case 2:
        Update();
        break;
    case 3:
        Delete();
        break;
    default:
        cout << "Your choice is unavailable. Try again.";
    }
}

void Donor::Register() {
    Donorr d;
    cout << "Enter Your ID : "; cin >> d.id;
    cout << "Enter Your Name : "; cin >> d.name;
    cout << "Enter Your Mail : "; cin >> d.mail;
    cout << "Enter Your Password : "; cin >> d.password;
    cout << "Enter Your Age : "; cin >> d.age;
    cout << "Enter Your Gender : "; cin >> d.gender;
    cout << "Enter Your BloodType : "; cin >> d.bloodType;
    cout << "If you suffers from any disease (blood pressure disorders, thyroid disease, diabetes, cancer, heart disorders, hepatitis), Please write it down below if you don't enter no: "; cin >> d.if_have_disease;
    cout << "If you take any medcine, Please write it down below: "; cin >> d.if_take_medcine; // دخل نو لو مش بتاخد علاج
    cout << "Enter the date of your last donation (Day >> Month >> Year) : "; cin >> d.day_last_donation >> d.month_last_donation >> d.year_last_donation;
    vDonor.push_back(d);
    cout << "---------------------------------------------------------------" << endl;
    cout << "-Your Registration has been successfully completed, thank you.- " << endl; ///// من فضلك قم بتسجيل الدخول
    cout << "---------------------------------------------------------------" << endl;
}

int Donor::checkAcc()
{
    string mail, pass;
    cout << "Enter Your Mail : "; cin >> mail;
    cout << "Enter Your Password : "; cin >> pass;
    for (int i = 0; i < vDonor.size(); i++)
    {
        if (vDonor[i].mail == mail)
        {
            if (vDonor[i].password == pass)
            {
                return i;
            }
        }
    }
    return -1;
}

void Donor::Login()
{
    int check = checkAcc();
    if (check != -1)
    {
        cout << "you're logged in successfully " << endl;
        list_for_donor();
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
        cout << "invalid mail\n" << "Do you want back to List of Donor? [y/n]\n" << "Enter Your Choice : ";
        cin >> choice1;
        if (choice1 == 'y')
            list_for_donor();
        else
        {
            cout << "Thank You." << endl;
            WriteFromFileAcc();
            rec.WriteFromFileData();
            exit(1);
        }
    }
}

void Donor::ReadFromFileAcc()
{
    fstream FileDonor;
    FileDonor.open("DonorRegister.txt", ios::in);
    if (!FileDonor) {
        cout << "File doesn’t exist.";
    }
    else {
        int i = 0;
        while (!FileDonor.eof())
        {
            Donorr donorr;
            getline(FileDonor, donorr.id);
            getline(FileDonor, donorr.name);
            getline(FileDonor, donorr.mail);
            getline(FileDonor, donorr.password);
            getline(FileDonor, donorr.age);
            getline(FileDonor, donorr.gender);
            getline(FileDonor, donorr.bloodType);
            getline(FileDonor, donorr.if_have_disease);
            getline(FileDonor, donorr.if_take_medcine);
            getline(FileDonor, donorr.day_last_donation);
            getline(FileDonor, donorr.month_last_donation);
            getline(FileDonor, donorr.year_last_donation);
            vDonor.push_back(donorr);
            i++;
        }
    }
    FileDonor.close();
}

void Donor::WriteFromFileAcc()
{
    fstream FileDonor;
    FileDonor.open("DonorRegister.txt", ios::out);
    if (!FileDonor) { cout << "File doesn’t exist."; }
    else
    {
        int i = 0;
        while (i < vDonor.size())
        {
            if (vDonor[i].name == "")
            {
                i++;
                continue;
            }
            else
            {
                FileDonor << vDonor[i].id << endl;
                FileDonor << vDonor[i].name << endl;
                FileDonor << vDonor[i].mail << endl;
                FileDonor << vDonor[i].password << endl;
                FileDonor << vDonor[i].age << endl;
                FileDonor << vDonor[i].gender << endl;
                FileDonor << vDonor[i].bloodType << endl;
                FileDonor << vDonor[i].if_have_disease << endl;
                FileDonor << vDonor[i].if_take_medcine << endl;
                FileDonor << vDonor[i].day_last_donation << endl;
                FileDonor << vDonor[i].month_last_donation << endl;
                FileDonor << vDonor[i].year_last_donation << endl;
                i++;
            }
        }
        FileDonor.close();
    }
}

void Donor::donationRequestDonor() {
    BloodData blood_data;
    Donorr checkDate;
    char choice;
    int mondon2, daydon2, yeardon2;
    cout << "Enter your blood type : " << endl; cin >> blood_data.Type;
    cout << "How many packets do you want to donor? : " << endl; cin >> blood_data.Quantity;
    cout << "Enter donor's date (day / month / year)" << endl; cin >> blood_data.dayR >> blood_data.monthR >> blood_data.yearR;
    int check = checkAcc();
    if (check != -1)
    {
        if (stoi(vDonor[check].age) < 17 || stoi(vDonor[check].age) > 60)
        {
            cout << "your donation request is rejected " << endl;
            WriteFromFileAcc();
            rec.WriteFromFileData();
            exit(1);
        }
        if (vDonor[check].if_have_disease != "no")
        {
            cout << "your donation request is rejected" << endl;
            WriteFromFileAcc();
            rec.WriteFromFileData();
            exit(1);
        }
        if (vDonor[check].if_take_medcine != "no")
        {
            cout << "your donation request is rejected" << endl;
            WriteFromFileAcc();
            rec.WriteFromFileData();
            exit(1);
        }
        if (stoi(vDonor[check].month_last_donation) <= 9)
        {
            mondon2 = stoi(vDonor[check].month_last_donation) + 3;
            daydon2 = stoi(vDonor[check].day_last_donation);
            yeardon2 = stoi(vDonor[check].year_last_donation);
        }
        else
        {
            int count = 1;
            for (int i = 10; i <= 12; i++)
            {
                if (stoi(vDonor[check].month_last_donation) == i)
                {
                    mondon2 = count;
                    daydon2 = stoi(vDonor[check].day_last_donation);
                    yeardon2 = stoi(vDonor[check].year_last_donation) + 1;
                    break;
                }
                count++;
            }
        }
        if (yeardon2 == stoi(blood_data.yearR))
        {
            if (mondon2 > stoi(blood_data.monthR))
            {
                cout << "your donation request is rejected" << endl;
                WriteFromFileAcc();
                rec.WriteFromFileData();
                exit(1);
            }
        }
        if (yeardon2 > stoi(blood_data.yearR))
        {
            cout << "your donation request is rejected" << endl;
            WriteFromFileAcc();
            rec.WriteFromFileData();
            exit(1);
        }

        /// <summary>
        /// 
        /// </summary>
        if (stoi(blood_data.monthR) <= 9)
        {
            blood_data.monthEX = to_string(stoi(blood_data.monthR) + 3);
            blood_data.dayEX = blood_data.dayR;
            blood_data.yearEX = blood_data.yearR;
        }
        else
        {
            int count = 1;
            for (int i = 10; i <= 12; i++)
            {
                if (stoi(blood_data.monthR) == i)
                {
                    blood_data.monthEX = count;
                    blood_data.dayEX = blood_data.dayR;
                    blood_data.yearEX = to_string(stoi(blood_data.yearR) + 1);
                    break;
                }
                count++;
            }
        }
        rec.bloodD.push_back(blood_data);
        cout << "your request is completed \n" << "do you want back to list for donr? [y/n]\n" << "Enter Your Choice : ";
        cin >> choice;
        if (choice == 'y')
            list_for_donor();
        else
        {
            cout << "Thank You.\n";
            WriteFromFileAcc();
            rec.WriteFromFileData();
            exit(1);
        }
    }
}

void Donor::Delete() {
    int index = checkAcc(); char choice1;
    if (index == -1) { cout << "Sorry Invaild Email !" << endl; }
    else {
        vDonor.erase(vDonor.begin() + index); //Remove element at this index
        cout << "Account is deleted !\n" << "Thank You." << endl;
        WriteFromFileAcc();
        rec.WriteFromFileData();
        exit(1);
    }
    cout << "Do you want back to List of Donor ? [y/n]\n" << "Enter Your Choice : "; cin >> choice1;
    if (choice1 == 'y')
        list_for_donor();
    else
    {
        cout << "Thank You." << endl;
        WriteFromFileAcc();
        rec.WriteFromFileData();
        exit(1);
    }
}

void Donor::Update()
{
    int index = checkAcc();
    char choice1;
    if (index == -1) { cout << "Sorry Invaild Email !" << endl; }
    else {
        int choice;
        string newday, newmonth, newyear;
        {
            cout << "To Update your Name press 1" << endl
                << "To Update your Mail press 2" << endl
                << "To Update your PassWord press 3" << endl
                << "To Update your Gender press 4" << endl
                << "To Update your Age press 5" << endl
                << "To Update your Blood Type press 6" << endl
                << "To Update  Have disease or no press 7" << endl
                << "To Update  Have take medcine or no press 8" << endl
                << "To Update  date_last_donation press 9" << endl
                << "Entre Your choice : "; cin >> choice;
            string newValue;
            string oldPassword;
            int counter = 0;
            switch (choice)
            {
            case 1:
                cout << "Please Enter new Name" << endl;
                cin >> newValue;
                vDonor[index].name = newValue;
                break;
            case 2:
                cout << "Please Enter new Mail" << endl;
                cin >> newValue;
                vDonor[index].mail = newValue;
                break;
            case 3:
                while (counter < 3)
                {
                    cout << "Please Enter old Password" << endl;
                    cin >> oldPassword;
                    if (oldPassword == vDonor[index].password) {
                        cout << "Please Enter new Password" << endl;
                        cin >> newValue;
                        vDonor[index].password = newValue;
                        break;
                    }
                    cout << "Sorry invaild password try again" << endl;
                    counter++;
                }
                break;
            case 4:
                cout << "Please Enter Gender" << endl;
                cin >> newValue;
                vDonor[index].gender = newValue;
                break;
            case 5:
                cout << "Please Enter Age" << endl;
                cin >> newValue;
                vDonor[index].age = newValue;
                break;
            case 6:
                cout << "Please Enter blood type" << endl;
                cin >> newValue;
                vDonor[index].bloodType = newValue;
                break;
            case 7:
                cout << "Please Enter if you have disease" << endl;
                cin >> newValue;
                vDonor[index].if_have_disease = newValue;
                break;
            case 8:
                cout << "Please Enter if tyou take medcine" << endl;
                cin >> newValue;
                vDonor[index].if_take_medcine = newValue;
                break;
            case 9:
                cout << "Please Enter date of last donation (Day >> Month >> Year) : " << endl; cin >> newday >> newmonth >> newyear;
                vDonor[index].day_last_donation = newday;
                vDonor[index].month_last_donation = newmonth;
                vDonor[index].year_last_donation = newyear;
                break;
            default:
                cout << "Sorry invaild option " << endl;
                break;
            }
        }
        cout << "Your Update has finished\n" << "Do you want back to List of Donor? [y/n]\n" << "Enter Your Choice : "; cin >> choice1;
        if (choice1 == 'y')
            list_for_donor();
        else
        {
            cout << "Thank You." << endl;
            WriteFromFileAcc();
            rec.WriteFromFileData();
            exit(1);
        }
    }
}