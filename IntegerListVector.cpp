/* IntegerListVector.cpp
 * 6/29/15
 * Brook Thomas - Adolfo von Zastrow
 */

/** \file IntegerListVector.cpp */

#include <iostream>
#include <exception>
#include "IntegerListVector.h"

/** Class constructor. Takes no arguments. */
IntegerListVector::IntegerListVector():
    list(NULL),
    length(0)
    {};

/** Class destructor. Relies upon std::vector destructor for heap deallocation. */
IntegerListVector::~IntegerListVector()
{
    delete list;
}

/**
*   Adds a new value to the top of the list.
*
*    \param value int An integer value to add to the top of the list.
*/
void IntegerListVector::push(int value) {
    if ( list == NULL )
    {
      try
      {
        list = new std::vector<int>(0,0);
      }
      catch( std::bad_alloc& e )
      {
        std::cerr << "Error while trying to instantiate vector: " << e.what() << "\n";
      }
      catch( ... )
      {
        std::cerr << "Unknown error. " << "\n";
      }
    }

    list->insert(list->begin(), value);
    length++;
}

/**
*   Removes and returns a single value from the top of the list.
*   If list is empty this will return 0.
*
*   \returns int The top element of the list.
*/
int IntegerListVector::pop()
{
    try
    {
        if (length == 0) { throw new std::length_error("List is empty."); }
    }
    catch( std::length_error& e )
    {
        std::cerr << "Error while trying to pop: " << e.what() << "\n";
        return 0;
    }
    catch( ... )
    {
        std::cerr << "Unknown error. " << "\n";
        return 0;
    }

    int returnValue = 0;
    returnValue = list->front();

    list->erase(list->begin());
    length--;
    return returnValue;
}

/**
*   Adds a new value to the bottom of the list.
*
*   \param value int An integer value to add to the bottom of the list.
*/
void IntegerListVector::pushEnd(int value) {
    if ( list == NULL )
    {
      try
      {
          list = new std::vector<int>(0,0);
      }
      catch( std::bad_alloc& e )
      {
          std::cerr << "Error while trying to instantiate vector: " << e.what() << "\n";
      }
      catch( ... )
      {
          std::cerr << "Unknown error. " << "\n";
      }
    }

    list->push_back(value);
    length++;
}

/**
*    Removes and returns a single value from the bottom of the list.
*   If list is empty this will return 0.
*
*    \returns int The bottom element of the list.
*/
int IntegerListVector::popEnd() {
    try
    {
        if (length == 0) { throw new std::length_error("List is emtpy."); }
    }
    catch( std::length_error& e )
    {
        std::cerr << "Error while trying to popEnd: " << e.what() << "\n";
        return 0;
    }
    catch( ... )
    {
        std::cerr << "Unknown error. " << "\n";
        return 0;
    }

    int returnValue = list->back();
    list->pop_back();
    length--;
    return returnValue;
}

/**
*    Returns the current length of the list. May be zero.
*
*    \returns int The current length of the list.
*/
int IntegerListVector::getLength() {
    if ( list && list->size() )
    {
        return list->size();
    }
    else
    {
        return 0;
    }
}

/**
*    Given an index value, returns the element at the given index value without removing it.
*
*    \param element int A valid index value.
*
*    \returns int The integer value at the given index.
*/
int IntegerListVector::getElement(int element) {
    int returnValue = 0;
    try
    {
        returnValue = list->at(element);
    }
    catch( std::out_of_range& e )
    {
        std::cerr << "Error while trying to get element: " << e.what() << "\n";
    }
    catch( ... )
    {
        std::cerr << "Unknown error. " << "\n";
    }
    return returnValue;
}

/**
    Sorts elements of the list from lowest to highest.
*/
void IntegerListVector::sort() {

    int current_length = list->size();

    for (int outer_pass = 0; outer_pass < current_length; outer_pass++) {
        for (int inner_pass = 0; inner_pass < current_length - outer_pass - 1; inner_pass++) {
            if (list->at(inner_pass) > list->at(inner_pass + 1)) {

                int _temp = list->at(inner_pass);               //store pos1 in temp
                list->at(inner_pass) = list->at(inner_pass+1);  //assign pos2 to pos1
                list->at(inner_pass+1) = _temp;                  //assign temp to pos2

            }
        }
    }
}
