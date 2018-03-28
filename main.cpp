#include "sms.h"
#include "dataio.h"
#include "all_roles.h"
#include "screen.h"

void main() {
	vector<User> users;

	ReadStudentDataFromFile("student.csv", users);
	ReadLecturerDataFromFile("lecturer.csv", users);
	ReadStaffDataFromFile("staff.csv", users);
	//	cout << DateToStr(StrToDate("05/02/1923")) << endl;


	User currentUser, student;
	bool isLoggedIn = false;
	Screen currentScreen = HOME;

	while (true) {
		cout << "  Student Management System v1.0  " << endl;
		cout << "----------------------------------" << endl;
		if (currentScreen == EXIT) {
			break;
		}
		else if (currentScreen == HOME) {
			if (isLoggedIn == false) {
				ShowHomeScreen_Guest(currentUser, users, isLoggedIn, currentScreen, student);
				system("CLS");
			}
			else if (currentUser.password == PASSWORD_DEFAULT) {
				system("CLS");
				cout << "This is your first login. Please change your password to continue." << endl;
				ChangePassword(currentUser);
				for (int i = 0; i < users.size(); ++i) {
					if (currentUser.username == users[i].username) users[i].password = currentUser.password;
				}
			}
			else {
				ShowHomeScreen_User(currentUser, users, isLoggedIn, currentScreen, student);
				for (int i = 0; i < users.size(); ++i) {
					if (currentUser.username == users[i].username) users[i].password = currentUser.password;
				}
			}
		}
		else if (currentScreen == MENU) {
			if (currentUser.type == ACADEMIC_STAFF) {
				ShowMenuScreen_Staff(currentUser, users, isLoggedIn, currentScreen, student);
				for (int i = 0; i < users.size(); ++i) {
					if (users[i].username == student.username) users[i] = student;
				}
			}
			else if (currentUser.type == LECTURER) {
				ShowMenuScreen_Lecturer(currentUser, users, isLoggedIn, currentScreen, student);
			}
			else if (currentUser.type == STUDENT) {
				ShowMenuScreen_Student(currentUser, users, isLoggedIn, currentScreen, student);
			}
		}
	}

	ShowExitScreen(currentUser, users, isLoggedIn, currentScreen, student);

	WriteStudentDataToFile("test1.csv", users);
	WriteLecturerDataToFile("test2.csv", users);
	WriteStaffDataToFile("test3.csv", users);
}
