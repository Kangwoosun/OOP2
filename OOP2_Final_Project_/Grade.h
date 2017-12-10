#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <string>
using namespace std;

class Grade {
private:
	int studentno; // using this studentno, compare with Student object's studno, print the grade 
	char period[10];
	int midscoreEq; // save the correct answer's number. 
	int finalscoreEq; // save the correct answer's number. 
	char subject[20];

public:
	/* Constructor & Set & Get Function */
	Grade(int = 0, const string& = "", int = 0, int = 0, const string& = "");
	void setStudno(int);
	void setperiod(const string&);
	void setMidScoreEq(int);
	void setFinalScoreEq(int);
	void setSubject(const string&);

	int getStudno();
	string getperiod();
	int getMidScoreEq();
	int getFinalScoreEq();
	string getSubject();
};

Grade::Grade(int _studentno, const string& _period, int _midscoreEq, int _finalscoreEq, const string& _subject) {
	studentno = _studentno;
	setperiod(_period);
	midscoreEq = _midscoreEq;
	finalscoreEq = _finalscoreEq;
	setSubject(_subject);
}

void Grade::setStudno(int _studentno) {
	studentno = _studentno;
}

void Grade::setperiod(const string& _period) {
	int length = _period.size();
	length = (length < 10 ? length : 9);
	_period.copy(period, length);
	period[length] = '\0';
}

void Grade::setMidScoreEq(int _midscoreeq) {
	midscoreEq = _midscoreeq;
}

void Grade::setFinalScoreEq(int _finalscoreeq) {
	finalscoreEq = _finalscoreeq;;
}

void Grade::setSubject(const string& _subject) {
	int length = _subject.size();
	length = (length < 20 ? length : 19);
	_subject.copy(subject, length);
	subject[length] = '\0';
}

int Grade::getStudno() {
	return studentno;
}

string Grade::getperiod() {
	return period;
}

int Grade::getMidScoreEq() {
	return midscoreEq;
}

int Grade::getFinalScoreEq() {
	return finalscoreEq;
}

string Grade::getSubject() {
	return subject;
}