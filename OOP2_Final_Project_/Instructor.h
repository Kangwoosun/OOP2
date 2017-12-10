#pragma once
#pragma warning(disable:4996)
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
	/* Constructor & Set & Get Function */
	Instructor(int = 0, const std::string& = "", const std::string& = "", const std::string& = "");
	int getInstructno();
	string getName();
	string getRank();
	string getPasswd();
	void SetInstructno(int);
	void SetName(const string&);
	void SetRank(const string&);
	void SetPasswd(const string&);

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
	void UpdateSublist();
	void delSublist();

	void GradeInformation();
	/* sub menu for grade*/
	void ShowGrdlist();
	void UpdateGrdlist();
	void AddGrdlist();
	void delGrdlist();
	char SubmenuforGrade();

	void BuildFile();
	/* sub menu for buildfile*/
	char subbuildfile();
	void build_studentfile();
	void build_instructorfile();
	void build_gradefile();
	void build_questionfile();
	void build_subjectfile();

	void updatePasswd(); // Function that updates logined Instructor's password. 
						 /*End Instructor Main Menu Funtion*/

						 /* -- Main Menu & Sub Menu-- */
	char MainMenu();
	char submenuforstudent();
	char submenuforinstructor();
	char submenuforquestion();
	char SubmenuforSubject();
};

void outputLine_stu(ostream &, Student&);
void outputLine_ins(ostream &, Instructor&);
void outputLine_sub(ostream &, Subject&);
void outputLine_que(ostream &, Question&);
void outputLine_grd(ostream &, Grade&);

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
	char c;
	while ((c = submenuforstudent()) != 'x') {
		switch (c)
		{
		case 's':
			ShowStuList();
			break;

		case 'u':
			UpdateStu();
			break;

		case 'a':
			AddNewStu();
			break;

		case 'd':
			DeleteStu();
			break;

		default:
			break;
		}
	}
}
void Instructor::InstructorInformation() {
	char c;
	while ((c = submenuforinstructor()) != 'x') {
		switch (c)
		{
		case 's':
			ShowInsList();
			break;
		case 'u':
			UpdateIns();
			break;
		case 'a':
			AddNewIns();
			break;
		case 'd':
			DeleteIns();
			break;

		default:
			break;
		}
	}
}
void Instructor::QuestionInformation() {
	char c;
	while ((c = submenuforquestion()) != 'x') {
		switch (c)
		{
		case 's':
			ShowQueList();
			break;

		case 'u':
			UpdateQue();
			break;

		case 'a':
			AddNewQue();
			break;

		case 'd':
			DeleteQue();
			break;

		default:
			break;
		}
	}
}

void Instructor::SubjectInformation() { // provide choice which makes user to choose what to do.
	char choice;
	while ((choice = SubmenuforSubject()) != 'x') {
		switch (choice) {
		case 's':
			ShowSublist();
			break;
		case 'u':
			UpdateSublist();
			break;
		case 'a':
			AddSublist();
			break;
		case 'd':
			delSublist();
			break;
		case 'x':
			break;
		}
	}
}

void Instructor::GradeInformation() {

	char choice;
	while ((choice = SubmenuforGrade()) != 'x') {
		switch (choice) {
		case 's':
			ShowGrdlist();
			break;
		case 'u':
			UpdateGrdlist();
			break;
		case 'a':
			AddGrdlist();
			break;
		case 'd':
			delGrdlist();
			break;
		case 'x':
			break;
		}
	}

}

void Instructor::updatePasswd() {
	system("cls");

	Instructor tmpInstructor; // Make temporary object to read from file and write on file.
	fstream UpdatingPasswd("InstructorList.bin", ios::in | ios::out | ios::binary);
	if (!UpdatingPasswd) { // Check whether file was opened or not.
		cerr << "Error Studentinfo can't open InstructorList.bin!" << endl;
		exit(EXIT_FAILURE);
	}

	UpdatingPasswd.read(reinterpret_cast<char *> (&tmpInstructor), sizeof(Instructor));
	//Input ID
	while (1) {
		if (!(this->getName().compare(tmpInstructor.getName())))// If user's ID is same with object's ID, escape while loop.
			break;
		else if (!UpdatingPasswd.eof())
			UpdatingPasswd.read(reinterpret_cast<char *> (&tmpInstructor), sizeof(Instructor));// Read data from file to object. then repeat while loop.
		else
			return;
	}

	string NewPasswd;

	cout << "Password must be within 29 characters!";
	cout << "\nPlease Input NewPasswd : ";
	cin >> NewPasswd; // Input password. It will be user's new password.
	this->SetPasswd(NewPasswd); // Modify password using set function.
	long pos = UpdatingPasswd.tellp();
	UpdatingPasswd.seekp(pos - sizeof(Instructor));
	UpdatingPasswd.write(reinterpret_cast<const char*> (this), sizeof(Instructor)); // Modify file.
	return;
}


/* --Main Menu-- */
char Instructor::MainMenu() {
	char mainmenu;
	system("cls");
	cout << endl;
	cout << "     ----<Admin> Instructor Main Menu----\n"
		<< "     |                                  |\n"
		<< "     |     <S>TUDENT INFORMATION        |\n"
		<< "     |     <I>NSTRUCTOR INFORMATION     |\n"
		<< "     |     <Q>UESTION INFORMATION       |\n"
		<< "     |     <J>SUBJECT INFORMATION       |\n"
		<< "     |     <G>RADE INFORMATION          |\n"
		<< "     |     <U>PDATE PASSWORDS           |\n"
		<< "     |     <B>UILD FILES                |\n"
		<< "     |     <X>EXIT                      |\n"
		<< "     |                                  |\n"
		<< "     |----------------------------------|\n";
	cin >> mainmenu;
	return mainmenu;
}
/* -- END Main Menu-- */


