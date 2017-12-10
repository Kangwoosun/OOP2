#include <iostream>
#include <string>
#include "Instructor.h"
#include "Student.h"
#include <fstream>
#pragma warning(disable:4996)
using namespace std;
int main() {/*
	ofstream StudentCreator("StudentList.bin", ios::out | ios::binary);
	int studno;
	string name;
	string course;
	string passwd;
	Student tmpstudent;
	cout << "cin studno:";
	while (cin >> studno) {
		cin.ignore();
		cout << "cin name:";
		getline(cin, name, '\n');
		cout << "cin course:";
		getline(cin, course, '\n');
		cout << "cin passwd:";
		getline(cin, passwd, '\n');

		tmpstudent.setStudno(studno);
		tmpstudent.setName(name);
		tmpstudent.setCourse(course);
		tmpstudent.setPasswd(passwd);
		StudentCreator.write(reinterpret_cast<const char*> (&tmpstudent), sizeof(Student));

		cout << "cin studno:";
	*/
	ofstream InstructorCreator("InstructorList.bin", ios::out | ios::binary);
	int studno;
	string name;
	string rank;
	string passwd;
	Instructor tmpInstructor;
	cout << "cin studno:";
	while (cin >> studno) {
		cin.ignore();
		cout << "cin name:";
		getline(cin, name, '\n');
		cout << "cin rank:";
		getline(cin, rank, '\n');
		cout << "cin passwd:";
		getline(cin, passwd, '\n');

		tmpInstructor.SetInstructno(studno);
		tmpInstructor.SetName(name);
		tmpInstructor.SetRank(rank);
		tmpInstructor.SetPasswd(passwd);
		InstructorCreator.write(reinterpret_cast<const char*> (&tmpInstructor), sizeof(Instructor));

		cout << "cin studno:";

		
	}
	return 0;
}