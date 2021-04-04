//
// Created by Marcin on 22.03.2021.
//

#include <chrono>
#include "List.h"
#include "stdio.h"
using namespace std::chrono;
high_resolution_clock::time_point listTimeStartList;
high_resolution_clock::time_point listTimeStopList;

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
bool List::remove(int data) {
    node_ptr prevNodePtr = nullptr;
    node_ptr currentNodePtr = head;
    duration<double> timeSpentOnInstance = duration<double>(0);
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
duration<double>List::removeGetTime(int data) {
    node_ptr prevNodePtr = nullptr;
    node_ptr currentNodePtr = head;
    duration<double> timeSpentOnInstance = duration<double>(0);
    if (isEmpty())
    {
        return timeSpentOnInstance;
    }
    while (currentNodePtr != nullptr)
    {
        if (data == currentNodePtr->data)
        {
            node_ptr nodeAfterCurrentPtr = currentNodePtr->nextNode;
            listTimeStartList = high_resolution_clock::now();
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
            listTimeStopList = high_resolution_clock::now();
            timeSpentOnInstance += duration_cast<duration<double>>(listTimeStopList - listTimeStartList);
            return timeSpentOnInstance;
        }
        prevNodePtr = currentNodePtr;
        currentNodePtr = currentNodePtr->nextNode;
    }
    return timeSpentOnInstance;
}
size_t List::size() {
    return this->sz;
}
List::~List(){
    this->emptyList();
}
