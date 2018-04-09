/*
Header for use-cases of academic staff about schedule managing
*/

#ifndef STAFF_SCHEDULE_H
#define STAFF_SCHEDULE_H

#include "sms.h"

void ImportScheduleFromFile(const vector<Course> &courses, vector<Schedule> &schedules);

void AddASchedule(const vector<Course> &courses, vector<Schedule> &schedules);

#endif // STAFF_SCHEDULE_H