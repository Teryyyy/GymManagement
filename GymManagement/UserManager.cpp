#pragma once
#include <iostream>
#include <fstream>
#include "UserManagerDAO.cpp"
#include "User.cpp"

class UserManager : public UserManagerDAO {
private:
	User users[100];
	int count = 0;
public:
	UserManager() {
		User user1("bob", "123", 1);
		User user2("jake", "123", 2);
		users[count++] = user1;
		users[count++] = user2;
	}
	void addUser(User user) {
		users[count] = user;
		count++;
	}
	void viewUser() {
		for (int i = 0; i < count; i++) {
			if (users[i].getType() == 1) {
				users[i].outputUser();
				cout << "Type: " << "ADMIN" << endl;
			}
			else if (users[i].getType() == 2) {
				users[i].outputUser();
				cout << "Type: " << "NORMAL" << endl;
			}


		}
	}
	int findUserByName(string name) {
		for (int i = 0; i < count; i++) {
			if (users[i].getUsername() == name) {
				return i;
			}
		}
		return -1;
	}
	User* getUserByName(string name) {
		User* user = nullptr;
		for (int i = 0; i < count; i++) {
			if (users[i].getUsername() == name) {
				if (users[i].getType() == 1) {
					users[i].outputUser();
					cout << "Type: " << "ADMIN" << endl;
				}
				else if (users[i].getType() == 2) {
					users[i].outputUser();
					cout << "Type: " << "NORMAL" << endl;
				}
				return &users[i];
			}
		}
		return user;
	}
	void editUserRole(string name) {
		int role;
		int found = findUserByName(name);
		if (found != -1) {
			cout << "Press 1. ADMIN 2. NORMAL " << endl;
			cin >> role;
			users[found].setType(role);
			cout << "Role has been updated" << endl;
		}
		else {
			cout << "not found" << endl;
		}
	}
	void editUserName(string name) {
		string userName;
		int found = findUserByName(name);
		if (found != -1) {
			cout << "Enter new name: ";
			cin >> userName;
			users[found].setUsername(userName);
			cout << "username has been updated" << endl;
		}
		else {
			cout << "not found" << endl;
		}
	}
	void editUserPassword(string name) {
		string password;
		int found = findUserByName(name);
		if (found != -1) {
			cout << "Enter new password: ";
			cin >> password;
			users[found].setPassword(password);
			cout << "password has been updated" << endl;
		}
		else {
			cout << "not found" << endl;
		}
	}
	void deleteUser(string name) {
		int found = findUserByName(name);
		if (found != -1) {
			for (int i = found; i < count; i++) {
				users[i] = users[i + 1];
			}
			count--;
			cout << "User has been deleted" << endl;
		}
		else {
			cout << "Not found" << endl;
		}
	}
	void searchUser(string name) {
		int found = findUserByName(name);
		if (found != -1) {
			for (int i = found; i < count; i++) {
				users[i].outputUser();
			}
		}
		else {
			cout << "not found" << endl;
		}
	}
	User* authenticateUser(string username, string password) {
		User* user = nullptr;
		for (int i = 0; i < count; i++) {
			if (users[i].getUsername() == username && users[i].getPassword() == password) {
				return &users[i];
			}
		}
		return user;
	}


};