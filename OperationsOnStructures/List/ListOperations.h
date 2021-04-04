//
// Created by Marcin on 22.03.2021.
//

#ifndef UNTITLED_LISTOPERATIONS_H
#define UNTITLED_LISTOPERATIONS_H
#include<vector>
#include "../../Structures/ResultsByRow/ResultsByRow.h"

void listCreate(int sizeOfStructure, unsigned numberOfRepeats, vector<int> &dataFromCsvVector, vector<string> &results);

void listSearch(int sizeOfStrucutre, unsigned numberOfRepeats, vector<int> &dataFromCsvVector, vector<string> &results);

void listAdd(int sizeOfStructure, unsigned numberOfRepeats, vector<int> &dataFromCsvVector, vector<string> &results);

void listDelete(int sizeOfStrucutre, unsigned numberOfRepeats, vector<int> &dataFromCsvVector, vector<string> &results);


#endif //UNTITLED_LISTOPERATIONS_H
