/* IntegerArrayList.h
 * 6/29/15
 * Brook Thomas - Adolfo von Zastrow
 */

/**	\file IntegerArrayList.h
 *	\mainpage
 *	<h1>IntegerArrayList</h1>
 *	IntegerArrayList is a List container-type specifically for storing and retrieving integers.<br>
 *	Despite it's name, IntegerArrayList is actually a Deque, and provides double-ended push and pop functionality.<br>
 */

#ifndef __INTEGER_ARRAY_LIST__H__
#define __INTEGER_ARRAY_LIST__H__

class IntegerArrayList
{
	private:
		int *list;
		int length;
		void resize(int newSize);
		void replaceList(int *newList);
		void copyArray(int* source, int* destination);
	public:
		IntegerArrayList();
		void push(int value);
		int pop();
		void pushEnd(int value);
		int popEnd();
		int getLength();
		int getElement(int element);
		void sort();
};

#endif
