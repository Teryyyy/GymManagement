#pragma once
#include <iostream> 
#include "GymAccount.cpp" 
#include "ConfirmService.cpp"
using namespace std;

class MonthlyAccount : public GymAccount
{
private:
    double discount;
public:
    MonthlyAccount() :GymAccount(), discount(0) {};
    MonthlyAccount(string accountName, int accountNumber, double balance, double discount) :
        GymAccount(accountName, accountNumber, balance), discount(discount) {};

    void setDiscount(double discount) {
        this->discount = discount;
    }
    double getDiscount() {
        return discount;
    }
    void deposit(double amount) {
        if (amount < 0) {
            ConfirmService::invalidAmount();
        }
        else {
            balance += amount;
        }
    }
    void withdraw(double amount) {
        if (amount > balance) {
            ConfirmService::invalidAmount();
        }
        else {
            balance -= amount;
        }
    }
    void checkBalance() {
        cout << "\n\n\tThe balance is : " << balance << endl;
    }

    void inputAccount()
    {
        GymAccount::inputAccount();
        cout << "\n\n\tEnter Discount: ";
        cin >> discount;
    }

    void outputAccount()
    {
        GymAccount::outputAccount();
        cout << "\n\n\tDiscount: " << discount << "%" << endl;
    }

};