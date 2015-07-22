/*  IntegerList.cpp
 *  6/25/15 by MHS
 */
#include <iostream>
#include "IntegerListVector.h"
using namespace std;

/**
 * This main method tests the IntegerList method.  An IntegerList
 * is populated and the values printed out to the console.
 */
int main()
{

	IntegerListVector list;

	list.push(15);
	list.push(27);
	list.push(39);
	list.push(24);

	list.pushEnd(11);
	list.pushEnd(29);

	list.pop();
	list.popEnd();

	list.push(12);
	list.push(73);
	list.push(13);

	for (int x = 0; x < list.getLength(); x++)
	{
		cout << list.getElement(x) << " ";
	}

	cout << endl;

	list.sort();

	for (int x = 0; x < list.getLength(); x++)
	{
		cout << list.getElement(x) << " ";
	}

	cout << endl;


}
