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
using namespace std;

enum menuType {
	NEW_ACCOUNT = '1', CUSTOMER_SERVICE = '2', VIEW_ALL_ACCOUNT = '3',
	DELETE_ACCOUNT = '4', EDIT_ACCOUNT = '5', SEARCH_ACCOUNT = '6', EXIT_APPLICATION = '0'
};
enum accountType { WEEKLY_ACCOUNT = 1, MONTHLY_ACCOUNT = 2, EXIT_ACCOUNT = 0 };
enum customerType { DEPOSIT = 1, WITHDRAW = 2, CHECKING_BALANCE = 3, EXIT_CUSTOMER = 0 };
enum userMenuType { NEW_USER = '1', VIEW_USER = '2', EDIT_USER = '3', DELETE_USER = '4', SEARCH_USER = '5', EXIT_USER = '0' };
class Application : public GymOffice {
public:
	void bankApplication() {
		char ch;
		int num = 0;
		string name;
		int op = 0;
		GymOffice gymOffice;
		WeeklyAccount* weeklyAccount = nullptr;
		MonthlyAccount* monthlyAccount = nullptr;
		char choice;
		do
		{
			system("cls");
			Menu::mainMenu();
			ch = InputService::getCommand(); //method from input service class
			system("cls");
			switch (ch)
			{
			case menuType::NEW_ACCOUNT:
				//input accounts
				do {
					Menu::createNewAccountMenu();
					op = InputService::getCommand2();
					switch (op) {
					case accountType::WEEKLY_ACCOUNT:
						weeklyAccount = new WeeklyAccount();
						weeklyAccount->inputAccount();
						gymOffice.addGymAccount(weeklyAccount);
						break;
					case accountType::MONTHLY_ACCOUNT:
						monthlyAccount = new MonthlyAccount();
						monthlyAccount->inputAccount();
						gymOffice.addGymAccount(monthlyAccount);
						break;
					case accountType::EXIT_ACCOUNT: break;
					default: cout << "\a"; break;
					}
					choice = getContinue(); //method from input service class
				} while (choice != 'n');
				break;
			case CUSTOMER_SERVICE:
				do {
					Menu::customerMenu();
					op = InputService::getCommand3();
					switch (op) {
					case customerType::DEPOSIT:
						num = getNumber(); //method from input service class
						gymOffice.depositGymAccount(num);
						break;
					case customerType::WITHDRAW:
						num = getNumber(); //method from input service class
						gymOffice.withdrawGymAccount(num);
						break;
					case customerType::CHECKING_BALANCE:
						num = getNumber(); //method from input service class
						gymOffice.checkBalance(num);
						break;
					case customerType::EXIT_CUSTOMER: break;
					default: cout << "\a";
					}
					choice = getContinue();
				} while (choice != 'n');
				break;
			case menuType::VIEW_ALL_ACCOUNT:
				gymOffice.viewAllGymAccount();
				break;
			case menuType::DELETE_ACCOUNT:
				do {
					Menu::optionMenu();
					op = InputService::getOption();
					switch (op) {
					case 1:
						num = getNumber(); //method from input service class
						gymOffice.deletedGymAccountbyAccNo(num);
						break;
					case 2:
						name = AccountName();
						gymOffice.deletedGymAccountbyName(name);
						break;
					case 0: break;
					default: cout << "\a";
					}

					choice = getContinue();
				} while (choice != 'n');
				break;
			case menuType::EDIT_ACCOUNT:
				do {
					Menu::optionMenu();
					op = InputService::getOption();
					switch (op) {
					case 1:
						num = getNumber(); //method from input service class
						gymOffice.editGymAccount(num);
						break;
					case 2:
						name = AccountName();
						gymOffice.editGymAccount(name);
						break;

					case 0: break;
					default: cout << "\a";
					}
					choice = getContinue();
				} while (choice != 'n');
				break;
			case menuType::SEARCH_ACCOUNT:
				Menu::optionMenu();
				op = InputService::getOption();
				switch (op) {
				case 1: {
					num = getNumber(); //method from input service class
					GymAccount* account = gymOffice.getAccountById(num);
					account->outputAccount();

				}
					  break;

				case 2: {
					name = AccountName(); //method from input service class
					GymAccount* account = gymOffice.getAccountByName(name);
					account->outputAccount();
				}
					  break;

				case 0:
					break;
				default: cout << "\a";
				}
				break;

			}
			cin.ignore();
			cin.get();
		} while (ch != '0');
	}
	void userApplication() {
		char cha;
		string username;
		UserManager userManager;
		do
		{
			system("cls");
			Menu::userMenu();
			cin >> cha;
			system("cls");
			switch (cha)
			{
			case userMenuType::NEW_USER: {
				User user;
				user.inputUser();
				userManager.addUser(user);
				break;
			}
			case userMenuType::VIEW_USER:
				userManager.viewUser();
				break;
			case userMenuType::EDIT_USER: {
				do {
					Menu::editUserMenu();
					cin >> cha;
					switch (cha) {
					case '1':
						username = getName();
						userManager.editUserRole(username);
						break;
					case '2':
						username = getName();
						userManager.editUserName(username);
						break;
					case '3':
						username = getName();
						userManager.editUserPassword(username);
						break;
					case '0':
						break;
					default: cout << "\a";
					}
					cha = getContinue();
				} while (cha != 'n');
				break;
			}
			case userMenuType::DELETE_USER: {
				string username = getName();
				userManager.deleteUser(username);
				break;
			}
			case userMenuType::SEARCH_USER: {
				string username = getName();
				User* user = userManager.getUserByName(username);
				break;
			}
			case userMenuType::EXIT_USER: exit(1); break;
			default:
				cout << "\a";
			}
			cin.ignore();
			cin.get();
		} while (cha != '0');
	}


};