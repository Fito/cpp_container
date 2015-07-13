/* IntegerList.cpp
 * 6/29/15
 * Brook Thomas - Adolfo von Zastrow
 */

/** \file IntegerList.cpp */

#include "IntegerList.h"
#include <exception>

/** Default class constructor. Takes no arguments. */
IntegerList::IntegerList():
    list(NULL)
    {};

/** Default class destructor. Takes no arguments. */
IntegerList::~IntegerList() {
    delete list;
}

/**
*   Adds a new value to the top of the list.
*
*    \param value int An integer value to add to the top of the list.
*/
void IntegerList::push(int value) {
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
        std::cerr << "Unknown error." << "\n";
      }
    }

    list->insert(list->begin(), value);
}

/**
*   Removes and returns a single value from the top of the list.
*
*   \returns int The top element of the list.
*/
int IntegerList::pop() {
    try
    {
        checkListLength();
    }
    catch( std::length_error& e )
    {
        std::cerr << "Error while trying to pop: " << e.what() << "\n";
        return 0;
    }
    catch( ... )
    {
        std::cerr << "Unknown error." << "\n";
        return 0;
    }

    int returnValue = 0;
    returnValue = list->front();

    list->erase(list->begin());
    return returnValue;
}

/**
*   Adds a new value to the bottom of the list.
*
*   \param value int An integer value to add to the bottom of the list.
*/
void IntegerList::pushEnd(int value) {
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
          std::cerr << "Unknown error." << "\n";
      }
    }

    list->push_back(value);
}

/**
*    Removes and returns a single value from the bottom of the list.
*
*    \returns int The bottom element of the list.
*/
int IntegerList::popEnd() {
    try
    {
        checkListLength();
    }
    catch( std::length_error& e )
    {
        std::cerr << "Error while trying to popEnd: " << e.what() << "\n";
        return 0;
    }
    catch( ... )
    {
        std::cerr << "Unknown error." << "\n";
        return 0;
    }

    int returnValue = list->back();
    list->pop_back();
    return returnValue;
}

/**
*    Returns the current length of the list. May be zero.
*
*    \returns int The current length of the list.
*/
int IntegerList::getLength() {
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
int IntegerList::getElement(int element) {
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
        std::cerr << "Unknown error." << "\n";
    }
    return returnValue;
}


/**
    Sorts elements of the list from lowest to highest.
*/
void IntegerList::sort() {

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

void IntegerList::checkListLength() {
    if (list == NULL || list->size() == 0)
    {
      throw std::length_error("List is empty");
    }
}
