#include "misc.h"
#include "UI.h"

int StrToInt(string s) {
	stringstream ss(s);
	int x = 0;
	ss >> x;
	return x;
}

double StrToDouble(string s) {
	stringstream ss(s);
	double x = 0;
	ss >> x;
	return x;
}

string IntToStr(int x, int d) {
	stringstream ss;
	ss << x;
	string s = ss.str();
	while (s.length() < d) s = "0" + s;
	return s;
}

Date StrToDate(string s) {
	Date d;
	d.day = 0;
	d.month = 0;
	d.year = 0;
	
	int pos1 = s.find('/'); // position of first slash
	int pos2 = s.find('/', pos1 + 1); // position of second slash
	d.day = StrToInt(s.substr(0, pos1));
	d.month = StrToInt(s.substr(pos1 + 1, pos2 - pos1 - 1));
	d.year = StrToInt(s.substr(pos2 + 1));
	return d;
}

string DateToStr(Date d) {
	return IntToStr(d.day, 2) + "/" + IntToStr(d.month, 2) + "/" + IntToStr(d.year, 4);
}

Time StrToTime(string s) {
	Time t;
	t.hour = 0;
	t.minute = 0;

	int pos = s.find(':'); // position of colon
	t.hour = StrToInt(s.substr(0, pos));
	t.minute = StrToInt(s.substr(pos + 1));
	return t;
}

string TimeToStr(Time t) {
	return IntToStr(t.hour, 2) + ":" + IntToStr(t.minute, 2);
}

DaysOfWeek StrToDow(string s) {
	if (s == "Monday") return MONDAY;
	if (s == "Tuesday") return TUESDAY;
	if (s == "Wednesday") return WEDNESDAY;
	if (s == "Thursday") return THURSDAY;
	if (s == "Friday") return FRIDAY;
	if (s == "Saturday") return SATURDAY;
	if (s == "Sunday") return SUNDAY;
	return MONDAY;
}

string DowToStr(DaysOfWeek dow) {
	if (dow == MONDAY) return "Monday";
	if (dow == TUESDAY) return "Tuesday";
	if (dow == WEDNESDAY) return "Wednesday";
	if (dow == THURSDAY) return "Thursday";
	if (dow == FRIDAY) return "Friday";
	if (dow == SATURDAY) return "Saturday";
	if (dow == SUNDAY) return "Sunday";
	return "Monday";
}

bool StrToBool(string s) {
	if (s == "True") return true;
	if (s == "False") return false;
	return false;
}

string BoolToStr(bool b) {
	if (b == true) return "True";
	if (b == false) return "False";
	return "False";
}

void Pause(int x, int y) {
	gotoxy(x, y);
	cout << "Press any key to continue." << endl;
	cin.get();
}

string getHash(string password) {
	SHA1 checksum;
	checksum.update(password);
	return checksum.final();
}
