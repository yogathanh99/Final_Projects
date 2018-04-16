/*
Implementation for use-cases of academic staff about attendance managing
*/

#include "staff_attendance.h"

void ImportAttendance(vector<Presence> &presences) {
	ifstream fin;
	fin.open("presence.csv");
	if (!fin.is_open()) {
		cout << "No csv file with such path was found. Please try again." << endl;
		Pause();
		return;
	}

	while (!fin.eof()) {
		Presence attendance;
		getline(fin, attendance.courseCode, ',');
		getline(fin, attendance.year, ',');
		fin >> attendance.semester;
		fin.ignore(1000, ',');
		getline(fin, attendance.studentId, ',');
		fin >> attendance.week;
		fin.ignore(1000, '\n');
		attendance.check = true;

		presences.push_back(attendance);
	}
	fin.close();
}

void SearchAndViewAttendance(vector<Presence> presences) {
	string courseCode;
	cout << "Enter course code: ";
	getline(cin, courseCode);

	cout << "List attendance of course: " << endl;
	for (int i = 0; i < presences.size(); ++i)
		presences[i].check = true;
	for (int i = 0; i < presences.size(); ++i) {
		if (presences[i].courseCode == courseCode && presences[i].check == true) {
			int j = i;
			cout << "Student ID: " << presences[i].studentId << endl;
			while (j < presences.size()) {
				if (presences[i].studentId == presences[j].studentId && presences[j].courseCode == courseCode) {
					cout << "Week: " << presences[j].week << endl;
					presences[j].check = false;
				}
				++j;
			}
			cout << endl;
		}
	}
	Pause();
}

void ExportAttendance(vector<Presence> presences) {
	ofstream fout;
	string path;
	cout << "Enter the csv path which wanted to exported: ";
	getline(cin, path);

	fout.open(path);
	fout << "Courses code,Year,Semester,Students ID,Week" << endl;
	for (int i = 0; i < presences.size(); ++i) {
		fout << presences[i].courseCode << "," << presences[i].year << "," << presences[i].semester << "," << presences[i].studentId << "," << presences[i].week << endl;
	}
	cout << "Export successfully" << endl;
	Pause();
	fout.close();
}