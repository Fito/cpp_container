/* IntegerListLinked.cpp
 * 6/29/15
 * Brook Thomas - Adolfo von Zastrow
 */

/** \file IntegerListLinked.cpp */

#include <iostream>
#include "IntegerListLinked.h"


/** Constructor class. Takes no arguments. */
IntegerListLinked::IntegerListLinked():
    head(NULL),
    length(0)
    {};

/** Destructor class. Will deallocate from the heap any remaining nodes. */
IntegerListLinked::~IntegerListLinked()
{
    Node<int> * currentNode = head;

    while (currentNode != NULL)
    {
        Node<int> * next = currentNode->next;
        delete currentNode;
        currentNode = next;
    }
}

/**
*   Add a new integer value to the front of the list.
*
*    \param value int The integer value to be added.
*/
void IntegerListLinked::push (int value)
{

    Node<int> * oldhead = head;

    try
    {
        head = new Node<int>();
    }
    catch (std::bad_alloc& e)
    {
        std::cerr << "Bad Allocation Error: " << e.what() << "\n";
        return;
    }
    catch (...)
    {
        std::cerr << "Uknown error." << "\n";
        return;
    }

    head->value = value;
    head->next = oldhead;

    length++;

}

/**
*   Removes and returns an integer value from the front of the list.
*   If list is empty a value of zero is returned.
*   It is strongly advised you check list size before calling the pop() method.
*
*   \returns int The integer value at the front of the list, if available.
*/
int IntegerListLinked::pop()
{
    try
    {
        if (length == 0) { throw new std::length_error("List is empty."); }
    }
    catch( std::length_error& e )
    {
        std::cerr << "Length Error: " << e.what() << "\n";
        return 0;
    }
    catch( ... )
    {
        std::cerr << "Unknown error." << "\n";
        return 0;
    }

    int returnValue = head->value;

    Node<int> * assignTohead = head->next;

    delete head;

    head = assignTohead;

    length--;

    return returnValue;
}

/**
*   Add a new integer value to the back of the list.
*
*    \param value int The integer value to be added.
*/
void IntegerListLinked::pushEnd(int value)
{
    // Special case - list is empty
    if (length == 0) { push(value); return; }

    // Traverse to last node
    Node<int> * currentNode = head;

    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }

    try
    {
        currentNode->next = new Node<int>();
    }
    catch (std::bad_alloc& e)
    {
        std::cerr << "Bad Allocation Error: " << e.what() << "\n";
        return;
    }
    catch (...)
    {
        std::cerr << "Uknown error." << "\n";
        return;
    }

    currentNode->next->value = value;

    length++;

}

/**
*   Removes and returns an integer value from the back of the list.
*   If list is empty a value of zero is returned.
*   It is strongly advised you check list size before calling the popEnd() method.
*
*   \returns int The integer value at the back of the list, if available.
*/
int IntegerListLinked::popEnd()
{
    try
    {
        if (length == 0) { throw new std::length_error("List is empty."); }
    }
    catch( std::length_error& e )
    {
        std::cerr << "Length Error: " << e.what() << "\n";
        return 0;
    }
    catch( ... )
    {
        std::cerr << "Unknown error." << "\n";
        return 0;
    }

    Node<int> * previousNode = NULL;
    Node<int> * currentNode = head;

    while (currentNode->next != NULL) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    // Isolate current node
    previousNode->next = NULL;

    // store current node's value
    int returnValue = currentNode->value;

    delete currentNode;

    length--;

    return returnValue;

}

/**
*    Returns the current length of the list. May be zero.
*
*    \returns int The current length of the list.
*/
int IntegerListLinked::getLength()
{
    return length;
}

/**
*   Returns the integer at the given index value.
*   If the index value is invalid, zero will be returned.
*   We strongly advise checking length before calling getElement to ensure your request is valid.
*
*    \param element int An index value in the list.
*
*    \returns int The integer value at the given index.
*/
int IntegerListLinked::getElement(int element)
{
    try
    {
        if (length == 0) { throw new std::out_of_range("List is empty."); }
    }
    catch( std::out_of_range& e )
    {
        std::cerr << "Out of Range Error: " << e.what() << "\n";
        return 0;
    }
    catch( ... )
    {
        std::cerr << "Unknown error." << "\n";
        return 0;
    }

    Node<int> * currentNode = head;

    for(int i = element; i > 0; i--) {
        currentNode = currentNode->next;
    }

    return currentNode->value;

}

/** Sorts the current list in place using the bubblesort method */
void IntegerListLinked::sort () {

    Node<int> * preNode = NULL;
    Node<int> * leftNode = NULL;
    Node<int> * rightNode = NULL;

    for (int ol = 0; ol < length - 1; ol++)
    {

        if (head->value > head->next->value)
        {
            preNode = NULL;
            leftNode = head;
            rightNode = head->next;

            head = rightNode;
            leftNode->next = rightNode->next;
            rightNode->next = leftNode;

        }

        preNode = head;
        leftNode = head->next;
        rightNode = head->next->next;

        for (int il = 0; il < length - ol - 2; il++)
        {
            if (leftNode->value > rightNode->value)
            {
                preNode->next = rightNode;
                leftNode->next = rightNode->next;
                rightNode->next = leftNode;

                preNode = rightNode;
                leftNode = leftNode;
                rightNode = leftNode->next;

            } else {

                preNode = leftNode;
                leftNode = rightNode;
                rightNode = leftNode->next;

            }
        }

    }


}   // end sort
