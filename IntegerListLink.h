/* IntegerListLink.h
 * 6/29/15
 * Brook Thomas - Adolfo von Zastrow
 */

/**	\file IntegerListLink.h
 *	\mainpage
 *	<h1>IntegerListLink</h1>
 *	IntegerListLink is a List container-type specifically for storing and retrieving integers.<br>
 *	Despite it's name, IntegerListLink is actually a Deque, and provides double-ended push and pop functionality.<br>
 */

#ifndef __INTEGER_LINKED_LIST__H__
#define __INTEGER_LINKED_LIST__H__

class Node
{
	public:
		int value;
		Node *nextNode;
};

class IntegerListLink
{
	private:
		Node *headNode;
		Node *endNode;
		int length;
		void checkListLength();
		void checkListBounds(int index);
	public:
		IntegerListLink();
		~IntegerListLink();
		void push(int value);
		int pop();
		void pushEnd(int value);
		int popEnd();
		int getLength();
		int getElement(int element);
		void sort();
};

#endif
