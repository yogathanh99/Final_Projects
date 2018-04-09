/*
Data structures Library
*/

#ifndef SMS_H
#define SMS_H

#include <iostream> 
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

const string PASSWORD_DEFAULT = "password";

enum UserTypes
{
	STUDENT,
	ACADEMIC_STAFF,
	LECTURER
};

enum DaysOfWeek
{
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
	SUNDAY
};

struct Date
{
	int day;
	int month;
	int year;
	bool inline operator < (const Date &rhs) const {

	}
};

struct Time
{
	int hours;
	int minutes;
};

struct User
{
	string username;
	string fullName;
	string email;
	string mobilePhone;
	UserTypes type;
	string password;
	string _class;
};

struct Course
{
	string courseCode;
	string year;
	int semester;
	string courseName;
	string lecturerUsername;
};

struct Schedule {
	string courseCode;
	string year;
	int semester;
	string _class;
	Date startAt;
	Date endAt;
	Time from;
	Time to;
	DaysOfWeek daysOfWeek;
};

struct Presence
{
	string courseCode;
	string year;
	int semester;
	string studentId;
	int week;
};

struct Score
{
	string courseCode;
	string year;
	int semester;
	string studentId;
	double midtermScore;
	double labScore;
	double finalScore;
	double totalScore;
};

#endif // !SMS_H
