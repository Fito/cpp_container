/* IntegerListSorted.cpp
 * 6/29/15
 * Brook Thomas - Adolfo von Zastrow
 */

/** \file IntegerListSorted.cpp */

#include <exception>
#include <iostream>
#include "IntegerListSorted.h"

/** Class constructor. Takes no arguments. */
IntegerListSorted::IntegerListSorted():
        head(NULL),
        length(0)
        {};

/** Class destructor. Will deallocate from the heap any remaining nodes. */
IntegerListSorted::~IntegerListSorted()
{
    Node<int> * currentNode = head;

    while (currentNode)
    {
        Node<int> * nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
}

/**
*   Add a new integer value to the list. Items are automatically sorted into ascending order.
*
*    \param value int The integer value to be added.
*/
void IntegerListSorted::insert(int value)
{
    // List is empty and this will be the first entry
    if (length == 0)
    {
        try
        {
            head = new Node<int>();
            head->value = value;
        }
        catch (std::bad_alloc& e)
        {
            std::cerr << "Bad Allocation Exception: " << e.what() << "\n";
            return;
        }
        catch (...)
        {
            std::cerr << "Unknown exception while allocating memory." << "\n";
            return;
        }

        length++;
        return;
    }

    // Entry will be the first node
    if (head->value >= value)
    {
        Node<int> * oldHeadNode = head;

        try
        {
            head = new Node<int>();
            head->value = value;
        }
        catch (std::bad_alloc& e)
        {
            std::cerr << "Bad Allocation Exception: " << "\n";
            return;
        }
        catch (...)
        {
            std::cerr << "Unknown exception occured while allocating memory." << "\n";
            return;
        }

        head->next = oldHeadNode;

    }

    // Entry will be subsequent node
    Node<int> * currentNode = head;

    while (currentNode->next->value < value && currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }

    Node<int> * nodeToInsert;

    try
    {
        nodeToInsert = new Node<int>();
        nodeToInsert->value = value;
    }
    catch (std::bad_alloc& e)
    {
        std::cerr << "Bad Allocation Exception: " << "\n";
        return;
    }
    catch (...)
    {
        std::cerr << "An unknown error occured while allocating memory." << "\n";
        return;
    }

    nodeToInsert->next = currentNode->next;
    currentNode->next = nodeToInsert;

    nodeToInsert = NULL;
    length++;
    return;

}

/**
*   Retrieve the integer at the provided index value.
*   Returns a value of 0 if the index position is not valid.
*   We strongly advise checking length using getLength() before calling this method.
*
*   \param index int The index position to be retrieved.
*/
int IntegerListSorted::getElement (int index)
{
    try
    {
        if ( index >= length || index < 0 )
        {
            throw std::out_of_range("Invalid index value provided.");
        }
    }
    catch (std::out_of_range& e)
    {
        std::cerr << "Out of Range Exception: " << e.what() << "\n";
        return 0;
    }
    catch (...)
    {
        std::cerr << "Unknown exception why retriving index value." << "\n";
        return 0;
    }

    Node<int> *currentNode = head;
    for ( int i = 0; (i < index) && currentNode->next != NULL; i++ )
    {
      currentNode = currentNode->next;
    }

    return currentNode->value;
}

/**
*   Given an integer value, will return the number of instances of that value within the list.
*
*   \param value int The integer value to count instances of.
*
*/
int IntegerListSorted::valueCount (int value)
{
    Node<int> *currentNode = head;
    int counter = 0;

    while( currentNode )
    {
      if ( currentNode->value == value ) { counter++; }
      currentNode = currentNode->next;
    }

    return counter;
}

/**
*   Given an integer value, returns the index position of the first instance of that value.
*   If no instance is found, a value of -1 is returned.
*
*   \param value int The integer value to find.
*
*   \returns int The index position of the first instance of the element, or -1 if no instance found.
*
*/
int IntegerListSorted::valueIndex (int value)
{
    int counter = 0;
    Node<int> * currentNode = head;

    while (currentNode != NULL)
    {
        if (currentNode->value == value)
        {
            return counter;
        }

        currentNode = currentNode->next;

        counter++;
    }

    return -1;
}

/**
*   Given an index value, removes the integer at that position without returning.
*
*   \param index int The index position you want to remove.
*/
void IntegerListSorted::remove (int index)
{
    // We'll want to throw an exception here if index > length - 1

    // Special case, 0th index
    if (index == 0)
    {
        Node<int> * nextNode = head->next;
        delete head;
        head = nextNode;
        nextNode = NULL;
        return;
    }

    // General case, Nth index
    Node<int> * nodeBeforeTargetNode = head;

    while (index - 1 > 0)
    {
        nodeBeforeTargetNode = nodeBeforeTargetNode->next;
        index--;
    }

    Node<int> * nodeAfterTargetNode = nodeBeforeTargetNode->next->next;
    delete nodeBeforeTargetNode->next;
    nodeBeforeTargetNode->next = nodeAfterTargetNode;

    nodeBeforeTargetNode = NULL;
    nodeAfterTargetNode = NULL;

}
