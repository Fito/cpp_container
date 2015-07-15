/* IntegerArrayList.cpp
 * 6/29/15
 * Brook Thomas - Adolfo von Zastrow
 */

/** \file IntegerArrayList.cpp */

#include <iostream>
#include <exception>
#include "IntegerArrayList.h"

/** Default constructor class. Takes no arguments. */
IntegerArrayList::IntegerArrayList():
  list(nullptr),
  length(0)
  {};

/**
*   Adds a new value to the front of the list.
*
*    \param value int An integer value to add to the front of the list.
*/
void IntegerArrayList::push(int value)
{
    // If the list is currently empty...
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
    return;

}

/**
*   Removes and returns a single value from the front of the list.
*
*   \returns int The front element of the list.
*/
int IntegerArrayList::pop()
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

    // Established the list isn't empty - continue...
    int returnValue = list[0];
    int *newList;

    try
    {
        newList = new int[length];
    }
    catch (std::bad_alloc& e)
    {
        std::cerr << "Bad Allocation Exception: " << e.what() << std::endl;
        return 0;
    }
    catch (...)
    {
        std::cerr << "An unknown exception occured while allocating memory for an array." << std::endl;
        return 0;
    }

    copyArray(list + 1, newList);
    replaceList(newList);

    // The list might be zero length now, delete the array if so
    if (--length == 0)
    {
        delete[] list;
        list = NULL;
    }

    return returnValue;

}

/**
*   Adds a new value to the end of the list.
*
*   \param value int An integer value to add to the end of the list.
*/
void IntegerArrayList::pushEnd(int value)
{
    if (!length)
    {
        push(value);    // push method already has exception handling
        return;
    }

    // At least one element in list already, continue...
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
*    Removes and returns a single value from the back of the list.
*
*    \returns int The back element of the list.
*/
int IntegerArrayList::popEnd() {

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

    // List might be empty now, if so delete the array
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
int IntegerArrayList::getLength() {
  return length;
}

/**
*    Given an index value, returns the element at the given index value without removing it.
*
*    \param element int A valid index value.
*
*    \returns int The integer value at the given index.
*/
int IntegerArrayList::getElement(int element) {
    try
    {
        if (element < 0  || element > length-1)
        {
            throw std::out_of_range("Requested index location does not exist in array.");
        }
    }
    catch (std::out_of_range& e)
    {
        std::cerr << "Out of Range Exception: " << e.what() << std::endl;
        return;
    }
    catch (...)
    {
        std::cerr << "Unknown exception while fetching index value." << std::endl;
        return;
    }

    // valid index location, proceed...
    return list[element];
}

void IntegerArrayList::copyArray(int* source, int* destination) {
  for(int i = 0; i < length; i++) {
    destination[i] = source[i];
  }
}

void IntegerArrayList::replaceList(int *newList) {
  delete[] list;
  list = newList;
  newList = nullptr;
}

/**
    Sorts the current list in ascending order using the bubblesort method.
*/
void IntegerArrayList::sort () {

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
