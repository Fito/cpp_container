/*  IntegerListArray.cpp
 *  6/25/15 by MHS
 */

#include "IntegerListArray.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

/**
 * This main method tests the IntegerListArray method.  An IntegerListArray
 * is populated and the values printed out to the console.
 */
int main()
{

	IntegerListArray list;

	list.push(5);
	list.push(7);
	list.push(3);

	list.pop();
	list.pop();

	list.pushEnd(5);
	list.pushEnd(3);

	list.push(9);
	list.push(2);

	list.popEnd();
	list.popEnd();

	for (int i = 0; i < list.getLength(); i++)
	{
		cout << list.getElement(i) << " ";
	}

	cout << endl;



}
