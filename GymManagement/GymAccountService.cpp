#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "GymAccount.cpp"
using namespace std;

class GymAccountService {
private:
	vector<GymAccount*> accounts;
public:

	void addGymAccount(GymAccount* account) {
		accounts.push_back(account);
	}
	void viewAllGymAccount() {
		vector<GymAccount*>::iterator it;
		for (it = accounts.begin(); it != accounts.end(); it++) {
			(*it)->outputAccount();
			cout << endl;
		}
	}
	void editGymAccount(string name) {
		vector<GymAccount*>::iterator it;
		for (it = accounts.begin(); it != accounts.end(); it++) {
			if ((*it)->getAccountName().compare(name)) {
				(*it)->inputAccount();
				break;
			}
		}
	}
	void deleteGymAccount(string name) {
		vector<GymAccount*>::iterator it;
		for (it = accounts.begin(); it != accounts.end(); it++) {
			if ((*it)->getAccountName().compare(name) == 0) {
				accounts.erase(it);
				break;
			}
		}
	}
	void sortGymAccount() {
		vector<GymAccount*>::iterator it;
		sort(accounts.begin(), accounts.end(), greater<GymAccount*>());
		for (it = accounts.begin(); it != accounts.end(); it++) {
			(*it)->outputAccount();
		}
	}
	GymAccount* getGymAccountByName(string name) {
		vector<GymAccount*>::iterator it;
		for (it = accounts.begin(); it != accounts.end(); it++) {
			if ((*it)->getAccountName().compare(name) == 0) {
				return *it;
			}
		}
	}


};