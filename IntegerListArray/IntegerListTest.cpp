/*  IntegerList.cpp
 *  6/25/15 by MHS
 */

#include "IntegerList.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

/**
 * This main method tests the IntegerList method.  An IntegerList
 * is populated and the values printed out to the console.
 */
int main(){
	IntegerList *list;
	int x = 0;

	for (int i = 0; i < 12; i++) {
		list.push(rand() % 101);
	}

	list.sort();

	for (int i = 0; i < 12; i++) {
		cout << list.getElement(i) << " ";
	}

	cout << endl;


	/*
	// list.push(10);
	// cout << "length: " << list.getLength() << endl;
	// list.push(20);
	cout << "length: " << list.getLength() << endl;
	for(int i = 0 ; i < 5 ; i++) {
		list.push(i*10);
	}

	for(int i = 0; i < list.getLength(); i++) {
		cout << list.getElement(i) << endl;
	}

	cout << "length: " << list.getLength() << endl;

	for(int i = 0 ; i < 6 ; i++) {
		cout << "poped: " << list.pop() << endl;
	}

	for(int i = 0 ; i < list.getLength() ; i++){
		cout << "list[" << i << "]: " << list.getElement(i) << endl;
	}

	for(int i = 0 ; i < 5 ; i++) {
		list.pushEnd(i*10);
	}

	cout << "After pushEnd" << endl;

	for(int i = 0 ; i < list.getLength() ; i++){
		cout << "list[" << i << "]: " << list.getElement(i) << endl;
	}

	for(int i = 0 ; i < 6 ; i++) {
		list.popEnd();
	}

	cout << "After popEnd" << endl;

	for(int i = 0 ; i < list.getLength() ; i++){
		cout << "list[" << i << "]: " << list.getElement(i) << endl;
	}

	*/
}