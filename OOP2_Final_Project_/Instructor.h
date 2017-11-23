#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

class Instructor {
private:
	string instructno;
	string name;
	string rank;
	string passwd;
public:
	Instructor(string, string, string, string);
	string GetInstructno();
	string GetName();
	string GetRank();
	void SetInstructno(int);
	void SetName(string);
	void SetRank(string);
	void StudentInformation(); //Instructor Main Menu Funtion
	void InstructorInformation();//Instructor Main Menu Funtion
	void QuestionInformation();//Instructor Main Menu Funtion
	void SubjectInformation();//Instructor Main Menu Funtion
	void GradeInformation();//Instructor Main Menu Funtion
	char MainMenu();//Instructor Main Menu Interface
	void updatePasswd();
	void BuildFile();

};

Instructor::Instructor(string a, string b, string c, string d) : instructno(a), name(b), rank(c), passwd(d) {}

void Instructor::StudentInformation() {
	ifstream studentinfo("StudentList.bin", ios::in | ios::binary);
}
void Instructor::InstructorInformation() {
	ifstream InstructorInfo("InstructorList.bin", ios::in | ios::binary);
}
void Instructor::QuestionInformation() {
	ifstream QuestionInfo("QuestionList.bin", ios::in | ios::binary);
}
void Instructor::SubjectInformation() {
	ifstream SubjectInfo("SubjectList.bin", ios::in | ios::binary);
}
void Instructor::GradeInformation() {
	ifstream GradeInfo("GradeList.bin", ios::in | ios::binary);
}
char Instructor::MainMenu() {
	char output;
	system("cls");
	cout << endl;
	cout << "             ----<Admin>Instructor Main Menu-----\n";
	cout << "             |                                  |\n";
	cout << "             |     <S>TUDENT INFORMATION        |\n";
	cout << "             |     <I>NSTRUCTOR INFORMATION     |\n";
	cout << "             |     <Q>UESTION INFORMATION       |\n";
	cout << "             |     <J>SUBJECT INFORMATION       |\n";
	cout << "             |     <G>GRADE INFORMATION         |\n";
	cout << "             |     <U>Update password           |\n";
	cout << "             |     <B>BUILD FILES               |\n";
	cout << "             |     <X>EXIT                      |\n";
	cout << "             |                                  |\n";
	cout << "             ------------------------------------\n";
	cin >> output;
	return output;
}

string Instructor::GetInstructno() { return instructno; }
string Instructor::GetName() { return name; }
string Instructor::GetRank() { return rank; }
void Instructor::SetInstructno(int a) {
	instructno = a;
}
void Instructor::SetName(string a) {
	name = a;
}
void Instructor::SetRank(string a) {
	rank = a;
}
void Instructor::updatePasswd() {

}
void Instructor::BuildFile() {

}
