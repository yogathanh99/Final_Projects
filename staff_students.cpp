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


void AddStudent(vector<User> &users) {
	User student;
	cout << "Input class: ";
	getline(cin, student._class);
	cout << "Input usersname: ";
	getline(cin, student.username);
	cout << "Input fullname: ";
	getline(cin, student.fullName); 
	cout << "Input email: ";
	getline(cin, student.email);
	cout << "Input mobile phone: ";
	getline(cin, student.mobilePhone);
	cout << "Input password: ";
	getline(cin, student.password);
	student.type = STUDENT;
	users.push_back(student);
}

void EditExistStudent(vector<User> &users) {
	int pick;
	string fullname, _class, mail, phone, password, ID;

	cout << "ID student: ";
	getline(cin, ID);
	bool check = false;
	int i;
	for (i = 0; i < users.size(); ++i)
	{
		if (users[i].username == ID && users[i].type == STUDENT) {
			check = true;
			break;
		}
	}

	if (check) {
		cout << "0. Change full name: ";
		cout << "\n1. Change email: ";
		cout << "\n2. Change mobile phone: ";
		cout << "\n3. Change password: ";
		cout << "\n4. Change class: ";

		cout << "\nWhat do you want to change: ";
		cin >> pick;

		if (pick == 0) {
			cin.ignore(1000, '\n');
			cout << "Input new full name: ";
			getline(cin, fullname);
			users[i].fullName = fullname;
			cout << "Changed successful" << endl;
			cin.ignore(1000, '\n');
		}

		else if (pick == 1) {
			cin.ignore(1000, '\n');
			cout << "Input new mail: ";
			getline(cin, mail);
			users[i].email = mail;
			cout << "Changed Successfull" << endl;
			cin.ignore(1000, '\n');
		}
		else if (pick == 2) {
			cin.ignore(1000, '\n');
			cout << "Input mobile phone: ";
			getline(cin, phone);
			users[i].mobilePhone = phone;
			cout << "Changed Successfull" << endl;
			cin.ignore(1000, '\n');
		}
		else if (pick == 3) {
			cin.ignore(1000, '\n');
			cout << "Input new password: ";
			getline(cin, password);
			users[i].password = password;
			cout << "Changed Successfull" << endl;
			cin.ignore(1000, '\n');
		}
		else if (pick == 4) {
			cin.ignore(1000, '\n');
			cout << "Input new class: ";
			getline(cin, _class);
			users[i]._class = _class;
			cout << "Changed Successfull" << endl;
			cin.ignore(1000, '\n');
		}
		else
			cout << "Invaild: " << endl;
	}
}

void ChangeClassStudent(vector <User> &users)
{
	int pick;
	int i = 0;
	string id, _class;

	cout << "0. Do not move student: ";
	cout << "\n1. Move all students:  ";
	cout << "\n2. Move a student: ";

	cout << "\nWhat do you want to pick: ";
	cin >> pick;
	cin.ignore(1000, '\n');

	if (pick == 0) {
		cout << "Do not move students: " << endl;
		cin.ignore(1000,'\n');
	}
	else if (pick == 1) {
		cout << "Input old class: ";
		string _oldclass;
		getline(cin, _oldclass);
		cout << "Input new class: ";
		getline(cin, _class);
		for (int i = 0; i < users.size(); ++i)
			if (users[i]._class == _oldclass) users[i]._class = _class;
		cout << "Changed successfull" << endl;
		cin.ignore(1000, '\n');
	}
	else if (pick == 2)
	{
		string ID;
		cout << "ID student: ";
		getline(cin, ID);
		bool check = false;
		int i;
		for (i = 0; i < users.size(); ++i)
		{
			if (users[i].username == ID && users[i].type == STUDENT)
			{
				check = true;
				break;
			}
		}
		if (check) {
			cout << "Input new class:"; 
			getline(cin, _class);
			users[i]._class = _class;
			cout << "Changed successfull" << endl;
			cin.ignore(1000, '\n');
		}
	}
}

void RemoveStudent(vector<User> &users) {
	string ID;
	cout << "Input ID: ";
	getline(cin, ID);
	for (int i = 0; i < users.size(); ++i) {
		if (users[i].username == ID) users.erase(users.begin() + i);
	}
	cout << "Changed successfull" << endl;
}

void View_Class_List(vector<User> users)
{
	int i;
	for (i = 0; i < users.size(); i++)
	{
		if (users[i].type==STUDENT) cout << "Class: " << users[i]._class<<endl;
	}
	cin.ignore(1000, '\n');
}

void ViewStudentList(vector<User> users)
{
	string _class;
	int i = 0;

	cout << "Input class: ";
	getline(cin, _class);

	for (int i = 0; i < users.size(); i++) {
		if (_class == users[i]._class)
			cout << users[i].username << " " << users[i].fullName << endl;
	}
	cin.ignore(1000, '\n');
}