#ifndef USER_CPP
#define USER_CPP

#include"User.h"
using namespace std;

void User::writeFile()
{
    ofstream filestr(("User/"+name+".txt").c_str());
    if(filestr.is_open()){
        filestr<<name<<'\n'<<password<<'\n'<<money;
    }
    else{
        cout<<"Something Went Wrong"<<endl;
    }
    filestr.close();
}

User::User(string name,string password)
{
    ofstream filestr(("User/"+name+".txt").c_str());
    if(filestr.is_open()){
        filestr<<name<<'\n'<<password<<'\n'<<0;
    }
    else{
        cout<<"Something Went Wrong"<<endl;
    }
    filestr.close();
}

User::User(string name)
{
    ifstream in(("User/"+name+".txt").c_str());
    if(in.is_open()){
        in>>this->name>>password>>money;
    }
    else{
        cout<<"Something Went Wrong"<<endl;
    }
    in.close();
}

double User::getMoney()
{
    return money;
}

void User::addMoney(double money)
{
    this->money+=money;
    writeFile();
}

void User::Payment(double money)
{
    this->money-=money;
    writeFile();
}

#endif // USER_H


