/* In IntegerList.cpp
 * 6/29/15
 * Brook Thomas - Adolfo von Zastrow
 */

/** \file IntegerList.cpp */

#include <iostream>
#include "IntegerList.h"

/** Default constructor class. Takes no arguments. */
IntegerList::IntegerList():
  list(new int[0]),
  length(0)
  {};

/**
*   Adds a new value to the top of the list.
*
*    \param value int An integer value to add to the top of the list.
*/
void IntegerList::push(int value) {

  int *newList = new int[++length];

  newList[0] = value;

  for(int i=0; i<length; i++) {
    newList[i+1] = list[i];
  }

  delete[] list;
  list = newList;
}

/**
*   Removes and returns a single value from the top of the list.
*
*   \returns int The top element of the list.
*/
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

/**
*   Adds a new value to the bottom of the list.
*
*   \param value int An integer value to add to the bottom of the list.
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
*    Removes and returns a single value from the bottom of the list.
*
*    \returns int The bottom element of the list.
*/
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

/**
*    Returns the current length of the list. May be zero.
*
*    \returns int The current length of the list.
*/
int IntegerList::getLength() {
  return length;
}

/**
*    Given an index value, returns the element at the given index value without removing it.
*
*    \param element int A valid index value.
*
*    \returns int The integer value at the given index.
*/
int IntegerList::getElement(int element) {

    return list[element];


}
