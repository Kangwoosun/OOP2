#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

class Instructor {
private:
	int instructno;
	string name;
	string rank;
	char* passwd;
public:
	int GetInstructno();
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
	
};

void Instructor::StudentInformation() {
	ifstream studentinfo("StudentList.bin", ios::in | ios::binary);
}
void Instructor::InstructorInformation() {
	ifstream studentinfo("InstructorList.bin", ios::in | ios::binary);
}
void Instructor::QuestionInformation() {
	ifstream studentinfo("QuestionList.bin", ios::in | ios::binary);
}
void Instructor::SubjectInformation() {
	ifstream studentinfo("SubjectList.bin", ios::in|ios::binary);
}
void Instructor::GradeInformation() {

}
char Instructor::MainMenu() {
	char output;
	cout << "";
	cin >> output;
	return output;
}

int Instructor::GetInstructno() { return instructno; }
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







