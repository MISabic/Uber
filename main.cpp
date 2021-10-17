#include <bits/stdc++.h>
#include "DriverInformation.h"
#include "Driver.h"
#include "User.h"
#include "Admin.h"
#include "Map.h"
using namespace std;

void intro();
void run();
bool checkAccount(string username,string password,ifstream &in);
void takeAdminInput(string username,string password);
void takeUserInput(string username,string password);
void takeDriverInput(string username,string password,int check);
void updateProfileDriver(DriverInformation &di);
void openpage(string username,string passenger,string location);

int main()
{
    intro();
    return 0;
}

void intro()
{
    cout<<endl<<endl<<endl<<endl;
    cout<<"         +--------------+"<<endl;
    cout<<"         +              +"<<endl;
    cout<<"         +     UBER     +"<<endl;
    cout<<"         +              +"<<endl;
    cout<<"         +--------------+"<<endl;
    cout<<"               ";

    time_t t = time(NULL);
    struct tm localt = *localtime(&t);
    int sec=(localt.tm_sec+4)%60,temp=localt.tm_sec;
    while(localt.tm_sec!=sec){
        time_t t = time(NULL);
        localt = *localtime(&t);    //cout<<temp<<"   "<<sec<<endl;
        if(temp!=localt.tm_sec && temp!=sec)
            cout<<".";
        temp=localt.tm_sec;
    }
    run();
}

void takeAdminInput(string username,string password)
{
    system("cls");
    cout<<"--------Admin Panel---------"<<endl;
    ifstream in(("FirstTimeTest/"+username+".txt").c_str());
    Admin adm;
    int option;
    E:
    cout<<"1. Top 5 monthly earners"<<endl;
    cout<<"2. Top 5 most fined drivers"<<endl;
    cout<<"3. Top 5 least rated drivers"<<endl;
    cout<<"4. Add money in user account"<<endl;
    cout<<"5. Add fine"<<endl;
    cout<<"6. View driver profile"<<endl;
    cout<<"7. Delete account"<<endl;
    cout<<"8. Log Out"<<endl<<endl;
    cout<<endl<<"Select An Option  ::  ";
    cin>>option;
    if(option==1){
        system("cls");
        adm.MonthlyEarners();
        cout<<endl;
        goto E;
    }
    else if(option==2){
        system("cls");
        adm.FinedDrivers();
        cout<<endl;
        goto E;
    }
    else if(option==3){
        system("cls");
        adm.LeastRatedDrivers();
        cout<<endl;
        goto E;
    }
    else if(option==4){
        system("cls");
        H:
        string temp;
        double val;
        cout<<"Type the user name  ::  ";
        cin>>temp;
        ifstream in(("User/"+temp+".txt").c_str());
        if(!in.is_open()){
            system("cls");
            cout<<"Such user does not exist"<<endl;
            goto H;
        }
        cout<<"Enter ammount       ::  ";
        cin>>val;
        adm.AddMoney(temp,val);
        cout<<"User information has been updated"<<endl<<endl;
        in.close();
        goto E;
    }
    else if(option==5){
        system("cls");
        I:
        string temp;
        double val;
        cout<<"Type the driver name  ::  ";
        cin>>temp;
        ifstream in(("Driver/"+temp+".txt").c_str());
        if(!in.is_open()){
            system("cls");
            cout<<"Such driver does not exist"<<endl;
            goto I;
        }
        cout<<"Amount of fine        ::  ";
        cin>>val;
        adm.SumOfFines(temp,val);
        cout<<"Driver information has been updated"<<endl<<endl;
        in.close();
        goto E;
    }
    else if(option==6){
        string toCheckUser;
        cout<<endl<<"Username of the account :: ";
        cin>>toCheckUser;
        ifstream checkIn(("Driver/"+toCheckUser+".txt").c_str());
        if(!checkIn.is_open()){
            system("cls");
            cout<<"Such driver does not exist"<<endl<<endl;
            goto E;
        }
        adm.DeleteAccount("Driver/"+toCheckUser+".txt");
        system("cls");
        adm.viewUserAccount(toCheckUser);
        checkIn.close();
        cout<<endl;
        goto E;
    }
    else if(option==7){
        string toDeleteUser,toDeleteType;
        cout<<"Username of the account :: ";
        cin>>toDeleteUser;
        cout<<"Type of account(D/H)    :: ";
        cin>>toDeleteType;
        adm.DeleteAccount(toDeleteUser+"/"+toDeleteType+".txt");
        system("cls");
        cout<<"Account has been successfully deleted"<<endl;
        goto E;
    }
    else if(option==8){
        exit(0);
    }
    else{
        cout<<"Unrecognized Command"<<endl;
        goto E;
    }
}

