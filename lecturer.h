/*
Header for use-cases of lecturer
*/

#ifndef LECTURER_H
#define LECTURER_H

#include "sms.h"
#include  "misc.h"

void ImportScoreFromFile(string path,vector <Score> &scores);
bool checkId(vector <Score> &scores);
void Editgrade(vector <Score> &scores);


#endif // LECTURER_H