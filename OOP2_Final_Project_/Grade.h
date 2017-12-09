#pragma once
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Grade {
private:
	int studentno;
	int period;
	int midscoreEq;// �߰���� ���� ex) 5���� �� 1��?
	int finalscoreEq; // �⸻��� ����
	char subject[20];

public:
	int getStudno();
	int getperiod();
	int getMidScoreEq();
	int getFinalScoreEq();
	string getSubject();

	void setStudno(int);
	void setperiod(int);
	void setMidScoreEq(int);
	void setFinalScoreEq(int);
	void setSubject(const string&);
};

int Grade::getStudno() {
	return studentno;
}

int Grade::getperiod() {
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

void Grade::setStudno(int _studentno) {
	studentno = _studentno;
}

void Grade::setperiod(int _period) {
	period = _period;
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