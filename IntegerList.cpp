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

/**
*   Adds a new value to the top of the list.
*
*    \param value int An integer value to add to the top of the list.
*/
void IntegerList::push(int value) {

    Node * assignToNextNode = headNode;

    headNode = new Node();

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

    endNode->nextNode = new Node();
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

    Node * currentNode = headNode;

    for(int i = element; i > 0; i--) {
        currentNode = currentNode->nextNode;
    }

    return currentNode->value;

}

void IntegerList::readOut() {

    Node * currentNode = headNode;

    while (currentNode != endNode) {
        std::cout << currentNode->value << " ";
        currentNode = currentNode->nextNode;
    }

    std::cout << currentNode->value << " ";

}

void IntegerList::sort () {

        Node * pointsToLeftNode = NULL;
        Node * leftNode = NULL;
        Node * rightNode = NULL;
        Node * rightNodePointsTo = NULL;

        for (int outer_loop = 0; outer_loop < length - 1; outer_loop++) {

            // Because headNode pointer is special, we treat it as a special case
            if (headNode->value > headNode->nextNode->value) {

                leftNode = headNode;
                rightNode = headNode->nextNode;
                rightNodePointsTo = rightNode->nextNode;

                headNode = rightNode;
                rightNode = leftNode;
                leftNode = rightNodePointsTo;

            }

            for (int inner_loop = 1; inner_loop < (length - outer_loop - 1); inner_loop++) {

                pointsToLeftNode = leftNode;
                leftNode = rightNode;
                rightNode = rightNode->nextNode;
                rightNodePointsTo = rightNode->nextNode;
                //
                // if (leftNode->value > rightNode->value) {
                //
                //     pointsToLeftNode = rightNode;
                //     rightNode = leftNode;
                //     leftNode = rightNodePointsTo;
                //
                // }
            }

        }

}
