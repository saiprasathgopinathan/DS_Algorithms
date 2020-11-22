#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
using namespace std;

#define min_bal 500
class insufficientfunds{};

class Account
{
    long acc_no;
    string first_name;
    string last_name;
    int balance;
    static long next_acc_no;

    public:
    Account(){};
    Account(string fname, string lname, float bal)
    {
        next_acc_no++;
        acc_no = next_acc_no;
        first_name = fname;
        last_name = lname;
        balance = bal;
    }
    string get_first_name(){return first_name;}
    string get_last_name(){return last_name;}
    float get_balance(){return balance;}
    long get_acc_no(){return acc_no;}
    
    void Deposit(float amt)
    {
        balance +=amt;
    }
    void Withdraw(float amt)
    {
        if(balance - amt < min_bal)
        {
            throw insufficientfunds();
        }
        balance -=amt;
    }
    
    static void set_last_acc_no(long acc_no)
    {
        next_acc_no = acc_no;
    }
    static long get_last_acc_no(long acc_no)
    {
        return next_acc_no;
    }
    friend ofstream &operator<<(ofstream &fos, Account &acc);
    friend ostream &operator<<(ostream &os, Account &acc);
    friend ifstream &operator>>(ifstream &fis, Account &acc);
};

long Account::next_acc_no = 0;

ofstream &operator<<(ofstream &fos, Account &acc)
{
    fos<<acc.acc_no<<endl;
    fos<<acc.first_name<<endl;
    fos<<acc.last_name<<endl;
    fos<<acc.balance<<endl;
    return fos;
}

ifstream &operator>>(ifstream &fis, Account &acc)
{
    fis>>acc.acc_no;
    fis>>acc.first_name;
    fis>>acc.last_name;
    fis>>acc.balance;
    return fis;
}

ostream &operator<<(ostream &os, Account &acc)
{
    os<<acc.acc_no<<endl;
    os<<acc.first_name<<endl;
    os<<acc.last_name<<endl;
    os<<acc.balance<<endl;
    return os;
}

class Bank
{
    map<long, Account> account_map;
    public:
    Bank();
    Account Openaccount(string fname, string lname, float amt);
    Account balance_inquiry(long acc_no);
    Account Deposit(long acc_no, float amt);
    Account Withdraw(long acc_no, float amt);
    void Closeaccount(long acc_no);
    void show_all();
    ~Bank();
};

Bank::Bank()
{
    Account acc_obj;
    ifstream infile("Bank.data");
    if(!infile)
    {
        return;
    }
    if(!infile.eof())
    {
        infile>>acc_obj;
        account_map.insert(pair<long, Account>(acc_obj.get_acc_no(), acc_obj));
    }
    acc_obj.set_last_acc_no(acc_obj.get_acc_no());
    infile.close();
}

Account Bank::Openaccount(string fname, string lname, float amt)
{
    Account acc_obj(fname, lname, amt);
    ofstream outfile("Bank.data",ios::trunc);
    account_map.insert(pair<long, Account>(acc_obj.get_acc_no(), acc_obj));
    map<long, Account>::iterator itr;
    for(itr=account_map.begin(); itr!=account_map.end();itr++)
    {
        outfile<<itr->second;
    }
    outfile.close();
    return acc_obj;
}

Account Bank::balance_inquiry(long acc_no)
{
    map<long, Account>::iterator itr = account_map.find(acc_no);
    return itr->second;
}

Account Bank::Deposit(long acc_no, float amt)
{
    map<long, Account>::iterator itr = account_map.find(acc_no);
    itr->second.Deposit(amt);
    return itr->second;
}

Account Bank::Withdraw(long acc_no, float amt)
{
    map<long, Account>::iterator itr = account_map.find(acc_no);
    itr->second.Withdraw(amt);
    return itr->second;
}

void Bank::Closeaccount(long acc_no)
{
    map<long, Account>::iterator itr = account_map.find(acc_no);
    account_map.erase(acc_no);
}

void Bank::show_all()
{
    map<long, Account>::iterator itr;
    for(itr = account_map.begin(); itr!=account_map.end();itr++)
    {
        cout<<itr->first<<" "<<itr->second<<endl;
    }
}

Bank::~Bank()
{
    ofstream outfile("Bank.data", ios::trunc);
    map<long, Account>::iterator itr;
    for(itr=account_map.begin(); itr!=account_map.end();itr++)
    {
        outfile<<itr->second;
    }
    outfile.close();
}

int main()
{
    Account acc_obj_main;
    Bank b;
    string f_name;
    string l_name;
    int amt;
    int bal;
    long acc_no;
    int choice;
    cout<<"*****BANKING SYSTEM*****"<<endl;
    do
    {
        cout<<endl;
        cout<<"1. Open Account"<<endl;
        cout<<"2. Balance Inquiry"<<endl;
        cout<<"3. Deposit"<<endl;
        cout<<"4. Withdraw"<<endl;
        cout<<"5. Close an Account"<<endl;
        cout<<"6. ShowAll"<<endl;
        cout<<"7. Quit"<<endl;
        cout<<"Enter a choice: ";
        cin>>choice;
        switch(choice)
        {
            // OPEN ACCOUNT
            case 1:
            {
                cout<<"Enter first name: ";
                cin>>f_name;
                cout<<"Enter second name: ";
                cin>>l_name;
                cout<<"Enter amount";
                cin>>amt;
                acc_obj_main = b.Openaccount(f_name, l_name, amt);
                cout<<"Congratulations your account has been created";
                cout<<endl<<"************************************************************************";
                break;
            }
            // BALANCE INQUIRY
            case 2:
            {
                cout<<endl<<"Enter an account number whose balance you want to see: ";
                cin>>acc_no;
                acc_obj_main = b.balance_inquiry(acc_no);
                cout<<"Balance in  account number= "<<acc_obj_main.get_balance();
                cout<<endl<<"************************************************************************";
                break;
            }
            // DEPOSIT
            case 3:
            {
                cout<<endl<<"Enter the account number in which the money needs to be deposited: ";
                cin>>acc_no;
                cout<<endl<<"Enter the amount to be deposited: ";
                cin>>amt;
                acc_obj_main = b.Deposit(acc_no, amt);
                cout<<endl<<"Total balance after deposit= "<<acc_obj_main.get_balance();
                cout<<endl<<"************************************************************************";
                break;
            }
            // WITHDRAWL
            case 4:
            {
                cout<<endl<<"Enter the account number from which the money needs to be removed: ";
                cin>>acc_no;
                cout<<endl<<"Enter the amount to be withdrawn: ";
                cin>>amt;
                acc_obj_main = b.Withdraw(acc_no, amt);
                cout<<endl<<"Total balance after withdrawl= "<<acc_obj_main.get_balance();
                cout<<endl<<"************************************************************************";
                break;
            }
            // CLOSE ACCOUNT
            case 5:
            {
                cout<<endl<<"Enter the account to be closed: ";
                cin>>acc_no;
                b.Closeaccount(acc_no);
                cout<<endl<<"Closed account= "<<endl<<acc_obj_main;
                cout<<endl<<"************************************************************************";
                break;
            }
            // SHOW ALL
            case 6:
            {
                b.show_all();
                cout<<endl;
                break;
            }
            // QUIT
            case 7:
            {
                break;
            }
            default:
            cout<<endl<<"Enter a valid choice";
            exit(0);
        }
    }while(choice!=7);
    return 0;
}