/* --Sub Menu-- */
char Instructor::submenuforstudent() {
	char submenu;
	cout << endl << endl;
	cout << "      ----Admin sub-menu for Student Information----\n"
		<< "      |                                             |\n"
		<< "      |     <S>how student list                     |\n"
		<< "      |     <U>pdate Student                        |\n"
		<< "      |     <A>dd new student                       |\n"
		<< "      |     <D>elete Student                        |\n"
		<< "      |     <X>EXIT                                 |\n"
		<< "      -----------------------------------------------\n";
	cin >> submenu;
	system("cls");
	return submenu;
}

char Instructor::submenuforinstructor() {
	char submenu;
	cout << endl << endl;
	cout << "      ----Admin sub-menu for Instructor----\n"
		<< "      |                                    |\n"
		<< "      |     <S>how Instructor list         |\n"
		<< "      |     <U>pdate Instructor            |\n"
		<< "      |     <A>dd new Instructor           |\n"
		<< "      |     <D>elete Instructor record     |\n"
		<< "      |     <X>Exit return main menu       |\n"
		<< "      --------------------------------------\n";
	cin >> submenu;
	system("cls");
	return submenu;
}

char Instructor::submenuforquestion() {
	char submenu;
	cout << endl;
	cout << "      ----Admin sub-menu for Question Information----\n"
		<< "      |                                              |\n"
		<< "      |     <S>how Question list                     |\n"
		<< "      |     <U>pdate Question                        |\n"
		<< "      |     <A>dd new Question                       |\n"
		<< "      |     <D>elete Question record                 |\n"
		<< "      |     <X>Exit return main menu                 |\n"
		<< "      ------------------------------------------------\n";
	cin >> submenu;
	system("cls");
	return submenu;
}

char Instructor::SubmenuforSubject() {
	char choice;
	cout << endl << "     " << endl;
	cout << "     " << " ---Instructor sub-menu for Subject Information-\n";
	cout << "     " << " |                                             |\n";
	cout << "     " << " |             <S>how Subject list             |\n";
	cout << "     " << " |             <U>pdate Subject                |\n";
	cout << "     " << " |             <A>dd new Subject               |\n";
	cout << "     " << " |             <D>elete Subject                |\n";
	cout << "     " << " |             <X>EXIT back to main            |\n";
	cout << "     " << " |---------------------------------------------|\n";
	cout << "      ";
	cin >> choice;
	system("cls");
	return choice;
}
char Instructor::SubmenuforGrade() {
	char choice;
	cout << endl << "     " << endl;
	cout << "     " << " ---Instructor sub-menu for Garde Information---\n";
	cout << "     " << " |                                             |\n";
	cout << "     " << " |             <S>how Grade list               |\n";
	cout << "     " << " |             <U>pdate Grade                  |\n";
	cout << "     " << " |             <A>dd new Grade                 |\n";
	cout << "     " << " |             <D>elete Grade                  |\n";
	cout << "     " << " |             <X>EXIT back to main            |\n";
	cout << "     " << " |---------------------------------------------|\n";
	cout << "     ";
	cin >> choice;
	system("cls");
	return choice;
}
/* -- END Sub Menu-- */


/* --Functions for sub-menu for STUDENT-- */
void Instructor::ShowStuList() {
	ifstream studentinfo("StudentList.bin", ios::in | ios::binary);

	cout << "--------------------STUDENT LIST--------------------" << endl;
	cout << left << setw(7) << "STUDNO" << setw(20) << "NAME" << setw(30) << "COURSE" << endl;

	Student tmpstudent;

	studentinfo.read(reinterpret_cast<char*>(&tmpstudent), sizeof(Student)); // Read contens of file from file to object.

	while (studentinfo && !studentinfo.eof()) {  // Read file until end of file.
		if (tmpstudent.getStudno() != 0) {  // If student number is not 0, print student information by using output function which I made.
			outputLine_stu(cout, tmpstudent); // Student data which has 0 of student number must not be printed. cuz It is deleted data.
		}
		studentinfo.read(reinterpret_cast<char*>(&tmpstudent), sizeof(Student));
	}
	studentinfo.close();
}

void Instructor::UpdateStu() {
	fstream updateStudent("StudentList.bin", ios::in | ios::out | ios::binary); // Create file as binary for input and output.

	int studno;
	string name, course, passwd;
	cin.ignore();
	cout << "Enter the studno to update : " << endl;
	cin >> studno;
	cin.get();
	cout << "Enter the name of the student to update : " << endl;
	getline(cin, name);
	cout << "Enter the course of the student to update : " << endl;
	getline(cin, course);
	cout << "Enter the password of the student to update : " << endl;
	cin >> passwd;

	Student tmpstudent;

	int num = 0; // Integer to notice where is information which user want to update. (It will be used with seek pointer in file.)
	updateStudent.read(reinterpret_cast<char*>(&tmpstudent), sizeof(Student));

	while (tmpstudent.getStudno() != studno)
	{
		updateStudent.read(reinterpret_cast<char*>(&tmpstudent), sizeof(Student));
		num++;
	}
	/* Update information using set function */
	tmpstudent.setName(name);
	tmpstudent.setCourse(course);
	tmpstudent.setPasswd(passwd);

	updateStudent.seekp(sizeof(Student)*num, ios::beg); // Find where is place to update data using seek pointer.
	updateStudent.write(reinterpret_cast<const char *>(&tmpstudent), sizeof(Student)); // Modify file.

	updateStudent.close();
}

