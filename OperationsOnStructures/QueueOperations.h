//
// Created by Marcin on 22.03.2021.
//

#ifndef UNTITLED_QUEUEOPERATIONS_H
#define UNTITLED_QUEUEOPERATIONS_H
#include "Structures/Queue/Queue.h"
using namespace std::chrono;

Queue *createQueue(unsigned int capacity) {
    Queue *queue = new Queue();
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = new int[queue->capacity];
    return queue;
}

void deleteQueue(Queue *queue) {
    delete queue;
}

int isFull(Queue *queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(Queue *queue) {
    return (queue->size == 0);
}

void queueForward(Queue *queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)
                  % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int queueBackwords(Queue *queue) {
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)
                   % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int front(Queue *queue) {
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

int rear(Queue *queue) {
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}

void queueCreate(int sizeOfStrucutre, unsigned numberOfRepeats, vector<int> &dataFromCsvVector, vector<string> &results_parser) {
    high_resolution_clock::time_point t_start = high_resolution_clock::now();
    for (int i = 0; i < numberOfRepeats; i++) {
        Queue *test_queue = createQueue(sizeOfStrucutre);
        for (int j = 0; j < sizeOfStrucutre; j++) {
            queueForward(test_queue, dataFromCsvVector[j]);
        }
    }
    high_resolution_clock::time_point t_end = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t_end - t_start);
    ResultByRow queue_create_result = ResultByRow("queue", "create", sizeOfStrucutre, time_span.count());
    results_parser.push_back(queue_create_result.toString());
}

void queueSearch(int size_of_queue, unsigned number_of_repeats, vector<int> &dataFromCsvVector, vector<string> &results_parser) {
    high_resolution_clock::time_point t_start = high_resolution_clock::now();
    high_resolution_clock::time_point t_end = high_resolution_clock::now();
    srand(time(NULL));
    duration<double> time_span = duration<double>(0);
    for (int repeat = 0; repeat < number_of_repeats; repeat++) {
        Queue *test_queue = createQueue(size_of_queue);
        for (int i = 0; i < size_of_queue; i++) {
            queueForward(test_queue, dataFromCsvVector[i]);
        }
        int random_index = rand() % size_of_queue;
        int searched_value = dataFromCsvVector[random_index];
        t_start = high_resolution_clock::now();
        Queue *temp_search_queue = createQueue(size_of_queue);
        int temp_queue_len = 0;
        bool found = false;
        for (int i = 0; i < size_of_queue; i++) {
            if (front(test_queue) == searched_value) {
                found = true;
                break;
            } else {
                queueForward(temp_search_queue, queueBackwords(test_queue));
            }
            temp_queue_len++;
        }
        for (int i = 0; i < temp_queue_len; i++) {
            queueForward(test_queue, queueBackwords(temp_search_queue));
        }
        if (!found) {
            cout << " queue search error " << endl;
        }
        t_end = high_resolution_clock::now();
        time_span += duration_cast<duration<double>>(t_end - t_start);
    }
    ResultByRow queue_search_result = ResultByRow("queue", "search", size_of_queue, time_span.count());
    results_parser.push_back(queue_search_result.toString());
}

void queueMovForward(int sizeOfStrucutre, unsigned numberOfRepeats, vector<int> &dataFromCsvVector, vector<string> &results_parser) {
    high_resolution_clock::time_point t_start = high_resolution_clock::now();
    high_resolution_clock::time_point t_end = high_resolution_clock::now();
    srand(time(NULL));
    duration<double> time_span = duration<double>(0);
    for (int i = 0; i < numberOfRepeats; i++) {
        Queue *test_queue = createQueue(sizeOfStrucutre);
        for (int j = 0; j < sizeOfStrucutre; j++) {
            queueForward(test_queue, dataFromCsvVector[j]);
        }
        int random_value = rand() % 1000000;
        t_start = high_resolution_clock::now();
        queueForward(test_queue, random_value);
        t_end = high_resolution_clock::now();
        time_span += duration_cast<duration<double>>(t_end - t_start);
    }
    ResultByRow queue_enqueue_result = ResultByRow("queue", "queueForward", sizeOfStrucutre, time_span.count());
    results_parser.push_back(queue_enqueue_result.toString());
}

void queueMovBackwords(int size_of_queue, unsigned number_of_repeats, vector<int> &data_vector, vector<string> &results_parser) {
    high_resolution_clock::time_point t_start = high_resolution_clock::now();
    high_resolution_clock::time_point t_end = high_resolution_clock::now();
    duration<double> time_span = duration<double>(0);
    for (int i = 0; i < number_of_repeats; i++) {
        Queue *test_queue = createQueue(size_of_queue);
        for (int j = 0; j < size_of_queue; j++) {
            queueForward(test_queue, data_vector[j]);
        }
        t_start = high_resolution_clock::now();
        queueBackwords(test_queue);
        t_end = high_resolution_clock::now();
        time_span += duration_cast<duration<double>>(t_end - t_start);
    }
    ResultByRow queue_dequeue_result = ResultByRow("queue", "queueBackwords", size_of_queue, time_span.count());
    results_parser.push_back(queue_dequeue_result.toString());
}

#endif //UNTITLED_QUEUEOPERATIONS_H
