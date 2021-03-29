//
// Created by Marcin on 22.03.2021.
//

#ifndef UNTITLED_ARRAYSOPERATIONS_H
#define UNTITLED_ARRAYSOPERATIONS_H

using namespace std::chrono;
high_resolution_clock::time_point arrayTimeStart;
high_resolution_clock::time_point arrayTimeStop;

void arrayCreate(int sizeOfStructure, int numberOfRepeats, vector<int> &dataFromCsvVector, vector<string> &results){
    arrayTimeStart = high_resolution_clock::now();
    for(int i = 0; i < numberOfRepeats; i++){
        int *testArray = new int[sizeOfStructure];
        for(int j = 0; j < sizeOfStructure; j++){
            testArray[j] = dataFromCsvVector[j];
        }
        delete[] testArray;
    }
    arrayTimeStop = high_resolution_clock::now();
    duration<double> finalDuration = duration_cast<duration<double>>(arrayTimeStop - arrayTimeStart);
    ResultByRow result = ResultByRow("array", "create", sizeOfStructure, finalDuration.count());
    results.push_back(result.toString());
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
    ResultByRow result = ResultByRow("array", "put", sizeOfStructure, finalDuration.count());
    results.push_back(result.toString());
}

void arraySearch(int sizeOfStructure, int repeatsPerInstance, vector<int> &dataFromCsvVector, vector<string> &results){
    int *testArray = new int[sizeOfStructure];
    for(int i = 0; i < sizeOfStructure; i++){
        testArray[i] = dataFromCsvVector[i];
    }
    srand(time(NULL));
    arrayTimeStart = high_resolution_clock::now();
    duration<double> finalDuration = duration<double>(0);
    for(int i = 0; i < repeatsPerInstance; i++){
        int randomIndex = rand() % sizeOfStructure;
        int searchedValue = dataFromCsvVector[randomIndex];
        arrayTimeStart = high_resolution_clock::now();
        for(int j = 0; j < sizeOfStructure; j++){
            if(testArray[j] == searchedValue){
                arrayTimeStop = high_resolution_clock::now();
                break;
            }
        }
        finalDuration += duration_cast<duration<double>>(arrayTimeStop - arrayTimeStart);
    }
    ResultByRow result = ResultByRow("array", "search", sizeOfStructure, finalDuration.count());
    results.push_back(result.toString());
    delete[] testArray;
}

void arrayDelete(int sizeOfStructure, int repeatsPerInstance, vector<int> &dataFromCsvVector, vector<string> &results){
    duration<double> time_span = duration<double>(0);
    for(int i = 0; i < repeatsPerInstance; i++){
        int *testArray = new int[sizeOfStructure];
        for(int j = 0; j < sizeOfStructure; j++){
            testArray[j] = dataFromCsvVector[j];
        }
        arrayTimeStart = high_resolution_clock::now();
        size_t temp_delete_array_size = sizeOfStructure - 1;
        int *temp_delete_array = new int[temp_delete_array_size];
        memcpy(temp_delete_array, testArray, temp_delete_array_size * sizeof(int));
        delete[] testArray;
        testArray = temp_delete_array;
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
