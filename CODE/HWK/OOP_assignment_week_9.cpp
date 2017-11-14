#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;

int getRequest(); // get user¡¯s request
void new_item(); // create new recorde to item file (Writing to item file)
void new_sale(); // create new recorde to sale file (Writing to sale file)
void display_items(); // Display items from file (Reading from item file )
void display_sales(); // Display sales from file (Reading from sale file)
bool search(string); // search if a specific item exist in item file
string found_item[] = { "","","" };// global variable for searching item
enum RequestType { NEW_ITEM = 1, SHOW_ITEMS, NEW_SALE, SHOW_SALES, END };



int main()
{
	int request = getRequest();

	while (request != END)
	{
		switch (request)
		{
		case NEW_ITEM:
			cout << "\n Entering a new item to store:\n";
			new_item();
			break;
		case SHOW_ITEMS:
			cout << "\n List items of the store:\n";
			display_items();
			break;
		case NEW_SALE:
			cout << "\n Enter a new sale (Purchase):\n";
			new_sale();
			break;
		case SHOW_SALES:
			cout << "\n List sales (Purchases):\n";
			display_sales();
			break;
		}
		request = getRequest();
	}
	system("pause");
	return 0;
}


int getRequest() {
	int Request;
	cout << "Enter request\n";
	cout << " 1 - Enter a new Item to store\n";
	cout << " 2 - List items of the store\n";
	cout << " 3 - Enter a new sale <Purchase>\n";
	cout << " 4 - List sales <Purchases>\n";
	cout << " 5 - End of run\n? ";
	cin >> Request;
	return Request;
}

void new_item() {

	ofstream outItemFile("Item.txt", ios::app);
	static string newitem[3];
	cout << "\nEnter Item number: ";
	cin >> newitem[0];
	cout << "\nEnter Item name: ";
	cin >> newitem[1];
	cout << "\nEnter Itme's prices: ";
	cin >> newitem[2];
	if (!outItemFile) {
		cerr << "File couldn't be opend" << endl;
		exit(EXIT_FAILURE);
	}
	else
		outItemFile << newitem[0] << ' ' << newitem[1] << ' ' << newitem[2]<<endl;
}

void new_sale() {
	int num;
	ofstream outSalesFile("Sales.txt", ios::app);
	static string newsale[3];
	cout << "\nEnter buyer's name: ";
	cin >> newsale[0];
	cout << "\nEnter Item number: ";
	cin >> newsale[1];
	if (search(newsale[1]))
	{
		cout << '\n' << found_item[0] << "	" << found_item[1] << "	" << found_item[2] << endl;
	}
	else
	{
		cerr << "Item Record is not found... try again\n";
		exit(EXIT_FAILURE);
	}
	cout << "\nEnter Quantity: ";
	cin >> num;
	
	num *=atoi(found_item[2].c_str());
	newsale[2] = to_string(num);
	if (!outSalesFile)
	{
		cerr << "File couldn't be opened" << endl;
		exit(EXIT_FAILURE);
	}
	else
		outSalesFile << newsale[0] << " " << newsale[1] << " " << newsale[2] << endl;
	return;
}
void display_items() {
	
	ifstream InItemFile("Item.txt", ios::in);
	static string DIS_ITEMS[3];
	cout << "\n=================== ITEMS RECORDS ====================\n";
	while (InItemFile >> DIS_ITEMS[0] >> DIS_ITEMS[1] >> DIS_ITEMS[2])
	{
		cout << setw(15)<<DIS_ITEMS[0] << setw(15) << DIS_ITEMS[1] << setw(15) << DIS_ITEMS[2] << endl;
	}
	cout << endl;
	return;
}
void display_sales(){

	ifstream InSalesFile("Sales.txt", ios::in);
	static string DIS_SALES[3];
	cout << "\n=================== SALES RECORDS ====================\n";
	while (InSalesFile >> DIS_SALES[0] >> DIS_SALES[1] >> DIS_SALES[2])
	{
		cout << setw(15)<<DIS_SALES[0] << setw(15) << DIS_SALES[1] << setw(15) << DIS_SALES[2] << endl;
	}
	cout << endl;
	return;
}
bool search(string a) {
	
	ifstream InItemFile("Item.txt", ios::in);
	while (InItemFile >> found_item[0] >> found_item[1] >> found_item[2])
	{
		if (found_item[0] == a)
			return 1;
	}
	return 0;
}

