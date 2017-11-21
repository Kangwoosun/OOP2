#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Point.h"
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
	stringstream ss("2 10 8 10 4 50 5 10 6 20 10 11 4 11 5 11 4 12 7 10 1 10");
	int a;
	int b;

	vector <Point> tokenOut;
	vector <Point> tokenIn;
	Circle c1(Point(4, 10), 2);
	while (ss >> a >> b)
	{
		if (sqrt((4 - a)*(4 - a) + (10 - b)*(10 - b)) <= 2)
			tokenIn.push_back(Point(a, b));
		else
			tokenOut.push_back(Point(a, b));
	}
	vector <Point>::iterator p;
	cout << "Number of points inside the circle " << tokenIn.size() << endl;
	cout << "Number of points outside the circle " << tokenOut.size() << endl;
	cout << "\nInside Points\n";
	for (p = tokenIn.begin(); p != tokenIn.end(); p++) {
		cout << p->getX() << "		" << p->getY() << endl;
	}
	cout << "Out side Points\n";
	for (p = tokenOut.begin(); p != tokenOut.end(); p++) {
		cout << p->getX() << "		" << p->getY() << endl;
	}
}