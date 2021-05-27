//
// Created by Marcin on 17.05.2021.
//

#ifndef UNTITLED_TREEOPERATIONS_H
#define UNTITLED_TREEOPERATIONS_H

#include<vector>

void binaryTreeCreateTimeMeasuring(int sizeOfStructure, vector<int> &dataFromCsvVector, vector<string> &results);

void avlTreeCreateTimeMeasuring(int sizeOfStructure, vector<int> &dataFromCsvVector, vector<string> &results);

void binaryTreeSearchTimeMeasuring(int sizeOfStructure, vector<int> &dataFromCsvVector, vector<string> &results);

void avlTreeSearchTimeMeasuring(int sizeOfStructure, vector<int> &dataFromCsvVector,vector<string> &results);

void binaryTreeDeleteTimeMeasuring(int sizeOfStructure, vector<int> &dataFromCsvVector, vector<string> &results);

void avlTreeDeleteTimeMeasuring(int sizeOfStructure, vector<int> &dataFromCsvVector,vector<string> &results);

void binaryTreeInsertTimeMeasuring(int sizeOfStructure, vector<int> &dataFromCsvVector, vector<string> &results);

void avlTreeInsertTimeMeasuring(int sizeOfStructure, vector<int> &dataFromCsvVector, vector<string> &results);


#endif //UNTITLED_TREEOPERATIONS_H
