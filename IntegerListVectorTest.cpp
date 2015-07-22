/*  IntegerList.cpp
 *  6/25/15 by MHS
 */

#include "IntegerListVector.h"
#include <iostream>
using namespace std;

/**
 * This main method tests the IntegerList method.  An IntegerList
 * is populated and the values printed out to the console.
 */
int main()
{

	IntegerListVector list;

	list.push(5);
	list.pushEnd(13);

	list.pop();

	list.popEnd();

	list.push(5);

	list.getElement(0);

	list.getLength();


}
