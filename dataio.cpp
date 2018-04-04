/*
Implementation for data reading and writing
*/

#include "dataio.h"
#include "misc.h"

void ReadStudentDataFromFile(string path, vector<User> &users) {
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
		return;

	while (!fin.eof()) {
		User student;
		getline(fin, student.username, ',');
		getline(fin, student.fullName, ',');
		getline(fin, student.email, ',');
		getline(fin, student.mobilePhone, ',');
		getline(fin, student.password, ',');
		getline(fin, student._class, '\n');
		student.type = STUDENT;
		
		if (student.username != "")
			users.push_back(student);
	}

	fin.close();
}

void ReadLecturerDataFromFile(string path, vector<User> &users) {
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
		return;

	while (!fin.eof()) {
		User lecturer;
		getline(fin, lecturer.username, ',');
		getline(fin, lecturer.fullName, ',');
		getline(fin, lecturer.email, ',');
		getline(fin, lecturer.mobilePhone, ',');
		getline(fin, lecturer.password, '\n');
		lecturer.type = LECTURER;

		if (lecturer.username != "")
			users.push_back(lecturer);
	}

	fin.close();
}

void ReadStaffDataFromFile(string path, vector<User> &users) {
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
		return;

	while (!fin.eof()) {
		User staff;
		getline(fin, staff.username, ',');
		getline(fin, staff.fullName, ',');
		getline(fin, staff.email, ',');
		getline(fin, staff.mobilePhone, ',');
		getline(fin, staff.password, '\n');
		staff.type = ACADEMIC_STAFF;

		if (staff.username != "")
			users.push_back(staff);
	}

	fin.close();
}

/* Unfinished
void ReadCourseDataFromFile(string path, vector<Course> &courses) {
ifstream fin;
fin.open(path);
if (!fin.is_open())
return;

while (!fin.eof()) {
Course course;
getline(fin, course.courseCode, ',');
getline(fin, course.year, ',');
int x =
getline(fin, course.email, ',');
getline(fin, staff.mobilePhone, ',');
getline(fin, staff.password, '\n');
staff.type = ACADEMIC_STAFF;

users.push_back(staff);
}

fin.close();
}
*/

void ReadCourseDataFromFile(string path, vector<Course> &courses) {
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
		return;

	string tmp;
	while (!fin.eof()) {
		Course course;

		getline(fin, course.courseCode, ',');
		getline(fin, course.year, ',');
		getline(fin, tmp, ',');
		course.semester = StrToInt(tmp);
		getline(fin, course.courseName, ',');
		getline(fin, course.lecturerUsername, ',');

		getline(fin, tmp, ',');
		course.startAt = StrToDate(tmp);
		getline(fin, tmp, ',');
		course.endAt = StrToDate(tmp);
		getline(fin, tmp, ',');
		course.from = StrToTime(tmp);
		getline(fin, tmp, ',');
		course.to = StrToTime(tmp);
		getline(fin, tmp, ',');
		course.daysOfWeek = StrToDow(tmp);
		getline(fin, tmp, '\n');
		course.isAvailable = StrToBool(tmp);

		if (course.courseCode != "") 
			courses.push_back(course);
	}

	fin.close();
}

void ReadPresenceDataFromFile(string path, vector<Presence> &presences);

void ReadScoreDataFromFile(string path, vector<Score> &score);

void WriteStudentDataToFile(string path, vector<User> &users) {
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
		return;

	for (int i = 0; i < users.size(); ++i) {
		if (users[i].type == STUDENT) {
			fout << users[i].username << ',';
			fout << users[i].fullName << ',';
			fout << users[i].email << ',';
			fout << users[i].mobilePhone << ',';
			fout << users[i].password << ',';
			fout << users[i]._class << endl;
		}
	}

	fout.close();
}

void WriteLecturerDataToFile(string path, vector<User> &users) {
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
		return;

	for (int i = 0; i < users.size(); ++i) {
		if (users[i].type == LECTURER) {
			fout << users[i].username << ',';
			fout << users[i].fullName << ',';
			fout << users[i].email << ',';
			fout << users[i].mobilePhone << ',';
			fout << users[i].password << endl;
		}
	}

	fout.close();
}

void WriteStaffDataToFile(string path, vector<User> &users) {
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
		return;

	for (int i = 0; i < users.size(); ++i) {
		if (users[i].type == ACADEMIC_STAFF) {
			fout << users[i].username << ',';
			fout << users[i].fullName << ',';
			fout << users[i].email << ',';
			fout << users[i].mobilePhone << ',';
			fout << users[i].password << endl;
		}
	}

	fout.close();
}

void WriteCourseDataToFile(string path, vector<Course> &courses) {
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
		return;

	for (int i = 0; i < courses.size(); ++i) {
		fout << courses[i].courseCode << ",";
		fout << courses[i].year << ",";
		fout << courses[i].semester << ",";
		fout << courses[i].courseName << ",";
		fout << courses[i].lecturerUsername << ",";
		fout << DateToStr(courses[i].startAt) << ",";
		fout << DateToStr(courses[i].endAt) << ",";
		fout << TimeToStr(courses[i].from) << ",";
		fout << TimeToStr(courses[i].to) << ",";
		fout << DowToStr(courses[i].daysOfWeek) << ",";
		fout << BoolToStr(courses[i].isAvailable) << endl;
	}

	fout.close();
}
