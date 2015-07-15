/* ListVector.cpp
 * 6/29/15
 * Brook Thomas - Adolfo von Zastrow
 */

/** \file ListVector.cpp */
#include <exception>

/** Default class constructor. Takes no arguments. */
template <typename T>
ListVector<T>::ListVector():
    list(NULL)
    {};

/** Default class destructor. Takes no arguments. */
template <typename T>
ListVector<T>::~ListVector() {
    delete list;
}

/**
*   Adds a new value to the top of the list.
*
*    \param value int An integer value to add to the top of the list.
*/
template <typename T>
void ListVector<T>::push(T value) {
    if ( list == NULL )
    {
      try
      {
        list = new std::vector<T>(0,0);
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
template <typename T>
T ListVector<T>::pop() {
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

    T returnValue = 0;
    returnValue = list->front();

    list->erase(list->begin());
    return returnValue;
}

/**
*   Adds a new value to the bottom of the list.
*
*   \param value int An integer value to add to the bottom of the list.
*/
template <typename T>
void ListVector<T>::pushEnd(T value) {
    if ( list == NULL )
    {
      try
      {
          list = new std::vector<T>(0,0);
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
template <typename T>
T ListVector<T>::popEnd() {
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

    T returnValue = list->back();
    list->pop_back();
    return returnValue;
}

/**
*    Returns the current length of the list. May be zero.
*
*    \returns int The current length of the list.
*/
template <typename T>
int ListVector<T>::getLength() {
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
template <typename T>
T ListVector<T>::getElement(int element) {
    T returnValue;
    try
    {
        returnValue = list->at(element);
    }
    catch( std::out_of_range& e )
    {
        std::cerr << "Error while trying to get element: " << e.what() << "\n";
        return returnValue;
    }
    catch( ... )
    {
        std::cerr << "Unknown error." << "\n";
        return returnValue;
    }
    return returnValue;
}

template <typename T>
void ListVector<T>::checkListLength() {
    if (list == NULL || list->size() == 0)
    {
      throw std::length_error("List is empty");
    }
}
