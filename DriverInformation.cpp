#ifndef DRIVERINFORMATION_CPP
#define DRIVERINFORMATION_CPP

#include "DriverInformation.h"

DriverInformation::DriverInformation(string username)
{
    system("cls");
    ifstream in(("Driver/"+username+".txt").c_str());
    if(in.is_open()){
        in>>name>>password>>phone>>farePerKm>>totalKmDriven>>carType>>carNumber>>numberOfPassCarSup>>currentLocation>>timesFined>>sumOfFine>>totalIncomeThisMonth>>totalIncome>>numberOfClientServed>>rating;
    }
    else{
        cout<<"Something Went Wrong"<<endl;
    }
    in.close();
}

DriverInformation::DriverInformation(string name,string password,string phone,double farePerKm,string carType,string carNumber,string currentLocation,int noOfPassCarSup)
{
    ofstream out(("Driver/"+name+".txt").c_str());
    ofstream out1("MonthlyEarners.txt",ios::app);
    ofstream out2("Drivers.txt",ios::app);
    ofstream out3("FinedDrivers.txt",ios::app);
    ofstream out4("RatedDrivers.txt",ios::app);
    out<<name<<'\n';
    out<<password<<'\n';
    out<<phone<<'\n';
    out<<farePerKm<<'\n';
    out<<0.0<<'\n';
    out<<carType<<'\n';
    out<<carNumber<<'\n';
    out<<noOfPassCarSup<<'\n';
    out<<currentLocation<<'\n';
    out<<0<<'\n';
    out<<0<<'\n';
    out<<0<<'\n';
    out<<0<<'\n';
    out<<0<<'\n';
    out<<"Not Rated Yet"<<'\n';
    out1<<name<<" "<<0<<'\n';
    out2<<name<<" "<<currentLocation<<'\n';
    out3<<name<<" "<<0<<'\n';
    out4<<name<<" "<<0<<'\n';
    out.close();
    out1.close();
    out2.close();
    out3.close();
    out4.close();
}

void DriverInformation::writeFile()
{
    ofstream filestr(("Driver/"+name+".txt").c_str());
    if(filestr.is_open()){
        filestr<<name<<'\n'<<password<<'\n'<<phone<<'\n'<<farePerKm<<'\n'<<totalKmDriven<<'\n'<<carType<<'\n'<<carNumber<<'\n'<<numberOfPassCarSup<<'\n'<<currentLocation<<'\n'<<timesFined<<'\n'<<sumOfFine<<'\n'<<totalIncomeThisMonth<<'\n'<<totalIncome<<'\n'<<numberOfClientServed<<'\n'<<rating;
    }
    else{
        cout<<"Something Went Wrong"<<endl;
    }
    filestr.close();
}

void DriverInformation::setPassword(string password)
{
    this->password=password;
    writeFile();
}

void DriverInformation::setPhone(string phone)
{
    this->phone=phone;
    writeFile();
}

void DriverInformation::setFarePerKm(double farePerKm)
{
    this->farePerKm=farePerKm;
    writeFile();
}

void DriverInformation::setCarType(string carType)
{
    this->carType=carType;
    writeFile();
}

void DriverInformation::setCarNumber(string carNumber)
{
    this->carNumber=carNumber;
    writeFile();
}

void DriverInformation::setNumberOfPassCarSup(int numberOfPassCarSup)
{
    this->numberOfPassCarSup=numberOfPassCarSup;
    writeFile();
}

void inputNewLocation(string username,string location)
{
    string str;
    string val;
    ifstream file1("Drivers.txt");
    vector< pair<string,string> >vec;
    while(file1>>str>>val){
        if(str==username)
            vec.push_back(make_pair(username,location));
        else
            vec.push_back(make_pair(str,val));
    }
    file1.close();
    ofstream out("Drivers.txt");
    for(int i=0; i<vec.size(); i++){
        out<<vec[i].first<<" "<<vec[i].second<<'\n';
    }
    out.close();
}

void DriverInformation::setLocation(string location)
{
    currentLocation=location;
    writeFile();
    inputNewLocation(name,location);
}

void inputMonthlyEarners(string username,double income)
{
    string str;
    double val;
    ifstream file1("MonthlyEarners.txt");
    vector< pair<string,double> >vec;
    while(file1>>str>>val){
        if(str==username)
            vec.push_back(make_pair(username,income));
        else
            vec.push_back(make_pair(str,val));
    }
    file1.close();
    ofstream out("MonthlyEarners.txt");
    for(int i=0; i<vec.size(); i++){
        //cout<<vec[i].first<<" "<<vec[i].second<<'\n';
        out<<vec[i].first<<" "<<vec[i].second<<'\n';
    }
    out.close();
}

