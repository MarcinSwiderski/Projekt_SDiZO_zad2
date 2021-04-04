//
// Created by Marcin on 22.03.2021.
//

#ifndef UNTITLED_STACKOPERATIONS_H
#define UNTITLED_STACKOPERATIONS_H
#include<vector>
#include "../../Structures/ResultsByRow/ResultsByRow.h"

void stackCreate(int sizeOfStrucutre, unsigned repeatsPerInstance, vector<int> &dataFromCsvVector, vector<string> &results);

void stackSearch(int sizeOfStructure, unsigned repeatsPerInstance, vector<int> &dataFromCsvVector, vector<string> &results);

void stackPush(int sizeOfStrucutre, unsigned repeatsPerInstance, vector<int> &dataFromCsvVector, vector<string> &results);

void stackPop(int sizeOfStrucutre, unsigned repeatsPerInstance, vector<int> &dataFromCsvVector, vector<string> &results);

#endif //UNTITLED_STACKOPERATIONS_H
