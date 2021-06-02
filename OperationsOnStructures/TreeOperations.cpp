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
#include "../Structures/Trees/BST/BST.h"

using namespace std::chrono;
high_resolution_clock::time_point sortStart;
high_resolution_clock::time_point sortStop;


void binaryTreeCreateTimeMeasuring(int sizeOfStructure, vector<int> &dataFromCsvVector, vector<string> &results) {
    duration<double> finalDuration = duration<double>(0);
    BinaryTree *binaryTree = new BinaryTree(3);
    sortStart = high_resolution_clock::now();
    for (int i = 0; i < sizeOfStructure; i++) {
        binaryTree->insertion(dataFromCsvVector[i]);
    }
    sortStop = high_resolution_clock::now();
    delete binaryTree;
    finalDuration = duration_cast<duration<double>>(sortStop - sortStart);
    ResultByRow bubbleSortResult = ResultByRow("binaryTreeCreate", sizeOfStructure, finalDuration.count());
    results.push_back(bubbleSortResult.toString());
}

void avlTreeCreateTimeMeasuring(int sizeOfStructure, vector<int> &dataFromCsvVector, vector<string> &results) {
    duration<double> finalDuration = duration<double>(0);
    srand(time(NULL));
    AVL *avlTree = new AVL();
    sortStart = high_resolution_clock::now();
    for (int i = 0; i < sizeOfStructure; i++) {
        avlTree->insert(dataFromCsvVector[i]);
    }
    delete avlTree;
    sortStop = high_resolution_clock::now();
    finalDuration = duration_cast<duration<double>>(sortStop - sortStart);
    ResultByRow quickSortResult = ResultByRow("avlTreeCreate", sizeOfStructure, finalDuration.count());
    results.push_back(quickSortResult.toString());
}

void binaryTreeInsertTimeMeasuring(int sizeOfStructure, vector<int> &dataFromCsvVector, vector<string> &results) {
    duration<double> finalDuration = duration<double>(0);
    BinaryTree *binaryTree = new BinaryTree(3);
    int i = 0;
    for (i = 0; i < sizeOfStructure; i++) {
        binaryTree->insertion(dataFromCsvVector[i]);
    }
    sortStart = high_resolution_clock::now();
    for (int j = 0; j < 100; j++) {
        binaryTree->insertion(dataFromCsvVector[i]);
        i++;
    }
    sortStop = high_resolution_clock::now();
    delete binaryTree;
    finalDuration = duration_cast<duration<double>>(sortStop - sortStart);
    ResultByRow bubbleSortResult = ResultByRow("binaryTreeInsert", sizeOfStructure, finalDuration.count());
    results.push_back(bubbleSortResult.toString());
}

void avlTreeInsertTimeMeasuring(int sizeOfStructure, vector<int> &dataFromCsvVector, vector<string> &results) {
    duration<double> finalDuration = duration<double>(0);
    srand(time(NULL));
//    AvlTree *avlTree = new AvlTree();
//    int i = 0;
//    for (i = 0; i < sizeOfStructure; i++) {
//        avlTree->insertInAvlTree(dataFromCsvVector[i]);
//    }
//    sortStart = high_resolution_clock::now();
//    for (i = 0; i < 100; i++) {
//        avlTree->insertInAvlTree(dataFromCsvVector[i]);
//    }
//    sortStop = high_resolution_clock::now();
//    delete avlTree;
    finalDuration = duration_cast<duration<double>>(sortStop - sortStart);
    ResultByRow quickSortResult = ResultByRow("avlTreeInsert", sizeOfStructure, finalDuration.count());
    results.push_back(quickSortResult.toString());
}

void binaryTreeSearchTimeMeasuring(int sizeOfStructure, vector<int> &dataFromCsvVector, vector<string> &results) {
    duration<double> finalDuration = duration<double>(0);
    BinaryTree *binaryTree = new BinaryTree(3);
    int i = 1;
    for (i = 1; i < sizeOfStructure; i++) {
        binaryTree->insertion(dataFromCsvVector[i]);
    }
    sortStart = high_resolution_clock::now();
    for (int j = 0; j < 20; j++) {
        binaryTree->deletion(dataFromCsvVector[i - 1]);
        i--;
    }
    sortStop = high_resolution_clock::now();
    delete binaryTree;
    finalDuration = duration_cast<duration<double>>(sortStop - sortStart);
    ResultByRow bubbleSortResult = ResultByRow("binaryTreeSearch", sizeOfStructure, finalDuration.count());
    results.push_back(bubbleSortResult.toString());
}

void avlTreeSearchTimeMeasuring(int sizeOfStructure, vector<int> &dataFromCsvVector, vector<string> &results) {
    duration<double> finalDuration = duration<double>(0);
    srand(time(NULL));
//    AvlTree *avlTree = new AvlTree();
//    int i = 1;
//    for (i = 1; i < sizeOfStructure; i++) {
//        avlTree->insertInAvlTree(dataFromCsvVector[i]);
//    }
//    sortStart = high_resolution_clock::now();
//    for (int j = 0; j < 20; j++) {
//        avlTree->searchFromAvlTree(dataFromCsvVector[i]);
//        i--;
//    }
//    delete avlTree;
//    sortStop = high_resolution_clock::now();;
    finalDuration = duration_cast<duration<double>>(sortStop - sortStart);
    ResultByRow quickSortResult = ResultByRow("avlTreeSearch", sizeOfStructure, finalDuration.count());
    results.push_back(quickSortResult.toString());
}

void binaryTreeDeleteTimeMeasuring(int sizeOfStructure, vector<int> &dataFromCsvVector, vector<string> &results) {
    duration<double> finalDuration = duration<double>(0);
    BinaryTree *binaryTree = new BinaryTree(3);
    int i;
    for (i = 0; i < sizeOfStructure; i++) {
        binaryTree->insertion(dataFromCsvVector[i]);
    }

    sortStart = high_resolution_clock::now();
    binaryTree->deletion(dataFromCsvVector[i]);
    sortStop = high_resolution_clock::now();
    delete binaryTree;

    finalDuration = duration_cast<duration<double>>(sortStop - sortStart);
    ResultByRow bubbleSortResult = ResultByRow("binaryTreeDelete", sizeOfStructure, finalDuration.count());
    results.push_back(bubbleSortResult.toString());
}

void avlTreeDeleteTimeMeasuring(int sizeOfStructure, vector<int> &dataFromCsvVector, vector<string> &results) {
    duration<double> finalDuration = duration<double>(0);
    srand(time(NULL));
//    AvlTree *avlTree = new AvlTree();
//    int i;
//    for (i = 0; i < sizeOfStructure; i++) {
//        avlTree->insertInAvlTree(dataFromCsvVector[i]);
//    }
//    sortStart = high_resolution_clock::now();
//    avlTree->removeFromAvlTree(dataFromCsvVector[i]);
//    sortStop = high_resolution_clock::now();
//    delete avlTree;

    finalDuration = duration_cast<duration<double>>(sortStop - sortStart);
    ResultByRow quickSortResult = ResultByRow("avlTreeDelete", sizeOfStructure, finalDuration.count());
    results.push_back(quickSortResult.toString());
}