#pragma once
#include <iostream>
#include "ConfirmService.cpp"
#include "InputService.cpp"
#include "NotFoundException.cpp"
#include <fstream>
#include <regex>
using namespace std;

class GymAccount : public InputService
{
private:
    string accountName;
    int accountNumber;
protected:
    double balance;
public:
    GymAccount() : accountName("Unknown"), accountNumber(0), balance(0) {}
    GymAccount(string accountName, int accountNumber, double balance) :
        accountName(accountName), accountNumber(accountNumber), balance(balance) {}

    void setAccountName(string accountName)
    {
        this->accountName = accountName;
    }
    string getAccountName()
    {
        return accountName;
    }
    void setAccountNumber(int accountNumber)
    {
        if (accountNumber > 0) {
            this->accountNumber = accountNumber;
        }
        else {

            ConfirmService::invalidMessage();
        }
    }
    int getAccountNumber()
    {
        return accountNumber;
    }
    void setBalance(double balance)
    {
        if (balance > 0) {
            this->balance = balance;
        }
        else {
            ConfirmService::invalidMessage();
        }
    }
    double getBalance()
    {
        return balance;
    }
    virtual void inputAccount() //validation 
    {
        accountName = AccountName();  //from input service class
        accountNumber = AccountNumber(); //from input service class
        balance = AccountBalance(); //from input service class

    }

    virtual void outputAccount()
    {
        cout << "\n\n\taccount name: " << accountName << endl;
        cout << "\n\n\taccount number: " << accountNumber << endl;
        cout << "\n\n\tbalance : " << balance << endl;
    }
    virtual void deposit(double amount) {
        if (amount < 0) {
            ConfirmService::invalidAmount();
        }
        else {
            balance += amount;
        }
    }
    virtual void withdraw(double amount) {
        if (amount > balance) {
            ConfirmService::invalidAmount();
        }
        else {
            balance -= amount;
        }
    }
    virtual void checkBalance() {
        cout << "\n\n\tThe Balance is : " << balance << endl;
    }
    const GymAccount& getGymAccount()const {
        return *this;
    }

};