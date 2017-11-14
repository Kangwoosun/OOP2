#pragma once
#include <iostream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


template<class T>
class Generic
{
private:
	T *marray;
	int size;
public:
	Generic(T* a, int b) :marray(a), size(b){}
	void setsize(int a);
	void setmarray(T* a);
	void mySort();
	void swap(T * element1Ptr, T * element2Ptr);
	void output();
	T* getmarray();
	int getsize();
};
template<class T>
void Generic<T>::setsize(int a) {
	size = a;
}
template<class T>
void Generic<T>::setmarray(T* a) {
	marray = a;
}
template<class T>
T* Generic<T>::getmarray() {
	return marray;
}
template<class T>
int Generic<T>::getsize() {
	return size;
}
template<class T>
void Generic<T>::mySort() {
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size-1; j++)
		{
			if (marray[j] > marray[j + 1])
				swap(&marray[j], &marray[j + 1]);
		}
	
}
template<class T>
void Generic<T>::swap(T * element1Ptr, T * element2Ptr) {
	T temp;
	temp = *element1Ptr;
	*element1Ptr = *element2Ptr;
	*element2Ptr = temp;
}
template<class T>
void Generic<T>::output() {
	for (int i = 0; i < size; i++)
		cout << marray[i] << setw(10);
	cout << endl;
}