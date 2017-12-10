#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Subject.h"
#include "Question.h"
#include "Grade.h"
#include "Instructor.h"
using namespace std;

void outputLine_sublist(ostream &, Subject&);
void outputLine_exam(ostream &, Question&);
void gotoxy(int x, int y);

class Student {
	int studno;
	char name[20];
	char course[30];
	char passwd[30];

public:
	/* Constructor & Set & Get Function */
	Student(int = 0, const std::string& = "", const std::string& = "", const std::string& = "");
	int getStudno();
	string getName();
	string getCourse();
	string getPasswd();

	void setStudno(int);
	void setName(string);
	void setCourse(string);
	void setPasswd(string);

	/* Student Main Menu Funtion */
	void takeExamination();
	void viewGradeReport();
	void updatePasswd();

	/* Student Main Menu Interface */
	char MainMenu();
};

/* Constructor & Set & Get Function */
Student::Student(int _studno, const string& _name, const string& _course, const string& _passwd)
{
	setStudno(_studno);
	setName(_name);
	setCourse(_course);
	setPasswd(_passwd);
}

int Student::getStudno() {
	return studno;
}

string Student::getName() {
	return name;
}

string Student::getCourse() {
	return course;
}

string Student::getPasswd() {
	return passwd;
}

void Student::setStudno(int _studno) {
	studno = _studno;
}

void Student::setName(string _name) {
	int length = _name.size();
	length = (length < 20 ? length : 19);
	_name.copy(name, length);
	name[length] = '\0';
}

void Student::setCourse(string _course) {
	int length = _course.size();
	length = (length < 20 ? length : 19);
	_course.copy(course, length);
	course[length] = '\0';
}

void Student::setPasswd(string _passwd) {
	int length = _passwd.size();
	length = (length < 20 ? length : 19);
	_passwd.copy(passwd, length);
	passwd[length] = '\0';
}
/* End Constructor & Set & Get Function */


/* Student Main menu function */
void Student::takeExamination() {
	system("cls");

	ifstream printSub("SubjectList.bin", ios::in | ios::binary);
	if (!printSub) {
		cerr << "Error printSub can't open SubjectList.bin!" << endl;
		exit(EXIT_FAILURE);
	}
	// open the "SubjectList.bin" file to print the subject list and choose subject to take exam

	// print the subject number, name
	cout << "Examination for the Subject\n";
	cout << "-------------------------------------------------------\n";
	cout << left << setw(10) << "SUBJECTNO" << setw(20) << "DESCRIPTION" << endl;

	Subject tmpsubject;
	printSub.read(reinterpret_cast<char*>(&tmpsubject),
		sizeof(Subject));

	while (printSub && !printSub.eof())
	{
		if (tmpsubject.GetSubjectno() != 0)
			outputLine_sublist(cout, tmpsubject);
		printSub.read(reinterpret_cast<char*>(&tmpsubject),
			sizeof(Subject));
	}

	// receive the subject number and examination period
	int subnumber;
	cout << "\nEnter Subject number : ";
	cin >> subnumber;

	string _period;
	cout << "\nEnter Examination Period : ";
	cin >> _period;

	printSub.clear();
	printSub.seekg(0, ios::beg);
	do {
		printSub.read(reinterpret_cast<char*>(&tmpsubject),
			sizeof(Subject));
	} while (tmpsubject.GetSubjectno() != subnumber);

	string subname = tmpsubject.GetSubname();
	// find the subject name of the subject-object that has same number with entered subject number. assign the subject name to variable subname. 

	// open the "QuestionList.bin" file to read and print the questions.
	fstream takeExam("QuestionList.bin", ios::in | ios::out | ios::binary);
	if (!takeExam) {
		cerr << "Error takeExam can't open QuestionList.bin!" << endl;
		exit(EXIT_FAILURE);
	}

	system("cls");
	// print Qustion list
	cout << "--------------------------------Questions--------------------------------\n";
	cout << left << "Name: " << this->getName();
	cout << "         Subject: " << subname << "         Period: " << _period << endl;
	cout << "-------------------------------------------------------------------------\n";

	Question tmpexam;
	takeExam.clear();
	takeExam.seekg(0, ios::beg);
	int count = 0; // variable that counts how many print. this var is used in how many receive the answer.
	takeExam.read(reinterpret_cast<char*>(&tmpexam),
		sizeof(Question));

	// print the questions that are matches with subname, post is true and the period is same with entered period
	while (takeExam && !takeExam.eof())
	{
		if (tmpexam.getsubject() == subname && tmpexam.getpost() == "true"
			&&  tmpexam.getperiod() == _period)
		{
			outputLine_exam(cout, tmpexam);
			count++;
		}
		takeExam.read(reinterpret_cast<char*>(&tmpexam),
			sizeof(Question));
	}

	// receive the answer for each question
	int _num = 1;
	char enterans[100]; // a or b or c
	for (int i = 0; i < count; i++)
	{
		gotoxy(70, 4 * _num);
		cin >> enterans[i];
		_num += 1;
	}

	// after comparing the entered answer with anskey and save in score variable.
	takeExam.clear();
	takeExam.seekg(0, ios::beg);
	int score = 0; // count the correct answer's number.
	int _count = 0; //
	takeExam.read(reinterpret_cast<char*>(&tmpexam),
		sizeof(Question));
	while (takeExam && !takeExam.eof())
	{
		if (tmpexam.getsubject() == subname && tmpexam.getpost() == "true"
			&&  tmpexam.getperiod() == _period)
		{
			if (enterans[_count] == 'a') {
				if (tmpexam.getchoice1() == tmpexam.getanskey())
					score++;
			}
			else if (enterans[_count] == 'b') {
				if (tmpexam.getchoice2() == tmpexam.getanskey())
					score++;
			}
			else if (enterans[_count] == 'c') {
				if (tmpexam.getchoice3() == tmpexam.getanskey())
					score++;
			}
			_count++;
		}
		takeExam.read(reinterpret_cast<char*>(&tmpexam),
			sizeof(Question));
	}

	fstream manageGrade("GradeList.bin", ios::in | ios::out | ios::binary);
	if (!manageGrade) {
		cerr << "Error! manageGrade can't openGradeList.bin!" << endl;
		exit(EXIT_FAILURE);
	}

	// save the grade to midscore(if entered period is midterm) or finalscore(if finalexam).
	int _studno = this->getStudno();
	Grade _tmpgrade;

	do {
		manageGrade.read(reinterpret_cast<char*>(&_tmpgrade),
			sizeof(Grade));
	} while (_tmpgrade.getStudno() != this->getStudno());

	if (_period == "midterm")
	{
		Grade tmpgrade(_studno, _period, score, _tmpgrade.getFinalScoreEq(), subname);
		manageGrade.write(reinterpret_cast<const char *>(&tmpgrade), sizeof(Grade));
	}
	else if (_period == "finalexam")
	{
		Grade tmpgrade(_studno, _period, _tmpgrade.getMidScoreEq(), score, subname);
		manageGrade.write(reinterpret_cast<const char *>(&tmpgrade), sizeof(Grade));
	}

	gotoxy(1, _count * 4 + 5); // move the cursor to bottom
	cout << "Your Grade is updated on GradeList, enter x to exit\n";
	char n;
	cin >> n;

	takeExam.close();
	printSub.close();
	manageGrade.close();
}

