/* IntegerList.cpp
 * 6/29/15
 * Brook Thomas - Adolfo von Zastrow
 */

/** \file IntegerList.cpp */

#include <iostream>
#include "IntegerList.h"

/** Default constructor class. Takes no arguments. */
IntegerList::IntegerList():
    headNode(NULL),
    endNode(NULL),
    length(0)
    {};

/** Default class destructor. Takes no arguments. */
IntegerList::~IntegerList() {
    Node * currentNode = headNode;

    while ( currentNode ) {
        Node * nextNode = currentNode->nextNode;
        delete currentNode;
        currentNode = nextNode;
    }
}

/**
*   Adds a new value to the top of the list.
*
*    \param value int An integer value to add to the top of the list.
*/
void IntegerList::push(int value) {

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

    if (length == 0) {
        endNode = headNode;
    }

    length++;

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
*   Adds a new value to the bottom of the list.
*
*   \param value int An integer value to add to the bottom of the list.
*/
void IntegerList::pushEnd(int value) {
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

void IntegerList::readOut() {

    Node * currentNode = headNode;

    for (int i = 0; i < length; i++) {
        std::cout << currentNode->value << " ";
        currentNode = currentNode->nextNode;
    }

}

void IntegerList::sort () {

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

            } else {

                preNode = leftNode;
                leftNode = rightNode;
                rightNode = leftNode->nextNode;

            }
        }

    }


}   // end sort

void IntegerList::checkListBounds(int index)
{
    if ( index < 0 || index > length )
    {
      throw std::out_of_range("Element is out of bounds");
    }
}

void IntegerList::checkListLength()
{
    if (headNode == NULL || length == 0)
    {
      throw std::length_error("List is empty");
    }
}
