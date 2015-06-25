#include <iostream>
#include "IntegerList.h"

IntegerList::IntegerList():
  list(new int[0]),
  length(0)
  {};

void IntegerList::push(int value) {
  length++;
  int *newList = new int[length];

  newList[0] = value;
  for(int i=0; i<length; i++) {
    newList[i+1] = list[i];
  }

  delete[] list;
  list = newList;
}

int IntegerList::pop() {
  int returnValue = list[0];

  int *newList = new int[length];

  for(int i=1; i<length; i++) {
    newList[i-1] = list[i];
  }

  length--;

  delete[] list;
  list = newList;
  return returnValue;
}

void IntegerList::pushEnd(int value) {
  int *newList = new int[length + 1];

  for(int i=0; i<length; i++) {
    newList[i] = list[i];
  }
  newList[length++] = value;

  delete[] list;
  list = newList;
}

int IntegerList::popEnd() {
  int returnValue = list[--length];
  int *newList = new int[length];

  for(int i=0; i<length; i++) {
    newList[i] = list[i];
  }

  delete[] list;
  list = newList;

  return returnValue;
}

int IntegerList::getLength() {
  return length;
}

int IntegerList::getElement(int element) {
  return list[element];
}
