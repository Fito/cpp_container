/* List<T>.cpp
 * 6/29/15
 * Brook Thomas - Adolfo von Zastrow
 */

/** \file List<T>.cpp */

#include <iostream>

void checkListBounds(int index, int length)
{
    if ( index < 0 || index > length )
    {
      throw std::out_of_range("Element is out of bounds");
    }
}

template <typename T>
void checkListLength(Node<T>* head, int length)
{
    if (head == NULL || length == 0)
    {
      throw std::length_error("List is empty");
    }
}

/** Default constructor class. Takes no arguments. */
template <typename T>
List<T>::List():
    head(NULL),
    length(0)
    {};

/**
*   Add a new integer value to the front of the list.
*
*    \param value int The integer value to be added.
*/
template <typename T>
void List<T>::push(T value)
{

    Node<T> * assignToNextNode = head;

    try
    {
        head = new Node<T>();
    }
    catch (std::bad_alloc& e)
    {
        std::cerr << "Error initializing Node: " << e.what() << "\n";
    }
    catch (...)
    {
        std::cerr << "Uknown error." << "\n";
    }

    head->value = value;
    head->next = assignToNextNode;

    length++;

}

/**
*   Removes and returns an integer value from the front of the list.
*   If list is empty a value of zero is returned.
*   It is strongly advised you check list size before calling the pop() method.
*
*   \returns int The integer value at the front of the list, if available.
*/
template <typename T>
T List<T>::pop()
{
    try
    {
        checkListLength(head, length);
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

    int returnValue = head->value;
    Node<T> * assignToHeadNode = head->next;

    delete head;

    head = assignToHeadNode;

    length--;

    return returnValue;
}

/**
*   Add a new integer value to the back of the list.
*
*    \param value int The integer value to be added.
*/
template <typename T>
void List<T>::pushEnd(T value)
{
    Node<T> * currentNode = head;

    // Traverse the list to get to the end node
    while ( currentNode->next ) {
        currentNode = currentNode->next;
    }

    try
    {
        currentNode->next = new Node<T>();
    }
    catch (std::bad_alloc& e)
    {
        std::cerr << "Error initializing Node: " << e.what() << "\n";
        return;
    }
    catch (...)
    {
        std::cerr << "Uknown error." << "\n";
        return;
    }

    currentNode = currentNode->next;
    currentNode->value = value;
    currentNode->next = NULL;

    length++;

}

/**
*   Removes and returns an integer value from the back of the list.
*   If list is empty a value of zero is returned.
*   It is strongly advised you check list size before calling the pop() method.
*
*   \returns int The integer value at the back of the list, if available.
*/
template <typename T>
T List<T>::popEnd()
{
    try
    {
        checkListLength(head, length);
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

    Node<T> * previousNode = NULL;
    Node<T> * currentNode = head;

    while (currentNode->next != NULL) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    int returnValue = currentNode->value;

    delete currentNode;

    previousNode-next = NULL;

    length--;

    return returnValue;

}

/**
*    Returns the current length of the list. May be zero.
*
*    \returns int The current length of the list.
*/
template <typename T>
int List<T>::getLength()
{
    return length;
}

/**
*   Returns the integer at the given index value, if valid.
*   If the index value is invalid, zero will be returned.
*   We strongly advise checking length before calling getElement to ensure your request is valid.
*
*    \param element int An index value in the list.
*
*    \returns int The integer value at the given index.
*/
template <typename T>
T List<T>::getElement(int element)
{
    try
    {
        checkListBounds(element, length);
    }
    catch( std::out_of_range& e )
    {
        std::cerr << "Error while trying to get element: " << e.what() << "\n";
        return 0;
    }
    catch( ... )
    {
        std::cerr << "Unknown error." << "\n";
        return 0;
    }

    Node<T> * currentNode = head;

    for(int i = element; i > 0; i--) {
        currentNode = currentNode->next;
    }

    return currentNode->value;

}