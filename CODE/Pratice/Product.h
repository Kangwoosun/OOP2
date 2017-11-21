#pragma once
#include <iostream>
#include <string>
using namespace std;
class Product {
private:
	string desc;
	int qtty;
	double price;
public:
	Product(string a, int b, double
		c) :desc(a), qtty(b), price(c) {}//constructor
	void setDesc(string);
	void setQtty(int);
	void setPrice(double);
	string getDesc();
	int getQtty();
	double getPrice();
};
void Product::setDesc(string a) {
	desc = a;
}
void Product::setQtty(int a) {
	qtty = a;
}
void Product::setPrice(double a) {
	price = a;
}
string Product::getDesc() {
	return desc;
}
int Product::getQtty() {
	return qtty;
}
double Product::getPrice() {
	return price;
}