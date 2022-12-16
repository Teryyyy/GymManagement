#include <iostream>
#include "GymAccount.cpp"
#include "MonthlyAccount.cpp"
#include "WeeklyAccount.cpp"
#include "GymOffice.cpp"
#include "Menu.cpp"
#include "ConfirmService.cpp"
#include "User.cpp"
#include "UserManager.cpp"
#include "InputService.cpp"
#include "GymAccountService.cpp"
#include "UserManager.cpp"
using namespace std;

class ApplicationService {
public:
	void run() {

		GymAccountService accounts;
		WeeklyAccount* weeklyAccount = nullptr;
		MonthlyAccount* monthlyAccount = nullptr;
		string name;
		int count = 0;
		int op;
		do {
			cout << "1 add" << endl;
			cout << "2 add" << endl;
			cout << "3 view" << endl;
			cout << "4 delete" << endl;
			cout << "5 sort" << endl;
			cin >> op;
			switch (op) {
			case 1:
				weeklyAccount->inputAccount();
				accounts.addGymAccount(weeklyAccount);
				break;
			case 2:
				monthlyAccount->inputAccount();
				accounts.addGymAccount(monthlyAccount);
				break;
			case 3:
				accounts.viewAllGymAccount();
				break;
			case 4:
				cin >> name;
				accounts.deleteGymAccount(name);
				break;
			case 5:
				accounts.sortGymAccount();
				break;
			}
		} while (op != 0);
	}


};