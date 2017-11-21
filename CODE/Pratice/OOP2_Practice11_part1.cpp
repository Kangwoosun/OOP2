#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include "Product.h"
using namespace std;

int main()
{
	stringstream ss("Banana 12 5.5 Apple 13 10.0 Orange 3 4.0 Apple 12 10 Banana 10 4 Mango 15 15.0");
	
	string a;
	int b;
	int sum=0;
	double c;
	vector <Product> token;
	while (ss >> a >> b >> c)
	{
		Product temp(a, b, c);
		token.push_back(temp);
	}
	vector<Product>::iterator p;
	cout << "----------NO DISCOUNT ----------\n";
	for (p = token.begin(); p != token.end(); p++) {
		cout << setw(8) << p->getDesc() << setw(3)
			<< p->getQtty() << "* " << p->getPrice() 
			<< " = " << p->getPrice()*p->getQtty() << endl;
		sum += p->getPrice()*p->getQtty();
	}
	cout << "Total     " << sum << endl;
	sum = 0;
	cout << "\n------WITH 50% DISCOUNT for Banana-----\n";
	for (p = token.begin(); p != token.end(); p++) {
		if (p->getDesc() == "Banana")
		{
			cout << setw(8) << p->getDesc() << setw(3)
				<< p->getQtty() << "* " << p->getPrice() / 2
				<< " = " << p->getPrice()*p->getQtty() / 2 << endl;
			sum += p->getPrice()*p->getQtty()/2;
		}
		else {
			cout << setw(8) << p->getDesc() << setw(3)
				<< p->getQtty() << "* " << p->getPrice()
				<< " = " << p->getPrice()*p->getQtty() << endl;
			sum += p->getPrice()*p->getQtty();
		}
	}
	cout << "Total     " << sum << endl;
	return 0;
}