/* IntegerList.cpp
 * 6/29/15
 * Brook Thomas - Adolfo von Zastrow
 */

/** \file IntegerList.cpp */

#include <iostream>
#include <exception>
#include "IntegerList.h"

/** Default constructor class. Takes no arguments. */
IntegerList::IntegerList():
  list(nullptr),
  length(0)
  {};

/**
*   Adds a new value to the top of the list.
*
*    \param value int An integer value to add to the top of the list.
*/
void IntegerList::push(int value)
{
    if (length == 0)
    {
        try
        {
            list = new int[++length];
        }
        catch (std::bad_alloc& e)
        {
            std::cerr << "Bad Allocation Exception: " << e.what() << std::endl;
            return;
        }
        catch (...)
        {
            std::cerr << "An unknown error occured while allocating memory to array." << std::endl;
            return;
        }

        list[0] = value;
        return;
    }

    // Otherwise...
    int *newList;

    try
    {
        newList = new int[++length];
    }
    catch (std::bad_alloc& e)
    {
        std::cerr << "Bad Allocation Exception: " << e.what() << std::endl;
        return;
    }
    catch (...)
    {
        std::cerr << "An unknown error occured while allocating memory to the array." << std::endl;
        return;
    }

    newList[0] = value;

    copyArray(list, newList + 1);
    replaceList(newList);

}

/**
*   Removes and returns a single value from the top of the list.
*
*   \returns int The top element of the list.
*/
int IntegerList::pop()
{
    try
    {
        if (length == 0)
        {
            throw std::out_of_range("The array is currently empty.");
        }
    }
    catch (std::out_of_range& e)
    {
        std::cerr << "Range Error: " << e.what() << std::endl;
        return 0;
    }
    catch (...)
    {
        std::cerr << "An unknown error occured while popping from the list." << std::endl;
        return 0;
    }

    int returnValue = list[0];

    int *newList = new int[length];

    copyArray(list + 1, newList);
    replaceList(newList);

    if (--length == 0)
    {
        delete[] list;
        list = NULL;
    }

    return returnValue;

}

/**
*   Adds a new value to the bottom of the list.
*
*   \param value int An integer value to add to the bottom of the list.
*/
void IntegerList::pushEnd(int value)
{
    if (!length)
    {
        push(value);    // push method already has exception handling
        return;
    }

    int *newList;

    try
    {
        newList = new int[length + 1];
    }
    catch (std::bad_alloc& e)
    {
        std::cerr << "Bad Allocation Error: " << e.what() << std::endl;
        return;
    }
    catch (...)
    {
        std::cerr << "An unknown error occured while allocating memory to the array." << std::endl;
        return;
    }

    copyArray(list, newList);
    replaceList(newList);

    list[length++] = value;
}

/**
*    Removes and returns a single value from the bottom of the list.
*
*    \returns int The bottom element of the list.
*/
int IntegerList::popEnd() {

    try
    {
        if (length == 0)
        {
            throw std::out_of_range("The array is currently empty.");
        }
    }
    catch (std::out_of_range& e)
    {
        std::cerr << "Range Error: " << e.what() << std::endl;
        return 0;
    }
    catch (...)
    {
        std::cerr << "An unknown error occured while popping from the list." << std::endl;
        return 0;
    }

    int returnValue = list[--length];

    int *newList;

    try
    {
        newList = new int[length];
    }
    catch (std::bad_alloc& e)
    {
        std::cerr << "Bad Allocation Error: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "An unknown error occured while allocating space for an array." << std::endl;
    }

    copyArray(list, newList);
    replaceList(newList);

    if (length == 0)
    {
        delete[] list;
        list = nullptr;
    }

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

void IntegerList::copyArray(int* source, int* destination) {
  for(int i = 0; i < length; i++) {
    destination[i] = source[i];
  }
}

void IntegerList::replaceList(int *newList) {
  delete[] list;
  list = newList;
  newList = nullptr;
}

void IntegerList::sort () {

    for (int outer_pass = 0; outer_pass < length - 1; outer_pass++) {
        for (int inner_pass = 0; inner_pass < length - outer_pass - 1; inner_pass++) {

            if (list[inner_pass] > list[inner_pass+1]) {
                int tempStorage = list[inner_pass];
                list[inner_pass] = list[inner_pass+1];
                list[inner_pass+1] = tempStorage;
            }
        }
    }
}
