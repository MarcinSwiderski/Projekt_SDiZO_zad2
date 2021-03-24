//
// Created by Marcin on 22.03.2021.
//

#ifndef UNTITLED_ARRAYSOPERATIONS_H
#define UNTITLED_ARRAYSOPERATIONS_H

using namespace std::chrono;
high_resolution_clock::time_point arrayTimeStart;
high_resolution_clock::time_point arrayTimeStop;

void arrayCreate(int sizeOfStructure, int number_of_repeats, vector<int> &dataFromCsvVector, vector<string> &results){
    arrayTimeStart = high_resolution_clock::now();
    for(int repeat = 0; repeat < number_of_repeats; repeat++){
        int *test_array = new int[sizeOfStructure];
        for(int i = 0; i < sizeOfStructure; i++){
            test_array[i] = dataFromCsvVector[i];
        }
        delete[] test_array;
    }
    arrayTimeStop = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(arrayTimeStop - arrayTimeStart);
    ResultByRow array_create_result = ResultByRow("array", "create", sizeOfStructure, time_span.count());
    results.push_back(array_create_result.toString());
}

void arrayPut(int sizeOfStructure, int repeatsPerInstance, vector<int> &dataFromCsvVector, vector<string> &results){
    int *test_array = new int[sizeOfStructure];
    for(int i = 0; i < sizeOfStructure; i++){
        test_array[i] = dataFromCsvVector[i];
    }
    int random_value = rand() % 1000000;
    int random_index = rand() % sizeOfStructure;
    arrayTimeStart = high_resolution_clock::now();
    for(int repeat = 0; repeat < repeatsPerInstance; repeat++){
        test_array[random_index] = random_value;
    }
    arrayTimeStop = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(arrayTimeStop - arrayTimeStart);
    ResultByRow array_put_result = ResultByRow("array", "put", sizeOfStructure, time_span.count());
    results.push_back(array_put_result.toString());
}

void arraySearch(int sizeOfStructure, int repeatsPerInstance, vector<int> &dataFromCsvVector, vector<string> &results){
    int *test_array = new int[sizeOfStructure];
    for(int i = 0; i < sizeOfStructure; i++){
        test_array[i] = dataFromCsvVector[i];
    }
    srand(time(NULL));
    int random_index = rand() % sizeOfStructure;
    int searched_value = dataFromCsvVector[random_index];
    bool found = false;
    arrayTimeStart = high_resolution_clock::now();
    duration<double> time_span = duration<double>(0);
    for(int repeat = 0; repeat < repeatsPerInstance; repeat++){
        int random_index = rand() % sizeOfStructure;
        int searched_value = dataFromCsvVector[random_index];
        arrayTimeStart = high_resolution_clock::now();
        for(int i = 0; i < sizeOfStructure; i++){
            if(test_array[i] == searched_value){
                arrayTimeStop = high_resolution_clock::now();
                found = true;
                break;
            }
        }
        if(!found){
            cout<<"Array searching error"<<endl;
            arrayTimeStop = high_resolution_clock::now();
        }
        time_span += duration_cast<duration<double>>(arrayTimeStop - arrayTimeStart);
    }
    ResultByRow array_search_result = ResultByRow("array", "search", sizeOfStructure, time_span.count());
    results.push_back(array_search_result.toString());
    delete[] test_array;
}

void arrayDelete(int sizeOfStructure, int repeatsPerInstance, vector<int> &dataFromCsvVector, vector<string> &results){
    duration<double> time_span = duration<double>(0);
    for(int repeat = 0; repeat < repeatsPerInstance; repeat++){
        int *test_array = new int[sizeOfStructure];
        for(int i = 0; i < sizeOfStructure; i++){
            test_array[i] = dataFromCsvVector[i];
        }
        arrayTimeStart = high_resolution_clock::now();
        size_t temp_delete_array_size = sizeOfStructure - 1;
        int *temp_delete_array = new int[temp_delete_array_size];
        memcpy(temp_delete_array, test_array, temp_delete_array_size * sizeof(int));
        delete[] test_array;
        test_array = temp_delete_array;
        arrayTimeStop = high_resolution_clock::now();
        time_span += duration_cast<duration<double>>(arrayTimeStop - arrayTimeStart);
        delete[] temp_delete_array;
    }
    ResultByRow array_delete_result = ResultByRow("array", "delete", sizeOfStructure, time_span.count());
    results.push_back(array_delete_result.toString());
}

void arrayAdd(int sizeOfStructure, int repeatsPerInstance, vector<int> &dataFromCsvVector, vector<string> &results_parser){
    duration<double> time_span = duration<double>(0);
    for(int repeat = 0; repeat < repeatsPerInstance; repeat++){
        int *test_array = new int[sizeOfStructure];
        for(int i = 0; i < sizeOfStructure; i++){
            test_array[i] = dataFromCsvVector[i];
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
        time_span += duration_cast<duration<double>>(arrayTimeStop - arrayTimeStart);
        delete[] temp_add_array;
    }
    ResultByRow array_add_result = ResultByRow("array", "add", sizeOfStructure, time_span.count());
    results_parser.push_back(array_add_result.toString());
}

#endif //UNTITLED_ARRAYSOPERATIONS_H
