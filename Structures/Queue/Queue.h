//
// Created by Marcin on 22.03.2021.
//

#ifndef UNTITLED_QUEUE_H
#define UNTITLED_QUEUE_H


class Queue {
public:
    Queue();
    int front, rear, size;
    unsigned int capacity;
    int *array;
    ~Queue();
};


#endif //UNTITLED_QUEUE_H