void Instructor::AddNewStu() {
	int studno;
	string name, course, passwd;

	ofstream addStudent("StudentList.bin", ios::app | ios::binary);

	cin.ignore();
	cout << "Enter the studno to add : " << endl;
	cin >> studno;
	cin.get(); // To remove '\n' entered with studno
	cout << "Enter the name of the student to add : " << endl;
	getline(cin, name);
	cout << "Enter the course of the student to add : " << endl;
	getline(cin, course);
	cout << "Enter the password of the student to add : " << endl;
	cin >> passwd;
	Student addstu(studno, name, course, passwd);

	addStudent.write(reinterpret_cast<const char *>(&addstu), sizeof(Student)); // Write contents of object to file.

	addStudent.close();
}

void Instructor::DeleteStu() {
	system("cls");
	fstream deleteStudent("StudentList.bin", ios::in | ios::out | ios::binary);
	cout << "Write numer of student which you want to delete." << endl;
	int n = 0;
	int num;
	cin >> num;
	Student tmpstudent;
	deleteStudent.read(reinterpret_cast<char*>(&tmpstudent), sizeof(Student));

	while (tmpstudent.getStudno() != num) {
		if (!deleteStudent.eof()) {
			deleteStudent.read(reinterpret_cast<char*>(&tmpstudent), sizeof(Student));
			n++;
		}

		else if (deleteStudent.eof()) {
			deleteStudent.clear();
			cout << "Wrong Input. Please enter correct number" << endl;
			cin >> num;
			n = 0;
			deleteStudent.seekg(0, ios::beg);
			deleteStudent.clear();
			deleteStudent.read(reinterpret_cast<char*>(&tmpstudent), sizeof(Student));
		}
	}
	// Most of logic is simiar with Update function.
	// We will change student number of data which are gonna be deleted to '0'.
	// Show function will not print data which has 0 of student number.
	Student tmpstudent2(0, "", "", "");
	deleteStudent.seekp(sizeof(Student)*(n), ios::beg);
	deleteStudent.write(reinterpret_cast<const char*>(&tmpstudent2), sizeof(Student));
	deleteStudent.close();
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

	cout << "--------------------INSTRUCTOR'S LIST--------------------" << endl;
	cout << left << setw(15) << "INSTRUCTORNO" << setw(20) << "NAME" << setw(20) << "RANK" << endl;

	Instructor tmpinstructor;

	instructorinfo.read(reinterpret_cast<char*>(&tmpinstructor), sizeof(Instructor));

	while (instructorinfo && !instructorinfo.eof()) { // Read file until end of file.
		if (tmpinstructor.getInstructno() != 0) // If instructor number is not 0, print instructor information using output function which I made. 
			outputLine_ins(cout, tmpinstructor);// Instructor data which has 0 of instructor number must not be printed. cuz It is deleted data.
		instructorinfo.read(reinterpret_cast<char*>(&tmpinstructor), sizeof(Instructor));
	}

	instructorinfo.close();
}

void Instructor::UpdateIns() {
	fstream updateInstructor("InstructorList.bin", ios::in | ios::out | ios::binary);

	int instructno;
	string name;
	string rank;
	string passwd;

	cout << "Enter the instrucno to update : " << endl;
	cin >> instructno;
	cin.get();
	cout << "Enter the name of the Instructor to update : " << endl;
	getline(cin, name);
	cout << "Enter the rank of the Instructor to update : " << endl;
	getline(cin, rank);
	cout << "Enter the password of the Instructor to update : " << endl;
	cin >> passwd;

	Instructor tmpinstructor;

	int num = 0;
	updateInstructor.seekg(0, ios::beg);
	updateInstructor.read(reinterpret_cast<char*>(&tmpinstructor),
		sizeof(Instructor));

	while (tmpinstructor.getInstructno() != instructno)
	{
		updateInstructor.read(reinterpret_cast<char*>(&tmpinstructor),
			sizeof(Instructor));
		num++;
	}

	tmpinstructor.SetName(name);
	tmpinstructor.SetRank(rank);
	tmpinstructor.SetPasswd(passwd);

	updateInstructor.seekp(sizeof(Instructor)*num, ios::beg);
	updateInstructor.write(reinterpret_cast<const char *>(&tmpinstructor), sizeof(Instructor));

	updateInstructor.close();
}

void Instructor::AddNewIns() {

	int instructno;
	string name, rank, passwd;

	ofstream addInstructor("InstructorList.bin", ios::app | ios::binary);

	cin.ignore();
	cout << "Enter the instructno to add : " << endl;
	cin >> instructno;
	cin.get();// To remove '\n' entered with studno
	cout << "Enter the name of the instructor to add : " << endl;
	getline(cin, name);
	cout << "Enter the rank of the instructor to add : " << endl;
	getline(cin, rank);
	cout << "Enter the password of the instructor to add : " << endl;
	cin >> passwd;
	Instructor addins(instructno, name, rank, passwd);

	addInstructor.write(reinterpret_cast<const char *>(&addins), sizeof(Instructor));// Write contents of object to file.

	addInstructor.close();
}


