/*
Header for use-cases of student
*/

#include "sms.h"
#include "misc.h"

#ifndef STUDENT_H
#define STUDENT_H

void CheckIn(User currentUser, vector<Course> courses, vector<Presence> &presences);

void ViewCheckInResult(User currentUser, vector<Presence> &presences);

void ViewScore(User currentUser, vector<Score> &scores);

void ViewScheduleStudent(User currentUser, vector<Schedule> &schedules);

#endif // STUDENT_H