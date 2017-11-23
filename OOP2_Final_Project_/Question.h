#pragma once
#include<iostream>
#include<string>
using namespace std;

class Question {
private:
	int qno;
	string qinfo;
	string choice1;
	string choice2;
	string choice3;
	string answer;
	string subject;
	string post;
	string period;
public:
	void Setqno(int a) {
		qno = a;
	}
	int Getqno() {
		return qno;
	}
	void Setqinfo(string a) {
		qinfo = a;
	}
	string Getqinfo() {
		return qinfo;
	}
	void Setchoice1(string a) {
		choice1 = a;
	}
	string Getchoice1() {
		return choice1;
	}
	void Setchoice2(string a) {
		choice2 = a;
	}
	string Getchoice2() {
		return choice2;
	}
	void Setchoice3(string a) {
		choice3 = a;
	}
	string Getchoice3() {
		return choice3;
	}
	void Setanser(string a) {
		answer = a;
	}
	string Getanser() {
		return answer;
	}
	void Setsubject(string a) {
		subject = a;
	}
	string Getsubject() {
		return subject;
	}
	void Setpost(string a) {
		post = a;
	}
	string Getpost() {
		return post;
	}
	void Setperiod(string a) {
		period = a;
	}
	string Getperiod() {
		return period;
	}
	char Mainmenu(); // 초기에 나오는 화면
	void Showinfo();
	void Update();
};

char Question::Mainmenu() {
	char input;
	system("cls");
	cout << endl;
	cout << "        --<Admin> Sub-Menu for Question information --";
	cout << "        |                                            l";
	cout << "        |     <S>how Question list                   l";
	cout << "        |     <U>pdate Question                      l";
	cout << "        |     <A>dd new Question                     l";
	cout << "        |     <D>elete Question record               l";
	cout << "        |     <E>xit return main menu                l";
	cout << "        ----------------------------------------------";
	cin >> input;
	return input;
}