void Instructor::DeleteIns() {
	system("cls");
	fstream deleteins("Instructorlist.bin", ios::in | ios::out | ios::binary);
	cout << "Write numer of Instructor which you want to delete." << endl;
	int n = 0;
	int num;
	cin >> num;
	Instructor tmpinstructor;

	deleteins.read(reinterpret_cast<char*>(&tmpinstructor), sizeof(Instructor));

	while (tmpinstructor.getInstructno() != num) {
		if (!deleteins.eof()) {
			deleteins.read(reinterpret_cast<char*>(&tmpinstructor), sizeof(Instructor));
			n++;
		}

		else if (deleteins.eof()) {
			deleteins.clear();
			cout << "Wrong Input. Please enter correct number" << endl;
			cin >> num;
			n = 0;
			deleteins.seekg(0, ios::beg);
			deleteins.clear();
			deleteins.read(reinterpret_cast<char*>(&tmpinstructor), sizeof(Instructor));
		}
	}
	// Most of logic is simiar with Update function.
	// We will change instructor number of data which are gonna be deleted to '0'.
	// Show function will not print data which has 0 of instructor number.
	Instructor tmpinstructor2(0, "", "", "");
	deleteins.seekp(sizeof(Instructor)*(n), ios::beg);
	deleteins.write(reinterpret_cast<const char*>(&tmpinstructor2), sizeof(Instructor));
	deleteins.close();
}

void outputLine_ins(ostream &output, Instructor& record) {
	output << left << setw(15) << record.getInstructno()
		<< setw(20) << record.getName()
		<< setw(20) << record.getRank() << endl;
}
/* --End Functions for sub-menu for INSTRUCTOR-- */


/* --Functions for sub-menu for QUESTION-- */
void Instructor::ShowQueList() {
	ifstream showquestion("QuestionList.bin", ios::in | ios::binary);

	cout << "--------------------Qustion List--------------------\n";
	cout << "Professer: " << this->getName() << endl;
	cout << "----------------------------------------------------\n";

	Question tmpquestion;

	showquestion.read(reinterpret_cast<char*>(&tmpquestion),
		sizeof(Question));

	while (showquestion && !showquestion.eof()) { // Read file until end of file.
		if (tmpquestion.getqno() != 0) // If question number is not 0, print question information using output function which I made. 
			outputLine_que(cout, tmpquestion);// Question data which has 0 of question number must not be printed. cuz It is deleted data.

		showquestion.read(reinterpret_cast<char*>(&tmpquestion),
			sizeof(Question));
	}

	showquestion.close();
}


void Instructor::UpdateQue() {
	fstream updateQuestion("QuestionList.bin", ios::in | ios::out | ios::binary);

	int qno;
	string question, choice1, choice2, choice3, anskey, subject, post, period;
	cin.ignore();

	cout << "Enter the question number to update: " << endl;
	cin >> qno;
	cin.get(); // for remove '\n' entered with qno
	cout << "Enter the question to update : " << endl;
	getline(cin, question);
	cout << "Enter the choice1 of the question to update : " << endl;
	getline(cin, choice1);
	cout << "Enter the choice2 of the question to update : " << endl;
	getline(cin, choice2);
	cout << "Enter the choice3 of the question to update : " << endl;
	getline(cin, choice3);
	cout << "Enter the anskey of the question to update : " << endl;
	getline(cin, anskey);
	cout << "Enter the subject of the question to update : " << endl;
	getline(cin, subject);
	cout << "Enter the post of the question to update : " << endl;
	getline(cin, post);
	cout << "Enter the period of the question to update : " << endl;
	getline(cin, period);

	Question tmpquestion;

	int count = 0;
	updateQuestion.read(reinterpret_cast<char*>(&tmpquestion), sizeof(Question));

	while (tmpquestion.getqno() != qno)
	{
		updateQuestion.read(reinterpret_cast<char*>(&tmpquestion), sizeof(Question));
		count++;
	}

	Question tmpquestion_enter(tmpquestion.getqno(), question, choice1, choice2, choice3, anskey, subject, post, period);

	updateQuestion.seekp(sizeof(Question)*count, ios::beg);
	updateQuestion.write(reinterpret_cast<const char *>(&tmpquestion_enter), sizeof(Question));

	updateQuestion.close();
}

void Instructor::AddNewQue() {
	ofstream addQuestion("QuestionList.bin", ios::app | ios::binary);

	int qno;
	string question, choice1, choice2, choice3, anskey, subject, post, period;

	cin.ignore();
	cout << "Enter the questionno to add : " << endl;
	cin >> qno;
	cout << "Enter the question to add : " << endl;
	cin.get();// To remove '\n' entered with studno
	getline(cin, question);
	cout << "Enter the choice1 of the question to add : " << endl;
	getline(cin, choice1);
	cout << "Enter the choice2 of the question to add : " << endl;
	getline(cin, choice2);
	cout << "Enter the choice3 of the question to add : " << endl;
	getline(cin, choice3);
	cout << "Enter the anskey of the question to add : " << endl;
	getline(cin, anskey);
	cout << "Enter the subject of the question to add : " << endl;
	getline(cin, subject);
	cout << "Enter the post of the question to add : " << endl;
	getline(cin, post);
	cout << "Enter the period of the question to add : " << endl;
	getline(cin, period);

	Question addque(qno, question, choice1, choice2, choice3, anskey, subject, post, period);

	addQuestion.write(reinterpret_cast<const char *>(&addque), sizeof(Question));// Write contents of object to file.
	addQuestion.close();
}

