/* IntegerListSorted.h
 * 6/29/15
 * Brook Thomas - Adolfo von Zastrow
 */

/**	\file IntegerListSorted.h
 *	\mainpage
 *	<h1>IntegerListSorted</h1>
 *	IntegerListSorted is a List container-type specifically for storing and retrieving integers.<br>
 *	Despite it's name, IntegerListSorted is actually a Deque, and provides double-ended push and pop functionality.<br>
 */

#ifndef __INTEGER_LIST_SORTED__H__
#define __INTEGER_LIST_SORTED__H__

#include <iostream>

class Node {
	public:
		Node (int value);
		int value;
		Node * next;
};

class IntegerListSorted {
private:
	Node * headNode;
	int length;
public:
	IntegerListSorted();
	~IntegerListSorted();
	void insert(int value);
	int get (int index);
	int count (int value);
	int findElement (int value);
	void removeElement (int index);
};

#endif
