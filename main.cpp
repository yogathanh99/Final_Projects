#include "staff_student.h"

int main() {
	string id;
	int count = 0;
	vector<User> users;
	vector <string> classes;
	importStudentsFromFile("17APCS1-Students.csv", users);
	for (int i = 0; i < users.size(); ++i)
		cout << users[i].username << " " << users[i].fullName << " " << users[i]._class << " " << endl;
	
	EditStudent(users, count);
	ChangeClassStudent(users);
	View_Class_List(users);
	Addemptyclass(users);
	ViewStudentList(users);

	system("pause");
	return 0;
}