void Instructor::DeleteQue() {
	system("cls");
	fstream deleteque("QuestionList.bin", ios::in | ios::out | ios::binary);
	cout << "Write numer of Question which you want to delete." << endl;
	int n = 0;
	int num;
	cin >> num;
	Question tmpque;

	deleteque.read(reinterpret_cast<char*>(&tmpque), sizeof(Question));

	while (tmpque.getqno() != num) {
		if (!deleteque.eof()) {
			deleteque.read(reinterpret_cast<char*>(&tmpque), sizeof(Question));
			n++;
		}

		else if (deleteque.eof()) {
			deleteque.clear();
			cout << "Wrong Input. Please enter correct number" << endl;
			cin >> num;
			n = 0;
			deleteque.seekg(0, ios::beg);
			deleteque.clear();
			deleteque.read(reinterpret_cast<char*>(&tmpque), sizeof(Question));
		}
	}
	// Most of logic is simiar with Update function.
	// We will change Question number of data which are gonna be deleted to '0'.
	// Show function will not print data which has 0 of Question number.
	Question tmpque2(0, "", "", "", "", "", "", "", "");
	deleteque.seekp(sizeof(Question)*(n), ios::beg);
	deleteque.write(reinterpret_cast<const char*>(&tmpque2), sizeof(Question));
	deleteque.close();
}

void outputLine_que(ostream &output, Question& record) {
	output << left << setw(3) << record.getqno()
		<< setw(30) << record.getque() << endl
		<< "  a. " << setw(20) << record.getchoice1() << endl
		<< "  b. " << setw(20) << record.getchoice2() << endl
		<< "  c. " << setw(20) << record.getchoice3() << endl << endl;
	cout << "Subject  : " << setw(20) << record.getsubject()
		<< "Posted  : " << setw(10) << record.getpost()
		<< "Period  : " << setw(10) << record.getperiod() << endl << endl;
}
/* --End Functions for sub-menu for QUESTION-- */

/* --Functions for sub-menu for SUBJECT-- */
void Instructor::ShowSublist() {
	system("cls");
	ifstream subjectinfo("SubjectList.bin", ios::in | ios::binary);

	cout << endl << "---------------------------SUBJECT LIST--------------------------" << endl;
	cout << left << setw(13) << "SUBJECTNO" << setw(13) << "DESCRIPTION" << setw(13) << "UNITS" << endl;
	Subject tmpsubject;
	subjectinfo.read(reinterpret_cast<char*>(&tmpsubject), sizeof(Subject));

	while (subjectinfo && !subjectinfo.eof()) { // Read file until end of file.
		if (tmpsubject.GetSubjectno() != 0) {// If subject number is not 0, print subject information using output function which I made. 
			outputLine_sub(cout, tmpsubject);// Subject data which has 0 of subject number must not be printed. cuz It is deleted data.
			subjectinfo.read(reinterpret_cast<char*>(&tmpsubject), sizeof(Subject));
		}
		else subjectinfo.read(reinterpret_cast<char*>(&tmpsubject), sizeof(Subject));
	}

	subjectinfo.close();
}

void Instructor::AddSublist() {
	ofstream addsubject("SubjectList.bin", ios::app | ios::binary);

	int num;
	string subname;
	int unit;

	Subject addsub;
	cin.ignore();
	cout << "Enter the number of Subject" << endl;
	cin >> num;
	cin.get(); // To remove '\n' entered with studno
	cout << "Enter the name of Subject" << endl;
	getline(cin, subname);
	cout << "Enter the Unit number" << endl;
	cin >> unit;
	addsub.SetSubjectno(num);
	addsub.SetSubname(subname);
	addsub.SetSubunit(unit);
	addsubject.write(reinterpret_cast<const char *>(&addsub), sizeof(Subject)); // Write contents of object to file.
	addsubject.close();
}

void Instructor::delSublist() {
	system("cls");
	fstream subjectinfo("SubjectList.bin", ios::in | ios::out | ios::binary);
	cout << "Write numer of subject which you want to delete." << endl;
	int n = 0;
	int num;
	cin >> num;
	Subject tmpsubject;

	subjectinfo.read(reinterpret_cast<char*>(&tmpsubject), sizeof(Subject));

	while (tmpsubject.GetSubjectno() != num) {
		if (!subjectinfo.eof()) {
			subjectinfo.read(reinterpret_cast<char*>(&tmpsubject), sizeof(Subject));
			n++;
		}

		else if (subjectinfo.eof()) {
			subjectinfo.clear();
			cout << "Wrong Input. Please enter correct number" << endl;
			cin >> num;
			n = 0;
			subjectinfo.seekg(0, ios::beg);
			subjectinfo.clear();
			subjectinfo.read(reinterpret_cast<char*>(&tmpsubject), sizeof(Subject));
		}
	}
	// Most of logic is simiar with Update function.
	// We will change subject number of data which are gonna be deleted to '0'.
	// Show function will not print data which has 0 of subject number.
	Subject tmpsubject2(0, "", 0);
	subjectinfo.seekp(sizeof(Subject)*(n), ios::beg);
	subjectinfo.write(reinterpret_cast<const char*>(&tmpsubject2), sizeof(Subject));
	subjectinfo.close();
}

