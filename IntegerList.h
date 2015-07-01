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

class IntegerList{
private:
	int *list;
	int length;
	void replaceList(int *newList);
	void copyArray(int* source, int* destination);
public:
	IntegerList();
	void push(int value);
	int pop();
	void pushEnd(int value);
	int popEnd();
	int getLength();
	int getElement(int element);
	void sort();
};

#endif
