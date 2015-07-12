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

	IntegerList list;

	list.push(7);
	list.push(12);
	list.push(8);
	list.push(13);
	list.push(27);
	list.push(165);
	list.push(83);
	list.push(17);

	list.readOut();

	cout << endl;

	list.sort();

	list.readOut();

	cout << endl;





}
