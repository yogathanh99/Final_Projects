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

void ShowHomeScreen_Guest(User &currentUser, vector<User> users, bool &isLoggedIn, Screen &currentScreen);

void ShowHomeScreen_User(User &currentUser, vector<User> users, bool &isLoggedIn, Screen &currentScreen);

void ShowMenuScreen_Staff(User &currentUser, vector<User> users, bool &isLoggedIn, Screen &currentScreen);

void ShowMenuScreen_Lecturer(User &currentUser, vector<User> users, bool &isLoggedIn, Screen &currentScreen);

void ShowMenuScreen_Student(User &currentUser, vector<User> users, bool &isLoggedIn, Screen &currentScreen);

void ShowExitScreen(User &currentUser, vector<User> users, bool &isLoggedIn, Screen &currentScreen);

#endif // !SCREEN_H