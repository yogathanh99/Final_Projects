/*
Implementation for use-cases of lecturer
*/

#include "lecturer.h"
void ImportScoreFromFile(string path,vector <Score> &scores)
{
	
	//cout << "Enter the csv file path: ";
	//getline(cin, path, '\n');

	ifstream fin;
	fin.open(path);
	if (!fin.is_open()) {
		cout << "No csv file with such path was found. Please try again." << endl;
		Pause();
		return;
	}
	int Scorecount = 0;
	string tmp;
	//getline(fin, tmp, ',');
	while (!fin.eof())
	{
		Score score;
		getline(fin, score.courseCode, ',');
		getline(fin, score.year, ',');
		getline(fin, tmp, ',');
		score.semester = StrToInt(tmp);
		getline(fin, score.studentId, ',');

		getline(fin, tmp, ',');
		score.midtermScore = StrToDouble(tmp);
		getline(fin, tmp, ',');
		score.labScore = StrToDouble(tmp);
		getline(fin, tmp, ',');
		score.finalScore = StrToDouble(tmp);
		getline(fin, tmp, '\n');
		score.totalScore = StrToDouble(tmp);
        scores.push_back(score);
		
	}
	
}

void Editgrade(vector <Score> &scores)
{
	int pick;
	double new_midterm, new_lab, new_final, new_total;
	int i;
	string coursecode;
	string id;

	cout << "Enter course code: ";
	getline(cin, coursecode);

	bool check = false;

	for (i = 0; i < scores.size(); i++)

	if (coursecode == scores[i].courseCode)
	{
		check = true;
		break;
	}

	if (check){

		cout << "\n0. Change midterm score: ";
		cout << "\n1. Change lab score: ";
		cout << "\n2. Change final score: ";
		cout << "\n3. Change total score: ";

		cout << "\nWhat do you want to change: ";
		cin >> pick;
		cin.ignore(1000, '\n');
	

		while (!checkId(scores));


			switch (pick){
			case 0:
				
				cout << "Pls input new midterm score: ";
				cin >> new_midterm;
				scores[i].midtermScore = new_midterm;
				cout << "Change successfully " << endl;
				Pause();
				break;

			case 1:

				cout << "Pls input new lab score: ";
				cin >> new_lab;
				scores[i].labScore = new_lab;
				cout << "Change successfully " << endl;
				Pause();
				break;

			case 2:

				cout << "Pls input new final score: ";
				cin >> new_final;
				scores[i].finalScore = new_final;
				cout << "Change successfully " << endl;
				Pause();
				break;

			case 3:

				cout << "Pls input new total score: ";
				cin >> new_total;
				scores[i].totalScore = new_total;
				Pause();
				break;

			default:

				cout << "invalid: " << endl;
				Pause();
				break;
			}
		}
	

	else
	{
		cout << "Pls try again: " << endl;
		
	}
}
bool checkId(vector <Score> &scores)
{
	string id;
	
    cout << "Pls enter id: ";
	getline(cin, id);
	for (int i = 0; i < scores.size(); i++)
	if (id == scores[i].studentId)
	{
		return true;
	}return false;
}



