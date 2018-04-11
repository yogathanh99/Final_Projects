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
		Pause();
		return;
	}

	Score s;
	string tmp;
	getline(fin, tmp, ' ');
	getline(fin, tmp, ' ');

	getline(fin, s.courseCode, '\n'); //Import course code 

	getline(fin, tmp, ' ');
	getline(fin, tmp, ' ');

	getline(fin, s.year, '\n'); //Import school year

	getline(fin, tmp, ' ');

	getline(fin, tmp, '\n');
	s.semester=StrToInt(tmp); //Import semester
	
	getline(fin, tmp,'\n'); //Ignore the title

	int studentCount = 0;
	while (!fin.eof())
	{
		getline(fin, s.studentId, ' ');
		
		getline(fin, tmp, ' ');
		s.midtermScore = StrToDouble(tmp); //Import midterm score

		getline(fin, tmp, ' ');
		s.labScore = StrToDouble(tmp); //Import lab score

		getline(fin, tmp, ' ');
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
	Pause();
}