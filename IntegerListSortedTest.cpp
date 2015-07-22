/*  IntegerListSorted.cpp
 *  6/25/15 by MHS
 */

#include "IntegerListSorted.h"
#include <iostream>
using namespace std;

/**
 * This main method tests the IntegerListSorted method.  An IntegerListSorted
 * is populated and the values printed out to the console.
 */
int main(){

	IntegerListSorted list;

	list.insert(10);
	list.insert(9);
	list.insert(7);
	list.insert(7);
	list.insert(7);
	list.insert(4);
	list.insert(2);
	list.insert(5);
	list.insert(6);

	cout << "Instance of 4 at: " <<(list.valueIndex(4)) << endl;
	cout << "Intance of 17 at: " <<(list.valueIndex(17)) << endl;

	list.remove(4);

	cout << "Element at index 4 removed." << endl;

	cout << "Instance of 4 at: " << (list.valueIndex(4)) << endl;

	cout << "Value at 0 is: " << list.getElement(0) << endl;
	cout << "Value at 3 is: " << list.getElement(3) << endl;
	cout << "Value at 11 is out of bounds and prints an alert: " << list.getElement(11) << endl;
	cout << "Value at -5 is out of bounds and prints an alert: " << list.getElement(-5) << endl;
	cout << "Value 2 is present " << list.valueCount(2) << " times" << endl;
	cout << "Value 7 is present " << list.valueCount(7) << " times" << endl;
	cout << "Value 10 is present " << list.valueCount(10) << " times" << endl;
	cout << "Value 13 is present " << list.valueCount(13) << " times" << endl;
}
