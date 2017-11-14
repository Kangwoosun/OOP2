#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	char c = ' ';
	string pass = "";
	while (c != 13) {
		c = getch();
		if (c != 13) {
			pass += c;
			cout << "*";
		}
	}
}