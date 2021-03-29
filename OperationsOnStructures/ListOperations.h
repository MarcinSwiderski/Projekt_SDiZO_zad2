//
// Created by Marcin on 22.03.2021.
//

#ifndef UNTITLED_LISTOPERATIONS_H
#define UNTITLED_LISTOPERATIONS_H

#include "Structures/List/List.h"
using namespace std::chrono;
high_resolution_clock::time_point listTimeStart;
high_resolution_clock::time_point listTimeStop;

void listCreate(int sizeOfStructure, unsigned number_of_repeats, vector<int> &data_vector, vector<string> &results_parser){
    listTimeStart = high_resolution_clock::now();
    for(int j = 0; j < number_of_repeats; j++){
        List test_list;
        for(int i = 0; i < sizeOfStructure; i++){
            test_list.add(data_vector[i]);
        }
    }
    listTimeStop = high_resolution_clock::now();
    duration<double> timeSpentOnInstance = duration_cast<duration<double>>(listTimeStop - listTimeStart);
    ResultByRow list_create_result = ResultByRow("list", "create", sizeOfStructure, timeSpentOnInstance.count());
    results_parser.push_back(list_create_result.toString());
}

void listSearch(int sizeOfStrucutre, unsigned numberOfRepeats, vector<int> &dataFromCsvVector, vector<string> &results_parser){
    listTimeStart = high_resolution_clock::now();
    duration<double> timeSpentOnInstance = duration<double>(0);
    srand(time(NULL));
    for(int i = 0; i < numberOfRepeats; i++){
        List testList;
        for(int j = 0; j < sizeOfStrucutre; j++){
            testList.add(dataFromCsvVector[j]);
        }
        int random_index = rand() % sizeOfStrucutre;
        int searched_value = dataFromCsvVector[random_index];
        listTimeStart = high_resolution_clock::now();
        if(testList.find(searched_value)){
            listTimeStop = high_resolution_clock::now();
            timeSpentOnInstance += duration_cast<duration<double>>(listTimeStop - listTimeStart);
        }
    }
    ResultByRow list_search_result = ResultByRow("list", "search", sizeOfStrucutre, timeSpentOnInstance.count());
    results_parser.push_back(list_search_result.toString());
}

void listAdd(int sizeOfStructure, unsigned numberOfRepeats, vector<int> &data_vector, vector<string> &results_parser){
    listTimeStart = high_resolution_clock::now();
    duration<double> timeSpentOnInstance = duration<double>(0);
    srand(time(NULL));
    for(int j = 0; j < numberOfRepeats; j++){
        List test_list;
        for(int i = 0; i < sizeOfStructure; i++){
            test_list.add(data_vector[i]);
        }
        int random_value = rand() % 1000000;
        listTimeStart = high_resolution_clock::now();
        test_list.add(random_value);
        listTimeStop = high_resolution_clock::now();
        timeSpentOnInstance += duration_cast<duration<double>>(listTimeStop - listTimeStart);
    }
    ResultByRow list_add_result = ResultByRow("list", "add", sizeOfStructure, timeSpentOnInstance.count());
    results_parser.push_back(list_add_result.toString());
}

void listDelete(int sizeOfStrucutre, unsigned numberOfRepeats, vector<int> &dataFromCsvVector, vector<string> &results_parser){
//    listTimeStart = high_resolution_clock::now();
    duration<double> timeSpentOnInstance = duration<double>(0);
//    srand(time(NULL));
    for(int j = 0; j < numberOfRepeats; j++){
        srand(time(NULL));
        List testList;
        for(int i = 0; i < sizeOfStrucutre; i++){
            testList.add(dataFromCsvVector[i]);
        }
        int randomIndex = rand() % sizeOfStrucutre;
        int randomValue = dataFromCsvVector[randomIndex];
        listTimeStart = high_resolution_clock::now();
        testList.remove(randomValue);
        listTimeStop = high_resolution_clock::now();
        timeSpentOnInstance += duration_cast<duration<double>>(listTimeStop - listTimeStart);
    }
    ResultByRow list_delete_result = ResultByRow("list", "delete", sizeOfStrucutre, timeSpentOnInstance.count());
    results_parser.push_back(list_delete_result.toString());
}


#endif //UNTITLED_LISTOPERATIONS_H
