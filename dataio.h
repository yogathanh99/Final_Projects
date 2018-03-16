/*
Header for data reading and writing
*/

#include "sms.h"

#ifndef DATABASE_H
#define DATABASE_H

void ReadStudentDataFromFile(string path, vector<User> &users);

void ReadLecturerDataFromFile(string path, vector<User> &users);

void ReadStaffDataFromFile(string path, vector<User> &users);

void ReadCourseDataFromFile(string path, vector<Course> &courses);

void ReadPresenceDataFromFile(string path, vector<Presence> &presences);

void ReadScoreDataFromFile(string path, vector<Score> &score);

void WriteStudentDataToFile(string path, vector<User> &users);

void WriteLecturerDataToFile(string path, vector<User> &users);

void WriteStaffDataToFile(string path, vector<User> &users);

void WriteCourseDataToFile(string path, vector<Course> &courses);

void WritePresenceDataToFile(string path, vector<Presence> &presences);

void WriteScoreDataToFile(string path, vector<Score> &score);

#endif // DATABASE_H