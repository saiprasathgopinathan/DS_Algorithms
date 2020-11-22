#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
using namespace std;

#define Min_bal 500
class insufficientBalance{};

class Account
{
    long acc_no;
    static long next_acc_no;
    string fname;
    string lname;
    float balance;
    public:
        Account(){};
        Account(string fn, string ln, float bal);
        
        long get_acc_no(){return acc_no;}
        void Deposit(float amt);
        void Withdraw(float amt);
        
        float get_bal(){return balance;}
        string get_f_name(string fname){return fname;}
        string get_l_name(string lname){return lname;}
        
        static void set_last_ac_no(long acc_no)
        {
            next_acc_no = acc_no;
        }
        static long get_last_ac_no(long acc_no)
        {
            return next_acc_no;
        }
        
        friend ofstream &operator<<(ofstream &fos, Account &acc);
        friend ostream &operator<<(ostream &os, Account &acc);
        friend ifstream &operator>>(ifstream &fis, Account &acc);
};
long Account::next_acc_no=0;

class Bank
{
    map<long, Account> account_map;
    public:
    Bank();
    Account OpenAccount(string fname, string lname, float bal);
    Account balance_enquiry(long acc_no);
    Account Deposit(long acc_no, float amt);
    Account Withdraw(long acc_no, float amt);
    void CloseAccount(long acc_no);
    void show_all_accounts();
    ~Bank();
};

// Account class
Account::Account(string fn, string ln, float bal)
{
    next_acc_no++;
    acc_no = next_acc_no;
    fname = fn;
    lname = ln;
    balance = bal;
}

void Account::Deposit(float amt)
{
    balance += amt;
}

void Account::Withdraw(float amt)
{
    if(balance - amt < Min_bal)
    {
        throw insufficientBalance();
    }
    balance -= amt;
}

ofstream &operator<<(ofstream &fos, Account &acc)
{
    fos<<acc.acc_no<<endl;
    fos<<acc.fname<<endl;
    fos<<acc.lname<<endl;
    fos<<acc.balance<<endl;
    return fos;
}

ostream &operator<<(ostream &os, Account &acc)
{
    os<<acc.acc_no<<endl;
    os<<acc.fname<<endl;
    os<<acc.lname<<endl;
    os<<acc.balance<<endl;
    return os;
}

ifstream &operator>>(ifstream &fis, Account &acc)
{
    fis>>acc.acc_no;
    fis>>acc.fname;
    fis>>acc.lname;
    fis>>acc.balance;
    return fis;
}

//Bank Class
Bank::Bank()
{
    Account account_obj;
    ifstream infile("Bank.data");
    if(!infile)
    {
        return;
    }
    if(!infile.eof())
    {
        infile>>account_obj;
        account_map.insert(pair<long, Account>(account_obj.get_acc_no(), account_obj));
    };
    // Account::set_last_ac_no(account_obj.get_acc_no());
    account_obj.set_last_ac_no(account_obj.get_acc_no());
    infile.close();
}

Account Bank::OpenAccount(string fname, string lname, float bal)
{
    Account account_obj(fname, lname, bal);
    account_map.insert(pair<long, Account>(account_obj.get_acc_no(), account_obj));
    ofstream outfile("Bank.data", ios::trunc);
    map<long, Account>::iterator itr;
    for(itr = account_map.begin();itr != account_map.end();itr++)
    {
        outfile<<itr->second;
    }
    outfile.close();
    return account_obj;
}

Account Bank::balance_enquiry(long acc_no)
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

void Bank::CloseAccount(long acc_no)
{
    map<long, Account>::iterator itr = account_map.find(acc_no);
    account_map.erase(acc_no);
}

void Bank::show_all_accounts()
{
    map<long, Account>:: iterator itr;
    for(itr=account_map.begin(); itr!=account_map.end();itr++)
    {
        cout<<itr->first<<" "<<itr->second<<endl;
    }
}

Bank::~Bank()
{
    ofstream outfile("Bank.data", ios::trunc);
    map<long, Account>::iterator itr;
    for(itr=account_map.begin(); itr!= account_map.end(); itr++)
    {
        outfile<<itr->second;
    } 
    outfile.close();
}

int main()
{
    Bank b;
    Account account_obj_main;
    int choice;
    string first_name;
    string second_name;
    float amt;
    float balance;
    long account_no;
    cout<<"*****BANKING SYSTEM******"<<endl;
    do
    {
        cout<<endl;
        cout<<"1. Open Account"<<endl;
        cout<<"2. Balance Inquiry"<<endl;
        cout<<"3. Deposit"<<endl;
        cout<<"4. Withdrawl"<<endl;
        cout<<"5. Close Account"<<endl;
        cout<<"6. Show all accounts"<<endl;
        cout<<"7. Quit"<<endl;

        cout<<"\n Select a choice: ";
        cin>>choice;
        switch(choice)
        {
            // OPEN ACCOUNT
            case 1:
            {
                cout<<"Enter first name: ";
                cin>>first_name;
                cout<<endl<<"Enter second name: ";
                cin>>second_name;
                cout<<endl<<"Enter Inital Balance: ";
                cin>>balance;
                account_obj_main = b.OpenAccount(first_name, second_name, balance);
                cout<<endl<<"Comgrats you opened the bank"<<endl;
                cout<<"*****************************************************************";
                break;
            }
            // BALANCE INQUIRY
            case 2:
            {
                cout<<"Enter an Account Number: ";
                cin>>account_no;
                account_obj_main = b.balance_enquiry(account_no);
                // cout<<endl<<"Balance in your account= "<<account_obj_main.get_bal();
                cout<<endl<<"Balance in your account= "<<account_obj_main;
                cout<<endl<<"*****************************************************************";
                break;
            }
            // DEPOSIT
            case 3:
            {
                cout<<"Enter an Account Number: ";
                cin>>account_no;
                cout<<endl<<"Enter amount to be deposited: ";
                cin>>amt;
                account_obj_main = b.Deposit(account_no, amt);
                cout<<endl<<"Balance in your account= "<<account_obj_main;
                cout<<endl<<"*****************************************************************";
                break;
            }
            // WITHDRAWL
            case 4:
            {
                cout<<"Enter an Account Number: ";
                cin>>account_no;
                cout<<endl<<"Enter amount to be withdrawn: ";
                cin>>amt;
                account_obj_main = b.Withdraw(account_no, amt);
                cout<<endl<<"Balance in your account= "<<account_obj_main;
                cout<<endl<<"*****************************************************************";
                break;
            }
            // CLOSE ACCOUNT
            case 5:
            {
                cout<<"Enter an Account Number: ";
                cin>>account_no;
                b.CloseAccount(account_no);
                cout<<endl<<"Closed account= "<<account_obj_main;
                cout<<endl<<"*****************************************************************";
                break;
            }
            // Display Existing Account Numbers
            case 6:
            {
                b.show_all_accounts();
                cout<<endl<<"*****************************************************************";
                break;
            }
            //QUIT
            case 7:
            {
                
                break;
            }
            default:
            {
                cout<<endl<<"Please Enter correct choice";
                exit(0);
            }
        }
    }while(choice != 7);
    return 0;
}