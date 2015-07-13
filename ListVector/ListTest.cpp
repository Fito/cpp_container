/*  IntegerList.cpp
 *  6/25/15 by MHS
 */

#include "List.h"
#include <iostream>
using namespace std;

/**
 * This main method tests the IntegerList method.  An IntegerList
 * is populated and the values printed out to the console.
 */
int main(){

	List<int> *list = new List<int>();

	list->push(10);
	cout << "length: " << list->getLength() << endl;
	list->push(20);
	cout << "length: " << list->getLength() << endl;

	list->push(10);
	list->pop();
	list->pop();

	for(int i = 0 ; i < 5 ; i++) {
		list->push(i*10);
	}
	cout << "done pushing" << endl;

	for(int i = 0; i < list->getLength(); i++) {
		cout << list->getElement(i) << endl;
	}

	cout << "length: " << list->getLength() << endl;

	for(int i = 0 ; i < 3 ; i++) {
		cout << "poped: " << list->pop() << endl;
	}

	for(int i = 0 ; i < list->getLength() ; i++){
		cout << "list[" << i << "]: " << list->getElement(i) << endl;
	}

	for(int i = 0 ; i < 5 ; i++) {
		list->pushEnd(i*10);
	}

	cout << "After pushEnd" << endl;

	for(int i = 0 ; i < list->getLength() ; i++){
		cout << "list[" << i << "]: " << list->getElement(i) << endl;
	}

	for(int i = 0 ; i < 3 ; i++) {
		list->popEnd();
	}

	cout << "After popEnd" << endl;

	for(int i = 0 ; i < list->getLength() ; i++){
		cout << "list[" << i << "]: " << list->getElement(i) << endl;
	}

	list->getElement(5);
}
