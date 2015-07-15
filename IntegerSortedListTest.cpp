/*  IntegerSortedList.cpp
 *  6/25/15 by MHS
 */

#include "IntegerSortedList.h"
#include <iostream>
using namespace std;

/**
 * This main method tests the IntegerSortedList method.  An IntegerSortedList
 * is populated and the values printed out to the console.
 */
int main(){

	IntegerSortedList list;

	list.insert(10);
	list.insert(9);
	list.insert(7);
	list.insert(7);
	list.insert(7);
	list.insert(4);
	list.insert(2);
	list.insert(5);
	list.insert(6);

	list.readOut();

	cout << "Instance of 4 at: " <<(list.findElement(4)) << endl;
	cout << "Intance of 17 at: " <<(list.findElement(17)) << endl;

	list.readOut();

	list.removeElement(4);

	cout << "Element at index 4 removed." << endl;

	list.readOut();

	cout << "Instance of 4 at: " << (list.findElement(4)) << endl;

	cout << "Value at 0 is: " << list.get(0) << endl;
	cout << "Value at 3 is: " << list.get(3) << endl;
	cout << "Value at 11 is out of bounds and prints an alert: " << list.get(11) << endl;
	cout << "Value at -5 is out of bounds and prints an alert: " << list.get(-5) << endl;
	cout << "Value 2 is present " << list.count(2) << " times" << endl;
	cout << "Value 7 is present " << list.count(7) << " times" << endl;
	cout << "Value 10 is present " << list.count(10) << " times" << endl;
	cout << "Value 13 is present " << list.count(13) << " times" << endl;
}
