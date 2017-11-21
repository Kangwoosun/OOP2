#include <iostream>
#include <string>
#include <set>
#include <iomanip>
using namespace std;
int main()
{
	set<char> s;
	
	string str = "";	getline(cin, str);
	for (int i = 0; i < str.size(); i++)
		s.insert(str.at(i));
	cout << "The set contains:\n";
	set<char>::iterator p;
	for (p = s.begin(); p != s.end(); p++)
		cout << *p << " ";
	cout << endl;
	char a;
	cin >> a;
	cout << "Set contains '" << a <<"': ";
	if (s.find(a) == s.end())
		cout << "no" << endl;
	else
		cout << "yes" << endl;

	system("pause");
	return 0;
}