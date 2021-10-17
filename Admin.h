#ifndef ADMIN_H
#define ADMIN_H

#include<bits/stdc++.h>
#include "TopEarners.h"
#include "TopFined.h"
#include "TopRated.h"
#include "DriverInformation.h"
#include "User.h"
using namespace std;

class Admin
{
public:
    void DeleteAccount(string);
    void AddMoney(string,double);
    void SumOfFines(string,double);
    void MonthlyEarners();
    void FinedDrivers();
    void viewUserAccount(string);
    void LeastRatedDrivers();
};

#endif // ADMIN_H

