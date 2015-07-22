/*  IntegerListLink.cpp
 *  6/25/15 by MHS
 */

#include "IntegerListLinked.h"
#include <iostream>
using namespace std;

/**
 * This main method tests the IntegerListLink method.  An IntegerListLink
 * is populated and the values printed out to the console.
 */
int main(){

	IntegerListLinked list;

	list.push(5);
	cout << "Pushed\n";

	list.push(7);
	cout << "PushedAgain.\n";


	list.pushEnd(3);

	cout << "PushedEnd.\n";

	list.pushEnd(1);
	cout << "PushedEndAgain.\n";

	list.pop();
	cout << "Popped.\n";

	list.popEnd();
	cout << "PoppedEnd.\n";

	list.push(3);
	list.push(9);
	list.push(5);
	list.push(1);
	list.push(7);
	cout << "Pushed a bunch more.\n";

	list.sort();
	cout << "Sorted.\n";

	for (int x = 0; x < list.getLength(); x++)
	{
		cout << list.getElement(x) << " ";
	}

	cout << endl;

}
