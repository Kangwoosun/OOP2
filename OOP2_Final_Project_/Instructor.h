#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Student.h"
#include "Grade.h"
#include "Question.h"
#include "Subject.h"
using namespace std;


class Instructor {
private:
	int instructno;
	char name[20];
	char rank[20];
	char passwd[30];

public:
	Instructor(int = 0, const std::string& = "", const std::string& = "", const std::string& = "");
	int getInstructno();
	string getName();
	string getRank();
	string getPasswd();
	void SetInstructno(int);
	void SetName(const string&);
	void SetRank(const string&);
	void SetPasswd(const string&);

	char submenuforstudent();
	char submenuforinstructor();
	char submenuforquestion();

	/*Instructor Main Menu Funtion*/
	void StudentInformation();
	/* sub menu for stu*/
	void ShowStuList();
	void UpdateStu();
	void AddNewStu();
	void DeleteStu();

	void InstructorInformation();
	/* sub menu for instructor*/
	void ShowInsList();
	void UpdateIns();
	void AddNewIns();
	void DeleteIns();

	void QuestionInformation();
	/* sub menu for question*/
	void ShowQueList();
	void UpdateQue();
	void AddNewQue();
	void DeleteQue();

	void SubjectInformation();
	/* sub menu for subject */
	void ShowSublist();
	void AddSublist();
	void delSublist();


	void GradeInformation();
	/* sub menu for gra*/

	void updatePasswd();
	void BuildFile();
	/*End Instructor Main Menu Funtion*/


	/* -- Main Menu & Sub Menu-- */
	char MainMenu();
};
void outputLine_stu(ostream &, Student&);
void outputLine_ins(ostream &, Instructor&);
void outputLine_sub(ostream &, Subject&);

/* Constructor & Set & Get Function */
Instructor::Instructor(int _instructno, const string& _name, const string& _rank, const string& _passwd) {
	instructno = _instructno;
	SetName(_name);
	SetRank(_rank);
	SetPasswd(_passwd);
}

int Instructor::getInstructno() { return instructno; }
string Instructor::getName() { return name; }
string Instructor::getRank() { return rank; }
string Instructor::getPasswd() { return passwd; }

void Instructor::SetInstructno(int a) {
	instructno = a;
}

void Instructor::SetName(const string& _name) {
	int length = _name.size();
	length = (length < 20 ? length : 19);
	_name.copy(name, length);
	name[length] = '\0';
}

void Instructor::SetRank(const string& _rank) {
	int length = _rank.size();
	length = (length < 20 ? length : 19);
	_rank.copy(rank, length);
	rank[length] = '\0';
}

void Instructor::SetPasswd(const string& _passwd) {
	int length = _passwd.size();
	length = (length < 30 ? length : 29);
	_passwd.copy(passwd, length);
	passwd[length] = '\0';
}


/* --Instructor Main Menu Funtion-- */
void Instructor::StudentInformation() {
	ifstream studentinfo("StudentList.bin", ios::in | ios::binary);

	char c;
	while (c = submenuforstudent() != 'x') {
		switch (c)
		{
		case 's':
			ShowStuList();
			break;

		case 'u':
			// update student
			break;

		case 'a':
			//add new student
			break;

		case 'd':
			//delete student
			break;

		default:
			break;
		}
	}
}
void Instructor::InstructorInformation() {
	ifstream studentinfo("InstructorList.bin", ios::in | ios::binary);
	char c;
	while (c = submenuforinstructor() != 'x') {
		switch (c)
		{
		case 's':
			ShowInsList();
			break;

		case 'u':
			break;

		case 'a':
			break;

		case 'd':
			break;

		default:
			break;
		}
	}
}
void Instructor::QuestionInformation() {
	ifstream studentinfo("QuestionList.bin", ios::in | ios::binary);

	char c;
	while (c = submenuforquestion() != 'x') {
		switch (c)
		{
		case 's':
			// show question list
			break;

		case 'u':
			break;

		case 'a':
			break;

		case 'd':
			break;

		default:
			break;
		}
	}
}

