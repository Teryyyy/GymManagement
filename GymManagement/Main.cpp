#include <iostream>
#include "Application.cpp"
#include "UserManager.cpp"
#include "ApplicationService.cpp"
using namespace std;

int main() {
	Application app;
	UserManager userManager;
	string username;
	string password;

	do {
		cout << "\n\n\n\t-----------------------------\n";
		cout << "\n\t     WELCOME TO OUR GYM";
		cout << "\n\n\t-----------------------------\n";
		cout << "\n\tEnter username: ";
		cin >> username;
		cout << "\n\n\tEnter password: ";
		cin >> password;

		User* user = userManager.authenticateUser(username, password);
		if (user != nullptr) {
			if (user->getType() == 1) {
				app.userApplication();

			}
			else if (user->getType() == 2) {
				app.bankApplication();
			}
		}
		else {
			cout << "invalid user" << endl;
		}
	} while (true);

	return 0;
}