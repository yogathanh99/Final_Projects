/*
Header for student management
*/

#include "sms.h"

#ifndef STAFF_STUDENTS_H
#define STAFF_STUDENTS_H

void ImportStudentFromFile(string path, vector<User> &users);
void OutputStudentToAnotherFile(string path, vector<User> users);

#endif // !STAFF_STUDENTS_H
