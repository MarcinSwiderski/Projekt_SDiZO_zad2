//
// Created by Marcin on 05.04.2021.
//
#include <chrono>
#include "../../Structures/Stack/Stack.h"
#include "StackOperations.h"

using namespace std::chrono;
high_resolution_clock::time_point stackTimeStart;
high_resolution_clock::time_point stackTimeStop;

void stackCreate(int sizeOfStrucutre, unsigned repeatsPerInstance, vector<int> &dataFromCsvVector, vector<string> &results) {
    stackTimeStart = high_resolution_clock::now();
    for (int i = 0; i < repeatsPerInstance; i++) {
        Stack testStack = Stack();
        for (int j = 0; j < sizeOfStrucutre; j++) {
            testStack.push(dataFromCsvVector[j]);
        }
    }
    stackTimeStop = high_resolution_clock::now();
    duration<double> finalDuration = duration_cast<duration<double>>(stackTimeStop - stackTimeStart);
    ResultByRow stackResult = ResultByRow("stack", "create", sizeOfStrucutre, finalDuration.count());
    results.push_back(stackResult.toString());
}

void stackSearch(int sizeOfStructure, unsigned repeatsPerInstance, vector<int> &dataFromCsvVector, vector<string> &results) {
    Stack testStack = Stack();
    for (int i = 0; i < sizeOfStructure; i++) {
        testStack.push(dataFromCsvVector[i]);
    }
    duration<double> finalDuration = duration<double>(0);
    srand(time(NULL));
    for (int j = 0; j < repeatsPerInstance; j++) {
        int randomIndex = rand() % sizeOfStructure;
        int value = dataFromCsvVector[randomIndex];
        stackTimeStart = high_resolution_clock::now();
        int temp_stack_deep = 0;
        Stack searchStack = Stack();

        for (int k = (sizeOfStructure - 1); k >= 0; k--) {
            if (testStack.peek() == value) {
                stackTimeStop = high_resolution_clock::now();
                break;
            } else {
                searchStack.push(testStack.pop());
                temp_stack_deep++;
            }
        }
        for (int k = 0; k < temp_stack_deep; k++) {
            testStack.push(searchStack.pop());
        }
        finalDuration += duration_cast<duration<double>>(stackTimeStop - stackTimeStart);
    }
    ResultByRow stackResult = ResultByRow("stack", "search", sizeOfStructure, finalDuration.count());
    results.push_back(stackResult.toString());
}

void stackPush(int sizeOfStrucutre, unsigned repeatsPerInstance, vector<int> &dataFromCsvVector, vector<string> &results) {
    duration<double> finalDuration = duration<double>(0);
    for (int i = 0; i < repeatsPerInstance; i++) {
        Stack testStack = Stack();
        for (int j = 0; j < sizeOfStrucutre; j++) {
            testStack.push(dataFromCsvVector[j]);
        }
        int randomValue = rand() % 1000000;
        stackTimeStart = high_resolution_clock::now();
        testStack.push(randomValue);
        stackTimeStop = high_resolution_clock::now();
        finalDuration += duration_cast<duration<double>>(stackTimeStop - stackTimeStart);
    }
    ResultByRow stackResult = ResultByRow("stack", "push", sizeOfStrucutre, finalDuration.count());
    results.push_back(stackResult.toString());
}

void stackPop(int sizeOfStrucutre, unsigned repeatsPerInstance, vector<int> &dataFromCsvVector, vector<string> &results) {
    duration<double> finalDuration = duration<double>(0);
    for (int i = 0; i < repeatsPerInstance; i++) {
        Stack testStack = Stack();
        for (int j = 0; j < sizeOfStrucutre; j++) {
            testStack.push(dataFromCsvVector[j]);
        }
        stackTimeStart = high_resolution_clock::now();
        testStack.pop();
        stackTimeStop = high_resolution_clock::now();
        finalDuration += duration_cast<duration<double>>(stackTimeStop - stackTimeStart);
    }
    ResultByRow stackResult = ResultByRow("stack", "pop", sizeOfStrucutre, finalDuration.count());
    results.push_back(stackResult.toString());
}
