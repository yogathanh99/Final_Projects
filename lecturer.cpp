/*
Implementation for use-cases of lecturer
*/

#include "lecturer.h"

void ImportScoreboard(vector<Score> &Scores)
{
	string path;
	cout << "Enter the csv file path: ";
	getline(cin, path, '\n');

	ifstream fin;
	fin.open(path);

	if (!fin.is_open())
	{
		cout << "No csv file with such path was found. Please try again." << endl;
		Pause(45,3);
		return;
	}

	Score s;
	string tmp;
	getline(fin, tmp, ',');
	getline(fin, s.courseCode, '\n'); //Import course code 

	getline(fin, tmp, ',');
	getline(fin, s.year, '\n'); //Import school year

	getline(fin, tmp, ',');
	getline(fin, tmp, '\n');
	s.semester = StrToInt(tmp); //Import semester

	getline(fin, tmp, '\n'); //Ignore the title

	int studentCount = 0;
	while (!fin.eof())
	{
		getline(fin, s.studentId, ',');

		getline(fin, tmp, ',');
		s.midtermScore = StrToDouble(tmp); //Import midterm score

		getline(fin, tmp, ',');
		s.labScore = StrToDouble(tmp); //Import lab score

		getline(fin, tmp, ',');
		s.finalScore = StrToDouble(tmp); //Import final score

		getline(fin, tmp, '\n');
		s.totalScore = StrToDouble(tmp); //Import total score

		if (tmp != "")
		{
			Scores.push_back(s);
			++studentCount;
		}
	}
	fin.close();

	cout << "Succesfully imported " << studentCount << " students' scores." << endl;
	Pause(45,3);
}

void Editgrade(vector <Score> &scores)
{
	int pick;
	double new_midterm, new_lab, new_final, new_total;
	int i, semester;
	string coursecode;
	string year;
	string id;
	string tmp;

	cout << "Enter course code: ";
	getline(cin, coursecode);
	cout << "Enter year: ";
	getline(cin, year);
	cout << "Enter semester: ";
	getline(cin, tmp);
	semester = StrToInt(tmp);
	cout << "Enter student ID: ";
	getline(cin, id);
	
	bool check = false;

	for (i = 0; i < scores.size(); i++)

		if (coursecode == scores[i].courseCode && year == scores[i].year && semester == scores[i].semester && id == scores[i].studentId)
		{
			check = true;
			break;
		}

	if (check) {

		cout << "\n0. Change midterm score: ";
		cout << "\n1. Change lab score: ";
		cout << "\n2. Change final score: ";
		cout << "\n3. Change total score: ";

		cout << "\nWhat do you want to change: ";
		cin >> pick;
		cin.ignore(1000, '\n');

		switch (pick) {
		case 0:

			cout << "Please input new midterm score: ";
			cin >> new_midterm;
			cin.ignore(1000, '\n');
			scores[i].midtermScore = new_midterm;
			cout << "Change successfully " << endl;
			Pause(45,12);
			break;

		case 1:

			cout << "Please input new lab score: ";
			cin >> new_lab;
			cin.ignore(1000, '\n');
			scores[i].labScore = new_lab;
			cout << "Change successfully " << endl;
			Pause(45,12);
			break;

		case 2:

			cout << "Please input new final score: ";
			cin >> new_final;
			cin.ignore(1000, '\n');
			scores[i].finalScore = new_final;
			cout << "Change successfully " << endl;
			Pause(45,12);
			break;

		case 3:

			cout << "Please input new total score: ";
			cin >> new_total;
			cin.ignore(1000, '\n');
			scores[i].totalScore = new_total;
			cout << "Change successfully " << endl;
			Pause(45,12);
			break;

		default:

			cout << "invalid: " << endl;
			Pause(45,11);
			break;
		}
	}
	else
	{
		cout << "Please try again: " << endl;
		Pause(45,11);
	}
}

void ViewScore(User CurrentUser, vector<Course> course, vector<Score> scores) {
	bool check = true;
	int count(0);
	for (int i = 0; i < course.size(); ++i) {
		if (CurrentUser.username == course[i].lecturerUsername) {
			check = false;
			break;
		}
		else check = true;
	}
	if (!check) {
		cout << "Enter course code: ";
		string code;
		getline(cin, code);
		bool ok = true;
		for (int i = 0; i < scores.size(); ++i) {
			if (code == scores[i].courseCode) {
				ok = false;
				break;
			}
		}
		if (!ok) {
			for (int i = 0; i < scores.size(); ++i) {
				if (code == scores[i].courseCode) {
					cout << "Course code: " << scores[i].courseCode << endl;
					cout << "Year: " << scores[i].year << endl;
					cout << "Semester: " << scores[i].semester << endl;
					cout << "Student ID: " << scores[i].studentId << endl;
					cout << "Midterm score: " << scores[i].midtermScore << endl;
					cout << "Lab score: " << scores[i].labScore << endl;
					cout << "Final score: " << scores[i].finalScore << endl;
					cout << "Total score: " << scores[i].totalScore << endl;
					cout << endl;
					++count;
				}
			}
		}
	}
	else cout << "Lecturer hasn't course" << endl;
	Pause(45,count*9+1);
}