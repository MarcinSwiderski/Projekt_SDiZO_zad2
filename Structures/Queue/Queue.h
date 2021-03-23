//
// Created by Marcin on 22.03.2021.
//

#ifndef UNTITLED_QUEUE_H
#define UNTITLED_QUEUE_H


class Queue {
public:
    int front, rear, size;
    unsigned int capacity;
    int *array;

    Queue();
    ~Queue();
};


#endif //UNTITLED_QUEUE_H
