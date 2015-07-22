#ifndef __INTEGERLIST__H__
#define __INTEGERLIST__H__

class IntegerList{
private:
	int *list;
	int length;
public:
	IntegerList();
	void push(int value);
	int pop();
	void pushEnd(int value);
	int popEnd();
	int getLength();
	int getElement(int element);
};

#endif