void Instructor::SubjectInformation() {
	ifstream studentinfo("SubjectList.bin", ios::in | ios::binary);

	cout << endl << "     ";
	cout << "     " << " ---Instructor sub-menu for Subject Information-\n";
	cout << "     " << " |                                             |\n";
	cout << "     " << " |             <S>how Subject list             |\n";
	cout << "     " << " |             <U>pdate Subject                |\n";
	cout << "     " << " |             <A>dd new Subject               |\n";
	cout << "     " << " |             <D>elete Subject                |\n";
	cout << "     " << " |             <X>EXIT back to main            |\n";
	cout << "     " << " |---------------------------------------------|\n";
	cout << "     ";
	char choice;
	cin >> choice;
	while (choice != 'x') {
		switch (choice) {
		case 's':
			ShowSublist();
			break;
		case 'u':
			break;
		case 'a':
			AddSublist();
			break;
		case 'd':
			break;
		case 'x':
			break;

		}
		cin >> choice;
	}
}

void Instructor::GradeInformation() {
	ifstream GradeInfo("GradeList.bin", ios::in | ios::binary);
}

void Instructor::updatePasswd() {

}
void Instructor::BuildFile() {

}
/* --End Instructor Main Menu Funtion-- */


/* --Main Menu-- */
char Instructor::MainMenu() {
	char mainmenu;
	system("cls");
	cout << endl;
	cout << " ----<Admin> Instructor Main Menu----\n"
		<< " |                                  |\n"
		<< " |     <S>TUDENT INFORMATION        |\n"
		<< " |     <I>NSTRUCTOR INFORMATION     |\n"
		<< " |     <Q>UESTION INFORMATION       |\n"
		<< " |     <J>SUBJECT INFORMATION       |\n"
		<< " |     <G>RADE INFORMATION          |\n"
		<< " |     <U>PDATE PASSWORDS           |\n"
		<< " |     <B>UILD FILES                |\n"
		<< " |     <X>EXIT                      |\n"
		<< " |                                  |\n"
		<< " |--------------------------------------|\n";
	cin >> mainmenu;
	return mainmenu;
}
/* -- END Main Menu-- */


/* --Sub Menu-- */
char Instructor::submenuforstudent() {
	char submenu;
	system("cls");
	cout << endl;
	cout << " ----Admin sub-menu for Student Information----\n"
		<< " |                                             |\n"
		<< " |     <S>how student list                     |\n"
		<< " |     <U>pdate Student                        |\n"
		<< " |     <A>dd new student                       |\n"
		<< " |     <D>elete Student                        |\n"
		<< " |     <X>EXIT                                 |\n"
		<< " -----------------------------------------------\n";
	cin >> submenu;
	return submenu;
}

char Instructor::submenuforinstructor() {
	char submenu;
	system("cls");
	cout << endl;
	cout << " ----Admin sub-menu for Instructor----\n"
		<< " |                                    |\n"
		<< " |     <S>how Instructor list         |\n"
		<< " |     <U>pdate Instructor            |\n"
		<< " |     <A>dd new Instructor           |\n"
		<< " |     <D>elete Instructor record     |\n"
		<< " |     <X>Exit return main menu       |\n"
		<< " --------------------------------------\n";
	cin >> submenu;
	return submenu;
}

char Instructor::submenuforquestion() {
	char submenu;
	system("cls");
	cout << endl;
	cout << " ----Admin sub-menu for Question Information----\n"
		<< " |                                              |\n"
		<< " |     <S>how Question list                     |\n"
		<< " |     <U>pdate Question                        |\n"
		<< " |     <A>dd new Question                       |\n"
		<< " |     <D>elete Question record                 |\n"
		<< " |     <X>Exit return main menu                 |\n"
		<< " ------------------------------------------------\n";
	cin >> submenu;
	return submenu;

} /* -- END Sub Menu-- */


  /* --Functions for sub-menu for STUDENT-- */
void Instructor::ShowStuList() {
	ifstream studentinfo("StudentList.bin", ios::in | ios::binary);

	cout << "--------------------STUDENT LIST--------------------\n";
	cout << left << setw(7) << "STUDNO" << setw(20) << "NAME" << setw(30) << "COURSE\n";

	Student tmpstudent;

	studentinfo.read(reinterpret_cast<char*>(&tmpstudent),
		sizeof(Student));

	while (studentinfo && !studentinfo.eof())
	{
		if (tmpstudent.getStudno() != 0)
			outputLine_stu(cout, tmpstudent);

		studentinfo.read(reinterpret_cast<char*>(&tmpstudent),
			sizeof(Student));
	}
}

void Instructor::UpdateStu() {

}

void Instructor::AddNewStu() {

}

void Instructor::DeleteStu() {

}

