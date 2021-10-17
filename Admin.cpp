#ifndef ADMIN_CPP
#define ADMIN_CPP

#include "Admin.h"

void Admin::DeleteAccount(string name)
{
    if(remove(name.c_str())==0)
        cout<<"Account successfully deleted" <<endl;
    else
        perror("Error deleting account");
}

void Admin::MonthlyEarners()
{
    cout<<"Top 5 monthly earners"<<endl<<endl;
    TopEarners<MaxElem> te;
    vector<string> vec=te.GetTopFive();
    for(int i=0; i<vec.size(); i++)
        cout<<i+1<<". "<<vec[i]<<endl;
}

void Admin::FinedDrivers()
{
    cout<<"Top 5 most Fined drivers"<<endl<<endl;
    TopFined<MaxElemAg> tf;
    vector<string> vec=tf.GetTopFive();
    for(int i=0; i<vec.size(); i++)
        cout<<i+1<<". "<<vec[i]<<endl;
}

void Admin::LeastRatedDrivers()
{
    cout<<"Top 5 least rated drivers"<<endl<<endl;
    TopRated<MinElem> tr;
    vector<string> vec=tr.GetTopFive();
    for(int i=0; i<vec.size(); i++)
        cout<<i+1<<". "<<vec[i]<<endl;
}

void Admin::viewUserAccount(string userCheck)
{
    DriverInformation di(userCheck);
    di.viewProfile();
}

void Admin::AddMoney(string userName,double val)
{
    User ui(userName);
    ui.addMoney(val);
}

void Admin::SumOfFines(string temp,double val)
{
    DriverInformation di(temp);
    di.setSumOfFine(val);
}

#endif // ADMIN_CPP
