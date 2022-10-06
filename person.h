#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
 class person
{
public:
     virtual void Update()=0;
     virtual void Delete()=0;
     virtual int checkAcc()=0;
     virtual void Register() = 0;
     virtual void Login() = 0;
     virtual void ReadFromFileAcc() = 0;
     virtual void WriteFromFileAcc() = 0;
};


