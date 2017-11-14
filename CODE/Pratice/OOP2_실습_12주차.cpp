#include <iostream>
#include <string>
using namespace std;

char Menu();
int countVowels(string);
string title(string);
void reverse(string&);
string lowerCase(string);
string upperCase(string);
int main()
{
	string input;
	char choice;
	choice = Menu();
	cin.ignore();
		system("cls");
		switch (choice) {
		case 't': 
			cout << "Enter a sentence : ";
			getline(cin, input);
			cout << "\n\n Lower case : " << lowerCase(input) << endl;
			cout << "\n\n Upper case : " << upperCase(input) << endl;
			cout << "\n\n Title case : " << title(input) << endl;
			break;
		case 'r':
			cout << "Enter a sentence : ";
			getline(cin, input);
			reverse(input);
			cout << "\n\n Reverse : " << input << endl;
			break;
		case 'c':
			cout << "Enter a sentence : ";
			getline(cin, input);
			cout << "\n\n Number of vowels : " << countVowels(input) << endl;
			break;
		default:
			break;
		}
		return 0;
}

char Menu() {
	char input;
	cout << "-----------------Main Menu------------------"
		<< "\n|                                           |"
		<< "\n|     <T>itle, Uppercase, Lower             |"
		<< "\n|     <R>everse string                      |"
		<< "\n|     <C>ount Vowels                        |"
		<< "\n|     <Q>uit                                |"
		<< "\n--------------------------------------------\n";
		cin >> input;
		return input;
}
int countVowels(string a) {
	int counter = 0;
	string vowel = "aeiou";
	for (int i = 0; i < a.size();i++)
		for (int j = 0; j < 5; j++)
			if (a.at(i) == vowel.at(j))
				counter++;
	return counter;
}
string title(string a) {

	for (int i = 0; i < a.size()-1; i++)
		if (a.at(i) == 0x20)
			if(a.at(i+1) >= 0x61 && a.at(i+1) <= 0x7A)
				a.at(i+1) -= 0x20;
	return a;
}
void reverse(string &a) {
	string b = a;
	for (int i = 0; i < a.size(); i++)
		b.at(a.size() - i - 1) = a.at(i);
	a = b;
}
string lowerCase(string a) {
	for (int i = 0; i < a.length(); i++)
		if (a.at(i) >= 0x41 && a.at(i) <= 0x5A)
			a.at(i) += 0x20;
	return a;
}
string upperCase(string a) {
	for (int i = 0; i < a.length(); i++)
		if (a.at(i) >= 0x61 && a.at(i) <= 0x7A)
			a.at(i) -= 0x20;
	return a;
}