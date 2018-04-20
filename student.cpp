/*
Implementation for use-cases of student
*/

#include "student.h"

void CheckIn(User currentUser, vector<Course> courses, vector<Presence> &presences) {
	string coursecode, year, tmp;
	int semester, week;

	cout << "Input Course Code: ";
	getline(cin, coursecode);
	
	cout << "Input Year: ";
	getline(cin, year);
	
	cout << "Input Semester: ";
	getline(cin, tmp);
	semester = StrToInt(tmp);
	
	cout << "Input Week: ";
	getline(cin, tmp);
	week = StrToInt(tmp);

	for (int i = 0; i < courses.size(); i++)
	{
		if (courses[i].courseCode == coursecode && courses[i].year == year && courses[i].semester == semester)
		{
			bool checkedIn = false;
			for (int i = 0; i < presences.size(); ++i) {
				if (presences[i].courseCode == coursecode && presences[i].year == year && presences[i].semester == semester && presences[i].studentId == currentUser.username && presences[i].week == week) {
					checkedIn = true;
					break;
				}
			}
			if (checkedIn) {
				cout << "Already checked in." << endl;
				Pause();
				return;
			}

			Presence checkin;
			checkin.courseCode = courses[i].courseCode;
			checkin.year = courses[i].year;
			checkin.semester = courses[i].semester;
			checkin.studentId = currentUser.username;
			checkin.week = week;
			presences.push_back(checkin);
			cout << "Check in successfully." << endl;
			Pause();
			return;
		}
	}
	cout << "There's something wrong, can't check in, please retry." << endl;
	Pause();
}

void ViewCheckInResult(User currentUser, vector<Presence> &presences) {

	cout << "   Code|     Year|Sem.|  Week" << endl;
	cout << "-------+---------+----+------" << endl;
	//	cout << "  MH251|2017-2018|   1|     9

	for (int i = 0; i < presences.size(); ++i) {
		if (presences[i].studentId == currentUser.username) {
			cout << setw(7) << presences[i].courseCode << "|";
			cout << setw(9) << presences[i].year << "|";
			cout << setw(4) << presences[i].semester << "|";
			cout << setw(6) << presences[i].week << endl;
		}
	}

	Pause();
}

void ViewScore(User currentUser, vector<Score> &scores) {
	string coursecode, year, tmp;
	int semester;

	cout << "Input Course Code: ";
	getline(cin, coursecode);
	
	cout << "Input Year: ";
	getline(cin, year);

	cout << "Input Semester: ";
	getline(cin, tmp);
	semester = StrToInt(tmp);

	cout << fixed << setprecision(1);

	for (int i = 0; i < scores.size(); i++)
	{
		if (scores[i].courseCode == coursecode && scores[i].year == year && scores[i].semester == semester)
		{
			cout << "   Code|     Year|Sem.|   Midterm|       Lab|     Final|     Total" << endl;
			cout << "-------+---------+----+----------+----------+----------+----------" << endl;
			//	cout << "  CS161|2017-2018|   1|         8|        10|         9|       9.5

			cout << setw(7) << scores[i].courseCode << "|";
			cout << setw(9) << scores[i].year << "|";
			cout << setw(4) << scores[i].semester << "|";
			cout << setw(10) << scores[i].midtermScore << "|";
			cout << setw(10) << scores[i].labScore << "|";
			cout << setw(10) << scores[i].finalScore << "|";
			cout << setw(10) << scores[i].totalScore << endl;
			Pause();
			return;
		}
	}
	cout << "Can't find the course, please retry." << endl;
	Pause();
}


void ViewScheduleStudent(User currentUser, vector<Schedule> &schedules) {

	cout << "   Code|     Year|Sem.|  Class|  Start At|    End At| From|   To|Day of week" << endl;
	cout << "-------+---------+----+-------+----------+----------+-----+-----+-----------" << endl;
	//	cout << "  MH251|2017-2018|   1| 17CTT1|05/09/2016|23/09/2016|13:30|17:30|   Thursday"

	for (int i = 0; i < schedules.size(); ++i) {
		if (schedules[i]._class == currentUser._class) {
			cout << setw(7) << schedules[i].courseCode << "|";
			cout << setw(9) << schedules[i].year << "|";
			cout << setw(4) << schedules[i].semester << "|";
			cout << setw(7) << schedules[i]._class << "|";
			cout << setw(10) << DateToStr(schedules[i].startAt) << "|";
			cout << setw(10) << DateToStr(schedules[i].endAt) << "|";
			cout << setw(5) << TimeToStr(schedules[i].from) << "|";
			cout << setw(5) << TimeToStr(schedules[i].to) << "|";
			cout << setw(11) << DowToStr(schedules[i].daysOfWeek) << endl;
		}
	}

	Pause();
}
