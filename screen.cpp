/*
Implementation for all menu showing function
*/

#include "screen.h"
#include "all_roles.h"
#include "staff_students.h"
#include "staff_course.h"
#include "staff_schedule.h"
#include "staff_attendance.h"
#include "staff_score.h"
#include "lecturer.h"
#include "student.h"
#include "UI.h"

void ShowHomeScreen_Guest(User &currentUser, vector<User> &users, vector<Course> &courses, vector<Schedule> &schedules, vector<Presence> &presences, vector<Score> &scores, bool &isLoggedIn, Screen &currentScreen, User &student) {
	string action;
	textcolor(10);
	gotoxy(45, 10);
	cout << "1. Login" << endl;
	gotoxy(45, 11);
	cout << "0. Exit" << endl;
	gotoxy(45, 12);
	cout << "Please enter an action (0-1): ";
	getline(cin, action);

	if (action == "1") {
		Login(currentUser, users, isLoggedIn);
	}
	else if (action == "0") {
		currentScreen = EXIT;
	}
	else {
		gotoxy(45, 13);
		cout << "Entered action is not legit. Please try again." << endl;
		Pause(45,14);
	}
}

void ShowHomeScreen_User(User &currentUser, vector<User> &users, vector<Course> &courses, vector<Schedule> &schedules, vector<Presence> &presences, vector<Score> &scores, bool &isLoggedIn, Screen &currentScreen, User &student) {
	string action;
	gotoxy(45, 10);
	cout << "1. Show Menu" << endl;
	gotoxy(45, 11);
	cout << "2. View info" << endl;
	gotoxy(45, 12);
	cout << "3. Change password" << endl;
	gotoxy(45, 13);
	cout << "0. Logout" << endl;
	gotoxy(45, 14);
	cout << "Please enter an action (0-3): ";
	getline(cin, action);
	system("CLS");

	if (action == "1") {
		currentScreen = MENU;
	}
	else if (action == "2") {
		// View info
		ViewInfo(currentUser);
	}
	else if (action == "3") {
		// Change password
		system("CLS");
		ChangePassword(currentUser);
	}
	else if (action == "0") {
		isLoggedIn = false;
	}
	else {
		cout << "Entered action is not legit. Please try again." << endl;
		Pause(45,15);
	}
}

void ShowMenuScreen_Staff(User &currentUser, vector<User> &users, vector<Course> &courses, vector<Schedule> &schedules, vector<Presence> &presences, vector<Score> &scores, bool &isLoggedIn, Screen &currentScreen, User &student) {
	string action;
	textcolor(6);
	gotoxy(45, 10);
	cout << "1. Import students of a class from a csv file" << endl;
	gotoxy(45, 11);
	cout << "2. Add a new student to a class" << endl;
	gotoxy(45, 12);
	cout << "3. Edit an existing student" << endl;
	gotoxy(45, 13);
	cout << "4. Remove a student" << endl;
	gotoxy(45, 14);
	cout << "5. Change students from class A to class B" << endl;
	gotoxy(45, 15);
	cout << "6. Add a new empty class" << endl;
	gotoxy(45, 16);
	cout << "7. View list of classes" << endl;
	gotoxy(45, 17);
	cout << "8. View list of students in a class" << endl;
	gotoxy(45, 18);
	cout << endl;
	gotoxy(45, 19);
	cout << "9. Import courses from a csv file" << endl;
	gotoxy(45, 20);
	cout << "10. Add a new course" << endl;
	gotoxy(45, 21);
	cout << "11. Edit an existing course" << endl;
	gotoxy(45, 22);
	cout << "12. Remove a course" << endl;
	gotoxy(45, 23);
	cout << "13. View list of courses" << endl;
	gotoxy(45, 24);
	cout << endl;
	gotoxy(45, 25);
	cout << "14. Import courses' schedules from a csv file" << endl;
	gotoxy(45, 26);
	cout << "15. Add a course's schedule" << endl;
	gotoxy(45, 27);
	cout << "16. Edit a course's schedule" << endl;
	gotoxy(45, 28);
	cout << "17. Remove a course's schedule" << endl;
	gotoxy(45, 29);
	cout << "18. View list of schedules." << endl;
	gotoxy(45, 30);
	cout << endl;
	gotoxy(45, 31);
	cout << "19. Search and view attendance list of a course" << endl;
	gotoxy(45, 32);
	cout << "20. Export attendance list to a csv file" << endl;
	gotoxy(45, 33);
	cout << endl;
	gotoxy(45, 34);
	cout << "21. Search and view scoreboard of a course" << endl;
	gotoxy(45, 35);
	cout << "22. Export a scoreboard to a csv file" << endl;
	gotoxy(45, 36);
	cout << "0. Go back" << endl;
	gotoxy(45, 37);
	cout << "Please enter an action (0-22): ";
	getline(cin, action);

	textcolor(11);
	if (action == "1") {
		// Import students of a class from a csv file
		system("CLS");
		ImportStudentFromFile(users);
	}
	else if (action == "2") {
		// Add a new student to a class
		system("CLS");
		AddStudent(users);
	}
	else if (action == "3") {
		// Edit an existing student
		system("CLS");
		EditExistStudent(users);
	}
	else if (action == "4") {
		// Remove a student
		system("CLS");
		RemoveStudent(users);
	}
	else if (action == "5") {
		// Change students from class A to class B
		system("CLS");
		ChangeClassStudent(users);
	}
	else if (action == "6") {
		// Add a new empty class
		system("CLS");
		cout << "You can add a new class by adding a new student belong to that class." << endl;
		Pause(45,2);
	}
	else if (action == "7") {
		// View list of classes
		system("CLS");
		View_Class_List(users);
	}
	else if (action == "8") {
		// View list of students in a class
		system("CLS");
		ViewStudentList(users);
	}
	else if (action == "9") {
		// Import courses from a csv file
		system("CLS");
		ImportCourseFromFile(courses);
	}
	else if (action == "10") {
		// Add a new course
		system("CLS");
		AddCourse(courses);
	}
	else if (action == "11") {
		// Edit an existing course
		system("CLS");
		EditExistCourse(courses);
	}
	else if (action == "12") {
		// Remove a course
		system("CLS");
		RemoveCourse(courses);
	}
	else if (action == "13") {
		// View list of courses
		system("CLS");
		View_Courses_List(courses);
	}
	else if (action == "14") {
		// Import courses' schedules from a csv file
		system("CLS");
		ImportScheduleFromFile(courses, schedules);
	}
	else if (action == "15") {
		// Add a course's schedule
		system("CLS");
		AddASchedule(courses, schedules);
	}
	else if (action == "16") {
		// Edit a course's schedule
		system("CLS");
		EditASchedule(courses, schedules);
	}
	else if (action == "17") {
		// Remove a course's schedule
		system("CLS");
		RemoveASchedule(schedules);
	}
	else if (action == "18") {
		// View list of schedules
		system("CLS");
		ViewSchedulesStaff(schedules);
	}
	else if (action == "19") {
		// Search and view attendance list of a course
		system("CLS");
		//ImportAttendance(presences);
		SearchAndViewAttendance(presences);
	}
	else if (action == "20") {
		// Export attendance list to a csv file
		ExportAttendance(presences);
	}
	else if (action == "21") {
		// Search and view scoreboard of a course
		system("CLS");
		//ImportScore(scores);
		SearchAndViewScoreboard(scores);
	}
	else if (action == "22") {
		// Export a scoreboard to a csv file
		ExportScoreboard(scores);
	}
	else if (action == "0") {
		currentScreen = HOME;
	}
	else {
		cout << "Entered action is not legit. Please try again." << endl;
		Pause(45,38);
	}
}

