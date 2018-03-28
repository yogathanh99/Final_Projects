/*
Header for student management
*/

#include "sms.h"

#ifndef STAFF_STUDENTS_H
#define STAFF_STUDENTS_H

void ImportStudentFromFile(string path, vector<User> &users);
void OutputStudentToAnotherFile(string path, vector<User> users);

void AddStudent(vector<User> &users);

void EditExistStudent(vector<User> &users);

void ChangeClassStudent(vector <User> &users);

void View_Class_List(vector<User> users);

void ViewStudentList(vector<User> users);

void RemoveStudent(vector<User> &users);

#endif // !STAFF_STUDENTS_H
