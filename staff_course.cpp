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
		Pause(45,3);
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

		if (course.courseCode != "") {
			courses.push_back(course);
			++courseCount;
		}
	}

	fin.close();

	cout << "Succesfully imported " << courseCount << " new courses." << endl;
	Pause(45,3);
}

void RemoveCourse(vector<Course> &courses)
{
	string x, y, tmp;
	int z;
	cout << "Input a Course code that you want to remove: ";
	getline(cin, x);
	cout << "Input a year: ";
	getline(cin, y);
	cout << "Input semester: ";
	getline(cin, tmp);
	z = StrToInt(tmp);

	for (int i = 0; i < courses.size(); i++)
	{
		if (courses[i].courseCode == x && courses[i].year == y && courses[i].semester == z)
		{
			courses.erase(courses.begin() + i);
			cout << "Remove successfully" << endl;
			Pause(45,5);
			break;
		}
	}

	cout << "Can not find course with given course code, year and semester." << endl;
	Pause(45,5);
}

void AddCourse(vector<Course> &courses) {
	Course newcourse;
	cout << "Input course code: ";
	getline(cin, newcourse.courseCode);
	cout << "Input year: ";
	getline(cin, newcourse.year);
	cout << "Input semester: ";
	cin >> newcourse.semester;
	cin.ignore(1000, '\n');
	cout << "Input course name: ";
	getline(cin, newcourse.courseName);
	cout << "Input lecturer username: ";
	getline(cin, newcourse.lecturerUsername);

	for (int i = 0; i < courses.size(); ++i) {
		if ((newcourse.courseCode == courses[i].courseCode && newcourse.lecturerUsername == courses[i].lecturerUsername)
			|| (newcourse.courseName == courses[i].courseName && newcourse.lecturerUsername == courses[i].lecturerUsername))
		{
			cout << "Course has already have" << endl;
			Pause(45,7);
			return;
		}
	}

	courses.push_back(newcourse);
	cout << "Add succesfully" << endl;
	Pause(45,7);
}

void EditExistCourse(vector<Course> &courses) {
	cout << "Input course code: ";
	string code;
	getline(cin, code);
	cout << "Input year: ";
	string year;
	getline(cin, year);
	cout << "Input semester: ";
	string tmp;
	getline(cin, tmp);
	int semester = StrToInt(tmp);

	bool check = false;
	int pick, i, new_semester;
	string newyear, new_name_course, new_lecturer;

	for (i = 0; i < courses.size(); ++i) {
		if (courses[i].courseCode == code && courses[i].year == year && courses[i].semester == semester) {
			check = true;
			break;
		}
	}

	if (check) {
		cout << "0. Change year";
		cout << "\n1. Change semester";
		cout << "\n2. Change course name";
		cout << "\n3. Change lecturer username";

		cout << "\nWhat do you want to change: ";
		cin >> pick;
		cin.ignore(1000, '\n');
		switch (pick) {
		case 0:
			cout << "Input new year: ";
			getline(cin, newyear);
			courses[i].year = newyear;
			cout << "Changed successfully" << endl;
			Pause(45,12);
			break;
		case 1:
			cout << "Input new semester: ";
			cin >> new_semester;
			courses[i].semester = new_semester;
			cin.ignore(1000, '\n');
			cout << "Changed successfully" << endl;
			Pause(45,12);
			break;
		case 2:
			cout << "Input new course name: ";
			getline(cin, new_name_course);
			courses[i].courseName = new_name_course;
			cout << "Changed successfully" << endl;
			Pause(45,12);
			break;
		case 3:
			cout << "Input new lecturer username: ";
			getline(cin, new_lecturer);
			courses[i].lecturerUsername = new_lecturer;
			cout << "Changed successfully" << endl;
			Pause(45,12);
			break;
		default:
			cout << "Invalid" << endl;
			Pause(45,11);
			break;
		}
	}
	else {
		cout << "Sorry. Course don't have" << endl;
		Pause(45,11);
	}
}

void View_Courses_List(vector <Course> &courses)
{
	int i;
	for (i = 0; i < courses.size(); i++)
		cout << courses[i].courseCode << " " << courses[i].year << " " << courses[i].semester << " " << courses[i].courseName << " " << courses[i].lecturerUsername << " " << endl;
	Pause(45,1+courses.size());
}