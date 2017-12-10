#pragma warning(disable : 4996)
#include "Instructor.h"
#include "Question.h"
#include "Subject.h"
#include "Student.h"
#include "Grade.h"
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;


void gotoxy(int x, int y);
Instructor Logined_Admin;
Student Logined_Student;
bool LoginAdmin();
bool LoginStudent();
string pass = "";

int main()
{
	char c;
__LoginGate__: // If Login Fail, comeback gate
	if (LoginAdmin()) { //Check ID that is Instructor's ID
while ((c = Logined_Admin.MainMenu()) != 'x') {
			switch (c)
			{
			case 's':
				system("cls");
				Logined_Admin.StudentInformation();
				break;
			case 'i':
				system("cls");
				Logined_Admin.InstructorInformation();
				break;
			case 'q':
				system("cls");
				Logined_Admin.QuestionInformation();
				break;
			case 'j':
				system("cls");
				Logined_Admin.SubjectInformation();
				break;
			case 'g':
				system("cls");
				Logined_Admin.GradeInformation();
				break;
			case 'u':
				system("cls");
				Logined_Admin.updatePasswd();
				break;
			case 'b':
				system("cls");
				Logined_Admin.BuildFile();
				break;
			default:
				break;
			}
		}
	}

	else if (LoginStudent()) {//Check ID that is Student's ID
		while ((c = Logined_Student.MainMenu()) != 'x') {
			switch (c)
			{
			case 't':
				Logined_Student.takeExamination();
				break;
			case 'v':
				Logined_Student.viewGradeReport();
				break;
			case 'u':
				Logined_Student.updatePasswd();
				break;
			default:
				break;
			}
		}
	}

	else // If Login Failed, User's interface
	{
		system("cls");
		cout << "Login Failed.\nThere is no ID in Information\n";
		cout << "Do you want Login again? y/n\n";
		cin >> c;
		cin.ignore();
		while (1) {
			switch (c) {
			case 'y':
				system("cls");
				goto __LoginGate__; //Comeback to Login interface
			case 'n':
				exit(EXIT_FAILURE);
			default:
				cout << "plz input y/n\n";
				cin >> c;
				break;
			}
		}
	}



	return 0;
}


bool LoginAdmin() {

	ifstream Admin_Search("InstructorList.bin", ios::in | ios::binary);
	if (Admin_Search.fail()) { //Error Check
		system("cls");
		cerr << "Fail to Open InstructorList.bin" << endl;
		exit(EXIT_FAILURE);
	}
	cout << endl << endl << endl;
	cout << "            -------------------------- Login ----------------------" << endl;
	cout << "            |                                                     |" << endl;
	cout << "            |      Enter username :                               |" << endl;
	cout << "            |      Enter password :                               |" << endl;
	cout << "            |                                                     |" << endl;
	cout << "            -------------------------- Login ----------------------" << endl;

	gotoxy(37, 6); // Move cursor to input user id

	Admin_Search.read(reinterpret_cast<char *> (&Logined_Admin), sizeof(Instructor));
	getline(cin, pass, '\n');
	//Input ID
	while (1) {
		if (!(pass.compare(Logined_Admin.getName())))//Compare Input ID with InstructorList.bin's ID
			break;

		else if (!Admin_Search.eof())
			Admin_Search.read(reinterpret_cast<char *> (&Logined_Admin), sizeof(Instructor));
		else
			return 0;
	}

	char output;



	//Input PassWord
	int count;
	while (1) {
		count = 0;


		while (1) {
			gotoxy(37, 7);//Move cursor to input password
			pass = "";
			while ((output = _getch()) != '\r') //Password view '*' and Checking ID's password
			{
				pass += output;
				cout << "*";
				count++;
			}
			if (pass == Logined_Admin.getPasswd())
				return 1;

			else {
				gotoxy(37, 7);
				for (int i = 0; i < count; i++)
					cout << " ";
			}
		}

	}
	Admin_Search.close();
	return 0;
}


//Student Login()
bool LoginStudent() { 
	ifstream Student_Search("StudentList.bin", ios::in | ios::binary);
	if (Student_Search.fail()) {
		system("cls");
		cerr << "Fail to Open StudentList.bin" << endl;
		exit(EXIT_FAILURE);
	}


	char output;
	Student_Search.read(reinterpret_cast<char *> (&Logined_Student), sizeof(Student));

	while (1) {
		if (!pass.compare(Logined_Student.getName()))//Compare Input ID with InstructorList.bin's ID
			break;
		else if (!Student_Search.eof())
			Student_Search.read(reinterpret_cast<char *>(&Logined_Student), sizeof(Student));
		else
			return 0;

	}



	//Input PassWord
	int count;
	while (1) {
		count = 0;


		while (1) {
			pass = "";
			gotoxy(37, 7);//Move cursor to input password
			while ((output = _getch()) != '\r')//Password view '*' and Checking ID's password
			{
				pass += output;
				cout << "*";
				count++;
			}
			if (pass == Logined_Student.getPasswd())
				return 1;

			else {
				gotoxy(37, 7);
				for (int i = 0; i < count; i++)
					cout << " ";
			}
		}

	}
	Student_Search.close();
	return 0;
}