void takeUserInput(string username,string password)
{
    cout<<"Welcome Back "<<username<<endl;
    ifstream in(("DriverAvailable/rating"+username+".txt").c_str());
    D:
    if(in.is_open()){
        string str;
        double k;
        in>>str;
        cout<<"Rate the driver(1 to 5)  ::  "<<endl;
        cin>>k;
        if(k<1 || k>5){
            system("cls");
            cout<<"Please give any rating in between 1 to 5"<<endl;
            goto D;
        }
        DriverInformation di(str);
        di.setRating(k);
        in.close();
        remove(("DriverAvailable/rating"+username+".txt").c_str());
        goto D;
    }
    else{
        int optionNumber;
        system("cls");
        E:
        User ui(username);
        cout<<"You have "<<ui.getMoney()<<" taka in your account"<<endl<<endl;
        string dest,loc;
        cout<<"Find Car -->>--"<<endl<<endl;
        cout<<"Location     ::  ";
        cin>>loc;
        cout<<"Destination  ::  ";
        cin>>dest;
        Map mapFind;
        if(mapFind.checkLocation(loc)==0){
            system("cls");
            cout<<loc<<" does not exist"<<endl;
            goto E;
        }
        if(mapFind.checkLocation(dest)==0){
            system("cls");
            cout<<dest<<" does not exist"<<endl;
            goto E;
        }
        vector<string>vec;
        mapFind.GetDrivers(loc,vec);
        string finalDriver="";
        double mx=ui.getMoney();
        int flag=0;
        for(int i=0; i<vec.size(); i++){
            DriverInformation di(vec[i]);
            double fare=di.getFarePerKm()*mapFind.GetCost(di.getLocation(),dest);
            if(fare<=mx){
                ifstream in1(("DriverAvailable/"+vec[i]+".txt").c_str());
                if(!in1.is_open()){
                    flag=1;
                    mx=fare;
                    finalDriver=vec[i];
                }
                in1.close();
            }
        }
        if(mx==ui.getMoney()){
            system("cls");
            cout<<"Sorry, you don't have enough cash to ride"<<endl;
            cout<<"Please deposit some cash before you begin"<<endl;
        }
        else if(flag==0){
            system("cls");
            cout<<"Sorry, there is not any drivers available right now"<<endl;
            cout<<"                  Try again later                  "<<endl;
        }
        else{
            system("cls");
            char beginTrip;
            DriverInformation di(finalDriver);
            cout<<finalDriver<<" is the best suited driver for you"<<endl<<endl;
            cout<<"Profile"<<endl<<endl;
            di.viewProfileForUser();
            cout<<endl<<"Begin trip(Y/N)  ::  ";
            cin>>beginTrip;
            if(tolower(beginTrip)=='y'){
                ofstream out(("DriverAvailable/"+finalDriver+".txt").c_str());
                ofstream out1(("DriverAvailable/rating"+username+".txt").c_str());
                out<<username<<'\n'<<dest<<'\n';
                out1<<finalDriver<<'\n';
                cout<<endl<<finalDriver<<" will be arriving within a couple of minutes"<<endl;
                cout<<"Have a safe journey!!!"<<endl;
            }
            else
                goto E;
        }
    }
}

void updateProfileDriver(DriverInformation &di)
{
    system("cls");
    int option;
    cout<<"1. Change Password"<<endl;
    cout<<"2. Change Phone Number"<<endl;
    cout<<"3. Change Fare/Km"<<endl;
    cout<<"4. Change Car Type"<<endl;
    cout<<"5. Change Car Number"<<endl;
    cout<<"6. Change Number Of Passengers Car Supports"<<endl;
    cout<<"7. Change Current Location"<<endl;
    cout<<endl<<"Select An Option :: ";
    cin>>option;
    string str;
    int n;
    double d1;
    if(option==1){
        cout<<endl<<"Password  ::  ";
        cin>>str;
        di.setPassword(str);
    }
    else if(option==2){
        cout<<endl<<"Phone Number  ::  ";
        cin>>str;
        di.setPhone(str);
    }
    else if(option==3){
        cout<<endl<<"Fare/Km  ::  ";
        cin>>d1;
        di.setFarePerKm(d1);
    }
    else if(option==4){
        cout<<endl<<"Car Type  ::  ";
        cin>>str;
        di.setCarType(str);
    }
    else if(option==5){
        cout<<endl<<"Car Number  ::  ";
        cin>>str;
        di.setCarNumber(str);
    }
    else if(option==6){
        cout<<endl<<"Number Of Passengers Car Supports  ::  ";
        cin>>n;
        di.setNumberOfPassCarSup(n);
    }
    else if(option==7){
        cout<<endl<<"Current Location  ::  ";
        cin>>str;
        di.setLocation(str);
    }
    else{
        cout<<"Unrecognized Command"<<endl;
    }
}

