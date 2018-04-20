/*
Header for use-cases of academic staff about attendance managing
*/

#ifndef STAFF_ATTENDANCE_H
#define STAFF_ATTENDANCE_H

#include "misc.h"
#include "sms.h"

void ImportAttendance(vector<Presence> &presences);
void SearchAndViewAttendance(vector<Presence> presences);
void ExportAttendance(vector<Presence> presences);

#endif // STAFF_ATTENDANCE_H