void Instructor::UpdateSublist() {
	fstream updatesubject("SubjectList.bin", ios::in | ios::out | ios::binary);
	int subno, unitno;
	int num = 0;
	string subname;
	Subject tmpsubject;

	cout << "Enter the subject number to update : ";
	cin >> subno;
	cin.get();
	cout << "Enter the name of the subject to update : ";
	getline(cin, subname);
	cout << "Enter the unit number of subject to update : ";
	cin >> unitno;

	updatesubject.read(reinterpret_cast<char*>(&tmpsubject), sizeof(Subject));

	while (1) {
		if (tmpsubject.GetSubjectno() == subno) { break; }
		// cout << tmpsubject.GetSubjectno() << " " << tmpsubject.GetSubname() << endl;
		updatesubject.read(reinterpret_cast<char*>(&tmpsubject), sizeof(Subject));
		num++;
	}

	tmpsubject.SetSubname(subname);
	tmpsubject.SetSubunit(unitno);
	cout << tmpsubject.GetSubname() << " " << tmpsubject.GetSubunit();
	updatesubject.seekp(sizeof(Subject)*num, ios::beg);
	updatesubject.write(reinterpret_cast<const char *>(&tmpsubject), sizeof(Subject));
	updatesubject.close();
}

void outputLine_sub(ostream &output, Subject& record) {
	output << setw(13) << record.GetSubjectno()
		<< setw(13) << record.GetSubname()
		<< setw(13) << record.GetSubunit() << endl;
}

/* -- End Functions for sub-menu for SUBJECT-- */


/* -- Functions for sub-menu for GRADE-- */
void Instructor::ShowGrdlist() {
	system("cls");
	ifstream Gradeinfo("GradeList.bin", ios::in | ios::binary);
	if (!Gradeinfo) {  // Check whether file was opened or not.
		cerr << "Error Studentinfo can't open GradeList.bin!" << endl;
		exit(EXIT_FAILURE);
	}

	cout << "---------------------------GRADE LIST--------------------------" << endl
		<< left << setw(15) << "STUDENTNO" << setw(15) << "PERIOD" << setw(15) << "SUBJECT" << setw(15) << "MIDSCORE" << setw(15) << "FINALSCORE" << endl;
	Grade tmpgrade;
	Gradeinfo.read(reinterpret_cast<char*>(&tmpgrade), sizeof(Grade)); // Read contens of file from file to object.

	while (Gradeinfo && !Gradeinfo.eof()) {// Read file until end of file.

		if (tmpgrade.getStudno() != 0) // If student number is not 0, print grade information by using output function which I made.
			outputLine_grd(cout, tmpgrade);

		Gradeinfo.read(reinterpret_cast<char*>(&tmpgrade), sizeof(Grade));
	}
	Gradeinfo.close();
	return;

}
void Instructor::UpdateGrdlist() {
	fstream updateGrade("GradeList.bin", ios::in | ios::out | ios::binary);

	int studentno_;
	string period_;
	int midscoreEq_;
	int finalscoreEq_;
	string subject_;

	cout << "Enter the studentno to update : " << endl;
	cin >> studentno_;
	cout << "Enter the period of the Grade to update : " << endl;
	cin >> period_;
	cout << "Enter the midscoreEq of the Grade to update : " << endl;
	cin >> midscoreEq_;
	cout << "Enter the finalscoreEq of the Grade to update : " << endl;
	cin >> finalscoreEq_;
	cout << "Enter the subject of the Grade to update : " << endl;
	cin.ignore();
	getline(cin, subject_, '\n');

	Grade tmpgrade;

	int num = 0;
	updateGrade.read(reinterpret_cast<char*>(&tmpgrade),
		sizeof(Grade));// Read contens of file from file to object.

	while (tmpgrade.getStudno() != studentno_) //Check studentnumber to update
	{
		updateGrade.read(reinterpret_cast<char*>(&tmpgrade),
			sizeof(Grade));
		num++;
	}

	tmpgrade.setStudno(studentno_);
	tmpgrade.setperiod(period_);
	tmpgrade.setMidScoreEq(midscoreEq_);
	tmpgrade.setFinalScoreEq(finalscoreEq_);
	tmpgrade.setSubject(subject_);

	updateGrade.seekp(sizeof(Grade)*num, ios::beg); //Relocation output cursor via seekp to write
	updateGrade.write(reinterpret_cast<const char *>(&tmpgrade), sizeof(Grade));
	updateGrade.close();
}
void Instructor::AddGrdlist() {


	ofstream addGrade("GradeList.bin", ios::app | ios::binary);
	int studentno_;
	string period_;
	int midscoreEq_;
	int finalscoreEq_;
	string subject_;

	cout << "Enter the studentno to add : " << endl;
	cin >> studentno_;
	cout << "Enter the period of the Grade to add : " << endl;
	cin >> period_;
	cout << "Enter the midscore of the Grade to add : " << endl;
	cin >> midscoreEq_;
	cout << "Enter the finalscore of the Grade to add : " << endl;
	cin >> finalscoreEq_;
	cout << "Enter the subject of the Grade to add : " << endl;
	cin.ignore();
	getline(cin, subject_, '\n');
	Grade addgrade(studentno_, period_, midscoreEq_, finalscoreEq_, subject_);

	addGrade.write(reinterpret_cast<const char *>(&addgrade), sizeof(Grade)); //Writing addgrade with app option

	addGrade.close();

}
void Instructor::delGrdlist() {
	system("cls");
	fstream gradeinfo("GradeList.bin", ios::in | ios::out | ios::binary);
	if (!gradeinfo) {
		cerr << "Error delGrdlist() can't open GradeList.bin!" << endl;
		exit(EXIT_FAILURE);
	}
	int n = 0;
	int num;
	string subject;
	cout << "Write studentnumber of Grade which you want to delete." << endl;
	cin >> num;
	cout << "Write subject of Grade which you want to delete." << endl;
	cin.ignore();
	getline(cin, subject, '\n');

	Grade tmpgrade;

	gradeinfo.read(reinterpret_cast<char*>(&tmpgrade), sizeof(Grade));

	while (tmpgrade.getStudno() != num || tmpgrade.getSubject() != subject) { //Check Studentnumber and Subject
		if (!gradeinfo.eof()) {
			gradeinfo.read(reinterpret_cast<char*>(&tmpgrade), sizeof(Grade));
			n++;
		}

		else if (gradeinfo.eof()) {
			gradeinfo.clear();
			cout << "Wrong Input. Please enter correct number" << endl;
			cin >> num;
			n = 0;
			gradeinfo.seekg(0, ios::beg);
			gradeinfo.clear();
			gradeinfo.read(reinterpret_cast<char*>(&tmpgrade), sizeof(Grade));
		}
	}

	Grade tmpgrade2;
	gradeinfo.seekp(sizeof(Grade)*(n), ios::beg);
	gradeinfo.write(reinterpret_cast<const char*>(&tmpgrade2), sizeof(Grade));//Overwrite on checking position with empty object
	gradeinfo.close();
}
void outputLine_grd(ostream &output, Grade& record) {
	output << setw(15) << record.getStudno()
		<< setw(15) << record.getperiod()
		<< setw(15) << record.getSubject()
		<< setw(15) << record.getMidScoreEq()
		<< setw(15) << record.getFinalScoreEq() << endl;
}
/* -- End Functions for sub-menu for GRADE-- */

