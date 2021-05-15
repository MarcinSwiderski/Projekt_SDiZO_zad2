//
// Created by Marcin on 15.05.2021.
//

#include <chrono>
#include <string>
#include <vector>
#include "OperationsOnTrees/SortOperations.h"
#include "../Structures/ResultsByRow/ResultsByRow.h"
#include "../Structures/Trees/AvlTree/AvlTree.h"
#include "../Structures/Trees/BinaryTree/BinaryTree.h"

using namespace std::chrono;
high_resolution_clock::time_point sortStart;
high_resolution_clock::time_point sortStop;


void binaryTreeInsertTimeMeasuring(int sizeOfStructure, vector<int> &dataFromCsvVector, vector<string> &results) {
    duration<double> finalDuration = duration<double>(0);
    BinaryTree *binaryTree = new BinaryTree();
    sortStart = high_resolution_clock::now();
    for (int i = 0; i < sizeOfStructure; i++) {
        binaryTree->insert(dataFromCsvVector[i]);
    }
    sortStop = high_resolution_clock::now();
    finalDuration = duration_cast<duration<double>>(sortStop - sortStart);
    ResultByRow bubbleSortResult = ResultByRow("binaryTreeInsert", sizeOfStructure, finalDuration.count());
    results.push_back(bubbleSortResult.toString());
}

void avlTreeInstertTimeMeasuring(int sizeOfStructure, vector<int> &dataFromCsvVector,vector<string> &results) {
    duration<double> finalDuration = duration<double>(0);
    srand(time(NULL));
    AvlTree* avlTree = new AvlTree();
    sortStart = high_resolution_clock::now();
    for (int i = 0; i < sizeOfStructure; i++) {
        avlTree->insertInAvlTree(dataFromCsvVector[i]);
    }
    sortStop = high_resolution_clock::now();
    finalDuration = duration_cast<duration<double>>(sortStop - sortStart);
    ResultByRow quickSortResult = ResultByRow("AvlTreeInsert", sizeOfStructure, finalDuration.count());
    results.push_back(quickSortResult.toString());
}