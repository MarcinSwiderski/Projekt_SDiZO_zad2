//
// Created by Marcin on 22.03.2021.
//

#include "List.h"

List::List(){
    this->head = nullptr;
    this->sz = 0;
}
void List::add(int data) {
    node_ptr newNodePtr = new Node;
    newNodePtr->data = data;
    newNodePtr->nextNode = nullptr;
    if (isEmpty())
    {
        this->head = newNodePtr;
    }
    else
    {
        node_ptr prevHeadPtr = this->head;
        this->head = newNodePtr;
        newNodePtr->nextNode = prevHeadPtr;
    }
    incrementSize();

}
bool List::find(int data) {
    node_ptr currentNodePtr = this->head;
    while (currentNodePtr != nullptr)
    {
        if((currentNodePtr->data) == data){
            return true;
        }
        currentNodePtr = currentNodePtr->nextNode;
    }
    return false;
}
bool List::isEmpty() {
    return this->head == nullptr;
}
bool List::remove(int data) {
    node_ptr prevNodePtr = nullptr;
    node_ptr currentNodePtr = head;

    if (isEmpty())
    {
        return false;
    }
    while (currentNodePtr != nullptr)
    {
        if (data == currentNodePtr->data)
        {
            node_ptr nodeAfterCurrentPtr = currentNodePtr->nextNode;
            if (prevNodePtr == nullptr)
            {
                this->head = nodeAfterCurrentPtr;
            }
            else
            {
                prevNodePtr->nextNode = nodeAfterCurrentPtr;
            }
            delete currentNodePtr;
            decrementSize();
            return true;
        }
        prevNodePtr = currentNodePtr;
        currentNodePtr = currentNodePtr->nextNode;
    }
    return false;
}
void List::emptyList() {
    node_ptr currentNodePtr;
    while (this->head != nullptr)
    {
        currentNodePtr = this->head;
        this->head = this->head->nextNode;
        delete currentNodePtr;
    }
    this->sz = 0;
}
size_t List::size() {
    return this->sz;
}
List::~List(){
    this->emptyList();
}
