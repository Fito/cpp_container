#ifndef __INTEGERLISTLINKED__H__
#define __INTEGERLISTLINKED__H__
#include "Node.h"

class IntegerListLinked
{
private:
	Node<int>* head;
	int length;
public:
	IntegerListLinked();
	~IntegerListLinked();
	void push(int value);
	int pop();
	void pushEnd(int value);
	int popEnd();
	int getLength();
	int getElement(int element);
	void sort();
};

#endif
