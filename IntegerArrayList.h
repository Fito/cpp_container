/* IntegerArrayList.h
 * 6/29/15
 * Brook Thomas - Adolfo von Zastrow
 */

/**	\file IntegerArrayList.h
 *	\mainpage
 *	<h1>List Library</h1>
 *	The List Library contains a number of classes for implementing double-ended lists.<br>
 *	Most of the classes are solely for use with Integer datatype, however, the VectorList template can be used with any datatype.<br>
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
