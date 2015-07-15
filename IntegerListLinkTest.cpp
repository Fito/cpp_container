/*  IntegerListLink.cpp
 *  6/25/15 by MHS
 */

#include "IntegerListLink.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

/**
 * This main method tests the IntegerListLink method.  An IntegerListLink
 * is populated and the values printed out to the console.
 */
int main(){

	IntegerListLink list;

	list.push(7);
	list.push(12);
	list.push(8);
	list.push(13);
	list.push(27);
	list.push(165);
	list.push(83);
	list.push(17);

	cout << "before sorting" << endl;
	int length = list.getLength();

	for(int i = 0; i < length; i++)
	{
		cout << list.getElement(i) << endl;
	}

	list.sort();

	cout << "after sorting" << endl;
	length = list.getLength();

	for(int i = 0; i < length; i++)
	{
		cout << list.getElement(i) << endl;
	}
}
