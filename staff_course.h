/*
Header for use-cases of academic staff about course managing
*/

#ifndef STAFF_COURSE_H
#define STAFF_COURSE_H

#include "sms.h"
#include "misc.h"

void ImportCourseFromFile(vector<Course> &courses);

void RemoveCourse(vector<Course> &courses);

void AddCourse(vector<Course> &courses);

void EditExistCourse(vector<Course> &courses);

void View_Courses_List(vector <Course> &courses);

#endif // STAFF_COURSE_H