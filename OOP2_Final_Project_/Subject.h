#pragma once
#pragma warning(disable:4996)
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Subject {
private:
	int subjectno;
	char subname[20];
	int subunit;

public:
	/* Constructor & Set & Get Function */
	Subject(int = 0, const string& = "", int = 0);
	void SetSubjectno(int);
	void SetSubname(const string& name);
	void SetSubunit(int);

	int GetSubjectno();
	string GetSubname();
	int GetSubunit();
};

Subject::Subject(int _subjectno, const string& _subname, int _subunit) {
	subjectno = _subjectno;
	SetSubname(_subname);
	subunit = _subunit;
}

void Subject::SetSubjectno(int a) {
	subjectno = a;
}
void Subject::SetSubname(const string& name) {
	int length = name.size();
	length = (length < 20 ? length : 19);
	name.copy(subname, length);
	subname[length] = '\0';
}
void Subject::SetSubunit(int a) {
	subunit = a;
}
int Subject::GetSubjectno() {
	return subjectno;
}
string Subject::GetSubname() {
	return subname;
}
int Subject::GetSubunit() {
	return subunit;
}