//
// Created by Marcin on 22.03.2021.
//

#ifndef UNTITLED_SORTOPERATIONS_H
#define UNTITLED_SORTOPERATIONS_H
#include<vector>
#include "../../Structures/ResultsByRow/ResultsByRow.h"

void bubbleSortTimeMessure(int sizeOfStructure, vector<int> &dataFromCsvVector, vector<string> &results);

void bubbleSortTimeMessureMemory(int sizeOfStructure, vector<int> &dataFromCsvVector, vector<string> &results);

void coctailSort(int sizeOfStructure, vector<int> &dataFromCsvVector, vector<string> &results);

void quickSortTimeMesureing(int sizeOfStructure, vector<int> &dataFromCsvVector, vector<string> &results);

void quickSortTimeMemoryMesureing(int sizeOfStructure, vector<int> &dataFromCsvVector, vector<string> &results);

void insertSort(int sizeOfStrucutre, vector<int> &dataFromCsvVector, vector<string> &results);




#endif //UNTITLED_SORTOPERATIONS_H
