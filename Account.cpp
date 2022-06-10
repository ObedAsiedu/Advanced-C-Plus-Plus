#include "Account.h"
#include "Savings.h"
#include "Checking.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
using namespace std;

int main(void) 
{
    int choice;
    int account_num;
    int savings_num = 0;
    int checking_num = 0;
    double balance;
    double amt;
    vector<Checking *>checking(50);
    vector<Savings *>savings(50);
    do 
    {
        cout << "#################################################\n";
        cout << "#  Enter one of the following                   #\n";
        cout << "#  1) Create a new Checking Account             #\n";
        cout << "#  2) Create a new Savings Account              #\n";
        cout << "#  3) Make a Deposit for Checking Accounts      #\n";
        cout << "#  4) Make a Withdraw for Checking Accounts     #\n";
        cout << "#  5) Make a Deposit for Savings Accounts       #\n";
        cout << "#  6) Make a Withdraw for Savings Accounts      #\n";
        cout << "#  7) Display all accounts                      #\n";
        cout << "#  8) Exit                                      #\n";
        cout << "#################################################\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        // Operations based on choice
        switch(choice)
        {
            case 1:
                cout << "Enter balance for account #" << checking_num + 1 << ": ";
                cin >> balance;
                checking[checking_num] = new Checking(checking_num + 1, balance);
                checking_num++;
                break;
            case 2:
                cout << "Enter balance for account #" << savings_num + 1<< ": ";
                cin >> balance;
                savings[savings_num] = new Savings(savings_num + 1, balance);
                savings_num++;
                break;
            case 3:
                cout << "Which savings account: ";
                cin >> account_num;
                cout << "Amount of deposit: ";
                cin >> amt;
                (*checking[account_num - 1]) += amt;
                break;
            case 4:
                cout << "Which savings account: ";
                cin >> account_num;
                cout << "Amount of withdraw: ";
                cin >> amt;
                (*checking[account_num - 1]) -= amt;
                break;
            case 5:
                cout << "Which savings account: ";
                cin >> account_num;
                cout << "Amount of deposit: ";
                cin >> amt;
                (*savings[account_num - 1]) += amt;
                break;
            case 6:
                cout << "Which savings account: ";
                cin >> account_num; 
                cout << "Amount of withdraw: ";
                cin >> amt;
                (*savings[account_num - 1]) -= amt;
                break;
            case 7:
                cout << fixed << showpoint << setprecision(2);
                cout << "\n----------------Checking--------\n";
                for (int i = 0; i < checking_num; i++)
                {
                    cout << "Checking Account ";
                    (*checking[i]).printBalance();
                }

                cout << "\n----------------Savings---------\n";
                for (int i = 0; i < savings_num; i++)
                {
                    cout << "Savings Account ";
                    (*savings[i]).printBalance();
                }
                cout << "****************************************************\n"; 
                break;
            case 8:
                cout << "Press enter key to continue . . .";
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cin.get();
                break;
            default:
                cout << "Wrong choice. Try again!!\n";
                break;
        }
        cout << "\n";
    } while (choice != 8);
    return 0;
}
Account::Account(int num, double balance)
{
    this->accountNum = num;
    this->balance = balance;
}

void Account::operator+=(double depst) 
{
    balance += depst;
}

void Account::operator-=(double withdrw) 
{
    balance -= withdrw;
}

// Getters
int Account::getAccountNum()
{
    return accountNum;
}

double Account::getBalance()
{
    return balance;
}

// Setters
void Account::setAccountNum(int num)
{
    this->accountNum = num;
}

void Account::setBalance(double balance)
{
    this->balance = balance;
}

void Account::printBalance()
{
    cout << "#" << accountNum << "\tBalance = $" << balance << endl;
}

Checking::Checking(int num, double balance):
Account(num, balance)
{
    
}

Savings::Savings(int num, double balance):
Account(num, balance)
{
    
}
