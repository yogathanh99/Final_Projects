/*
Implementation for use-cases of academic staff about score managing
*/

#include "staff_score.h"

void ImportScore(vector<Score> &scores) {
	ifstream fin;
	fin.open("score.csv");
	if (!fin.is_open()) {
		cout << "No csv file with such path was found. Please try again." << endl;
		Pause();
		return;
	}

	while (!fin.eof()) {
		Score scoreboard;
		getline(fin, scoreboard.courseCode, ',');
		getline(fin, scoreboard.year, ',');
		fin >> scoreboard.semester;
		fin.ignore(1000, ',');
		getline(fin, scoreboard.studentId, ',');
		fin >> scoreboard.midtermScore;
		fin.ignore(1000, ',');
		fin >> scoreboard.labScore;
		fin.ignore(1000, ',');
		fin >> scoreboard.finalScore;
		fin.ignore(1000, ',');
		fin >> scoreboard.totalScore;
		fin.ignore(1000, ',');

		scores.push_back(scoreboard);
	}
	fin.close();
}

void SearchAndViewScoreboard(vector<Score> scores) {
	string courseCode;
	cout << "Enter course code: ";
	getline(cin, courseCode);

	cout << fixed << setprecision(1);

	for (int i = 0; i < scores.size(); ++i) {
		if (courseCode == scores[i].courseCode) {
			cout << "Student ID: " << scores[i].studentId << endl;
			cout << "Midterm score: " << scores[i].midtermScore << endl;
			cout << "Lab score: " << scores[i].labScore << endl;
			cout << "Final score: " << scores[i].finalScore << endl;
			cout << "Total score: " << scores[i].totalScore << endl;
			cout << endl;
		}
	}
	Pause();
}

void ExportScoreboard(vector<Score> scores) {
	string path;
	//cin.ignore(1000, '\n');
	cout << "Enter the csv path which wanted to exported: ";
	getline(cin, path);

	string courseCode;
	cout << "Enter course code: ";
	getline(cin, courseCode);

	bool check = true;
	for (int i = 0; i < scores.size(); ++i) {
		if (courseCode == scores[i].courseCode) {
			check = false;
			break;
		}
	}
	if (!check) {
		ofstream fout;
		fout.open(path);
		fout << "Course code,Year,Semester,Student ID,Midterm score,Lab score,Final score,Total score" << endl;
		for (int i = 0; i < scores.size(); ++i) {
			if (courseCode == scores[i].courseCode) {
				fout << scores[i].courseCode << ',' << scores[i].year << ',' << scores[i].semester << ',' << scores[i].studentId << ',' << scores[i].midtermScore << ',' << scores[i].labScore << ',' << scores[i].finalScore << ',' << scores[i].totalScore << endl;
			}
		}
		cout << "Export successfully" << endl;
		fout.close();
	}
	else {
		cout << "No course code" << endl;
	}
	Pause();
}