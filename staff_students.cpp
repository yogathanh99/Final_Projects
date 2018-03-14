#include "staff_students.h"

void ImportStudentFromFile(char path[], vector<User> &users)
{
	ifstream fin;
	fin.open(path);

	if (!fin.is_open())
	{
		cout << "File not open";
		return;
	}
	string tmp, _class;
	getline(fin, tmp, ','); //tmp=Class
	getline(fin, _class, ','); //Put class into _class
	getline(fin, tmp, '\n'); //put second line into tmp
	while (!fin.eof())
	{
		getline(fin, tmp, ','); //get ordinal number into tmp
		User students;
		getline(fin, students.username, ','); //get ID
		getline(fin, students.fullName, '\n'); //get fullname
		students._class = _class;
		students.type = STUDENT;
		users.push_back(students);
	}
	fin.close();
}

void OutputStudentToAnotherFile(char path[], vector<User> users)
{
	ofstream fout;
	fout.open(path);
	for (int i = 0; i < users.size(); ++i)
	{
		fout << users[i]._class << ' ' << users[i].username << ' ' << users[i].fullName << endl;
	}
	fout.close();
}