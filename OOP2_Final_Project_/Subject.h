#pragma once
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
	Subject(int, string, int);
	Subject();
	void SetSubjectno(int);
	void SetSubname(const string& name);
	void SetSubunit(int);
	int GetSubjectno();
	string GetSubname();
	int GetSubunit();

};
Subject::Subject() {}
Subject::Subject(int _subjectno, string _subname, int _subunit) {
	subjectno = _subjectno;
	int length = _subname.size();
	length = (length < 20 ? length : 19);
	_subname.copy(subname, length);
	subname[length] = '\0';
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