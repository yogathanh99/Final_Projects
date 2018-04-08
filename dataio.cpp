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
		getline(fin, course.lecturerUsername, '\n');

		if (course.courseCode != "") 
			courses.push_back(course);
	}

	fin.close();
}

void ReadScheduleDataFromFile(string path, vector<Schedule> &schedules) {
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
		return;

	string tmp;
	while (!fin.eof()) {
		Schedule schedule;

		getline(fin, schedule.courseCode, ',');
		getline(fin, schedule.year, ',');
		getline(fin, tmp, ',');
		schedule.semester = StrToInt(tmp);

		getline(fin, tmp, ',');
		schedule.startAt = StrToDate(tmp);
		getline(fin, tmp, ',');
		schedule.endAt = StrToDate(tmp);
		getline(fin, tmp, ',');
		schedule.from = StrToTime(tmp);
		getline(fin, tmp, ',');
		schedule.to = StrToTime(tmp);
		getline(fin, tmp, '\n');
		schedule.daysOfWeek = StrToDow(tmp);

		if (schedule.courseCode != "")
			schedules.push_back(schedule);
	}

	fin.close();
}

void ReadPresenceDataFromFile(string path, vector<Presence> &presences) {
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
		return;

	string tmp;
	while (!fin.eof()) {
		Presence presence;
		getline(fin, presence.courseCode, ',');
		getline(fin, presence.year, ',');
		getline(fin, tmp, ',');
		presence.semester = StrToInt(tmp);
		getline(fin, presence.studentId, ',');
		getline(fin, tmp, '\n');
		presence.week = StrToInt(tmp);

		if (presence.courseCode != "")
			presences.push_back(presence);
	}

	fin.close();
}

void ReadScoreDataFromFile(string path, vector<Score> &scores) {
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
		return;

	string tmp;
	while (!fin.eof()) {
		Score score;
		getline(fin, score.courseCode, ',');
		getline(fin, score.year, ',');
		getline(fin, tmp, ',');
		score.semester = StrToInt(tmp);
		getline(fin, score.studentId, ',');

		getline(fin, tmp, ',');
		score.midtermScore = StrToDouble(tmp);
		getline(fin, tmp, ',');
		score.labScore = StrToDouble(tmp);
		getline(fin, tmp, '\n');
		score.finalScore = StrToDouble(tmp);

		if (score.courseCode != "")
			scores.push_back(score);
	}

	fin.close();
}

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
		fout << courses[i].lecturerUsername << endl;
	}

	fout.close();
}

void WriteScheduleDataToFile(string path, vector<Schedule> &schedules) {
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
		return;

	for (int i = 0; i < schedules.size(); ++i) {
		fout << schedules[i].courseCode << ",";
		fout << schedules[i].year << ",";
		fout << schedules[i].semester << ",";
		fout << DateToStr(schedules[i].startAt) << ",";
		fout << DateToStr(schedules[i].endAt) << ",";
		fout << TimeToStr(schedules[i].from) << ",";
		fout << TimeToStr(schedules[i].to) << ",";
		fout << DowToStr(schedules[i].daysOfWeek) << endl;
	}

	fout.close();
}

void WritePresenceDataToFile(string path, vector<Presence> &presences) {
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
		return;

	for (int i = 0; i < presences.size(); ++i) {
		fout << presences[i].courseCode << ",";
		fout << presences[i].year << ",";
		fout << presences[i].semester << ",";
		fout << presences[i].studentId << ",";
		fout << presences[i].week << endl;
	}

	fout.close();
}

void WriteScoreDataToFile(string path, vector<Score> &scores) {
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
		return;

	for (int i = 0; i < scores.size(); ++i) {
		fout << scores[i].courseCode << ",";
		fout << scores[i].year << ",";
		fout << scores[i].semester << ",";
		fout << scores[i].studentId << ",";
		fout << scores[i].midtermScore << ",";
		fout << scores[i].labScore << ",";
		fout << scores[i].finalScore << endl;
	}

	fout.close();
}