void openpage(string username,string passenger,string location)
{
    Map mapList;
    F:
    char ch,check;
    DriverInformation di(username);
    cout<<"Drop Off "<<passenger<<endl<<endl;
    cout<<"Reached destination(Y/N)  ::  ";
    cin>>ch;
    if(tolower(ch)=='y'){
        double taka=di.getFarePerKm()*mapList.GetCost(di.getLocation(),location);
        User ui(passenger);
        ui.Payment(taka);
        di.setTotalIncome(taka);
        di.setLocation(location);
        remove(("DriverAvailable/"+username+".txt").c_str());
        takeDriverInput(username,passenger,taka);
    }
    else{
        goto F;
    }
}

void takeDriverInput(string username,string password,int check)
{
    cout<<"Welcome Back "<<username<<endl;
    ifstream in(("FirstTimeTest/"+username+".txt").c_str());
    D:
    if(in.is_open()){
        string phone,carType,carNumber,location;
        int noOfPassCarSup;
        double fpkm;
        ofstream out(("Driver/"+username+".txt").c_str());
        cout<<endl<<"Please Complete Your Information"<<endl<<endl;
        cout<<"Name                     ::  "<<username<<endl;
        cout<<"Phone                    ::  ";
        cin>>phone;
        cout<<"Fare/Kilometer           ::  ";
        cin>>fpkm;
        cout<<"Car Type                 ::  ";
        cin>>carType;
        cout<<"Car Number               ::  ";
        cin>>carNumber;
        cout<<"Passengers Car Supports  ::  ";
        cin>>noOfPassCarSup;
        cout<<"Location                 ::  ";
        cin>>location;
        DriverInformation newDriver(username,password,phone,fpkm,carType,carNumber,location,noOfPassCarSup);
        in.close();
        remove(("FirstTimeTest/"+username+".txt").c_str());
        system("cls");
        cout<<"        Thank You!!!        "<<endl;
        cout<<"Have A Great Journey With Us"<<endl;
        cout<<"        Loading";
        time_t t = time(NULL);
        struct tm localt = *localtime(&t);
        int sec=(localt.tm_sec+4)%60,temp=localt.tm_sec;
        while(localt.tm_sec!=sec){
            time_t t = time(NULL);
            localt = *localtime(&t);    //cout<<temp<<"   "<<sec<<endl;
            if(temp!=localt.tm_sec && temp!=sec)
                cout<<".";
            temp=localt.tm_sec;
        }
        goto D;
    }
    else{
        ifstream in(("DriverAvailable/"+username+".txt").c_str());
        if(in.is_open()){
            string passenger,location;
            in>>passenger>>location;
            in.close();
            openpage(username,passenger,location);
            in.close();
            remove(("DriverAvailable/"+username+".txt").c_str());
        }
        else{
            DriverInformation di(username);
            int optionNumber;
            system("cls");
            if(check!=-1) cout<<endl<<"Congratulations!!! You have earned "<<check<<" taka"<<endl<<endl;
            E:
            cout<<"1. View Profile"<<endl;
            cout<<"2. Update Profile"<<endl;
            cout<<"3. Log Out"<<endl<<endl;
            cout<<"Select An Option :: ";
            cin>>optionNumber;
            if(optionNumber==1){
                system("cls");
                di.viewProfile();
                cout<<endl;
                goto E;
            }
            else if(optionNumber==2){
                updateProfileDriver(di);
                system("cls");
                cout<<"Your Profile Has Been Successfully Updated"<<endl;
                goto E;
            }
            else if(optionNumber==3){
                exit(0);
            }
            else{
                cout<<"Unrecognized Command"<<endl;
                goto E;
            }
        }
    }
}