void outputLine_sublist(ostream &output, Subject& record) {
	output << left << setw(10) << record.GetSubjectno()
		<< setw(20) << record.GetSubname() << endl;
}

void outputLine_exam(ostream &output, Question& record) {
	output << left << setw(3) << record.getqno()
		<< setw(50) << record.getque();
	output << record.getqno() << " Answer here :" << endl;
	output << "  a. " << setw(20) << record.getchoice1() << endl
		<< "  b. " << setw(20) << record.getchoice2() << endl
		<< "  c. " << setw(20) << record.getchoice3() << endl;
	//gotoxy();
	//output << record.getqno() << " Answer here :" << endl;
}

void Student::viewGradeReport() { // print the grade information about the logined student
	ifstream inClientFile("GradeList.bin", ios::in | ios::binary);
	system("cls");
	Grade tmpGrade;
	do { inClientFile.read(reinterpret_cast<char *> (&tmpGrade), sizeof(Grade)); } while (this->getStudno() != tmpGrade.getStudno());

	cout << "---------------------------GRADE LIST--------------------------\n";
	cout << "Name: " << this->getName() << endl;
	cout << "---------------------------------------------------------------\n"
		<< left << setw(12) << "STUDENTNO" << setw(9) << "PERIOD" << setw(15) << "SUBJECT" << setw(11) << "MIDSCORE" << setw(13) << "FINALSCORE" << endl
		<< setw(12) << tmpGrade.getStudno() << setw(9) << tmpGrade.getperiod() << setw(15) << tmpGrade.getSubject()
		<< setw(11) << tmpGrade.getMidScoreEq() << setw(13) << tmpGrade.getFinalScoreEq() << endl;

	char x;
	cout << "Enter x to exit\n";
	cin >> x;
	if (x = 'x')
	{
		return;
	}
	else {
		"You entered the wrong number! Please Enter the 'x' to exit";
	}
}

void Student::updatePasswd() { // update the passwd of logined student
	system("cls");
	fstream UpdatingPasswd("StudentList.bin", ios::in | ios::out | ios::binary);
	if (!UpdatingPasswd) {
		cerr << "Error Studentinfo can't open StudentList.bin!" << endl;
		exit(EXIT_FAILURE);
	}

	Student tmpStudent;
	UpdatingPasswd.read(reinterpret_cast<char *> (&tmpStudent), sizeof(Student));

	while (1) { // read the object until find the object that has logined student's name
		if (!(this->getName().compare(tmpStudent.getName())))
			break;

		else if (!UpdatingPasswd.eof())
			UpdatingPasswd.read(reinterpret_cast<char *> (&tmpStudent), sizeof(Student));
		else
			return;
	}

	string NewPasswd;
	cout << "Password must be within 29 characters!";
	cout << "\nPlease Input NewPasswd : ";
	cin >> NewPasswd;
	this->setPasswd(NewPasswd);
	long pos = UpdatingPasswd.tellp();
	UpdatingPasswd.seekp(pos - sizeof(Student));
	UpdatingPasswd.write(reinterpret_cast<const char*> (this), sizeof(Student));
	return;
}
/* End Student Main menu function */

char Student::MainMenu() {
	system("cls");
	char input;
	cout << endl;
	cout << "     ---------------Main Menu----------------\n"
		<< "     |       <T>ake examination             |\n"
		<< "     |       <V>iew grade report            |\n"
		<< "     |       <U>pdate password              |\n"
		<< "     |       <X>EXIT                        |\n"
		<< "     |--------------------------------------|\n";
	cin >> input;
	return input;
}