/*
Header for miscellaneous function
*/

#include "sms.h"

#ifndef MISC_H
#define MISC_H

// Convert string to integer
int StrToInt(string s);

string IntToStr(int x, int d = 0);

// Convert string ('dd/mm/yyyy' format) to Date
Date StrToDate(string s);

// Convert Date to string ('dd/mm/yyyy' format)
string DateToStr(Date d);

// Convert string ('hh:mm' format) to Time
Time StrToTime(string s);

// Convert Time to string ('hh:mm' format)
string TimeToStr(Time t);


#endif // !MISC_H