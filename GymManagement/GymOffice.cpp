#pragma once
#include<iostream>
#include<iomanip>
#include <vector>
#include "GymAccount.cpp"
#include "ConfirmService.cpp"
#include "InputService.cpp"
#include "DynamicArray.cpp"
#include <fstream>
using namespace std;
class GymOffice : public GymAccount {
private:

	DynamicArray<GymAccount*> accounts;

	int count = 0;
public:

	int findGymAccountById(int accountNumber) {
		for (int i = 0; i < count; i++) {
			if (accounts[i]->getAccountNumber() == accountNumber) {
				return i;
			}
		}
		return -1;
	}
	int findGymAccountByName(string accountName) {
		for (int i = 0; i < count; i++) {
			if (accounts[i]->getAccountName() == accountName) {
				return i;
			}
		}
		return -1;
	}
	//Get account by number
	GymAccount* getAccountById(int accountNumber) {
		GymAccount* account = nullptr;
		for (int i = 0; i < count; i++) {
			if (accounts[i]->getAccountNumber() == accountNumber) {
				return accounts[i];
			}
		}
		return account;
	}
	GymAccount* getAccountByName(string accountName) {
		GymAccount* account = nullptr;
		for (int i = 0; i < count; i++) {
			if (accounts[i]->getAccountName() == accountName) {
				return accounts[i];
			}
		}
		return account;
	}

	//addGymAccount
	void addGymAccount(GymAccount* account) {
		accounts[count] = new GymAccount();
		accounts[count] = account;
		count++;
	}
	//editBankAccount
	void editGymAccount(int accountNumber) {
		string name;
		char option;
		int found = findGymAccountById(accountNumber);

		if (found != -1) {
			name = InputService::getNewName();
			option = InputService::confirmMessage();
			if (option != 'n') {
				accounts[found]->setAccountName(name);
				ConfirmService::editMessage(); //message
			}
			else {
				ConfirmService::editCanncelMessage(); //message
			}
		}
		else {
			ConfirmService::notFoundMessage();
		}

	}
	void editGymAccount(string accountName) {
		string name;
		char option;
		int found = findGymAccountByName(accountName);

		if (found != -1) {
			name = InputService::getNewName();
			option = InputService::confirmMessage();
			if (option != 'n') {
				accounts[found]->setAccountName(name);
				ConfirmService::editMessage(); //message
			}
			else {
				ConfirmService::editCanncelMessage(); //message
			}
		}
		else {
			ConfirmService::notFoundMessage();
		}

	}
	//deleteBankAccount
	void deleteGymAccount(int accountNumber) {
		int found = findGymAccountById(accountNumber);
		if (found != -1) {
			for (int i = found; i < count; i++) {
				accounts[i] = accounts[i + 1];
			}
			count--;
		}
		else {
			ConfirmService::notFoundMessage(); //message
		}
	}
	void deleteGymAccount(string accountName) {
		int found = findGymAccountByName(accountName);
		if (found != -1) {
			for (int i = found; i < count; i++) {
				accounts[i] = accounts[i + 1];
			}
			count--;
		}
		else {
			ConfirmService::notFoundMessage(); //message
		}
	}
	void deletedGymAccountbyName(string accountName) {
		char option;
		int index = findGymAccountByName(accountName);
		if (index != -1) {
			accounts[index]->outputAccount();
			option = InputService::confirmMessage();
			if (option != 'n') {
				deleteGymAccount(accountName);
				ConfirmService::deleteMessage(); //message
			}
			else {
				ConfirmService::deleteCanncelMessage(); //message
			}
		}
		else {
			ConfirmService::notFoundMessage(); //message
		}
	}
	void deletedGymAccountbyAccNo(int accountNumber) {
		char option;
		int index = findGymAccountById(accountNumber);
		if (index != -1) {
			accounts[index]->outputAccount();
			option = InputService::confirmMessage();
			if (option != 'n') {
				deleteGymAccount(accountNumber);
				ConfirmService::deleteMessage(); //message
			}
			else {
				ConfirmService::deleteCanncelMessage(); //message
			}
		}
		else {
			ConfirmService::notFoundMessage(); //message
		}
	}
	//sort gym account by number
	void sortGymAccountById() {
		GymAccount* temp;
		for (int i = 0; i < count - 1; i++) {
			for (int j = 0; j < count - i - 1; j++) {
				if (accounts[j]->getAccountNumber() > accounts[j + 1]->getAccountNumber()) {
					temp = accounts[j];
					accounts[j] = accounts[j + 1];
					accounts[j + 1] = temp;
				}
			}
		}
	}
	//viewAllgymAccount
	void viewAllGymAccount() {
		cout << "No" << "\t" << "Account No" << setw(10) << "  " << " Account Name" << setw(10) << " " << "Balance" << endl;

		for (int i = 0; i < count; i++) {
			cout << i + 1 << "\t" << accounts[i]->getAccountNumber() << setw(17) << "" << accounts[i]->getAccountName() << setw(18) << " " << accounts[i]->getBalance() << endl;
		}
	}


	void depositGymAccount(int accountNumber) {
		double amount;

		GymAccount* account = getAccountById(accountNumber);
		if (account != nullptr) {
			amount = InputService::getAmount();
			account->deposit(amount);
			cout << "\\n\n\tdeposit success to your account " << amount << endl;
		}
		else {
			ConfirmService::invalidAmount();
		}

	}
	void withdrawGymAccount(int accountNumber) {
		double amount;

		GymAccount* account = getAccountById(accountNumber);
		if (account != nullptr) {
			amount = InputService::getAmount();
			account->withdraw(amount);
			cout << "\n\n\twithdraw success from your account " << amount << endl;
		}
		else {
			ConfirmService::invalidAmount();
		}

	}

	void checkBalance(int accountNumber) {
		GymAccount* account = getAccountById(accountNumber);
		if (account != nullptr) {
			cout << "\n\n\tThe account balance is:" << account->getBalance();
		}
		else {
			ConfirmService::notFoundMessage();
		}
	}

};