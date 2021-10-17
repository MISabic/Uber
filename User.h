#ifndef USER_H
#define USER_H

#include<bits/stdc++.h>
#include"Driver.h"
using namespace std;

class User
{
private:
    string name;
    string password;
    double money;
public:
    User(string);
    User(string,string);
    void Rating(double);
    void Payment(double);
    void addMoney(double);
    double getMoney();
    void writeFile();
};

#endif // USER_H