void DriverInformation::setTotalIncome(double income)
{
    ++numberOfClientServed;
    totalIncomeThisMonth+=income;
    totalIncome+=income;
    writeFile();
    inputMonthlyEarners(name,totalIncome);
}

void inputFinedDrivers(string username,int fine)
{
    string str;
    int val;
    ifstream file2("FinedDrivers.txt");
    vector< pair<string,double> >vec;
    while(file2>>str>>val){ //cout<<str<<"   "<<val<<endl;
        if(str==username)
            vec.push_back(make_pair(username,fine));
        else
            vec.push_back(make_pair(str,val));
    }
    file2.close();
    ofstream out("FinedDrivers.txt");
    for(int i=0; i<vec.size(); i++){    //cout<<vec[i].first<<"   "<<vec[i].second<<endl;
        out<<vec[i].first<<" "<<vec[i].second<<'\n';
    }
    out.close();
}

void DriverInformation::setSumOfFine(double sumFine)
{
    sumOfFine+=sumFine;
    timesFined++;
    writeFile();
    inputFinedDrivers(name,timesFined);
}

void inputRatedDrivers(string username,double rating)
{
    string str;
    double val;
    ifstream file3("RatedDrivers.txt");
    vector< pair<string,double> >vec;
    while(file3>>str>>val){
        if(str==username)
            vec.push_back(make_pair(username,rating));
        else
            vec.push_back(make_pair(str,val));
    }
    file3.close();
    ofstream out("RatedDrivers.txt");
    for(int i=0; i<vec.size(); i++){
        out<<vec[i].first<<" "<<vec[i].second<<'\n';
    }
    out.close();
}

void DriverInformation::setRating(double rate)
{
    rating=(rating+rate)/numberOfClientServed;
    writeFile();
    inputRatedDrivers(name,rating);
}

void DriverInformation::setTotalKmDriven(double km)
{
    totalKmDriven+=km;
    writeFile();
}

double DriverInformation::getFarePerKm()
{
    return farePerKm;
}

string DriverInformation::getLocation()
{
    return currentLocation;
}

void DriverInformation::viewProfile()
{
    cout<<"Name                         ::  "<<name<<endl;
    cout<<"Password                     ::  "<<password<<endl;
    cout<<"Phone                        ::  "<<phone<<endl;
    cout<<"Fare/Kilometer               ::  "<<farePerKm<<endl;
    cout<<"Total km driven(This month)  ::  "<<totalKmDriven<<endl;
    cout<<"Car Type                     ::  "<<carType<<endl;
    cout<<"Car Number                   ::  "<<carNumber<<endl;
    cout<<"Passengers Car Supports      ::  "<<numberOfPassCarSup<<endl;
    cout<<"Location                     ::  "<<currentLocation<<endl;
    cout<<"Number of times Fined        ::  "<<timesFined<<endl;
    cout<<"Sum of Fines                 ::  "<<sumOfFine<<endl;
    cout<<"Total Income(This month)     ::  "<<totalIncomeThisMonth<<endl;
    cout<<"Total Income                 ::  "<<totalIncome<<endl;
    cout<<"Number of clients served     ::  "<<numberOfClientServed<<endl;
    cout<<"Rating                       ::  "<<rating<<endl;
}

void DriverInformation::viewProfileForUser()
{
    cout<<"Name                         ::  "<<name<<endl;
    cout<<"Phone                        ::  "<<phone<<endl;
    cout<<"Fare/Kilometer               ::  "<<farePerKm<<endl;
    cout<<"Car Type                     ::  "<<carType<<endl;
    cout<<"Car Number                   ::  "<<carNumber<<endl;
    cout<<"Passengers Car Supports      ::  "<<numberOfPassCarSup<<endl;
    cout<<"Location                     ::  "<<currentLocation<<endl;
    cout<<"Number of times Fined        ::  "<<timesFined<<endl;
    cout<<"Sum of Fines                 ::  "<<sumOfFine<<endl;
    cout<<"Number of clients served     ::  "<<numberOfClientServed<<endl;
    cout<<"Rating                       ::  "<<rating<<endl;
}

#endif // DRIVERINFORMATION_CPP
