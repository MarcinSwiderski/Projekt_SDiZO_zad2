//
// Created by Marcin on 22.03.2021.
//

#ifndef UNTITLED_ARRAYSOPERATIONS_H
#define UNTITLED_ARRAYSOPERATIONS_H



void array_create_operation(int size_of_array, int number_of_repeats,vector<int> &data_vector, vector<string> &results_parser){
    using namespace std::chrono;
    high_resolution_clock::time_point t_start = high_resolution_clock::now();
    for(int repeat = 0; repeat < number_of_repeats; repeat++){
        int *test_array = new int[size_of_array];
        for(int i = 0; i < size_of_array; i++){
            test_array[i] = data_vector[i];
        }
        delete[] test_array;
    }
    high_resolution_clock::time_point t_end = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t_end - t_start);
    Result array_create_result = Result("array","create",size_of_array,time_span.count(),number_of_repeats);
    results_parser.push_back(array_create_result.toString());
}

void array_put_operation(int size_of_array, int number_of_repeats,vector<int> &data_vector, vector<string> &results_parser){
    using namespace std::chrono;
    int *test_array = new int[size_of_array];
    for(int i = 0; i < size_of_array; i++){
        test_array[i] = data_vector[i];
    }
    int random_value = rand() % 1000000;
    int random_index = rand() % size_of_array;
    high_resolution_clock::time_point t_start = high_resolution_clock::now();
    for(int repeat = 0; repeat < number_of_repeats; repeat++){
        test_array[random_index] = random_value;
    }
    high_resolution_clock::time_point t_end = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t_end - t_start);
    Result array_put_result = Result("array","put",size_of_array,time_span.count(),number_of_repeats);
    results_parser.push_back(array_put_result.toString());
}

void array_search_operation(int size_of_array, int number_of_repeats,vector<int> &data_vector, vector<string> &results_parser){
    using namespace std::chrono;
    int *test_array = new int[size_of_array];
    for(int i = 0; i < size_of_array; i++){
        test_array[i] = data_vector[i];
    }
    srand(time(NULL));
    int random_index = rand() % size_of_array;
    int searched_value = data_vector[random_index];
    bool found = false;
    high_resolution_clock::time_point t_end = high_resolution_clock::now();
    high_resolution_clock::time_point t_start = high_resolution_clock::now();
    duration<double> time_span = duration<double>(0);
    for(int repeat = 0; repeat < number_of_repeats; repeat++){
        int random_index = rand() % size_of_array;
        int searched_value = data_vector[random_index];
        t_start = high_resolution_clock::now();
        for(int i = 0; i < size_of_array; i++){
            if(test_array[i] == searched_value){
                t_end = high_resolution_clock::now();
                found = true;
                break;
            }
        }
        if(!found){
            cout<<"Array searching error"<<endl;
            t_end = high_resolution_clock::now();
        }
        time_span += duration_cast<duration<double>>(t_end - t_start);
    }
    Result array_search_result = Result("array","search",size_of_array,time_span.count(),number_of_repeats);
    results_parser.push_back(array_search_result.toString());
    delete[] test_array;
}

void array_delete_operation(int size_of_array, int number_of_repeats,vector<int> &data_vector, vector<string> &results_parser){
    using namespace std::chrono;
    duration<double> time_span = duration<double>(0);
    high_resolution_clock::time_point t_start = high_resolution_clock::now();
    high_resolution_clock::time_point t_end = high_resolution_clock::now();
    for(int repeat = 0; repeat < number_of_repeats; repeat++){
        int *test_array = new int[size_of_array];
        for(int i = 0; i < size_of_array; i++){
            test_array[i] = data_vector[i];
        }
        t_start = high_resolution_clock::now();
        size_t temp_delete_array_size = size_of_array-1;
        int *temp_delete_array = new int[temp_delete_array_size];
        memcpy(temp_delete_array, test_array, temp_delete_array_size * sizeof(int));
        delete[] test_array;
        test_array = temp_delete_array;
        t_end = high_resolution_clock::now();
        time_span += duration_cast<duration<double>>(t_end - t_start);
        delete[] temp_delete_array;
    }
    Result array_delete_result = Result("array","delete",size_of_array,time_span.count(),number_of_repeats);
    results_parser.push_back(array_delete_result.toString());
}

