/*
Header for miscellaneous function
*/

#include "sms.h"
#include "sha1.h"

#ifndef MISC_H
#define MISC_H

// Convert string to integer
int StrToInt(string s);

// Convert string to double
double StrToDouble(string s);

// Convert integer to string
string IntToStr(int x, int d = 0);

// Convert string ('dd/mm/yyyy' format) to Date
Date StrToDate(string s);

// Convert Date to string ('dd/mm/yyyy' format)
string DateToStr(Date d);

// Convert string ('hh:mm' format) to Time
Time StrToTime(string s);

// Convert Time to string ('hh:mm' format)
string TimeToStr(Time t);

// Convert string to DaysOfWeek
DaysOfWeek StrToDow(string s);

// Convert DaysOfWeek to string
string DowToStr(DaysOfWeek dow);

// Convert string to bool
bool StrToBool(string s);

// Convert bool to string
string BoolToStr(bool b);

// Pause the program. User can press any key to continue.
void Pause();

// Get password hash with SHA-1
string getHash(string password);

#endif // !MISC_H