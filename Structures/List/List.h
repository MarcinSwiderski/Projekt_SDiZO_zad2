//
// Created by Marcin on 22.03.2021.
//

#ifndef UNTITLED_LIST_H
#define UNTITLED_LIST_H



class List
{
private:
    typedef struct Node
    {
        int data;
        Node *nextNode;
    } * node_ptr;

    node_ptr head;

    size_t sz;

    void incrementSize(){
        this->sz++;
    }
    void decrementSize(){
        this->sz--;
    }

public:
    List();
    bool find(int data);
    void add(int data);
    bool remove(int data);
    bool isEmpty();

    void emptyList();

    size_t size();

    ~List();
};


#endif //UNTITLED_LIST_H
