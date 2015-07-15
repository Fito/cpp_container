/* IntegerLinkedList.cpp
 * 6/29/15
 * Brook Thomas - Adolfo von Zastrow
 */

/** \file IntegerLinkedList.cpp */

#include <iostream>
#include "IntegerLinkedList.h"

/** Default constructor class. Takes no arguments. */
IntegerLinkedList::IntegerLinkedList():
    headNode(NULL),
    endNode(NULL),
    length(0)
    {};

/** Default class destructor. Takes no arguments. */
IntegerLinkedList::~IntegerLinkedList()
{
    Node * currentNode = headNode;

    while ( currentNode ) {
        Node * nextNode = currentNode->nextNode;
        delete currentNode;
        currentNode = nextNode;
    }
}

/**
*   Add a new integer value to the front of the list.
*
*    \param value int The integer value to be added.
*/
void IntegerLinkedList::push(int value)
{

    Node * assignToNextNode = headNode;

    try
    {
        headNode = new Node();
    }
    catch (std::bad_alloc& e)
    {
        std::cerr << "Error initializing Node: " << e.what() << "\n";
    }
    catch (...)
    {
        std::cerr << "Uknown error." << "\n";
    }

    headNode->value = value;
    headNode->nextNode = assignToNextNode;

    if (length == 0)
    {
        endNode = headNode;
    }

    length++;

}

/**
*   Removes and returns an integer value from the front of the list.
*   If list is empty a value of zero is returned.
*   It is strongly advised you check list size before calling the pop() method.
*
*   \returns int The integer value at the front of the list, if available.
*/
int IntegerLinkedList::pop()
{
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

    int returnValue = headNode->value;
    Node * assignToHeadNode = headNode->nextNode;

    delete headNode;

    headNode = assignToHeadNode;

    length--;

    if (length == 0) {
        endNode = NULL;
    }

    return returnValue;
}

/**
*   Add a new integer value to the back of the list.
*
*    \param value int The integer value to be added.
*/
void IntegerLinkedList::pushEnd(int value)
{
    try
    {
        endNode->nextNode = new Node();
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

    endNode = endNode->nextNode;
    endNode->value = value;
    endNode->nextNode = NULL;

    length++;

}

/**
*   Removes and returns an integer value from the back of the list.
*   If list is empty a value of zero is returned.
*   It is strongly advised you check list size before calling the pop() method.
*
*   \returns int The integer value at the back of the list, if available.
*/
int IntegerLinkedList::popEnd()
{
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

    Node * previousNode = NULL;
    Node * currentNode = headNode;

    while (currentNode->nextNode != NULL) {
        previousNode = currentNode;
        currentNode = currentNode->nextNode;
    }

    int returnValue = currentNode->value;

    delete currentNode;

    endNode = previousNode;

    endNode->nextNode = NULL;

    length--;

    return returnValue;

}

/**
*    Returns the current length of the list. May be zero.
*
*    \returns int The current length of the list.
*/
int IntegerLinkedList::getLength()
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
int IntegerLinkedList::getElement(int element)
{
    try
    {
        checkListBounds(element);
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

    Node * currentNode = headNode;

    for(int i = element; i > 0; i--) {
        currentNode = currentNode->nextNode;
    }

    return currentNode->value;

}

/**
    Sorts the current list in ascending order using the bubblesort method.
*/
void IntegerLinkedList::sort ()
{

    Node * preNode = NULL;
    Node * leftNode = NULL;
    Node * rightNode = NULL;

    for (int ol = 0; ol < length - 1; ol++)
    {

        if (headNode->value > headNode->nextNode->value)
        {
            preNode = NULL;
            leftNode = headNode;
            rightNode = headNode->nextNode;

            headNode = rightNode;
            leftNode->nextNode = rightNode->nextNode;
            rightNode->nextNode = leftNode;

        }

        preNode = headNode;
        leftNode = headNode->nextNode;
        rightNode = headNode->nextNode->nextNode;

        for (int il = 0; il < length - ol - 2; il++)
        {
            if (leftNode->value > rightNode->value)
            {
                preNode->nextNode = rightNode;
                leftNode->nextNode = rightNode->nextNode;
                rightNode->nextNode = leftNode;

                preNode = rightNode;
                leftNode = leftNode;
                rightNode = leftNode->nextNode;
            }
            else
            {

                preNode = leftNode;
                leftNode = rightNode;
                rightNode = leftNode->nextNode;

            }
        }
    }
}   // end sort

void IntegerLinkedList::checkListBounds(int index)
{
    if ( index < 0 || index > length )
    {
      throw std::out_of_range("Element is out of bounds");
    }
}

void IntegerLinkedList::checkListLength()
{
    if (headNode == NULL || length == 0)
    {
      throw std::length_error("List is empty");
    }
}
