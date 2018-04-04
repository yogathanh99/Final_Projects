/*
Implementation for use-cases of academic staff about course managing
*/

#include "staff_course.h"

void ImportCourseFromFile(vector<Course> &courses) {
	string path;
	cout << "Enter the csv file path: ";
	getline(cin, path, '\n');

	ifstream fin;
	fin.open(path);
	if (!fin.is_open()) {
		cout << "No csv file with such path was found. Please try again." << endl;
		Pause();
		return;
	}

	int courseCount = 0;
	string tmp;
	getline(fin, tmp, '\n');
	while (!fin.eof()) {
		Course course;

		getline(fin, course.courseCode, ',');
		getline(fin, course.year, ',');
		getline(fin, tmp, ',');
		course.semester = StrToInt(tmp);
		getline(fin, course.courseName, ',');
		getline(fin, course.lecturerUsername, '\n');
		
		course.isAvailable = false;

		if (course.courseCode != "") {
			courses.push_back(course);
			++courseCount;
		}
	}

	fin.close();

	cout << "Succesfully imported " << courseCount << " new courses." << endl;
	Pause();
}
