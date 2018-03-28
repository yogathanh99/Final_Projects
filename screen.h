/*
Header for all screen and menu showing function
*/

#include "sms.h"

#ifndef SCREEN_H
#define SCREEN_H

enum Screen {
	HOME,
	MENU,
	EXIT,
};

void ShowHomeScreen_Guest(User &currentUser, vector<User> &users, bool &isLoggedIn, Screen &currentScreen, User &student);

void ShowHomeScreen_User(User &currentUser, vector<User> &users, bool &isLoggedIn, Screen &currentScreen, User &student);

void ShowMenuScreen_Staff(User &currentUser, vector<User> &users, bool &isLoggedIn, Screen &currentScreen, User &student);

void ShowMenuScreen_Lecturer(User &currentUser, vector<User> &users, bool &isLoggedIn, Screen &currentScreen, User &student);

void ShowMenuScreen_Student(User &currentUser, vector<User> &users, bool &isLoggedIn, Screen &currentScreen, User &student);

void ShowExitScreen(User &currentUser, vector<User> &users, bool &isLoggedIn, Screen &currentScreen, User &student);
//bool checkInput(vector <User> &users);
void AddStudent(vector<User> &users);

void EditExistStudent(vector<User> &users);

void ChangeClassStudent(vector <User> &users);

void View_Class_List(vector<User> users);

void ViewStudentList(vector<User> users);

void RemoveStudent(vector<User> &users);
#endif // !SCREEN_H