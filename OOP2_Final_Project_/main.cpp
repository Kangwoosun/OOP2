#include "Instructor.h"
#include "Question.h"
#include "Subject.h"
#include "Student.h"
#include "Grade.h"
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <vector>
using namespace std;


void gotoxy(int x, int y);
Instructor* Logined_Admin;
Student* Logined_Student;
bool LoginAdmin();
bool LoginStudent();
string instructor[4];
string student[4];
string pass = "";

int main()
{
	char c;
__LoginGate__:
	if (LoginAdmin()) {
		while (c = Logined_Admin->MainMenu() != 'x') {
			switch (c)
			{
			case 's':
				Logined_Admin->StudentInformation();
				break;
			case 'i':
				Logined_Admin->InstructorInformation();
				break;
			case 'q':
				Logined_Admin->QuestionInformation();
				break;
			case 'j':
				Logined_Admin->SubjectInformation();
				break;
			case 'g':
				Logined_Admin->GradeInformation();
				break;
			case 'u':
				Logined_Admin->updatePasswd();
				break;
			case 'b':
				Logined_Admin->BuildFile();
				break;
			default:
				break;
			}
		}
	}

	else if (LoginStudent()) {
		while (c = Logined_Student->MainMenu() != 'x') {
			switch (c)
			{
			case 't':
				Logined_Student->takeExamination();
				break;
			case 'v':
				Logined_Student->viewGradeReport();
				break;
			case 'u':
				Logined_Student->updatePasswd();
				break;
			default:
				break;
			}
		}
	}

	else
	{
		system("cls");
		cout << "Login Failed.\nThere is no ID in Information\n";
		cout << "Do you want Login again? y/n\n";
		cin >> c;
		while (1) {
			switch (c) {
			case 'y':
				system("cls");
				goto __LoginGate__;
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
	if (Admin_Search.fail()) {
		system("cls");
		cerr << "Fail to Open InstructorList.bin" << endl;
		exit(EXIT_FAILURE);
	}
	cout << endl << endl << endl;
	cout << "            ---------------- Login ----------------" << endl;
	cout << "            |                                     |" << endl;
	cout << "            |      Enter username :               |" << endl;
	cout << "            |      Enter password :               |" << endl;
	cout << "            |                                     |" << endl;
	cout << "            ---------------- Login ----------------" << endl;

	gotoxy(37, 6); // Move cursor to input user id

	char output;
	for (int i = 0; i < 4; i++)
		Admin_Search >> instructor[i];

	cin >> pass;
	//Input ID
	while (1) {
		if (instructor[1] == pass)
			break;
		else if (!Admin_Search.eof())
			for (int i = 0; i < 4; i++)
				Admin_Search >> instructor[i];
		else
			return 0;

		cin.clear();
	}

	Logined_Admin = new Instructor(instructor[0], instructor[1], instructor[2], instructor[3]);


	//Input PassWord
	int count;
	while (1) {
		count = 0;
		

		while (1) {
			gotoxy(37, 7);//Move cursor to input password
			pass = "";
			while ((output = _getch())!='\r')
			{
				pass += output;
				cout << "*";
				count++;
			}
			if (pass == instructor[3])
				return 1;

			else {
				gotoxy(37, 7);
				for (int i = 0;i < count; i++)
					cout << " ";
			}
		}

	}

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


	while (1) {
		if (student[1] == pass)
			break;
		else if (!Student_Search.eof())
			for (int i = 0; i < 4; i++)
				Student_Search >> student[i];
		else
			return 0;

		cin.clear();
	}

	Logined_Student = new Student(student[0], student[1], student[2], student[3]);

	//Input PassWord
	int count;
	while (1) {
		count = 0;
		

		while (1) {
			pass = "";
			gotoxy(37, 7);//Move cursor to input password
			while ((output = _getch()) != '\r')
			{
				pass += output;
				cout << "*";
				count++;
			}
			if (pass == student[3])
				return 1;

			else {
				gotoxy(37, 7);
				for (int i = 0;i < count; i++)
					cout << " ";
			}
		}

	}

	return 0;
}

void gotoxy(int x, int y)
{
	COORD pos;
	pos.X = x - 1;
	pos.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}