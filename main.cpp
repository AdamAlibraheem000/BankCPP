#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<fstream>
#include<cstdlib>

using namespace std;

const float MINIMUM {300.00};

class Account
{
    private:
    long accountNumber;
    string firstName;
    string lastName;
    float balance;
    // static var to account for next number
    static long NextAccountNumber;

    public:
    // constructor overloading
    Account(){}
    Account(string fname, string lname, float balance);
    static void setLastAccountNumber(long accountNumber);
    static long getLastAcccountNumber();
    friend ofstream & operator<<(ofstream &ofs,Account &acc);
    friend ifstream & operator>>(ifstream &ifs,Account &acc);
    friend ostream & operator<<(ostream &os,Account &acc);
};

long Account::NextAccountNumber = 0;

class Bank
{
    private:
    map<long, Account> accounts;
    public:
    Bank();
    Account OpenAccount(string fname, string lname, float balance);
    Account BalanceEnquiry(long accountNumber);
    Account Deposit(long accountNumber, float amount);
    Account Withdraw(long accountNumber, float amount);
    void CloseAccount(long accountNumber);
    void ShowAllAccounts();
    ~Bank();
};

int main(){

    cout << "What's going on?";
    return 0;
}