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
    for(int repeat = 0; repeat < number_of_repeats; repeat++){
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

void listSearch(int size, unsigned number_of_repeats,vector<int> &data_vector, vector<string> &results_parser){
    listTimeStart = high_resolution_clock::now();
    duration<double> timeSpentOnInstance = duration<double>(0);
    srand(time(NULL));
    for(int repeat = 0; repeat < number_of_repeats; repeat++){
        List test_list;
        for(int i = 0; i < size; i++){
            test_list.add(data_vector[i]);
        }
        int random_index = rand() % size;
        int searched_value = data_vector[random_index];
        listTimeStart = high_resolution_clock::now();
        if(test_list.find(searched_value)){
            listTimeStop = high_resolution_clock::now();
            timeSpentOnInstance += duration_cast<duration<double>>(listTimeStop - listTimeStart);
        }
    }
    ResultByRow list_search_result = ResultByRow("list","search",size,timeSpentOnInstance.count());
    results_parser.push_back(list_search_result.toString());
}

void listAdd(int size_of_list, unsigned number_of_repeats,vector<int> &data_vector, vector<string> &results_parser){
    listTimeStart = high_resolution_clock::now();
    duration<double> timeSpentOnInstance = duration<double>(0);
    srand(time(NULL));
    for(int repeat = 0; repeat < number_of_repeats; repeat++){
        List test_list;
        for(int i = 0; i < size_of_list; i++){
            test_list.add(data_vector[i]);
        }
        int random_value = rand() % 1000000;
        listTimeStart = high_resolution_clock::now();
        test_list.add(random_value);
        listTimeStop = high_resolution_clock::now();
        timeSpentOnInstance += duration_cast<duration<double>>(listTimeStop - listTimeStart);
    }
    ResultByRow list_add_result = ResultByRow("list","add",size_of_list,timeSpentOnInstance.count());
    results_parser.push_back(list_add_result.toString());
}

void listDelete(int size_of_list, unsigned number_of_repeats,vector<int> &data_vector, vector<string> &results_parser){
    listTimeStart = high_resolution_clock::now();
    duration<double> timeSpentOnInstance = duration<double>(0);
    srand(time(NULL));
    for(int repeat = 0; repeat < number_of_repeats; repeat++){
        List list;
        for(int i = 0; i < size_of_list; i++){
            list.add(data_vector[i]);
        }
        int random_index = rand() % size_of_list;
        int random_value = data_vector[random_index];
        listTimeStart = high_resolution_clock::now();
        list.remove(random_value);
        listTimeStop = high_resolution_clock::now();
        timeSpentOnInstance += duration_cast<duration<double>>(listTimeStop - listTimeStart);
    }
    ResultByRow list_delete_result = ResultByRow("list","delete",size_of_list,timeSpentOnInstance.count());
    results_parser.push_back(list_delete_result.toString());
}


#endif //UNTITLED_LISTOPERATIONS_H
