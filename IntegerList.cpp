/** \file IntegerList.cpp */

#include <iostream>
#include "IntegerList.h"

/** Default constructor class. Takes no arguments */
IntegerList::IntegerList():
  list(new int[0]),
  length(0)
  {};

/**
    Pushes a new value to the top of the list.
    \param value int An integer value to add to the top of the list.
*/
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

/**
    Removes and returns a single value from the top of the list.
    Returns nullptr if the list is currently empty.

    \returns int The top list element, or nullptr if the list is empty.
*/
int IntegerList::pop() {

    if (length == 0) {
        return nullptr;
    }

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

/**
    Pushes a new value to the bottom of the list.
    \param value int An integer value to add to the bottom of the list.
*/
void IntegerList::pushEnd(int value) {
  int *newList = new int[length + 1];

  for(int i=0; i<length; i++) {
    newList[i] = list[i];
  }
  newList[length++] = value;

  delete[] list;
  list = newList;
}

/**
    Removes and returns a single value from the bottom of the list.
    Returns nullptr if the list is currently empty.

    \returns int The bottom list element, or nullptr if the list is empty.
*/
int IntegerList::popEnd() {

    if (length == 0) {
        return nullptr;
    }

  int returnValue = list[--length];
  int *newList = new int[length];

  for(int i=0; i<length; i++) {
    newList[i] = list[i];
  }

  delete[] list;
  list = newList;

  return returnValue;
}

/**
    Returns the current length of the list. May be zero.
    \returns int The current length of the list.
*/
int IntegerList::getLength() {
  return length;
}

/**
    Given an index value, returns the element at the given index value.
    Returns nullptr if the index position is invalid.
    \param element int A valid list index value.
    \returns int The integer at the given index, or nullptr if index is invalid.
*/
int IntegerList::getElement(int element) {

    if (element < length && element >= 0) {
        return list[element];
    } else {
        return nullptr;
    }

}
