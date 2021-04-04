//
// Created by Marcin on 04.04.2021.
//
#include "ArraysOperations.h"
#include<vector>
#include <chrono>
#include "../../Structures/ResultsByRow/ResultsByRow.h"
using namespace std::chrono;
using namespace std;
high_resolution_clock::time_point arrayTimeStart;
high_resolution_clock::time_point arrayTimeStop;

void arrayCreate(int sizeOfStructure, int repeatsPerInstance, vector<int> &dataFromCsvVector, vector<string> &results){
    arrayTimeStart = high_resolution_clock::now();
    for(int i = 0; i < repeatsPerInstance; i++){
        int *testArray = new int[sizeOfStructure];
        for(int j = 0; j < sizeOfStructure; j++){
            testArray[j] = dataFromCsvVector[j];
        }
        delete[] testArray;
    }
    arrayTimeStop = high_resolution_clock::now();
    duration<double> finalDuration = duration_cast<duration<double>>(arrayTimeStop - arrayTimeStart);
    ResultByRow arrayResult = ResultByRow("array", "create", sizeOfStructure, finalDuration.count());
    results.push_back(arrayResult.toString());
}
void arrayPut(int sizeOfStructure, int repeatsPerInstance, vector<int> &dataFromCsvVector, vector<string> &results){
    int *testArray = new int[sizeOfStructure];
    for(int i = 0; i < sizeOfStructure; i++){
        testArray[i] = dataFromCsvVector[i];
    }
    int randomValue = rand() % 1000000;
    int randomIndex = rand() % sizeOfStructure;
    arrayTimeStart = high_resolution_clock::now();
    for(int j = 0; j < repeatsPerInstance; j++){
        testArray[randomIndex] = randomValue;
    }
    arrayTimeStop = high_resolution_clock::now();
    duration<double> finalDuration = duration_cast<duration<double>>(arrayTimeStop - arrayTimeStart);
    ResultByRow arrayResult = ResultByRow("array", "put", sizeOfStructure, finalDuration.count());
    results.push_back(arrayResult.toString());
}
void arraySearch(int sizeOfStructure, int repeatsPerInstance, vector<int> &dataFromCsvVector, vector<string> &results){
    int *testArray = new int[sizeOfStructure];
    for(int i = 0; i < sizeOfStructure; i++){
        testArray[i] = dataFromCsvVector[i];
    }
    srand(time(NULL));
    duration<double> finalDuration = duration<double>(0);
    for(int i = 0; i < repeatsPerInstance; i++){
        int searchedValue = dataFromCsvVector[sizeOfStructure - 1];
        arrayTimeStart = high_resolution_clock::now();
        for(int j = 0; j < sizeOfStructure; j++){
            if(testArray[j] == searchedValue){
                arrayTimeStop = high_resolution_clock::now();
                break;
            }
        }
        finalDuration += duration_cast<duration<double>>(arrayTimeStop - arrayTimeStart);
    }
    ResultByRow arrayResult = ResultByRow("array", "search", sizeOfStructure, finalDuration.count());
    results.push_back(arrayResult.toString());
    delete[] testArray;
}
void arrayDelete(int sizeOfStructure, int repeatsPerInstance, vector<int> &dataFromCsvVector, vector<string> &results){
    duration<double> finalDuration = duration<double>(0);
    for(int i = 0; i < repeatsPerInstance; i++){
        int *testArray = new int[sizeOfStructure];
        for(int j = 0; j < sizeOfStructure; j++){
            testArray[j] = dataFromCsvVector[j];
        }
        arrayTimeStart = high_resolution_clock::now();
        size_t tempSize = sizeOfStructure - 1;
        int *tempArray = new int[tempSize];
        memcpy(tempArray, testArray, tempSize * sizeof(int));
        delete[] testArray;
        testArray = tempArray;
        arrayTimeStop = high_resolution_clock::now();
        finalDuration += duration_cast<duration<double>>(arrayTimeStop - arrayTimeStart);
        delete[] tempArray;
    }
    ResultByRow arrayResult = ResultByRow("array", "delete", sizeOfStructure, finalDuration.count());
    results.push_back(arrayResult.toString());
}
void arrayAdd(int sizeOfStructure, int repeatsPerInstance, vector<int> &dataFromCsvVector, vector<string> &results){
    duration<double> finalDuration = duration<double>(0);
    for(int i = 0; i < repeatsPerInstance; i++){
        int *test_array = new int[sizeOfStructure];
        for(int j = 0; j < sizeOfStructure; j++){
            test_array[j] = dataFromCsvVector[j];
        }
        int random_value = rand() % 1000000;
        arrayTimeStart = high_resolution_clock::now();
        size_t temp_add_array_size = sizeOfStructure + 1;
        int *temp_add_array = new int[temp_add_array_size];
        memcpy(temp_add_array, test_array, sizeOfStructure * sizeof(int));
        temp_add_array[sizeOfStructure] = random_value;
        delete[] test_array;
        test_array = temp_add_array;
        arrayTimeStop = high_resolution_clock::now();
        finalDuration += duration_cast<duration<double>>(arrayTimeStop - arrayTimeStart);
        delete[] temp_add_array;
    }
    ResultByRow arrayResult = ResultByRow("array", "add", sizeOfStructure, finalDuration.count());
    results.push_back(arrayResult.toString());
}