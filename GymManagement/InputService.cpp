#pragma once
#include <iostream>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include "Menu.cpp"
#include "ConfirmService.cpp"
using namespace std;

class InputService : public Menu, public ConfirmService {

public:
	char confirmMessage() {
		char choice;
		cout << "\n\n\tare you sure?(y/n): ";
		cin >> choice;
		return choice;
	}
	int getNumber() {
		int num;
		while (true) {
			cout << "\n\n\tEnter account number: ";
			cin >> num;
			if (cin.fail()) {
				ConfirmService::isInvalidNumber();
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (cin.gcount() > 1) {
				ConfirmService::isInvalidNumber();
				continue;
			}
			if (num <= 0) {
				ConfirmService::isInvalidNumber();
				continue;
			}
			break;
		}
		return num;
	}
	int getAmount() {
		int num;
		while (true) {
			cout << "\n\n\tEnter amount: ";
			cin >> num;
			if (cin.fail()) {
				ConfirmService::invalidAmount();
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (cin.gcount() > 1) {
				ConfirmService::invalidAmount();
				continue;
			}
			if (num <= 0) {
				ConfirmService::invalidAmount();
				continue;
			}
			break;
		}
		return num;
	}
	string getName() {
		string name;
		cout << "\n\n\tEnter username: ";
		cin >> name;
		while (!isNameLegal(name)) {
			ConfirmService::invalidMessage();
			cout << "\n\n\t Enter username: ";
			cin >> name;
		}
		return name;
	}
	string AccountName() {
		string name;
		cout << "\n\n\tEnter account name: ";
		cin >> name;
		while (!isNameLegal(name)) {
			ConfirmService::invalidMessage();
			cout << "\n\n\t Enter account name: ";
			cin >> name;
		}
		return name;
	}
	string getNewName() {
		string name;
		cout << "\n\n\tEnter new name: ";
		cin >> name;
		while (!isNameLegal(name)) {
			ConfirmService::invalidMessage();
			cout << "\n\n\t Enter new name: ";
			cin >> name;
		}
		return name;
	}
	int AccountNumber() {
		int num;
		while (true) {
			cout << "\n\n\tEnter account number: ";
			cin >> num;
			if (cin.fail()) {
				ConfirmService::isInvalidNumber();
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (cin.gcount() > 1) {
				ConfirmService::isInvalidNumber();
				continue;
			}
			if (num <= 0) {
				ConfirmService::isInvalidNumber();
				continue;
			}
			break;
		}

		return num;
	}
	int AccountBalance() {
		int num;
		while (true) {
			cout << "\n\n\tEnter balance: ";
			cin >> num;
			if (cin.fail()) {
				ConfirmService::isInvalidNumber();
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (cin.gcount() > 1) {
				ConfirmService::isInvalidNumber();
				continue;
			}
			if (num <= 0) {
				ConfirmService::isInvalidNumber();
				continue;
			}
			break;
		}
		return num;
	}
	char getContinue() {
		char choice;
		cout << "\n\n\tDo you want to continue(y/n)";
		cin >> choice;
		return choice;
	}
	char getCommand() {
		char ch;
		cin >> ch;
		while (!isLegal(ch)) {
			cout << "\n\n\tinvalid choice, please select you option (0-7)" << endl;
			Menu::mainMenu();
			cin >> ch;
		}
		return ch;
	}
	int getCommand2() {
		int op;
		cin >> op;
		while (!islegal2(op)) {
			cout << "\n\n\tinvalid choice, please select your option(0-2)" << endl;
			Menu::createNewAccountMenu();
			cin >> op;
		}
		return op;
	}
	int getCommand3() {
		int op;
		cin >> op;
		while (!islegal3(op)) {
			cout << "\n\n\tinvalid choice, please select your option(0-3)" << endl;
			Menu::customerMenu();
			cin >> op;
		}
		return op;
	}

	int getOption() {
		int op;
		cin >> op;
		while (!islegal2(op)) {
			cout << "\n\n\tinvalid choice, please select your option(0-2)" << endl;
			Menu::optionMenu();
			cin >> op;
		}
		return op;
	}
	bool isLegal(char c) {
		return ((c == '1') || (c == '2') || (c == '3') || (c == '4') || (c == '5') || (c == '6') || (c == '7') || (c == '0'));
	}
	bool islegal2(int c) {
		return ((c == 1) || (c == 2) || (c == 0));
	}
	bool islegal3(int c) {
		return ((c == 1) || (c == 2) || (c == 3) || (c == 0));
	}
	bool isNameLegal(string name)
	{
		return all_of(name.begin(), name.end(), [](char ch) {
			return (isalpha(ch) || isspace(ch));
			});
	}

};