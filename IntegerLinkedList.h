/* IntegerLinkedList.h
 * 6/29/15
 * Brook Thomas - Adolfo von Zastrow
 */

/**	\file IntegerLinkedList.h
 *	\mainpage
 *	<h1>IntegerLinkedList</h1>
 *	IntegerLinkedList is a List container-type specifically for storing and retrieving integers.<br>
 *	Despite it's name, IntegerLinkedList is actually a Deque, and provides double-ended push and pop functionality.<br>
 */

#ifndef __INTEGER_LINKED_LIST__H__
#define __INTEGER_LINKED_LIST__H__

class Node {
	public:
		int value;
		Node *nextNode;
};

class IntegerLinkedList {
private:
	Node *headNode;
	Node *endNode;
	int length;
	void checkListLength();
	void checkListBounds(int index);
public:
	IntegerLinkedList();
	~IntegerLinkedList();
	void push(int value);
	int pop();
	void pushEnd(int value);
	int popEnd();
	int getLength();
	int getElement(int element);
	void readOut();
	void sort();
};

#endif
