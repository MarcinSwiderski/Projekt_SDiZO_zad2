////
//// Created by Marcin on 04.04.2021.
////
//#include <chrono>
//#include "SortOperations.h"
//#include<vector>
//
//using namespace std::chrono;
//high_resolution_clock::time_point sortStart;
//high_resolution_clock::time_point sortStop;
//
//
//void binaryTreeInsertTimeMeasuring(int sizeOfStructure, vector<int> &dataFromCsvVector, vector<string> &results) {
//    duration<double> finalDuration = duration<double>(0);
//    AvlTree
//    sortStart = high_resolution_clock::now();
//
//    sortStop = high_resolution_clock::now();
//    finalDuration = duration_cast<duration<double>>(sortStop - sortStart);
//    ResultByRow bubbleSortResult = ResultByRow("bubblesort", sizeOfStructure, finalDuration.count());
//    results.push_back(bubbleSortResult.toString());
//}
//
//void avlTreeInstertTimeMeasuring(int sizeOfStructure, vector<int> &dataFromCsvVector,vector<string> &results) {
//    duration<double> finalDuration = duration<double>(0);
//    srand(time(NULL));
//
//    sortStart = high_resolution_clock::now();
//
//    sortStop = high_resolution_clock::now();
//    finalDuration = duration_cast<duration<double>>(sortStop - sortStart);
//    ResultByRow quickSortResult = ResultByRow("quicksort", sizeOfStructure, finalDuration.count());
//    results.push_back(quickSortResult.toString());
//}
//
