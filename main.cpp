#include "staff_students.h"

int main()
{
	vector<User> users;
	ImportStudentFromFile("17APCS1-Students.csv", users);
	OutputStudentToAnotherFile("OutputStudents.csv", users);
}