//
// Created by Marcin on 22.03.2021.
//

#ifndef UNTITLED_LIST_H
#define UNTITLED_LIST_H


class List {
private:
    typedef struct Node {
        int data;
        Node *nextNode;
    } *node_ptr;

    node_ptr head;

    size_t sz;

    void incrementSize() {
        this->sz++;
    }

    void decrementSize() {
        this->sz--;
    }

    bool isEmpty() {
        return this->head == nullptr;
    };

    void emptyList() {
        node_ptr currentNodePtr;
        while (this->head != nullptr) {
            currentNodePtr = this->head;
            this->head = this->head->nextNode;
            delete currentNodePtr;
        }
        this->sz = 0;
    };
public:
    List();

    bool find(int data);

    void add(int data);

    bool remove(int data);

    size_t size();

    ~List();

    std::chrono::duration<double> removeGetTime(int data);
};


#endif //UNTITLED_LIST_H
