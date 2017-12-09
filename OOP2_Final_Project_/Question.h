#pragma once
#pragma once
#include<iostream>
#include<string>
using namespace std;

class Question {
private:
	int qno;
	char choice1[20];
	char choice2[20];
	char choice3[20];
	char anskey[20];

	char subject[20];
	char post[10];
	char period[10];

public:
	Question(int = 0, const string& = "", const string& = "", const string& = "",
		const string& = "", const string& = "", const string& = "", const string& = "");
	void qrandom();
	int getqno() { return qno; }
	string getchoice1() { return choice1; }
	string getchoice2() { return choice2; }
	string getchoice3() { return choice3; }
	string getanskey() { return anskey; }
	string getsubject() { return subject; }
	string getpost() { return post; }
	string getperiod() { return period; }
	void setqno(int);
	void setchoice1(const string&);
	void setchoice2(const string&);
	void setchoice3(const string&);
	void setanskey(const string&);
	void setsubject(const string&);
	void setpost(const string&);
	void setperiod(const string&);
};

Question::Question(int _qno, const string& _choice1, const string& _choice2, const string& _choice3, const string& _anskey,
	const string& _subject, const string& _post, const string& _period)
{
	qno = _qno;
	setchoice1(_choice1);
	setchoice2(_choice2);
	setchoice3(_choice3);
	setanskey(_anskey);
	setsubject(_subject);
	setpost(_post);
	setperiod(_period);
}

void Question::setqno(int _qno) {
	qno = _qno;
}

void Question::setchoice1(const string& _choice1) {
	int length = _choice1.size();
	length = (length < 20 ? length : 19);
	_choice1.copy(choice1, length);
	choice1[length] = '\0';
}

void Question::setchoice2(const string& _choice2) {
	int length = _choice2.size();
	length = (length < 20 ? length : 19);
	_choice2.copy(choice2, length);
	choice2[length] = '\0';
}

void Question::setchoice3(const string& _choice3) {
	int length = _choice3.size();
	length = (length < 20 ? length : 19);
	_choice3.copy(choice3, length);
	choice3[length] = '\0';
}

void Question::setanskey(const string& _anskey) {
	int length = _anskey.size();
	length = (length < 20 ? length : 19);
	_anskey.copy(anskey, length);
	anskey[length] = '\0';
}

void Question::setsubject(const string& _subject) {
	int length = _subject.size();
	length = (length < 20 ? length : 19);
	_subject.copy(subject, length);
	subject[length] = '\0';
}

void Question::setpost(const string& _post) {
	int length = _post.size();
	length = (length < 10 ? length : 9);
	_post.copy(post, length);
	post[length] = '\0';
}

void Question::setperiod(const string& _period) {
	int length = _period.size();
	length = (length < 10 ? length : 9);
	_period.copy(period, length);
	period[length] = '\0';
}

void Question::qrandom() {

}