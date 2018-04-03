/*
Header for common use-cases of all roles
*/

#include "sms.h"

#ifndef ALL_ROLES_H
#define ALL_ROLES_H

// Login
void Login(User &currentUser, vector<User> users, bool &loginSuccessful);

// Change user's password
void ChangePassword(User &currentUser);

//View information of current user
void ViewInfo(User &currentUser);

#endif // ALL_ROLES_H