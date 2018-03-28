#include "staff_students.h"

void ImportStudentFromFile(string path, vector<User> &users)
{
	ifstream fin;
	fin.open(path);

	if (!fin.is_open())
	{
		cout << "File '" << path << "' not open" << endl;;
		return;
	}
	string tmp, _class;
	getline(fin, tmp, ','); //tmp=Class
	getline(fin, _class, '\n'); //Put class into _class
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

void OutputStudentToAnotherFile(string path, vector<User> users)
{
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
	{
		cout << "File '" << path << "' not open" << endl;
		return;
	}
	for (int i = 0; i < users.size(); ++i)
	{
		fout << users[i]._class << ',' << users[i].username << ',' << users[i].fullName << endl;
	}
	fout.close();
}

/*void EditStudent(vector <User> &users, int count)
{
	string id;
	int pick, i = 0;
	string fullname, _class;
	char mail[50];
	char phone[20];
	char pass[20];
	int gender;


	cout << "\n0. Change full name: ";
	cout << "\n1. Change email: ";
	cout << "\n2. Change mobile phone: ";
	cout << "\n3. Change password: ";
	cout << "\n4. Change gender: ";
	cout << "\n5. Chang _class: ";

	cout << "\nWhat do you want to change: ";
	cin >> pick;


	while (!checkInput(users));

	if (pick == 0) {
		cout << " input new full name: " << endl;
		getline(cin, fullname, ' ');
	}

	else if (pick == 1) {
		cout << "Input new mail: " << endl;
		cin >> mail;
	}
	else if (pick == 2) {
		cout << "Input mobile phone: " << endl;
		cin >> phone;
	}
	else if (pick == 3) {
		cout << "Input new password: " << endl;
		cin >> pass;
	}
	else if (pick == 4) {
		cout << "Input new gender: " << endl;
		cin >> gender;
	}
	else if (pick == 5) {
		cin.ignore(2000, '\n');
		cout << " Input new class: " << endl;
		getline(cin, _class);

	}
	else
		cout << "invaild: " << endl;

}
void ChangeClassStudent(vector <User> &users)
{
	int pick;
	int i = 0;
	string id, _class;


	cout << "\n0. Do not move student: ";
	cout << "\n1 . Move all students:  ";
	cout << "\n2. Move a student: ";

	cout << "\nWhat do you want to pick: " << endl;
	cin >> pick;

	if (pick == 0) {
		cout << "Do not move students: " << endl;
		return;
	}

	else if (pick == 1) {
		cout << "Input new class: ";
		cin >> _class;

	}
	else if (pick == 2)
	{

		while (!checkInput(users));
		cout << "input class:"; cin >> _class;

	}
}
bool checkInput(vector <User> &users)
{


	int i;
	string id;

	cout << "Input id: ";
	cin >> id;
	for (i = 0; i < users.size(); i++)


		if ((id == users[i].username) && (users[i].type == STUDENT))
		{
			return true;
		}return false;


}
void View_Class_List(vector<User> users)
{
	int i;
	for (i = 0; i < users.size(); i++) {
		cout << users[i]._class;
		break;
	}

}

void Addemptyclass(vector <User> &users)
{
	User x;
	cout << "\nInput new class: ";
	getline(cin, x._class);

}
void ViewStudentList(vector<User> &users)
{
	string _class;
	int i = 0;
	cin.ignore(2000, '\n');

	cout << "Input class: ";
	getline(cin, _class);

	for (int i = 0; i < users.size(); i++)

		if (_class == users[i]._class)

			cout << users[i].username << " " << users[i].fullName << endl;

}*/