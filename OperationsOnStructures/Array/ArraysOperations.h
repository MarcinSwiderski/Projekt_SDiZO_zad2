//
// Created by Marcin on 22.03.2021.
//

#ifndef UNTITLED_ARRAYSOPERATIONS_H
#define UNTITLED_ARRAYSOPERATIONS_H
#include<vector>
#include <chrono>
using namespace std::chrono;
using namespace std;


void arrayCreate(int sizeOfStructure, int repeatsPerInstance, vector<int> &dataFromCsvVector, vector<string> &results);

void arrayPut(int sizeOfStructure, int repeatsPerInstance, vector<int> &dataFromCsvVector, vector<string> &results);

void arraySearch(int sizeOfStructure, int repeatsPerInstance, vector<int> &dataFromCsvVector, vector<string> &results);

void arrayDelete(int sizeOfStructure, int repeatsPerInstance, vector<int> &dataFromCsvVector, vector<string> &results);

void arrayAdd(int sizeOfStructure, int repeatsPerInstance, vector<int> &dataFromCsvVector, vector<string> &results);

#endif //UNTITLED_ARRAYSOPERATIONS_H
