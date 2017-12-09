#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

class Student {

private:
	int studno;
	char name[20];
	char course[30];
	// 변수들이 return type은 확실하지 않음

public:
	char passwd[30];
	Student(int = 0, const std::string& = "", const std::string& = "", const std::string& = "");
	int getStudno();
	string getName();
	string getCourse();
	string getPasswd();

	void setStudno(int);
	void setName(string);
	void setCourse(string);
	void setPasswd(string);

	void takeExamination(); // Student Main Menu Funtion
	void viewGradeReport(); // Student Main Menu Funtion
	void updatePasswd(); // Student Main Menu Funtion

	char MainMenu();//Student Main Menu Interface
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

void Student::takeExamination() {
	ifstream inClientFile("QuestionList.bin", ios::in | ios::binary);
}

void Student::viewGradeReport() {
	ifstream inClientFile("GradeList.bin", ios::in | ios::binary);
}

void Student::updatePasswd() {
	ifstream inClientFile("StudentList.bin", ios::in | ios::binary);
}


char Student::MainMenu() {
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