void array_add_operation(int size_of_array, int number_of_repeats,vector<int> &data_vector, vector<string> &results_parser){
    using namespace std::chrono;
    duration<double> time_span = duration<double>(0);
    high_resolution_clock::time_point t_start = high_resolution_clock::now();
    high_resolution_clock::time_point t_end = high_resolution_clock::now();
    for(int repeat = 0; repeat < number_of_repeats; repeat++){
        int *test_array = new int[size_of_array];
        for(int i = 0; i < size_of_array; i++){
            test_array[i] = data_vector[i];
        }
        int random_value = rand() % 1000000;
        t_start = high_resolution_clock::now();
        size_t temp_add_array_size = size_of_array+1;
        int *temp_add_array = new int[temp_add_array_size];
        memcpy(temp_add_array, test_array, size_of_array * sizeof(int));
        temp_add_array[size_of_array] = random_value;
        delete[] test_array;
        test_array = temp_add_array;
        t_end = high_resolution_clock::now();
        time_span += duration_cast<duration<double>>(t_end - t_start);
        delete[] temp_add_array;
    }
    Result array_add_result = Result("array","add",size_of_array,time_span.count(),number_of_repeats);
    results_parser.push_back(array_add_result.toString());
}

void array_operations(int size_of_array,vector<int> &data_vector, vector<string> &results_parser){
    using namespace std::chrono;
    //CREATE OPERATION
    high_resolution_clock::time_point t_start = high_resolution_clock::now();
    int *test_array = new int[size_of_array];
    for(int i = 0; i < size_of_array; i++){
        test_array[i] = data_vector[i];
    }
    high_resolution_clock::time_point t_end = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t_end - t_start);
    Result array_create_result = Result("array","create",size_of_array,time_span.count());
    results_parser.push_back(array_create_result.toString());
    //SEARCH OPERATION
    srand(time(NULL));
    int random_index = rand() % size_of_array;
    int searched_value = data_vector[random_index];
    bool found = false;
    t_start = high_resolution_clock::now();
    for(int i = 0; i < size_of_array; i++){
        if(test_array[i] == searched_value){
            t_end = high_resolution_clock::now();
            found = true;
            break;
        }
    }
    if(!found){
        cout<<"Array searching error"<<endl;
        t_end = high_resolution_clock::now();
    }
    time_span = duration_cast<duration<double>>(t_end - t_start);
    Result array_search_result = Result("array","search",size_of_array,time_span.count());
    results_parser.push_back(array_search_result.toString());
    //PUT OPERATION
    random_index = rand() % size_of_array;
    t_start = high_resolution_clock::now();
    test_array[random_index] = random_index;
    t_end = high_resolution_clock::now();
    test_array[random_index] = data_vector[random_index];
    time_span = duration_cast<duration<double>>(t_end - t_start);
    Result array_put_result = Result("array","put",size_of_array,time_span.count());
    results_parser.push_back(array_put_result.toString());
    //ADD OPERATION
    int *temp_test_array = test_array;
    int random_value = rand() % 1000000;
    t_start = high_resolution_clock::now();
    size_t temp_add_array_size = size_of_array+1;
    int *temp_add_array = new int[temp_add_array_size];
    memcpy(temp_add_array, test_array, size_of_array * sizeof(int));
    temp_add_array[size_of_array] = random_value;
    delete[] test_array;
    test_array = temp_add_array;
    t_end = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(t_end - t_start);
    test_array = temp_test_array;
    Result array_add_result = Result("array","add",size_of_array,time_span.count());
    results_parser.push_back(array_add_result.toString());
    delete[] temp_add_array;
    //DELETE OPERATION
    int *test_delete_array = new int[size_of_array];
    for(int i = 0; i < size_of_array; i++){
        test_delete_array[i] = data_vector[i];
    }
    t_start = high_resolution_clock::now();
    size_t temp_delete_array_size = size_of_array-1;
    int *temp_delete_array = new int[temp_delete_array_size];
    memcpy(temp_delete_array, test_delete_array, temp_delete_array_size * sizeof(int));
    delete[] test_delete_array;
    test_delete_array = temp_delete_array;
    t_end = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(t_end - t_start);
    Result array_delete_result = Result("array","delete",size_of_array,time_span.count());
    results_parser.push_back(array_delete_result.toString());
    delete[] temp_delete_array;
}


#endif //UNTITLED_ARRAYSOPERATIONS_H
