/* IntegerSortedList.h
 * 6/29/15
 * Brook Thomas - Adolfo von Zastrow
 */

/**	\file IntegerSortedList.h
 *	\mainpage
 *	<h1>IntegerSortedList</h1>
 *	IntegerSortedList is a List container-type specifically for storing and retrieving integers.<br>
 *	Despite it's name, IntegerSortedList is actually a Deque, and provides double-ended push and pop functionality.<br>
 */

#ifndef __INTEGER_SORTED_LIST__H__
#define __INTEGER_SORTED_LIST__H__

#include <iostream>

class Node {
	public:
		Node (int value);
		int value;
		Node * next;
};

class IntegerSortedList {
private:
	Node * headNode;
	int length;
public:
	IntegerSortedList();
	~IntegerSortedList();
	void insert(int value);
	int get (int index);
	int count (int value);
	int findElement (int value);
	void removeElement (int index);
	void readOut ();
};

#endif
