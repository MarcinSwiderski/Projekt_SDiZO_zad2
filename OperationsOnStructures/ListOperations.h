//
// Created by Marcin on 22.03.2021.
//

#ifndef UNTITLED_LISTOPERATIONS_H
#define UNTITLED_LISTOPERATIONS_H

#include "Structures/List/List.h"

void list_create_operation(int size_of_list, int number_of_repeats,vector<int> &data_vector, vector<string> &results_parser){
    using namespace std::chrono;
    high_resolution_clock::time_point t_start = high_resolution_clock::now();
    for(int repeat = 0; repeat < number_of_repeats; repeat++){
        List test_list;
        for(int i = 0; i < size_of_list; i++){
            test_list.add(data_vector[i]);
        }
    }
    high_resolution_clock::time_point t_end = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t_end - t_start);
    Result list_create_result = Result("list","create",size_of_list,time_span.count(),number_of_repeats);
    results_parser.push_back(list_create_result.toString());
}

void list_search_operation(int size_of_list, int number_of_repeats,vector<int> &data_vector, vector<string> &results_parser){
    using namespace std::chrono;
    high_resolution_clock::time_point t_start = high_resolution_clock::now();
    high_resolution_clock::time_point t_end = high_resolution_clock::now();
    duration<double> time_span = duration<double>(0);
    srand(time(NULL));
    for(int repeat = 0; repeat < number_of_repeats; repeat++){
        List test_list;
        for(int i = 0; i < size_of_list; i++){
            test_list.add(data_vector[i]);
        }
        int random_index = rand() % size_of_list;
        int searched_value = data_vector[random_index];
        t_start = high_resolution_clock::now();
        if(!test_list.find(searched_value)){
            cout<<" find error ";
            t_end = high_resolution_clock::now();
            time_span += duration_cast<duration<double>>(t_end - t_start);
        }
    }
    Result list_search_result = Result("list","search",size_of_list,time_span.count(),number_of_repeats);
    results_parser.push_back(list_search_result.toString());
}

void list_add_operation(int size_of_list, int number_of_repeats,vector<int> &data_vector, vector<string> &results_parser){
    using namespace std::chrono;
    high_resolution_clock::time_point t_start = high_resolution_clock::now();
    high_resolution_clock::time_point t_end = high_resolution_clock::now();
    duration<double> time_span = duration<double>(0);
    srand(time(NULL));
    for(int repeat = 0; repeat < number_of_repeats; repeat++){
        List test_list;
        for(int i = 0; i < size_of_list; i++){
            test_list.add(data_vector[i]);
        }
        int random_value = rand() % 1000000;
        t_start = high_resolution_clock::now();
        test_list.add(random_value);
        t_end = high_resolution_clock::now();
        time_span += duration_cast<duration<double>>(t_end - t_start);
    }
    Result list_add_result = Result("list","add",size_of_list,time_span.count(),number_of_repeats);
    results_parser.push_back(list_add_result.toString());
}

void list_delete_operation(int size_of_list, int number_of_repeats,vector<int> &data_vector, vector<string> &results_parser){
    using namespace std::chrono;
    high_resolution_clock::time_point t_start = high_resolution_clock::now();
    high_resolution_clock::time_point t_end = high_resolution_clock::now();
    duration<double> time_span = duration<double>(0);
    srand(time(NULL));
    for(int repeat = 0; repeat < number_of_repeats; repeat++){
        List test_list;
        for(int i = 0; i < size_of_list; i++){
            test_list.add(data_vector[i]);
        }
        int random_index = rand() % size_of_list;
        int random_value = data_vector[random_index];
        t_start = high_resolution_clock::now();
        if(!test_list.remove(random_value)){
            cout<<" delete error ";
        }
        t_end = high_resolution_clock::now();
        time_span += duration_cast<duration<double>>(t_end - t_start);
    }
    Result list_delete_result = Result("list","delete",size_of_list,time_span.count(),number_of_repeats);
    results_parser.push_back(list_delete_result.toString());
}

void list_operations(int size_of_list,vector<int> &data_vector, vector<string> &results_parser){
    using namespace std::chrono;
    //CREATE OPERATION
    high_resolution_clock::time_point t_start = high_resolution_clock::now();
    List test_list;
    for(int i = 0; i < size_of_list; i++){
        test_list.add(data_vector[i]);
    }
    high_resolution_clock::time_point t_end = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t_end - t_start);
    Result list_create_result = Result("list","create",size_of_list,time_span.count());
    results_parser.push_back(list_create_result.toString());
    //SEARCH OPERATION
    int random_index = rand() % size_of_list;
    int searched_value = data_vector[random_index];
    t_start = high_resolution_clock::now();
    if(!test_list.find(searched_value)){
        cout<<" find error ";
    }
    t_end = high_resolution_clock::now();
    Result list_search_result = Result("list","search",size_of_list,time_span.count());
    results_parser.push_back(list_search_result.toString());
    //ADD OPERATION
    int random_value = rand() % 1000000;
    t_start = high_resolution_clock::now();
    test_list.add(random_value);
    t_end = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(t_end - t_start);
    Result list_add_result = Result("list","add",size_of_list,time_span.count());
    results_parser.push_back(list_add_result.toString());
    //DELETE OPERATION
    t_start = high_resolution_clock::now();
    if(!test_list.remove(random_value)){
        cout<<" delete error ";
    }
    t_end = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(t_end - t_start);
    Result list_delete_result = Result("list","delete",size_of_list,time_span.count());
    results_parser.push_back(list_delete_result.toString());
}


#endif //UNTITLED_LISTOPERATIONS_H
