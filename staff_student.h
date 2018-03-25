/*
Header for use-cases of academic staff about student managing
*/

#include "sms.h"

#ifndef STAFF_STUDENT_H
#define STAFF_STUDENT_H

void importStudentsFromFile(string path, vector<User> &users);
bool checkInput(vector <User> &users);
void EditStudent(vector <User> &users, int count);
void ChangeClassStudent(vector <User> &users);
void View_Class_List(vector<User> users);
void Addemptyclass(vector <User> &users);
void ViewStudentList(vector<User> &users);


#endif // STAFF_STUDENT_H