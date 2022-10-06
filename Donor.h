#pragma once
#include "Rrecipient.h"
#include "person.h"

struct Donorr {
    string id;
    string name;
    string mail;
    string password;
    string age;
    string gender;
    string bloodType;
    string if_have_disease;
    string if_take_medcine;
    string day_last_donation;
    string month_last_donation;
    string year_last_donation;
};

class Donor : public  person 
{
private :
    vector<Donorr>vDonor;
public :
    void list_for_donor();
    void Register();
    void Login();
    void donationRequestDonor();
    void Update();
    void Delete();
    int checkAcc();
    void ReadFromFileAcc();
    void WriteFromFileAcc();
};