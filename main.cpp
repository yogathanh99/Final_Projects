#include "sms.h"
#include "dataio.h"
#include "all_roles.h"
#include "screen.h"

void main() {
	vector<User> users;
	vector<Course> courses;

	ReadStudentDataFromFile("student.csv", users);
	ReadLecturerDataFromFile("lecturer.csv", users);
	ReadStaffDataFromFile("staff.csv", users);
	ReadCourseDataFromFile("course.csv", courses);

	User currentUser, student;
	bool isLoggedIn = false;
	Screen currentScreen = HOME;

	while (true) {
		system("CLS");
		cout << "  Student Management System v1.0  " << endl;
		cout << "----------------------------------" << endl;
		if (currentScreen == EXIT) {
			break;
		}
		else if (currentScreen == HOME) {
			if (isLoggedIn == false) {
				ShowHomeScreen_Guest(currentUser, users, courses, isLoggedIn, currentScreen, student);
			}
			else if (currentUser.password == PASSWORD_DEFAULT) {
				cout << "This is your first login. Please change your password to continue." << endl;
				ChangePassword(currentUser);
				for (int i = 0; i < users.size(); ++i) {
					if (currentUser.username == users[i].username) users[i].password = currentUser.password;
				}
			}
			else {
				ShowHomeScreen_User(currentUser, users, courses, isLoggedIn, currentScreen, student);
				for (int i = 0; i < users.size(); ++i) {
					if (currentUser.username == users[i].username) users[i].password = currentUser.password;
				}
			}
		}
		else if (currentScreen == MENU) {
			if (currentUser.type == ACADEMIC_STAFF) {
				ShowMenuScreen_Staff(currentUser, users, courses, isLoggedIn, currentScreen, student);
				for (int i = 0; i < users.size(); ++i) {
					if (users[i].username == student.username) users[i] = student;
				}
			}
			else if (currentUser.type == LECTURER) {
				ShowMenuScreen_Lecturer(currentUser, users, courses, isLoggedIn, currentScreen, student);
			}
			else if (currentUser.type == STUDENT) {
				ShowMenuScreen_Student(currentUser, users, courses, isLoggedIn, currentScreen, student);
			}
		}
	}

	ShowExitScreen(currentUser, users, courses, isLoggedIn, currentScreen, student);

	WriteStudentDataToFile("test1.csv", users);
	WriteLecturerDataToFile("test2.csv", users);
	WriteStaffDataToFile("test3.csv", users);
	WriteCourseDataToFile("test4.csv", courses);
}
