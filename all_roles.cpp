/*
Implementation for common use-cases of all roles
*/

#include "misc.h"
#include "all_roles.h"

void Login(User &currentUser, vector<User> users, bool &loginSuccessful) {
	cout << "Username: ";
	string username; getline(cin, username);
	cout << "Password: ";
	string password; getline(cin, password);
	for (int i = 0; i < users.size(); ++i) {
		if (users[i].username == username && users[i].password == password) {
			cout << "Sucessfully logged in as '" << users[i].username << "'." << endl;
			currentUser = users[i];
			loginSuccessful = true;
			return;
		}
	}
	
	cout << "No such combination of username and password found. Please try again." << endl;
	loginSuccessful = false;
}

void ChangePassword(User &currentUser) {
	cout << "Enter new password: ";
	string newPassword; getline(cin, newPassword);

	if (newPassword == currentUser.password) {
		cout << "New password must be different from current password. Please try again." << endl;
		return;
	}

	currentUser.password = newPassword;
}
