#include "misc.h"

int StrToInt(string s) {
	stringstream ss(s);
	int x;
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
	int pos = s.find(':'); // position of colon
	t.hours = StrToInt(s.substr(0, pos));
	t.minutes = StrToInt(s.substr(pos + 1));
	return t;
}

string TimeToStr(Time t) {
	return IntToStr(t.hours, 2) + ":" + IntToStr(t.minutes, 2);
}