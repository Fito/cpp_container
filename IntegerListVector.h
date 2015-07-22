#ifndef __INTEGERLISTVECTOR__H__
#define __INTEGERLISTVECTOR__H__
#include <vector>
using namespace std;

class IntegerListVector{
private:
	vector<int> *list;
	int length;
public:
	IntegerListVector();
	void push(int value);
	int pop();
	void pushEnd(int value);
	int popEnd();
	int getLength();
	int getElement(int element);
};

#endif