bool checkAccount(string username,string password,ifstream &in)
{
    string un,pw;
    in>>un;
    in>>pw;
    if(username==un && password==pw){
        cout<<endl<<"Logging In";
        time_t t = time(NULL);
        struct tm localt = *localtime(&t);
        int sec=(localt.tm_sec+4)%60,temp=localt.tm_sec;
        while(localt.tm_sec!=sec){
            time_t t = time(NULL);
            localt = *localtime(&t);    //cout<<temp<<"   "<<sec<<endl;
            if(temp!=localt.tm_sec && temp!=sec)
                cout<<".";
            temp=localt.tm_sec;
        }
        system("cls");
        cout<<"Successfully logged in"<<endl;

        while(localt.tm_sec!=(sec+1)%60){
            t = time(NULL);
            localt = *localtime(&t);
        }
        system("cls");
        return true;
    }
    else{
        system("cls");
        cout<<"Oops! The login details you entered were incorrect."<<endl;
        return false;
    }
}

void run()
{
    system("cls");
    char haveAnyAccount,accountType;
    string username,password,confirmPassword;
    A:
    cout<<"New to Uber? (Y/N) :: ";
    cin>>haveAnyAccount;
    if(tolower(haveAnyAccount)=='n'){
        C:
        cout<<endl<<"-----Sign In-----"<<endl<<endl;;
        cout<<"| USERNAME :: ";
        cin>>username;
        cout<<"| PASSWORD :: ";
        cin>>password;
        string fileName1="Driver/"+username+".txt",fileName2="User/"+username+".txt";
        ifstream in1(fileName1.c_str()),in2(fileName2.c_str()),in3("AdminAccount.txt");
        if(in1.is_open()){
            if(checkAccount(username,password,in1)==false) goto C;
            takeDriverInput(username,password,-1);
        }
        else if(in2.is_open()){
            if(checkAccount(username,password,in2)==false) goto C;
            takeUserInput(username,password);
        }
        else if(in3.is_open()){
            if(checkAccount(username,password,in3)==false) goto C;
            takeAdminInput(username,password);
        }
        else{
            system("cls");
            cout<<"Oops! The login details you entered were incorrect."<<endl;
            goto C;
        }
        in1.close(),in2.close();
    }
    else if(tolower(haveAnyAccount)=='y'){
        B:
        cout<<endl<<"-----Sign Up-----"<<endl<<endl;
        cout<<"| USERNAME                    ::  ";
        cin>>username;
        cout<<"| PASSWORD                    ::  ";
        cin>>password;
        cout<<"| CONFIRM PASSWORD            ::  ";
        cin>>confirmPassword;
        cout<<"| I Want to Drive/Hire (D/H)  ::  ";
        cin>>accountType;
        if(password==confirmPassword){
            if(tolower(accountType)=='d'){
                string fileName1="Driver/"+username+".txt";
                string fileName2="User/"+username+".txt";
                ifstream testIn1(fileName1.c_str());
                ifstream testIn2(fileName2.c_str());
                if(testIn1.is_open() || testIn2.is_open()){
                    system("cls");
                    cout<<"Username Already Exists"<<endl;
                    goto B;
                }
                else{
                    ofstream out(fileName1.c_str());
                    out<<username<<'\n';
                    out<<password;
                    ofstream otest(("FirstTimeTest/"+username+".txt").c_str());
                    otest.close();
                    out.close();
                }
                testIn1.close();
                testIn2.close();
            }
            else if(tolower(accountType)=='h'){
                string fileName1="Driver/"+username+".txt";
                string fileName2="User/"+username+".txt";
                ifstream testIn1(fileName1.c_str());
                ifstream testIn2(fileName2.c_str());
                if(testIn1.is_open() || testIn2.is_open()){
                    system("cls");
                    cout<<"Username Already Exists"<<endl;
                    goto B;
                }
                else{
                    ofstream out(fileName2.c_str());
                    out<<username<<'\n';
                    out<<password<<'\n';
                    out<<0;
                    ofstream otest(("FirstTimeTest/"+username+".txt").c_str());
                    otest.close();
                    out.close();
                }
                testIn1.close();
                testIn2.close();
            }
            system("cls");
            if(tolower(accountType)!='h' && tolower(accountType)!='d'){
                cout<<"Unrecognized Command"<<endl;
                goto B;
            }
            else{
                cout<<"Account Created Successfully"<<endl;
                goto C;
            }
        }
        else{
            system("cls");
            cout<<"Oops, that's not the same password as the first one"<<endl;
            goto B;
        }
    }
    else{
        system("cls");
        goto A;
    }
}
