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

	list.push(5);
	list.push(7);
	list.push(9);
	list.push(4);
	list.push(1);
	list.push(9);
	list.push(2);


	list.sort();


}
