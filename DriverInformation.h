#ifndef DRIVERINFORMATION_H
#define DRIVERINFORMATION_H

#include <bits/stdc++.h>

using namespace std;

class DriverInformation
{
private:
    string name;
    string password;
    string phone;
    double farePerKm;
    double totalKmDriven;
    string carType;
    string carNumber;
    int numberOfPassCarSup;
    string currentLocation;
    int timesFined;
    double sumOfFine;
    double rating;
    int numberOfClientServed;
    double totalIncome;
    double totalIncomeThisMonth;

public:
    DriverInformation(string);
    DriverInformation(string,string,string,double,string,string,string,int);

    void setPassword(string);
    void setPhone(string);
    void setFarePerKm(double);
    void setCarType(string);
    void setCarNumber(string);
    void setNumberOfPassCarSup(int);
    void setLocation(string);
    void setTotalIncome(double);
    void setSumOfFine(double);
    void setRating(double);
    void setTotalKmDriven(double);
    double getFarePerKm();
    string getLocation();
    void writeFile();
    void viewProfile();
    void viewProfileForUser();
};

#endif // DRIVERINFORMATION_H

