/* IntegerList.cpp
 * 6/29/15
 * Brook Thomas - Adolfo von Zastrow
 */

/** \file IntegerList.cpp */

#include "IntegerList.h"

Node::Node (int value):
    value(value),
    next(NULL)
    {};

IntegerList::IntegerList():
        headNode(NULL),
        length(0)
        {};

void IntegerList::insert(int value) {

        // List is empty and this will be the first entry
        if (length == 0) {

            headNode = new Node(value);
            length++;
            return;
        }

        // Entry will be the first node
        if (headNode->value >= value) {

            Node * oldHeadNode = headNode;
            headNode = new Node(value);
            headNode->next = oldHeadNode;

            oldHeadNode = NULL;
            length++;
            return;
        }

        // Entry will be subsequent node
        Node * currentNode = headNode;

        while (currentNode->next->value < value && currentNode->next != NULL) {
            currentNode = currentNode->next;
        }

        Node * nodeToInsert = new Node(value);
        nodeToInsert->next = currentNode->next;
        currentNode->next = nodeToInsert;

        nodeToInsert = NULL;
        length++;
        return;

}

int IntegerList::get (int index)
{
    if ( index >= length || index < 0 )
    {
      std::cout << "Index out of bounds for list." << std::endl;
      return 0;
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
