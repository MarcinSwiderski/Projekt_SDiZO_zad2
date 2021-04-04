//
// Created by Marcin on 04.04.2021.
//
#include <chrono>
#include "ListOperations.h"
#include "../../Structures/List/List.h"
#include<vector>

using namespace std::chrono;
high_resolution_clock::time_point listTimeStart;
high_resolution_clock::time_point listTimeStop;

void listCreate(int sizeOfStructure, unsigned numberOfRepeats, vector<int> &dataFromCsvVector, vector<string> &results){
    listTimeStart = high_resolution_clock::now();
    for(int j = 0; j < numberOfRepeats; j++){
        List test_list;
        for(int i = 0; i < sizeOfStructure; i++){
            test_list.add(dataFromCsvVector[i]);
        }
    }
    listTimeStop = high_resolution_clock::now();
    duration<double> finalDuration = duration_cast<duration<double>>(listTimeStop - listTimeStart);
    ResultByRow listResult = ResultByRow("list", "create", sizeOfStructure, finalDuration.count());
    results.push_back(listResult.toString());
}
void listSearch(int sizeOfStrucutre, unsigned numberOfRepeats, vector<int> &dataFromCsvVector, vector<string> &results){
    listTimeStart = high_resolution_clock::now();
    duration<double> finalDuration = duration<double>(0);
    srand(time(NULL));
    for(int i = 0; i < numberOfRepeats; i++){
        List testList;
        for(int j = 0; j < sizeOfStrucutre; j++){
            testList.add(dataFromCsvVector[j]);
        }
        int randomIndex = rand() % sizeOfStrucutre;
        int searchedValue = dataFromCsvVector[randomIndex];
        listTimeStart = high_resolution_clock::now();
        if(testList.find(searchedValue)){
            listTimeStop = high_resolution_clock::now();
            finalDuration += duration_cast<duration<double>>(listTimeStop - listTimeStart);
        }
    }
    ResultByRow listResult = ResultByRow("list", "search", sizeOfStrucutre, finalDuration.count());
    results.push_back(listResult.toString());
}

void listAdd(int sizeOfStructure, unsigned numberOfRepeats, vector<int> &dataFromCsvVector, vector<string> &results){
    listTimeStart = high_resolution_clock::now();
    duration<double> finalDuration = duration<double>(0);
    srand(time(NULL));
    for(int i = 0; i < numberOfRepeats; i++){
        List test_list;
        for(int j = 0; j < sizeOfStructure; j++){
            test_list.add(dataFromCsvVector[j]);
        }
        int random_value = rand() % 1000000;
        listTimeStart = high_resolution_clock::now();
        test_list.add(random_value);
        listTimeStop = high_resolution_clock::now();
        finalDuration += duration_cast<duration<double>>(listTimeStop - listTimeStart);
    }
    ResultByRow listResult = ResultByRow("list", "add", sizeOfStructure, finalDuration.count());
    results.push_back(listResult.toString());
}

void listDelete(int sizeOfStrucutre, unsigned numberOfRepeats, vector<int> &dataFromCsvVector, vector<string> &results){
    duration<double> finalDuration = duration<double>(0);
    for(int i = 0; i < numberOfRepeats; i++){
        srand(time(NULL));
        List testList;
        for(int j = 0; j < sizeOfStrucutre; j++){
            testList.add(dataFromCsvVector[j]);
        }
        int randomIndex = 0;
        int randomValue = dataFromCsvVector[randomIndex];
        finalDuration += testList.removeGetTime(randomValue);;
    }
    ResultByRow listResult = ResultByRow("list", "delete", sizeOfStrucutre, finalDuration.count());
    results.push_back(listResult.toString());
}
