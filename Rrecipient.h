#pragma once
#include "Donor.h"
#include "person.h"
#include <map>;

struct Recipient {
    string id;
    string name;
    string mail;
    string password;
    string age;
    string gender;
    string bloodType;
    string hospital;
    string drOfTheCase;
};
struct BloodData {
    string Type;
    string Quantity;
    string dayR;
    string monthR;
    string yearR;
    string dayEX;
    string monthEX;
    string yearEX;
};

class Rrecipient : public person
{
private :
    vector<Recipient>vRegister;
    map<string, int>quantitymp{};
public:
    vector<BloodData>bloodD;
	void list_for_recipient();
	bool searchAvailabilityOfBloodType(string bloodtype, int quantity);
	void bloodQuantity();
	void displayAllbloodData();
	void Request();
    void Update();
    void Delete();
    int checkAcc();
    void Register();
    void Login();
    void ReadFromFileAcc();
    void ReadFromFileData();
    void WriteFromFileAcc();
    void WriteFromFileData();
};
 
