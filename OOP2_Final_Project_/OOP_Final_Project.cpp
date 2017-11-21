#include "Instructor.h"
#include "Question.h"
#include "Subject.h"
#include <conio.h>
using namespace std;


char Login();
Instructor Admin_IDsearch(string);
Student Student_IDsearch(string);
Instructor LoginAdmin;
Stduent LoginAdmin;
int main()
{
	char c;
	while (c = Login() != 'x') {
		switch (c)
		{
		case 's':

			break;
		case 'i':

			break;
		case 'q':

			break;
		case 'j':

			break;
		case 'g':

			break;
		case 'u':

			break;
		case 'b':

			break;
		default:

		}

	}
	return 0;
}

char Login() {
	ifstream Admin_Search("InstructorList.bin", ios::in | ios::binary);
	ifstream Student_Search("StudentList.bin", ios::in | ios::binary);
	char output;
	static string instructor[4];
	static string student[4];
	string pass = "";
	
	for (int i = 0; i < 4; i++)
	{
		Admin_Search >> instructor[i];
		Student_Search >> student[i];
	}
	//Input ID
	while (!(cin >> pass)) {
		if (instructor[1] == pass)
			break;
		else if (student[1] == pass)
			break;
		else 
			for (int i = 0; i < 4; i++)
			{
				Admin_Search >> instructor[i];
				Student_Search >> student[i];
			}
	}
	


	//Input PassWord
	while (1) {
		pass = "";
		while(1) {
			output = _getch();
			pass += output;
			cout << "*";
		}
	if (pass == "string")
			break;
		system("cls");
	}
	return output;
}