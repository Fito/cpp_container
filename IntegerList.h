/* IntegerList.h
 * 6/29/15
 * Brook Thomas - Adolfo von Zastrow
 */

/**	\file IntegerList.h
 *	\mainpage
 *	<h1>IntegerList</h1>
 *	IntegerList is a List container-type specifically for storing and retrieving integers.<br>
 *	Despite it's name, IntegerList is actually a Deque, and provides double-ended push and pop functionality.<br>
 */

#ifndef __INTEGERLIST__H__
#define __INTEGERLIST__H__

#include <iostream>

class Node {
	public:
		Node (int value);
		int value;
		Node * next;
};

class IntegerList {
private:
	Node * headNode;
	int length;
public:
	void insert(int value);
	int get (int index);
	int count (int value);
	int findElement (int value);
	void removeElement (int index);
	void readOut ();
};

#endif
