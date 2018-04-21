#include "staff_students.h"
#include "UI.h"

void ImportStudentFromFile(vector<User> &users)
{
	string path;
	cout << "Enter the csv file path: ";
	getline(cin, path, '\n');

	ifstream fin;
	fin.open(path);

	if (!fin.is_open())
	{
		cout << "No csv file with such path was found. Please try again." << endl;
		Pause(45,3);
		return;
	}

	string tmp, _class;
	getline(fin, tmp, ','); //tmp=Class
	getline(fin, _class, '\n'); //Put class into _class
	getline(fin, tmp, '\n'); //put second line into tmp
	
	int studentCount = 0;
	while (!fin.eof())
	{
		getline(fin, tmp, ','); //get ordinal number into tmp
		User student;
		getline(fin, student.username, ','); //get ID
		getline(fin, student.fullName, ','); //get fullname
		getline(fin, student.email, ','); //get email
		getline(fin, student.mobilePhone, '\n'); //get phone number
		student.password = PASSWORD_DEFAULT;
		student._class = _class;
		student.type = STUDENT;
		if (tmp != "") {
			users.push_back(student);
			++studentCount;
		}
	}
	fin.close();

	gotoxy(45, 11);
	cout << "Succesfully imported " << studentCount << " new students." << endl;
	Pause(45,3);
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
	student.password = PASSWORD_DEFAULT;
	student.type = STUDENT;
	
	users.push_back(student);
	
	cout << "Successfully added" << endl;
	Pause(45,7);
}

void EditExistStudent(vector<User> &users) {
	string pick;
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
		getline(cin, pick);

		if (pick == "0") {
			cout << "Input new full name: ";
			getline(cin, fullname);
			users[i].fullName = fullname;
			cout << "Changed successfully" << endl;
			Pause(45,9);
		}

		else if (pick == "1") {
			cout << "Input new mail: ";
			getline(cin, mail);
			users[i].email = mail;
			cout << "Changed Successfully" << endl;
			Pause(45,9);
		}
		else if (pick == "2") {
			cout << "Input mobile phone: ";
			getline(cin, phone);
			users[i].mobilePhone = phone;
			cout << "Changed Successfully" << endl;
			Pause(45,9);
		}
		else if (pick == "3") {
			cout << "Input new password: ";
			getline(cin, password);
			users[i].password = password;
			cout << "Changed Successfully" << endl;
			Pause(45,9);
		}
		else if (pick == "4") {
			cout << "Input new class: ";
			getline(cin, _class);
			users[i]._class = _class;
			cout << "Changed Successfully" << endl;
			Pause(45,9);
		}
		else {
			cout << "Entered action is not legit. Please try again." << endl;
			Pause(45,8);
		}
	}
	else {
		cout << "No student with given ID found" << endl;
		Pause(45,8);
	}
}

void ChangeClassStudent(vector <User> &users)
{
	int pick;
	int i = 0;
	string id, _class;

	cout << "0. Do not move student: ";
	cout << "\n1. Move all students: ";
	cout << "\n2. Move a student: ";

	cout << "\nWhat do you want to pick: ";
	cin >> pick;
	cin.ignore(1000, '\n');

	if (pick == 0) {
		cout << "Action cancelled." << endl;
		Pause(45,6);
	}
	else if (pick == 1) {
		cout << "Input old class: ";
		string _oldclass;
		getline(cin, _oldclass);
		cout << "Input new class: ";
		getline(cin, _class);
		for (int i = 0; i < users.size(); ++i)
			if (users[i]._class == _oldclass) users[i]._class = _class;
		cout << "Changed successfully" << endl;
		Pause(45,8);
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
			cout << "Input new class: "; 
			getline(cin, _class);
			users[i]._class = _class;
			cout << "Changed successfully" << endl;
			Pause(45,8);
		}
		else {
			cout << "No student with given ID found" << endl;
			Pause(45,5);
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
	cout << "Changed successfully" << endl;
	Pause(45,3);
}

void View_Class_List(vector<User> users)
{
	int i;
	for (i = 0; i < users.size(); i++)
	{
		if (users[i].type == STUDENT) {
			bool isDuplicate = false;
			int j;
			for (j = 0; j < i; ++j) {
				if (users[i]._class == users[j]._class) {
					isDuplicate = true;
					break;
				}
			}
			if (!isDuplicate)
				cout << "Class: " << users[i]._class << endl;
		}
	}
	Pause(45,users.size()+1);
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
	Pause(45,2+users.size());
}