void Instructor::build_instructorfile() {
	ifstream iinstructor_file("InstructorList.bin", ios::in | ios::binary);

	if (!iinstructor_file) {
		cerr << "Error build_instructorfile() can't open InstructorList.bin!" << endl;
		exit(EXIT_FAILURE);
	}
	string input_name;
	string input_path;
	cin.ignore();
	cout << "Enter the name of file what you want to build." << endl;
	getline(cin, input_name, '\n');

	cout << "Write path of file where you want to build.(Ex. C:\\Users\\Downloads\\)"
		<< endl;
	getline(cin, input_path, '\n');

	if (input_path[input_path.size() - 1] != '\\') // ifn't input_path's last word is "\". Use append function to append "\"
		input_path.append("\\");

	ofstream oinstructor_file(input_path + input_name, ios::out | ios::binary);// Create file by using received name and path. using '+'operator
	if (!iinstructor_file) {
		cerr << "Error build_instructorfile() can't create " << input_name << "!" << endl;
		exit(EXIT_FAILURE);
	}
	Instructor tmpInstructor;
	iinstructor_file.read(reinterpret_cast<char*>(&tmpInstructor), sizeof(Instructor));

	while (iinstructor_file && !iinstructor_file.eof())
	{
		oinstructor_file.write(reinterpret_cast<const char*> (&tmpInstructor), sizeof(Instructor));
		iinstructor_file.read(reinterpret_cast<char*>(&tmpInstructor), sizeof(Instructor));
	}
	iinstructor_file.close();
	oinstructor_file.close();
	system("cls");
}

void Instructor::build_studentfile() {
	ifstream istudent_file("StudentList.bin", ios::in | ios::binary);

	if (!istudent_file) {
		cerr << "Error build_studentfile() can't open StudentList.bin!" << endl;
		exit(EXIT_FAILURE);
	}
	string input_name;
	string input_path;

	cin.ignore();
	cout << "Enter the name of file what you want to build." << endl;
	getline(cin, input_name, '\n');

	cout << "Write path of file where you want to build.(Ex. C:\\Users\\Downloads\\)"
		<< endl;
	getline(cin, input_path, '\n');

	if (input_path[input_path.size() - 1] != '\\')// ifn't input_path's last word is "\". Use append function to append "\"
		input_path.append("\\");

	ofstream ostudent_file(input_path + input_name, ios::out | ios::binary); // Create file by using received name and path.
	if (!istudent_file) {
		cerr << "Error build_studentfile() can't create " << input_name << "!" << endl;
		exit(EXIT_FAILURE);
	}

	Student tmpStudent;

	istudent_file.read(reinterpret_cast<char*>(&tmpStudent), sizeof(Student));

	while (istudent_file && !istudent_file.eof())
	{
		ostudent_file.write(reinterpret_cast<const char*> (&tmpStudent), sizeof(Student));
		istudent_file.read(reinterpret_cast<char*>(&tmpStudent), sizeof(Student));
	}
	istudent_file.close();
	ostudent_file.close();
	system("cls");
}

