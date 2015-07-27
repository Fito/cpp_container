/* IntegerListArray.cpp
 * 6/29/15
 * Brook Thomas - Adolfo von Zastrow
 */

/** \file IntegerListArray.cpp */

/**
*   \mainpage
*   <h3>Adolfo Von Zastrow and Brook Thomas</h3>
*   <h3>CSC 340 - Programming Methodology - Summer 2015</h3>
*
*   <p>IntegerList provides four integer-type %List classes of varying container types,
*    along with a type-independent %List template.</p>
*
*   <h4>Common features...</h4>
*   <ul>
*    <li>Automatic memory management.</li>
*   <li>Robust exception handling using the std::exception class.</li>
*   <li>Methods for arbitrary element retrieval and sorting.</li>
*   </ul>
*
*   <h4>The following classes are provided...</h4>
*
*   <p><b>IntegerListArray</b> - An integer-type array-based container that supports double-ended insertion and retrieval.</p>
*   <p><b>IntegerListVector</b> - An integer-type container utilizing the Standard Template Library's Vector template.</p>
*   <p><b>IntegerListLinked</b> - An integer-type singly-linked list container that supports double-ended insertion and retrieval.</p>
*   <p><b>IntegerListSorted</b> - An integer-type singly-linked list container that automatically orders elements ASCENDING upon insertion.
*        Note that %IntegerListSorted does not support End insertion or retrieval.</p>
*
*   <h4>The following template is also provided...</h4>
*
*   <p><b>List</b> - A type-independent container template that supports double-ended insertion and retrieval.</p>
*
*/

#include <iostream>
#include <exception>
#include "IntegerListArray.h"

/**
*   Copies the elements from the source array into the destination array.
*
*    \param source int* Pointer the source array.
*    \param destination int* Pointer the destination array.
*    \param numberOfElements int The number of elements to copy.
*/
void copyArray(int* source, int* destination, int numberOfElements)
{
  for(int i = 0; i < numberOfElements; i++) {
    destination[i] = source[i];
  }
}

/**
*   Deletes an array and points its reference to a new array.
*
*    \param list &int* Reference to the pointer to the array being deleted.
*    \param newList int* Pointer to the new array.
*/
void replaceList(int* &list, int* newList)
{
  delete[] list;
  list = newList;
  newList = nullptr;
}

/** Class constructor. Takes no arguments. */
IntegerListArray::IntegerListArray():
    list(nullptr),
    length(0)
    {};

/** Class destructor. Will deallocate from the heap any remaining elements in the list array. */
IntegerListArray::~IntegerListArray()
{
    delete[] list;
}

/**
*   Add a new integer value to the front of the list.
*
*    \param value int The integer value to be added.
*/
void IntegerListArray::push(int value)
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

    copyArray(list, newList + 1, length);
    replaceList(list, newList);

    return;

}

/**
*   Removes and returns an integer value from the front of the list.
*   If list is empty a value of zero is returned.
*   It is strongly advised you check list size before calling the pop() method.
*
*   \returns int The integer value at the front of the list, if available.
*/
int IntegerListArray::pop()
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

    copyArray(list + 1, newList, length);
    replaceList(list, newList);;

    // The list might be zero length now, delete the array if so
    if (--length == 0)
    {
        delete[] list;
        list = NULL;
    }

    return returnValue;

}

/**
*   Add a new integer value to the back of the list.
*
*    \param value int The integer value to be added.
*/
void IntegerListArray::pushEnd(int value)
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

    copyArray(list, newList, length);
    replaceList(list, newList);

    list[length++] = value;
}

/**
*   Removes and returns an integer value from the back of the list.
*   If list is empty a value of zero is returned.
*   It is strongly advised you check list size before calling the popEnd() method.
*
*   \returns int The integer value at the back of the list, if available.
*/
int IntegerListArray::popEnd()
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

    copyArray(list, newList, length);
    replaceList(list, newList);

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
int IntegerListArray::getLength()
{
  return length;
}

/**
*   Returns the integer at the given index value.
*   If the index value is invalid, zero will be returned.
*   We strongly advise checking length before calling getElement() to ensure your request is valid.
*
*    \param element int An index value in the list.
*
*    \returns int The integer value at the given index.
*/
int IntegerListArray::getElement(int element)
{
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
        return 0;
    }
    catch (...)
    {
        std::cerr << "Unknown exception while fetching index value." << std::endl;
        return 0;
    }

    // valid index location, proceed...
    return list[element];
}

/**
    Sorts the current list in ascending order using the bubblesort method.
*/
void IntegerListArray::sort ()
{
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
