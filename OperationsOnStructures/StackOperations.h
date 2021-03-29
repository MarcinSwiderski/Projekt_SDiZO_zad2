//
// Created by Marcin on 22.03.2021.
//

#ifndef UNTITLED_STACKOPERATIONS_H
#define UNTITLED_STACKOPERATIONS_H
#include "Structures/Stack/Stack.h"
using namespace std::chrono;

void stackCreate(int sizeOfStrucutre, unsigned repeatsPerInstance, vector<int> &dataFromCsvVector, vector<string> &results) {
    high_resolution_clock::time_point t_start = high_resolution_clock::now();
    for (int i = 0; i < repeatsPerInstance; i++) {
        Stack testStack = Stack();
        for (int j = 0; j < sizeOfStrucutre; j++) {
            testStack.push(dataFromCsvVector[j]);
        }
    }
    high_resolution_clock::time_point t_end = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t_end - t_start);
    ResultByRow stackResult = ResultByRow("stack", "create", sizeOfStrucutre, time_span.count());
    results.push_back(stackResult.toString());
}

void stackSearch(int size_of_stack, unsigned number_of_repeats, vector<int> &data_vector, vector<string> &results_parser) {
    Stack test_stack = Stack();
    for (int i = 0; i < size_of_stack; i++) {
        test_stack.push(data_vector[i]);
    }
    high_resolution_clock::time_point t_start = high_resolution_clock::now();
    high_resolution_clock::time_point t_end = high_resolution_clock::now();
    duration<double> time_span = duration<double>(0);
    srand(time(NULL));
    for (int repeat = 0; repeat < number_of_repeats; repeat++) {
        int random_index = rand() % size_of_stack;
        int searched_value = data_vector[random_index];
        bool found = false;
        t_start = high_resolution_clock::now();
        int temp_stack_deep = 0;
        Stack temp_search_stack = Stack();
        for (int i = (size_of_stack - 1); i >= 0; i--) {
            if (test_stack.peek() == searched_value) {
                t_end = high_resolution_clock::now();
                found = true;
                break;
            } else {
                temp_search_stack.push(test_stack.pop());
                temp_stack_deep++;
            }
        }
        for (int i = 0; i < temp_stack_deep; i++) {
            test_stack.push(temp_search_stack.pop());
        }
        if (!found) {
            t_end = high_resolution_clock::now();
        }
        time_span += duration_cast<duration<double>>(t_end - t_start);
    }
    ResultByRow stackResult = ResultByRow("stack", "search", size_of_stack, time_span.count());
    results_parser.push_back(stackResult.toString());
}

void stackPush(int sizeOfStrucutre, unsigned numberOfRepeats, vector<int> &dataFromCsvVector, vector<string> &results_parser) {
    high_resolution_clock::time_point t_start = high_resolution_clock::now();
    high_resolution_clock::time_point t_end = high_resolution_clock::now();
    duration<double> time_span = duration<double>(0);
    for (int repeat = 0; repeat < numberOfRepeats; repeat++) {
        Stack testStack = Stack();
        for (int i = 0; i < sizeOfStrucutre; i++) {
            testStack.push(dataFromCsvVector[i]);
        }
        int randomValue = rand() % 1000000;
        t_start = high_resolution_clock::now();
        testStack.push(randomValue);
        t_end = high_resolution_clock::now();
        time_span += duration_cast<duration<double>>(t_end - t_start);
    }
    ResultByRow stackResult = ResultByRow("stack", "push", sizeOfStrucutre, time_span.count());
    results_parser.push_back(stackResult.toString());
}

void stackPop(int sizeOfStrucutre, unsigned numberOfRepeats, vector<int> &dataFromCsvVector, vector<string> &results_parser) {
    high_resolution_clock::time_point t_start = high_resolution_clock::now();
    high_resolution_clock::time_point t_end = high_resolution_clock::now();
    duration<double> time_span = duration<double>(0);
    for (int repeat = 0; repeat < numberOfRepeats; repeat++) {
        Stack test_stack = Stack();
        for (int i = 0; i < sizeOfStrucutre; i++) {
            test_stack.push(dataFromCsvVector[i]);
        }
        t_start = high_resolution_clock::now();
        test_stack.pop();
        t_end = high_resolution_clock::now();
        time_span += duration_cast<duration<double>>(t_end - t_start);
    }
    ResultByRow stackResult = ResultByRow("stack", "pop", sizeOfStrucutre, time_span.count());
    results_parser.push_back(stackResult.toString());
}
#endif //UNTITLED_STACKOPERATIONS_H
