#pragma once
#include <iostream>
using namespace std;
class Point {
private:
	int x;
	int y;
public:
	Point(int a, int b) :x(a), y(b) {} //constructor
int getX() { return x; }
int getY() { return y; }
void setX(int a) { x = a; }
void setY(int a) { y = a; }
};

class Circle {
	Point center; // composite class
	double radius;
public:
	Circle(Point a, double b) :center(a), radius(b) {}
	Point getPoint() { return center; }
	double getRadius() { return radius; }
};