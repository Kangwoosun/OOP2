#include "Generic.h"

void stringData(); //to pass string array for sorting function
void intData();//to pass int array for sorting function
void doubleData();//to pass double array for sorting function
char enterChoice(void); //for the menu
int main() {
	char choice;
	while ((choice = enterChoice()) != 'q') {
		system("cls");
		switch (choice) {
		case 's': stringData(); break;
		case 'i': intData(); break;
		case 'd': doubleData(); break;
		default: cerr << "Incorrect choice" << endl; break;
		}
	}
	system("pause");
	return 0;
}void stringData() {
	static string _String[6] = { "China", "Australia", "Russia", "Japan", "Vietnam", "Korea" };
	Generic<string> Obj(_String, 6);
	cout << "\n-------------------Unsorted------------\n";
		Obj.output();
	cout << "\n-------------------Sorted--------------\n";
	Obj.mySort();
		Obj.output();
	cout << endl;}void intData() {
	static int _Int[6] = { 5,4,3,3,2,1 };
	Generic<int> Obj(_Int, 6);
	cout << "\n-------------------Unsorted------------\n";
		Obj.output();
	cout << "\n-------------------Sorted--------------\n";
	Obj.mySort();
		Obj.output();
	cout << endl;
}
void doubleData() {
	static double _Double[6] = { 5.5,4.25,10.1,3.6,2,1 };
	Generic<double> Obj(_Double, 6);
	cout << "\n-------------------Unsorted------------\n";
		Obj.output();
	cout << "\n-------------------Sorted--------------\n";
	Obj.mySort();
		Obj.output();
	cout << endl;
}
char enterChoice() {
	cout << "\n\n----------------- Main Menu ------------------\n\n"
		<< "	Sort array of <i>nteger\n" 
		<< "	Sort array of <d>ouble\n" 
		<< "	Sort array of <s>tring\n" 
		<< "	<Q>uit\n";
	static char input;
	cin >> input;
	return input;
}