void Instructor::build_subjectfile() {
	ifstream isubject_file("SubjectList.bin", ios::in | ios::binary);

	if (!isubject_file) {
		cerr << "Error build_subjectfile() can't open StudentList.bin!" << endl;
		exit(EXIT_FAILURE);
	}
	string input_name;
	string input_path;
	cin.ignore();
	cout << "Enter the name of file what you want to build." << endl;
	getline(cin, input_name, '\n');

	cout << "Write path of file where you want to build.(Ex. C:\\Users\\Downloads\\)"
		<< endl;
	getline(cin, input_path, '\n');

	if (input_path[input_path.size() - 1] != '\\')// ifn't input_path's last word is "\". Use append function to append "\"
		input_path.append("\\");

	ofstream osubject_file(input_path + input_name, ios::out | ios::binary); // Create file by using received name and path.
	if (!isubject_file) {
		cerr << "Error build_subjectfile() can't create " << input_name << "!" << endl;
		exit(EXIT_FAILURE);
	}

	Subject tmpSubject;

	isubject_file.read(reinterpret_cast<char*>(&tmpSubject), sizeof(Subject));

	while (isubject_file && !isubject_file.eof())
	{
		osubject_file.write(reinterpret_cast<const char*> (&tmpSubject), sizeof(Subject));
		isubject_file.read(reinterpret_cast<char*>(&tmpSubject), sizeof(Subject));
	}
	isubject_file.close();
	osubject_file.close();
	system("cls");
}

void Instructor::build_questionfile() {
	ifstream iquestion_file("QuestionList.bin", ios::in | ios::binary);

	if (!iquestion_file) {
		cerr << "Error build_questionfile() can't open QuestionList.bin!" << endl;
		exit(EXIT_FAILURE);
	}
	string input_name;
	string input_path;

	cin.ignore();
	cout << "Enter the name of file what you want to build." << endl;
	getline(cin, input_name, '\n');

	cout << "Write path of file where you want to build.(Ex. C:\\Users\\Downloads\\)"
		<< endl;
	getline(cin, input_path, '\n');

	if (input_path[input_path.size() - 1] != '\\')// ifn't input_path's last word is "\". Use append function to append "\"
		input_path.append("\\");

	ofstream oquestion_file(input_path + input_name, ios::out | ios::binary); // Create file by using received name and path.
	if (!iquestion_file) {
		cerr << "Error build_questionfile() can't create " << input_name << "!" << endl;
		exit(EXIT_FAILURE);
	}

	Question tmpQuestion;

	iquestion_file.read(reinterpret_cast<char*>(&tmpQuestion), sizeof(Question));

	while (iquestion_file && !iquestion_file.eof())
	{
		oquestion_file.write(reinterpret_cast<const char*> (&tmpQuestion), sizeof(Question));
		iquestion_file.read(reinterpret_cast<char*>(&tmpQuestion), sizeof(Question));
	}
	iquestion_file.close();
	oquestion_file.close();
	system("cls");
}

void Instructor::build_gradefile() {
	ifstream igrade_file("GradeList.bin", ios::in | ios::binary);

	if (!igrade_file) {
		cerr << "Error build_gradefile() can't open GradeList.bin!" << endl;
		exit(EXIT_FAILURE);
	}
	string input_name;
	string input_path;

	cin.ignore();
	cout << "Enter the name of file what you want to build." << endl;
	getline(cin, input_name, '\n');

	cout << "Write path of file where you want to build.(Ex. C:\\Users\\Downloads\\)"
		<< endl;
	getline(cin, input_path, '\n');

	if (input_path[input_path.size() - 1] != '\\')// ifn't input_path's last word is "\". Use append function to append "\"
		input_path.append("\\");

	ofstream ograde_file(input_path + input_name, ios::out | ios::binary); // Create file by using received name and path.
	if (!igrade_file) {
		cerr << "Error build_gradefile() can't create " << input_name << "!" << endl;
		exit(EXIT_FAILURE);
	}

	Grade tmpGrade;

	igrade_file.read(reinterpret_cast<char*>(&tmpGrade), sizeof(Grade));

	while (igrade_file && !igrade_file.eof())
	{
		ograde_file.write(reinterpret_cast<const char*> (&tmpGrade), sizeof(Grade));
		igrade_file.read(reinterpret_cast<char*>(&tmpGrade), sizeof(Grade));
	}
	igrade_file.close();
	ograde_file.close();
	system("cls");
}

void Instructor::BuildFile() {
	char choice;
	while ((choice = subbuildfile()) != 'x') {
		switch (choice) {
		case 'i':
			build_instructorfile();
			break;
		case 's':
			build_studentfile();
			break;
		case 'j':
			build_subjectfile();
			break;
		case 'q':
			build_questionfile();
			break;
		case 'g':
			build_gradefile();
			break;
		case 'x':
			break;
		}
	}
}

char Instructor::subbuildfile() {
	char submenu;
	cout << endl;
	cout << "      ----Admin sub-menu for BuildFile-----\n"
		<< "      |                                    |\n"
		<< "      |     <I>nstructorList               |\n"
		<< "      |     <S>tudentList                  |\n"
		<< "      |      Sub<J>ectList                 |\n"
		<< "      |     <Q>uestionList                 |\n"
		<< "      |     <G>radeList                    |\n"
		<< "      |     <X>Exit return main menu       |\n"
		<< "      --------------------------------------\n";
	cin >> submenu;
	system("cls");
	return submenu;
}
