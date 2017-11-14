#pragma once
#include <iostream>
#include <string>
#include <iomanip>
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
};