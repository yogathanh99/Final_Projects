/*
Header for student management
*/

#include "sms.h"

#ifndef STAFF_STUDENTS_H
#define STAFF_STUDENTS_H

void ImportStudentFromFile(char path[], vector<User> &users);
void OutputStudentToAnotherFile(char path[], vector<User> users);
#endif // !STAFF_STUDENTS_H
