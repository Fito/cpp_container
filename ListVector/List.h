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

#ifndef __LIST__H__
#define __LIST__H__

#include <vector>
#include <iostream>

template <typename T>
class List {
	private:
		std::vector<T> *list;
		void checkListLength();
	public:
		List();
		~List();
		void push(T value);
		T pop();
		void pushEnd(T value);
		T popEnd();
		int getLength();
		T getElement(int element);
};

#include "List.cpp"

#endif
