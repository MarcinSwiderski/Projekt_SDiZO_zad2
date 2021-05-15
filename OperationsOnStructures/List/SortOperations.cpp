//
// Created by Marcin on 04.04.2021.
//
#include <chrono>
#include "SortOperations.h"
#include<vector>

using namespace std::chrono;
high_resolution_clock::time_point sortStart;
high_resolution_clock::time_point sortStop;

int memoryUsage = 0;

void swapfuncMemory(int *a, int *b) {
    int t = *a;
    memoryUsage += sizeof(t);
    *a = *b;
    *b = t;
}

int partitionMemory(vector<int> &dataFromCsvVector, int startingIndex, int sizeOfStructure) {
    int bufor = dataFromCsvVector[sizeOfStructure];
    memoryUsage += sizeof(bufor);
    int i = (startingIndex - 1);
    memoryUsage += sizeof(i);
    for (int j = startingIndex; j <= sizeOfStructure - 1; j++) {
        if (dataFromCsvVector[j] < bufor) {
            i++;
            swapfuncMemory(&dataFromCsvVector[i], &dataFromCsvVector[j]);
        }
    }
    swapfuncMemory(&dataFromCsvVector[i + 1], &dataFromCsvVector[sizeOfStructure]);
    return (i + 1);
}

void quickSortMemory(vector<int> &dataFromCsvVector, int startingIndex, int endingIndex) {
    if (startingIndex < endingIndex) {
        int buf = partitionMemory(dataFromCsvVector, startingIndex, endingIndex);
        memoryUsage += sizeof(buf);
        quickSortMemory(dataFromCsvVector, startingIndex, buf - 1);
        quickSortMemory(dataFromCsvVector, buf + 1, endingIndex);
    }
}

void quickSortTimeMemoryMesureing(int sizeOfStructure, vector<int> &dataFromCsvVector, vector<string> &results) {
    memoryUsage = 0;
    quickSortMemory(dataFromCsvVector, 0, sizeOfStructure - 1);
    ResultByRow quickSortResult = ResultByRow("quicksortMEMORY", sizeOfStructure, memoryUsage);
    results.push_back(quickSortResult.toString());
}

void swapfunc(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}


int partition(vector<int> &dataFromCsvVector, int startingIndex, int sizeOfStructure) {
    int bufor = dataFromCsvVector[sizeOfStructure];
    int i = (startingIndex - 1);
    for (int j = startingIndex; j <= sizeOfStructure - 1; j++) {
        if (dataFromCsvVector[j] < bufor) {
            i++;
            swapfunc(&dataFromCsvVector[i], &dataFromCsvVector[j]);
        }
    }
    swapfunc(&dataFromCsvVector[i + 1], &dataFromCsvVector[sizeOfStructure]);
    return (i + 1);
}


void quickSort(vector<int> &dataFromCsvVector, int startingIndex, int endingIndex) {
    if (startingIndex < endingIndex) {
        int buf = partition(dataFromCsvVector, startingIndex, endingIndex);
        quickSort(dataFromCsvVector, startingIndex, buf - 1);
        quickSort(dataFromCsvVector, buf + 1, endingIndex);
    }
}

void bubbleSort(int sizeOfStructure, vector<int> &dataFromCsvVector) {
    bool swapp = true;
    memoryUsage = sizeof(swapp);
    while (swapp) {
        swapp = false;
        size_t i;
        memoryUsage = sizeof(i);
        for ( i = 0; i < sizeOfStructure - 1; i++) {
            if (dataFromCsvVector[i] > dataFromCsvVector[i + 1]) {
                dataFromCsvVector[i] += dataFromCsvVector[i + 1];
                dataFromCsvVector[i + 1] = dataFromCsvVector[i] - dataFromCsvVector[i + 1];
                dataFromCsvVector[i] -= dataFromCsvVector[i + 1];
                swapp = true;
            }
        }
    }
}

void bubbleSortTimeMessure(int sizeOfStructure, vector<int> &dataFromCsvVector, vector<string> &results) {
    duration<double> finalDuration = duration<double>(0);
    sortStart = high_resolution_clock::now();
    bubbleSort(sizeOfStructure, dataFromCsvVector);
    sortStop = high_resolution_clock::now();
    finalDuration = duration_cast<duration<double>>(sortStop - sortStart);
    ResultByRow bubbleSortResult = ResultByRow("bubblesort", sizeOfStructure, finalDuration.count());
    results.push_back(bubbleSortResult.toString());
}
void bubbleSortTimeMessureMemory(int sizeOfStructure, vector<int> &dataFromCsvVector, vector<string> &results) {
    memoryUsage = 0;
    bubbleSort(sizeOfStructure, dataFromCsvVector);
    ResultByRow bubbleSortResult = ResultByRow("bubblesortMEMORY", sizeOfStructure, memoryUsage);
    results.push_back(bubbleSortResult.toString());
}

void coctailSort(int sizeOfStructure, vector<int> &dataFromCsvVector, vector<string> &results) {
    duration<double> finalDuration = duration<double>(0);
    bool swapped = true;
    int start = 0;
    int bufor = sizeOfStructure;
    int end = bufor - 1;

    sortStart = high_resolution_clock::now();
    while (swapped) {
        swapped = false;
        for (int i = start; i < end; ++i) {
            if (dataFromCsvVector[i] > dataFromCsvVector[i + 1]) {
                swap(dataFromCsvVector[i], dataFromCsvVector[i + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
        swapped = false;
        --end;
        for (int i = end - 1; i >= start; --i) {
            if (dataFromCsvVector[i] > dataFromCsvVector[i + 1]) {
                swap(dataFromCsvVector[i], dataFromCsvVector[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }


    sortStop = high_resolution_clock::now();
    finalDuration = duration_cast<duration<double>>(sortStop - sortStart);
    ResultByRow bubbleSortResult = ResultByRow("coctailsort", sizeOfStructure, finalDuration.count());
    results.push_back(bubbleSortResult.toString());
}


void quickSortTimeMesureing(int sizeOfStructure, vector<int> &dataFromCsvVector,
                            vector<string> &results) {
    duration<double> finalDuration = duration<double>(0);
    srand(time(NULL));
    sortStart = high_resolution_clock::now();
    quickSort(dataFromCsvVector, 0, sizeOfStructure - 1);
    sortStop = high_resolution_clock::now();
    finalDuration = duration_cast<duration<double>>(sortStop - sortStart);
    ResultByRow quickSortResult = ResultByRow("quicksort", sizeOfStructure, finalDuration.count());
    results.push_back(quickSortResult.toString());
}


void insertSort(int sizeOfStrucutre, vector<int> &dataFromCsvVector, vector<string> &results) {
    duration<double> finalDuration = duration<double>(0);
    int bufor, j;
    sortStop = high_resolution_clock::now();
    for (int i = 1; i < sizeOfStrucutre; i++) {
        bufor = dataFromCsvVector[i];
        j = i - 1;
        while (j >= 0 && dataFromCsvVector[j] > bufor) {
            dataFromCsvVector[j + 1] = dataFromCsvVector[j];
            --j;
        }
        dataFromCsvVector[j + 1] = bufor;
    }
    sortStop = high_resolution_clock::now();
    finalDuration = duration_cast<duration<double>>(sortStop - sortStart);
    ResultByRow insertSortResult = ResultByRow("insertsort", sizeOfStrucutre, finalDuration.count());
    results.push_back(insertSortResult.toString());
}
