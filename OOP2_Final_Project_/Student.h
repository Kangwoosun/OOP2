#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

class Student {
private:
	string studno;
	string name;
	string course;
	// 변수들이 return type은 확실하지 않음
public:
	string passwd;

	Student(string, string, string, string);
	string getStudno();
	string getName();
	string getCourse();
	string getPasswd();

	void setStudno(string);
	void setName(string);
	void setCourse(string);
	void setPasswd(string);

	void takeExamination(); // Student Main Menu Funtion
	void viewGradeReport(); // Student Main Menu Funtion
	void updatePasswd(); // Student Main Menu Funtion

	char MainMenu();//Student Main Menu Interface
};

Student::Student(string _studno, string _name, string _course, string _passwd)
	: studno(_studno), name(_name), course(_course), passwd(_passwd) {}

string Student::getStudno() {
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

void Student::setStudno(string _studno) {
	studno = _studno;
}

void Student::setName(string _name) {
	name = _name;
}
void Student::setCourse(string _course) {
	course = _course;
}

void Student::setPasswd(string _passwd) {
	passwd = _passwd;
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
	system("cls");
	cout << "\n\n\n\n          ---------------Main Menu----------------\n"
		<< "          |       <T>ake examination             |\n"
		<< "          |       <V>iew grade report            |\n"
		<< "          |       <U>pdate password              |\n"
		<< "          |       <X>EXIT                        |\n"
		<< "          |--------------------------------------|\n";
	cin >> input;
	return input;
}