/*
Implementation for use-cases of academic staff about schedule managing
*/

#include "staff_schedule.h"
#include "misc.h"

void printSchedule(const Schedule &schedule) {
	cout << "Course code: " << schedule.courseCode << endl;
	cout << "Year: " << schedule.year << endl;
	cout << "Semester: " << schedule.semester << endl;
	cout << "Class: " << schedule._class << endl;
	cout << "Date: " << DateToStr(schedule.startAt) << " - " << DateToStr(schedule.endAt) << endl;
	cout << "Time: " << TimeToStr(schedule.from) << " - " << TimeToStr(schedule.to) << endl;
	cout << "Day of week: " << DowToStr(schedule.daysOfWeek) << endl;
}

string findLecturer(const vector<Course> &courses, const Schedule &s) {
	for (int i = 0; i < courses.size(); ++i) {
		if (courses[i].courseCode == s.courseCode && courses[i].year == s.year && courses[i].semester == s.semester) 
			return courses[i].lecturerUsername;		
	}
	return "N/A";
}

bool dateConflicted(const Date &l1, const Date &r1, const Date &l2, const Date &r2) {
	Date l = max(l1, l2);
	Date r = min(r1, r2);
	return (l <= r);
}

bool timeConflicted(const Time &l1, const Time &r1, const Time &l2, const Time &r2) {
	Time l = max(l1, l2);
	Time r = min(r1, r2);
	return (l <= r);
}

bool checkSchedule(const vector<Course> &courses, vector<Schedule> &schedules, Schedule schedule, Schedule &conflictedSchedule) {
	string sLecturer = findLecturer(courses, schedule);
	
	for (int i = 0; i < schedules.size(); ++i) {
		if ((dateConflicted(schedules[i].startAt, schedules[i].endAt, schedule.startAt, schedule.endAt) && timeConflicted(schedules[i].from, schedules[i].to, schedule.from, schedule.to) && schedules[i].daysOfWeek == schedule.daysOfWeek)
		|| (schedules[i].courseCode == schedule.courseCode && schedules[i].year == schedule.year && schedules[i].semester == schedule.semester && schedules[i]._class == schedule._class))
		{
			string iLecturer = findLecturer(courses, schedules[i]);
			cout << iLecturer << endl;
			if (schedules[i]._class == schedule._class || iLecturer == sLecturer) {
				conflictedSchedule = schedules[i];
				return true;
			}
		}
		
	}

	return false;
}

bool confirmUpdate(const vector<Course> &courses, vector<Schedule> &schedules, Schedule schedule, string action) {
	Schedule conflictedSchedule;
	bool result = checkSchedule(courses, schedules, schedule, conflictedSchedule);
	if (result) {
		cout << "Warning: the entered schedule conflicted with the following schedule" << endl;
		printSchedule(conflictedSchedule);
		cout << action << " anyway (Y/N)? ";
		string respond;
		getline(cin, respond);
		if (respond == "N" || respond == "n") {
			cout << "Operation aborted." << endl;
			Pause();
			return false;
		}
	}
	return true;
}

void ImportScheduleFromFile(const vector<Course> &courses, vector<Schedule> &schedules) {
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

	string _class;
	getline(fin, _class);
	string tmp;
	getline(fin, tmp);

	int scheduleCount = 0;
	while (!fin.eof()) {
		Schedule schedule;

		getline(fin, schedule.courseCode, ',');
		getline(fin, schedule.year, ',');
		getline(fin, tmp, ',');
		schedule.semester = StrToInt(tmp);
		schedule._class = _class;
			
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

		string s = findLecturer(courses, schedule);
		if (s == "N/A") continue;

		if (!confirmUpdate(courses, schedules, schedule, "Import")) 
			continue;

		schedules.push_back(schedule);
		++scheduleCount;		
	}

	fin.close();

	cout << "Succesfully imported " << scheduleCount << " new schedules." << endl;
	Pause();
}

void AddASchedule(const vector<Course> &courses, vector<Schedule> &schedules) {
	string tmp;
	Schedule schedule;

	cout << "Enter course code: ";
	getline(cin, schedule.courseCode);

	cout << "Enter school year: ";
	getline(cin, schedule.year);

	cout << "Enter semester: ";
	cin >> schedule.semester;
	getline(cin, tmp);

	string s = findLecturer(courses, schedule);
	if (s == "N/A") {
		cout << "Can not find course with given course code, year and semester." << endl;
		Pause();
		return;
	}

	cout << "Enter class: ";
	getline(cin, schedule._class);

	cout << "Enter start date (dd/mm/yyyy): ";
	getline(cin, tmp);
	schedule.startAt = StrToDate(tmp);

	cout << "Enter end date (dd/mm/yyyy): ";
	getline(cin, tmp);
	schedule.endAt = StrToDate(tmp);

	cout << "Enter start time (hh:mm): ";
	getline(cin, tmp);
	schedule.from = StrToTime(tmp);
	
	cout << "Enter end time (hh:mm): ";
	getline(cin, tmp);
	schedule.to = StrToTime(tmp);
	
	cout << "Enter day of week (e.g. Monday): ";
	getline(cin, tmp);
	schedule.daysOfWeek = StrToDow(tmp);

	if (!confirmUpdate(courses, schedules, schedule, "Add"))
		return;

	schedules.push_back(schedule);
	cout << "Operation successful." << endl;
	Pause();
}

