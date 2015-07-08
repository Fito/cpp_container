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

            Node * nodeToInsert = new Node(value);
            nodeToInsert->next = currentNode->next;
            currentNode->next = nodeToInsert;

            nodeToInsert = NULL;
            length++;
            return;

        }

}

int IntegerList::get (int index) {
    return 0;
}

int IntegerList::count (int value) {
    return 0;
}


int IntegerList::findElement (int value) {
    return 0;
}

void IntegerList::removeElement (int index) {

}

void IntegerList::readOut () {

    Node * currentNode = headNode;

    while (currentNode != NULL) {
        std::cout << currentNode->value << " ";
        currentNode = currentNode->next;
    }

    std::cout << std::endl;

}