void outputLine_stu(ostream &output, Student& record) {
	output << left << setw(7) << record.getStudno()
		<< setw(20) << record.getName()
		<< setw(30) << record.getCourse() << endl;
}
/* -- end Functions for sub-menu for STUDENT-- */


/* --Functions for sub-menu for INSTRUCTOR-- */
void Instructor::ShowInsList() {
	ifstream instructorinfo("InstructorList.bin", ios::in | ios::binary);

	cout << "--------------------INSTRUCTOR'S LIST--------------------\n";
	cout << left << setw(15) << "INSTRUCTORNO" << setw(20) << "NAME" << setw(20) << "RANK\n";

	Instructor tmpinstructor;

	instructorinfo.read(reinterpret_cast<char*>(&tmpinstructor),
		sizeof(Instructor));

	while (instructorinfo && !instructorinfo.eof())
	{
		if (tmpinstructor.getInstructno() != 0)
			outputLine_ins(cout, tmpinstructor);

		instructorinfo.read(reinterpret_cast<char*>(&tmpinstructor),
			sizeof(Instructor));
	}
}

void Instructor::UpdateIns() {

}

void Instructor::AddNewIns() {

}

void Instructor::DeleteIns() {

}

void outputLine_ins(ostream &output, Instructor& record) {
	output << left << setw(7) << record.getInstructno()
		<< setw(20) << record.getName()
		<< setw(30) << record.getRank() << endl;
}
/* --End Functions for sub-menu for INSTRUCTOR-- */



/* --Functions for sub-menu for QUESTION-- */
void Instructor::ShowQueList() {

}

void Instructor::UpdateQue() {

}

void Instructor::AddNewQue() {

}

void Instructor::DeleteQue() {

}

void outputLine_que(ostream &output, Question& record) {
	/*output << left << setw(7) << record.getInstructno()
	<< setw(20) << record.getName()
	<< setw(30) << record.getRank() << endl;*/
}
/* --End Functions for sub-menu for QUESTION-- */

/* --Functions for sub-menu for SUBJECT-- */
void Instructor::ShowSublist() {
	system("cls");
	ifstream subjectinfo("SubjectList.bin", ios::in | ios::binary);
	cout << "---------------------------SUBJECT LIST--------------------------\n"
		<< left << setw(13) << "SUBJECTNO" << setw(13) << "DESCRIPTION" << setw(13) << "UNITS\n";
	Subject tmpsubject;
	subjectinfo.read(reinterpret_cast<char*>(&tmpsubject), sizeof(Subject));
	while (subjectinfo && !subjectinfo.eof()) {
		if (tmpsubject.GetSubjectno() != 0) {
			outputLine_sub(cout, tmpsubject);
			subjectinfo.read(reinterpret_cast<char*>(&tmpsubject), sizeof(Subject));
		}
	}
}

void Instructor::AddSublist() {
	int num;
	string subname;
	int unit;

	ofstream addsubject("SubjectList.bin", ios::app | ios::binary);
	Subject addsub;
	cin.ignore();
	cout << "과목 번호를 입력해" << endl;
	cin >> num;
	cout << "이름을 입력해라!!!!!!!!!!!!!!" << endl;
	cin >> subname;
	cout << "unit번호를 입력해 >3<" << endl;
	cin >> unit;
	addsub.SetSubjectno(num);
	addsub.SetSubname(subname);
	addsub.SetSubunit(unit);
	addsubject.write(reinterpret_cast<const char *>(&addsub), sizeof(Subject));
}
/*
void Instructor::delSublist() {
system("cls");
ifstream subjectinfo("SubjectList.bin", ios::in | ios::binary);
cout << "Write numer of subject which you want to delete.";
int num;
cin >> num;
Subject tmpsubject;
subjectinfo.read(reinterpret_cast<char*>(&tmpsubject), sizeof(Subject));
while (subjectinfo && !subjectinfo.eof()) {
if (tmpsubject.GetSubjectno() != num) {
outputLine_sub(cout, tmpsubject);
subjectinfo.read(reinterpret_cast<char*>(&tmpsubject), sizeof(Subject));
}
else return; //여기서 지워야됨.
}
}
*/

void outputLine_sub(ostream &output, Subject& record) {
	output << setw(13) << record.GetSubjectno()
		<< setw(13) << record.GetSubname()
		<< setw(13) << record.GetSubunit() << endl;
}
/* --Functions for sub-menu for SUBJECT-- */