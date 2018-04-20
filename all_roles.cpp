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
	password = getHash(password);
	/*char tmp;
	for (int i = 0;;) {
		tmp = getchar();
		if ((tmp >= 'a' && tmp <= 'z') || (tmp >= 'A' && tmp <= 'Z') || (tmp >= 0 && tmp <= 9)) {
			password[i] = tmp;
			++i;
			cout << "*";
		}
		if (tmp == '\b' && i >= 1) {	//if user typed back space
			cout << "\b \b";
			--i;
		}
		if (tmp == '\r'){ //if enter is pressed
			password[i] = '\0'; //null means end of string.
			break; //break the loop
		}
	}*/
	for (int i = 0; i < users.size(); ++i) {
		if (users[i].username == username && users[i].password == password) {
			cout << "Sucessfully logged in as '" << users[i].username << "'." << endl;
			currentUser = users[i];
			loginSuccessful = true;
			Pause();
			return;
		}
	}

	cout << "No such combination of username and password found. Please try again." << endl;
	loginSuccessful = false;
	Pause();
}

void ChangePassword(User &currentUser) {
	cout << "Enter new password: ";
	string newPassword; getline(cin, newPassword);

	if (newPassword == "") {
		cout << "New password cannot be empty. Please try again." << endl;
		Pause();
		return;
	}

	newPassword = getHash(newPassword);
	if (newPassword == currentUser.password) {
		cout << "New password must be different from current password. Please try again." << endl;
		Pause();
		return;
	}
	
	currentUser.password = newPassword;

	cout << "Password has changed successfully" << endl;
	Pause();
}

void ViewInfo(User &currentUser) {
	system("CLS");
	cout << "ID: " << currentUser.username << endl;
	cout << "Name: " << currentUser.fullName << endl;
	cout << "Email: " << currentUser.email << endl;
	cout << "Phone: " << currentUser.mobilePhone << endl;
	if (currentUser.type == 0) cout << "Class: " << currentUser._class << endl;
	cout << "Type: ";
	if (currentUser.type == 0) cout << "Student" << endl;
	else if (currentUser.type == 1) cout << "Academic staff" << endl;
	else cout << "Lecturer" << endl;
	cout << endl;
	Pause();
}