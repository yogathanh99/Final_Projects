/*
Implementation for all menu showing function
*/

#include "screen.h"
#include "all_roles.h"

void ShowHomeScreen_Guest(User &currentUser, vector<User> &users, bool &isLoggedIn, Screen &currentScreen, User &student) {
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
	}
}

void ShowHomeScreen_User(User &currentUser, vector<User> &users, bool &isLoggedIn, Screen &currentScreen, User &student) {
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
		for (int i = 0; i < users.size(); ++i) {
			if (users[i].username == currentUser.username) {
				system("CLS");
				cout << "ID: " << users[i].username << endl;
				cout << "Name: " << users[i].fullName << endl;
				cout << "Email: " << users[i].email << endl;
				cout << "Phone: " << users[i].mobilePhone << endl;
				if (users[i].type == 0) cout << "Class: " << users[i]._class << endl;
				cout << "Type: ";
				if (users[i].type == 0) cout << "Student" << endl;
				else if (users[i].type == 1) cout << "Academic staff" << endl;
				else cout << "Lecturer" << endl;
				cout << endl;
			}
		}
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
		system("CLS");
	}
}

void ShowMenuScreen_Staff(User &currentUser, vector<User> &users, bool &isLoggedIn, Screen &currentScreen, User &student) {
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
	}
	else if (action == "10") {
		// Add a new course
	}
	else if (action == "11") {
		// Edit an existing course
	}
	else if (action == "12") {
		// Remove a course
	}
	else if (action == "13") {
		// View list of courses
	}
	else if (action == "14") {
		// Import courses' schedules from a csv file
	}
	else if (action == "15") {
		// Add a course's schedule
	}
	else if (action == "16") {
		// Edit a course's schedule
	}
	else if (action == "17") {
		// Remove a course's schedule
	}
	else if (action == "18") {
		// View list of schedules
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
	}
}

void ShowMenuScreen_Lecturer(User &currentUser, vector<User> &users, bool &isLoggedIn, Screen &currentScreen, User &student) {
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
	}
}

void ShowMenuScreen_Student(User &currentUser, vector<User> &users, bool &isLoggedIn, Screen &currentScreen, User &student) {
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
	}
}

void ShowExitScreen(User &currentUser, vector<User> &users, bool &isLoggedIn, Screen &currentScreen, User &student) {
	cout << "Thanks for using the software!" << endl;
}

void AddStudent(vector<User> &users) {
	User student;
	cout << "Input class: ";
	getline(cin, student._class);
	cout << "Input usersname: ";
	getline(cin, student.username);
	cout << "Input fullname: ";
	getline(cin, student.fullName); 
	cout << "Input email: ";
	getline(cin, student.email);
	cout << "Input mobile phone: ";
	getline(cin, student.mobilePhone);
	cout << "Input password: ";
	getline(cin, student.password);
	student.type = STUDENT;
	users.push_back(student);
}

void EditExistStudent(vector<User> &users) {
	int pick;
	string fullname, _class, mail, phone, password, ID;

	cout << "ID student: ";
	getline(cin, ID);
	bool check = false;
	int i;
	for (i = 0; i < users.size(); ++i)
	{
		if (users[i].username == ID && users[i].type == STUDENT) {
			check = true;
			break;
		}
	}

	if (check) {
		cout << "0. Change full name: ";
		cout << "\n1. Change email: ";
		cout << "\n2. Change mobile phone: ";
		cout << "\n3. Change password: ";
		cout << "\n4. Change class: ";

		cout << "\nWhat do you want to change: ";
		cin >> pick;

		if (pick == 0) {
			cin.ignore(1000, '\n');
			cout << "Input new full name: ";
			getline(cin, fullname);
			users[i].fullName = fullname;
			cout << "Changed successful" << endl;
			cin.ignore(1000, '\n');
		}

		else if (pick == 1) {
			cin.ignore(1000, '\n');
			cout << "Input new mail: ";
			getline(cin, mail);
			users[i].email = mail;
			cout << "Changed Successfull" << endl;
			cin.ignore(1000, '\n');
		}
		else if (pick == 2) {
			cin.ignore(1000, '\n');
			cout << "Input mobile phone: ";
			getline(cin, phone);
			users[i].mobilePhone = phone;
			cout << "Changed Successfull" << endl;
			cin.ignore(1000, '\n');
		}
		else if (pick == 3) {
			cin.ignore(1000, '\n');
			cout << "Input new password: ";
			getline(cin, password);
			users[i].password = password;
			cout << "Changed Successfull" << endl;
			cin.ignore(1000, '\n');
		}
		else if (pick == 4) {
			cin.ignore(1000, '\n');
			cout << "Input new class: ";
			getline(cin, _class);
			users[i]._class = _class;
			cout << "Changed Successfull" << endl;
			cin.ignore(1000, '\n');
		}
		else
			cout << "Invaild: " << endl;
	}
}

void ChangeClassStudent(vector <User> &users)
{
	int pick;
	int i = 0;
	string id, _class;

	cout << "0. Do not move student: ";
	cout << "\n1. Move all students:  ";
	cout << "\n2. Move a student: ";

	cout << "\nWhat do you want to pick: ";
	cin >> pick;
	cin.ignore(1000, '\n');

	if (pick == 0) {
		cout << "Do not move students: " << endl;
		cin.ignore(1000,'\n');
	}
	else if (pick == 1) {
		cout << "Input old class: ";
		string _oldclass;
		getline(cin, _oldclass);
		cout << "Input new class: ";
		getline(cin, _class);
		for (int i = 0; i < users.size(); ++i)
			if (users[i]._class == _oldclass) users[i]._class = _class;
		cout << "Changed successfull" << endl;
		cin.ignore(1000, '\n');
	}
	else if (pick == 2)
	{
		string ID;
		cout << "ID student: ";
		getline(cin, ID);
		bool check = false;
		int i;
		for (i = 0; i < users.size(); ++i)
		{
			if (users[i].username == ID && users[i].type == STUDENT)
			{
				check = true;
				break;
			}
		}
		if (check) {
			cout << "Input new class:"; 
			getline(cin, _class);
			users[i]._class = _class;
			cout << "Changed successfull" << endl;
			cin.ignore(1000, '\n');
		}
	}
}

void RemoveStudent(vector<User> &users) {
	string ID;
	cout << "Input ID: ";
	getline(cin, ID);
	for (int i = 0; i < users.size(); ++i) {
		if (users[i].username == ID) users.erase(users.begin() + i);
	}
	cout << "Changed successfull" << endl;
}

void View_Class_List(vector<User> users)
{
	int i;
	for (i = 0; i < users.size(); i++)
	{
		if (users[i].type==STUDENT) cout << "Class: " << users[i]._class<<endl;
	}
	cin.ignore(1000, '\n');
}

void ViewStudentList(vector<User> users)
{
	string _class;
	int i = 0;

	cout << "Input class: ";
	getline(cin, _class);

	for (int i = 0; i < users.size(); i++) {
		if (_class == users[i]._class)
			cout << users[i].username << " " << users[i].fullName << endl;
	}
	cin.ignore(1000, '\n');
}