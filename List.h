/* List.h
 * 6/29/15
 * Brook Thomas - Adolfo von Zastrow
 */

/**	\file List.h
 *	\mainpage
 *	<h1>List</h1>
 *	List is a List container-type specifically for storing and retrieving integers.<br>
 *	Despite it's name, List is actually a Deque, and provides double-ended push and pop functionality.<br>
 */

#ifndef __LIST__H__
#define __LIST__H__

template <typename T>
class Node
{
	public:
		T value;
		Node *nextNode;
};

template <typename T>
class List
{
	private:
		Node<T> *headNode;
		Node<T> *endNode;
		int length;
		void checkListLength();
		void checkListBounds(int index);
	public:
		List();
		~List();
		void push(T value);
		T pop();
		void pushEnd(T value);
		T popEnd();
		int getLength();
		T getElement(int element);
		void sort();
};

#include "List.cpp"

#endif
