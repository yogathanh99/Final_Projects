#include "sms.h"
#include "dataio.h"
#include "all_roles.h"
#include "screen.h"
#include "misc.h"

void main() {
	vector<User> users;
	vector<Course> courses;
	vector<Schedule> schedules;
	vector<Presence> presences;
	vector<Score> scores;

	ReadStudentDataFromFile("student.csv", users);
	ReadLecturerDataFromFile("lecturer.csv", users);
	ReadStaffDataFromFile("staff.csv", users);
	ReadCourseDataFromFile("course.csv", courses);
	ReadScheduleDataFromFile("schedule.csv", schedules);
	ReadPresenceDataFromFile("presence.csv", presences);
	ReadScoreDataFromFile("score.csv", scores);

	WriteStudentDataToFile("Backup/student.csv", users);
	WriteLecturerDataToFile("Backup/lecturer.csv", users);
	WriteStaffDataToFile("Backup/staff.csv", users);
	WriteCourseDataToFile("Backup/course.csv", courses);
	WriteScheduleDataToFile("Backup/schedule.csv", schedules);
	WritePresenceDataToFile("Backup/presence.csv", presences);
	WriteScoreDataToFile("Backup/score.csv", scores);


	//ofstream fout;
	//fout.open("text.txt");
	//if (fout.is_open()) {
	//	SHA1 checksum;
	//	checksum.update("abc");
	//	fout << "123: " << checksum.final() << endl;
	//	checksum.update(PASSWORD_DEFAULT);
	//	fout << PASSWORD_DEFAULT << ": " << checksum.final() << endl;
	//}
	//fout.close();

	//ReadStudentDataFromFile("test1.csv", users);
	//ReadLecturerDataFromFile("test2.csv", users);
	//ReadStaffDataFromFile("test3.csv", users);
	//ReadCourseDataFromFile("test4.csv", courses);

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
				ShowHomeScreen_Guest(currentUser, users, courses, schedules, presences, scores, isLoggedIn, currentScreen, student);
			}
			else if (currentUser.password == getHash(PASSWORD_DEFAULT)) {
				cout << "This is your first login. Please change your password to continue." << endl;
				ChangePassword(currentUser);
				for (int i = 0; i < users.size(); ++i) {
					if (currentUser.username == users[i].username) users[i].password = currentUser.password;
				}
			}
			else {
				ShowHomeScreen_User(currentUser, users, courses, schedules, presences, scores, isLoggedIn, currentScreen, student);
				for (int i = 0; i < users.size(); ++i) {
					if (currentUser.username == users[i].username) users[i].password = currentUser.password;
				}
			}
		}
		else if (currentScreen == MENU) {
			if (currentUser.type == ACADEMIC_STAFF) {
				ShowMenuScreen_Staff(currentUser, users, courses, schedules, presences, scores, isLoggedIn, currentScreen, student);
				for (int i = 0; i < users.size(); ++i) {
					if (users[i].username == student.username) users[i] = student;
				}
			}
			else if (currentUser.type == LECTURER) {
				ShowMenuScreen_Lecturer(currentUser, users, courses, schedules, presences, scores, isLoggedIn, currentScreen, student);
			}
			else if (currentUser.type == STUDENT) {
				ShowMenuScreen_Student(currentUser, users, courses, schedules, presences, scores, isLoggedIn, currentScreen, student);
			}
		}
	}

	WriteStudentDataToFile("student.csv", users);
	WriteLecturerDataToFile("lecturer.csv", users);
	WriteStaffDataToFile("staff.csv", users);
	WriteCourseDataToFile("course.csv", courses);
	WriteScheduleDataToFile("schedule.csv", schedules);
	WritePresenceDataToFile("presence.csv", presences);
	WriteScoreDataToFile("score.csv", scores);

	ShowExitScreen(currentUser, users, courses, schedules, presences, scores, isLoggedIn, currentScreen, student);
}
