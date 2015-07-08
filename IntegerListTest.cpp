/*  IntegerList.cpp
 *  6/25/15 by MHS
 */

#include "IntegerList.h"
#include <iostream>
using namespace std;

/**
 * This main method tests the IntegerList method.  An IntegerList
 * is populated and the values printed out to the console.
 */
int main(){

	IntegerList list;

	list.insert(10);
	list.insert(9);
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

}