void EditASchedule(const vector<Course> &courses, vector<Schedule> &schedules) {
	string tmp;
	string courseCode;
	string year;
	int semester;
	string _class;

	cout << "Enter course code: ";
	getline(cin, courseCode);
	cout << "Enter school year: ";
	getline(cin, year);
	cout << "Enter semester: ";
	cin >> semester;
	getline(cin, tmp);
	cout << "Enter class: ";
	getline(cin, _class);

	int iSchedule;
	for (iSchedule = 0; iSchedule < schedules.size(); ++iSchedule) {
		if (schedules[iSchedule].courseCode == courseCode && schedules[iSchedule].year == year && schedules[iSchedule].semester == semester && schedules[iSchedule]._class == _class)
			break;
	}
	if (iSchedule == schedules.size()) {
		cout << "Can not find schedule with given course code, year, semester and class." << endl;
		Pause();
		return;
	}

	Schedule editedSchedule = schedules[iSchedule];

	cout << "1. Edit course code" << endl;
	cout << "2. Edit school year" << endl;
	cout << "3. Edit semester" << endl;
	cout << "4. Edit class" << endl;
	cout << "5. Edit start date" << endl;
	cout << "6. Edit end date" << endl;
	cout << "7. Edit state time (from)" << endl;
	cout << "8. Edit end time (to)" << endl;
	cout << "9. Edit day of week" << endl;
	cout << "0. Edit cancel" << endl;

	cout << "Please enter an action (0-9): ";
	string action; getline(cin, action);

	if (action == "1") {
		cout << "Enter new course code: ";
		getline(cin, editedSchedule.courseCode);
	}
	else if (action == "2") {
		cout << "Enter new school year: ";
		getline(cin, editedSchedule.year);
	}
	else if (action == "3") {
		cout << "Enter semester: ";
		cin >> semester;
		getline(cin, tmp);
	}
	else if (action == "4") {
		cout << "Enter class (dd/mm/yyyy): ";
		getline(cin, editedSchedule._class);
	}
	else if (action == "5") {
		cout << "Enter new start date (dd/mm/yyyy): ";
		getline(cin, tmp);
		editedSchedule.startAt = StrToDate(tmp);
	}
	else if (action == "6") {
		cout << "Enter new end date (dd/mm/yyyy): ";
		getline(cin, tmp);
		editedSchedule.endAt = StrToDate(tmp);
	}
	else if (action == "7") {
		cout << "Enter new start time (hh:mm): ";
		getline(cin, tmp);
		editedSchedule.from = StrToTime(tmp);
	}
	else if (action == "8") {
		cout << "Enter new end time (hh:mm): ";
		getline(cin, tmp);
		editedSchedule.to = StrToTime(tmp);
	}
	else if (action == "9") {
		cout << "Enter new date of week (e.g Monday): ";
		getline(cin, tmp);
		editedSchedule.daysOfWeek = StrToDow(tmp);
	}
	else if (action == "0") {
		cout << "Operation aborted." << endl;
		Pause();
		return;
	}

	string s = findLecturer(courses, editedSchedule);
	if (s == "N/A") {
		cout << "Can not find course with edited course code, year and semester." << endl;
		Pause();
		return;
	}

	if (!confirmUpdate(courses, schedules, editedSchedule, "Edit"))
		return;

	schedules[iSchedule] = editedSchedule;
	cout << "Operation successful." << endl;
	Pause();
}

void RemoveASchedule(vector<Schedule> &schedules) {
	string tmp;
	string courseCode;
	string year;
	int semester;
	string _class;

	cout << "Enter course code: ";
	getline(cin, courseCode);
	cout << "Enter school year: ";
	getline(cin, year);
	cout << "Enter semester: ";
	cin >> semester;
	getline(cin, tmp);
	cout << "Enter class: ";
	getline(cin, _class);

	int iSchedule;
	for (iSchedule = 0; iSchedule < schedules.size(); ++iSchedule) {
		if (schedules[iSchedule].courseCode == courseCode && schedules[iSchedule].year == year && schedules[iSchedule].semester == semester && schedules[iSchedule]._class == _class)
			break;
	}
	if (iSchedule == schedules.size()) {
		cout << "Can not find schedule with given course code, year, semester and class." << endl;
		Pause();
		return;
	}

	schedules.erase(schedules.begin() + iSchedule);
	cout << "Operation successful." << endl;
	Pause();
}

void ViewSchedulesStaff(vector<Schedule> &schedules) {
	string _class;
	cout << "Enter class (enter * to view schedule of all class): ";
	getline(cin, _class);
	
	cout << "   Code|     Year|Sem.|  Class|  Start At|    End At| From|   To|Day of week" << endl;
	cout << "-------+---------+----+-------+----------+----------+-----+-----+-----------" << endl;
//	cout << "  MH251|2017-2018|   1| 17CTT1|05/09/2016|23/09/2016|13:30|17:30|   Thursday"
	
	for (int i = 0; i < schedules.size(); ++i) {
		if (_class == "*" || schedules[i]._class == _class) {
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