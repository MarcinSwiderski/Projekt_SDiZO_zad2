//
// Created by Marcin on 22.03.2021.
//

#ifndef UNTITLED_QUEUEOPERATIONS_H
#define UNTITLED_QUEUEOPERATIONS_H
#include<vector>
#include "../../Structures/ResultsByRow/ResultsByRow.h"

void queueCreate(int sizeOfStrucutre, unsigned repeatsPerInstance, vector<int> &dataFromCsvVector, vector<string> &results);

void queueSearch(int sizeOfStrucutre, unsigned repeatsPerInstance, vector<int> &dataFromCsvVector, vector<string> &results);

void queueMovForward(int sizeOfStrucutre, unsigned repeatsPerInstance, vector<int> &dataFromCsvVector, vector<string> &results);

void queueMovBackwords(int sizeOfStrucutre, unsigned numberOfRepeats, vector<int> &dataFromCsvVector, vector<string> &results);

#endif //UNTITLED_QUEUEOPERATIONS_H
