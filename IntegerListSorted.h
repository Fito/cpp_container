#ifndef __INTEGERLISTSORTED__H__
#define __INTEGERLISTSORTED__H__
#include "Node.h"

class IntegerListSorted{
private:
	Node<int>* head;
	int length;
public:
	IntegerListSorted();
	~IntegerListSorted();
	void insert(int value);
	void remove(int index);
	int valueCount(int value);
	int valueIndex(int value);
	int getElement(int element);
	int getLength();
};

#endif