void ShowMenuScreen_Lecturer(User &currentUser, vector<User> &users, vector<Course> &courses, vector<Schedule> &schedules, vector<Presence> &presences, vector<Score> &scores, bool &isLoggedIn, Screen &currentScreen, User &student) {
	string action;
	textcolor(6);
	gotoxy(45, 10);
	cout << "1. Import scoreboard of a course (midterm, final, lab, bonus)" << endl;
	gotoxy(45, 11);
	cout << "2. Edit grade of a student" << endl;
	gotoxy(45, 12);
	cout << "3. View a scoreboard" << endl;
	gotoxy(45, 13);
	cout << "0. Go back" << endl;
	gotoxy(45, 14);
	cout << "Please enter an action (0-3): ";
	getline(cin, action);

	textcolor(11);
	if (action == "1") {
		// Import scoreboard of a course (midterm, final, lab, bonus)
		system("CLS");
		ImportScoreboard(scores);
	}
	else if (action == "2") {
		// Edit grade of a studen
		system("CLS");
		Editgrade(scores);
	}
	else if (action == "3") {
		// View a scoreboard
		system("CLS");
		ViewScore(currentUser, courses, scores);
	}
	else if (action == "0") {
		currentScreen = HOME;
	}
	else {
		cout << "Entered action is not legit. Please try again." << endl;
		Pause(45,15);
	}
}

void ShowMenuScreen_Student(User &currentUser, vector<User> &users, vector<Course> &courses, vector<Schedule> &schedules, vector<Presence> &presences, vector<Score> &scores, bool &isLoggedIn, Screen &currentScreen, User &student) {
	string action;
	textcolor(14);
	gotoxy(45, 10);
	cout << "1. Check-in" << endl;
	gotoxy(45, 11);
	cout << "2. View check-in result" << endl;
	gotoxy(45, 12);
	cout << "3. View your scores of a course" << endl;
	gotoxy(45, 13);
	cout << "4. View schedules" << endl;
	gotoxy(45, 14);
	cout << "0. Go back" << endl;
	gotoxy(45, 15);
	cout << "Please enter an action (0-4): ";
	getline(cin, action);

	textcolor(11);
	if (action == "1") {
		// Check-in
		system("CLS");
		CheckIn(currentUser, courses, presences);
	}
	else if (action == "2") {
		// View check-in result
		system("CLS");
		ViewCheckInResult(currentUser, presences);
	}
	else if (action == "3") {
		// View student's scores of a course
		system("CLS");
		ViewScore(currentUser, scores);
	}
	else if (action == "4") {
		// View schedules
		system("CLS");
		ViewScheduleStudent(currentUser, schedules);
	}
	else if (action == "0") {
		currentScreen = HOME;
	}
	else {
		cout << "Entered action is not legit. Please try again." << endl;
		Pause(45,16);
	}
}

void ShowExitScreen(User &currentUser, vector<User> &users, vector<Course> &courses, vector<Schedule> &schedules, vector<Presence> &presences, vector<Score> &scores, bool &isLoggedIn, Screen &currentScreen, User &student) {
	textcolor(10);
	gotoxy(47, 10);
	cout << "Thanks for using the software!" << endl;
}
