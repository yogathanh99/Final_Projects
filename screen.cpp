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

void ShowHomeScreen_Guest(User &currentUser, vector<User> &users, vector<Course> &courses, vector<Schedule> &schedules, vector<Presence> &presences, vector<Score> &scores, bool &isLoggedIn, Screen &currentScreen, User &student) {
	string action;

	cout << "1. Login" << endl;
	cout << "0. Exit" << endl;
	cout << "Please enter an action (0-1): ";
	getline(cin, action);

	if (action == "1") {
		Login(currentUser, users, isLoggedIn);
	}
	else if (action == "0") {
		currentScreen = EXIT;
	}
	else {
		cout << "Entered action is not legit. Please try again." << endl;
		Pause();
	}
}

void ShowHomeScreen_User(User &currentUser, vector<User> &users, vector<Course> &courses, vector<Schedule> &schedules, vector<Presence> &presences, vector<Score> &scores, bool &isLoggedIn, Screen &currentScreen, User &student) {
	string action;
	cout << "1. Show Menu" << endl;
	cout << "2. View info" << endl;
	cout << "3. Change password" << endl;
	cout << "0. Logout" << endl;
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
		Pause();
	}
}

void ShowMenuScreen_Staff(User &currentUser, vector<User> &users, vector<Course> &courses, vector<Schedule> &schedules, vector<Presence> &presences, vector<Score> &scores, bool &isLoggedIn, Screen &currentScreen, User &student) {
	string action;
	cout << "1. Import students of a class from a csv file" << endl;
	cout << "2. Add a new student to a class" << endl;
	cout << "3. Edit an existing student" << endl;
	cout << "4. Remove a student" << endl;
	cout << "5. Change students from class A to class B" << endl;
	cout << "6. Add a new empty class" << endl;
	cout << "7. View list of classes" << endl;
	cout << "8. View list of students in a class" << endl;
	cout << endl;
	cout << "9. Import courses from a csv file" << endl;
	cout << "10. Add a new course" << endl;
	cout << "11. Edit an existing course" << endl;
	cout << "12. Remove a course" << endl;
	cout << "13. View list of courses" << endl;
	cout << endl;
	cout << "14. Import courses' schedules from a csv file" << endl;
	cout << "15. Add a course's schedule" << endl;
	cout << "16. Edit a course's schedule" << endl;
	cout << "17. Remove a course's schedule" << endl;
	cout << "18. View list of schedules." << endl;
	cout << endl;
	cout << "19. Search and view attendance	list of a course" << endl;
	cout << "20. Export attendance list to a csv file" << endl;
	cout << endl;
	cout << "21. Search and view scoreboard	of a course" << endl;
	cout << "22. Export a scoreboard to a csv file" << endl;
	cout << "0. Go back" << endl;
	cout << "Please enter an action (0-22): ";
	getline(cin, action);

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
		Pause();
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
		ViewSchedules(schedules);
	}
	else if (action == "19") {
		// Search and view attendance list of a course
	}
	else if (action == "20") {
		// Export attendance list to a csv file
	}
	else if (action == "21") {
		// Search and view scoreboard of a course
	}
	else if (action == "22") {
		// Export a scoreboard to a csv file
	}
	else if (action == "0") {
		currentScreen = HOME;
	}
	else {
		cout << "Entered action is not legit. Please try again." << endl;
		Pause();
	}
}

void ShowMenuScreen_Lecturer(User &currentUser, vector<User> &users, vector<Course> &courses, vector<Schedule> &schedules, vector<Presence> &presences, vector<Score> &scores, bool &isLoggedIn, Screen &currentScreen, User &student) {
	string action;

	cout << "1. Import scoreboard of a course (midterm, final, lab, bonus)" << endl;
	cout << "2. Edit grade of a student" << endl;
	cout << "3. View a scoreboard" << endl;
	cout << "0. Go back" << endl;
	cout << "Please enter an action (0-3): ";
	getline(cin, action);

	if (action == "1") {
		// Import scoreboard of a course (midterm, final, lab, bonus)
	}
	else if (action == "2") {
		// Edit grade of a student
	}
	else if (action == "3") {
		// View a scoreboard
	}
	else if (action == "0") {
		currentScreen = HOME;
	}
	else {
		cout << "Entered action is not legit. Please try again." << endl;
		Pause();
	}
}

void ShowMenuScreen_Student(User &currentUser, vector<User> &users, vector<Course> &courses, vector<Schedule> &schedules, vector<Presence> &presences, vector<Score> &scores, bool &isLoggedIn, Screen &currentScreen, User &student) {
	string action;

	cout << "1. Check-in" << endl;
	cout << "2. View check-in result" << endl;
	cout << "3. View your scores of a course" << endl;
	cout << "4. View schedules" << endl;
	cout << "0. Go back" << endl;
	cout << "Please enter an action (0-4): ";
	getline(cin, action);

	if (action == "1") {
		// Check-in
	}
	else if (action == "2") {
		// View check-in result
	}
	else if (action == "3") {
		// View student's scores of a course
	}
	else if (action == "4") {
		// View schedules
	}
	else if (action == "0") {
		currentScreen = HOME;
	}
	else {
		cout << "Entered action is not legit. Please try again." << endl;
		Pause();
	}
}

void ShowExitScreen(User &currentUser, vector<User> &users, vector<Course> &courses, vector<Schedule> &schedules, vector<Presence> &presences, vector<Score> &scores, bool &isLoggedIn, Screen &currentScreen, User &student) {
	cout << "Thanks for using the software!" << endl;
}
