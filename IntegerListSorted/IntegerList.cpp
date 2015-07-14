/* IntegerList.cpp
 * 6/29/15
 * Brook Thomas - Adolfo von Zastrow
 */

/** \file IntegerList.cpp */
#include <exception>
#include "IntegerList.h"

Node::Node (int value):
    value(value),
    next(NULL)
    {};

IntegerList::IntegerList():
        headNode(NULL),
        length(0)
        {};

IntegerList::~IntegerList()
{
    Node * currentNode = headNode;

    while (currentNode)
    {
        Node * nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
}

void IntegerList::insert(int value)
{
        // List is empty and this will be the first entry
        if (length == 0)
        {
            try
            {
                headNode = new Node(value);
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
        if (headNode->value >= value)
        {
            Node * oldHeadNode = headNode;

            try
            {
                headNode = new Node(value);
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

            headNode->next = oldHeadNode;

        }

        // Entry will be subsequent node
        Node * currentNode = headNode;

        while (currentNode->next->value < value && currentNode->next != NULL) {
            currentNode = currentNode->next;
        }

        Node * nodeToInsert;

        try
        {
            nodeToInsert = new Node(value);
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

int IntegerList::get (int index)
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
    }
    catch (...)
    {
        std::cerr << "Unknown exception why retriving index value." << "\n";
    }

    Node *currentNode = headNode;
    for ( int i = 0; (i < index) && currentNode->next != NULL; i++ )
    {
      currentNode = currentNode->next;
    }

    return currentNode->value;
}

int IntegerList::count (int value) {
    Node *currentNode = headNode;
    int counter = 0;

    while( currentNode )
    {
      if ( currentNode->value == value ) { counter++; }
      currentNode = currentNode->next;
    }

    return counter;
}


int IntegerList::findElement (int value) {

    int counter = 0;
    Node * currentNode = headNode;

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

void IntegerList::removeElement (int index) {

    // We'll want to throw an exception here if index > length - 1

    // Special case, 0th index
    if (index == 0)
    {
        Node * nextNode = headNode->next;
        delete headNode;
        headNode = nextNode;
        nextNode = NULL;
        return;
    }

    // General case, Nth index
    Node * nodeBeforeTargetNode = headNode;

    while (index - 1 > 0)
    {
        nodeBeforeTargetNode = nodeBeforeTargetNode->next;
        index--;
    }

    Node * nodeAfterTargetNode = nodeBeforeTargetNode->next->next;
    delete nodeBeforeTargetNode->next;
    nodeBeforeTargetNode->next = nodeAfterTargetNode;

    nodeBeforeTargetNode = NULL;
    nodeAfterTargetNode = NULL;

}

void IntegerList::readOut () {

    Node * currentNode = headNode;

    while (currentNode != NULL) {
        std::cout << currentNode->value << " ";
        currentNode = currentNode->next;
    }

    std::cout << std::endl;

}
