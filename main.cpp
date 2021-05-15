//
// Created by Marcin on 21.03.2021.
//

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<chrono>
#include "OperationsOnStructures/OperationsOnTrees/SortOperations.h"
#include "StreamHandliing/Streams.h"

using namespace std;
vector<int> dataFromCsvVector;
vector<string> results;
vector<vector<string>> registers;
string dataCsvName = "";
const int dataCsvRegisters = 10000000;
string resultCsvName = "";
unsigned differenceInElementsPerInstance = 1000;

bool config() {
    cout << "config" << endl;
    ifstream fin;
    fin.open("config.ini", ios::in);
    if (fin.fail()) {
        cout << "file not found";
        return false;
    }
    vector<string> row;
    string line;
    fin >> dataCsvName;
    fin >> resultCsvName;
    while (!fin.eof()) {
        string structure, maxElementsInMaxInstance;
        fin >> structure >> maxElementsInMaxInstance;
        vector<string> task;
        task.push_back(structure);
        task.push_back(maxElementsInMaxInstance);
        registers.push_back(task);
    }
    return true;
}

int main() {
    config();
    loadDataFromDataCSV(dataCsvName, dataCsvRegisters, dataFromCsvVector);
    for (int i = 0; i < registers.size(); i++) {
        string structure = registers[i][0];
        int maxElementsInMaxInstance = stoi(registers[i][1]);
        for (int j = 1; j <= maxElementsInMaxInstance; j += differenceInElementsPerInstance) {
            if (structure == "bubbleSort") {
//                binaryTreeInsertTimeMeasuring(j, dataFromCsvVector, results);
                saveResultsByRow(resultCsvName, results);
                cout << endl << "Ended " << structure << " for " << j << " size " << endl;
            } else if (structure == "coctailSort") {
//                coctailSort(j, dataFromCsvVector, results);
                saveResultsByRow(resultCsvName, results);
                cout << endl << "Ended " << structure << " for " << j << " size " << endl;
            } else if (structure == "quickSort") {
//                avlTreeInstertTimeMeasuring(j, dataFromCsvVector, results);
                saveResultsByRow(resultCsvName, results);
                cout << endl << "Ended " << structure << " for " << j << " size " << endl;
            } else if (structure == "insertSort") {
//                insertSort(j, dataFromCsvVector, results);
                saveResultsByRow(resultCsvName, results);
                cout << endl << "Ended " << structure << " for " << j << " size " << endl;
            } else if (structure == "quickSortMEMORY") {
//                quickSortTimeMemoryMesureing(j, dataFromCsvVector, results);
                saveResultsByRow(resultCsvName, results);
                cout << endl << "Ended " << structure << " for " << j << " size " << endl;
            } else if (structure == "bubbleSortMEMORY") {
//                bubbleSortTimeMessureMemory(j, dataFromCsvVector, results);
                saveResultsByRow(resultCsvName, results);
                cout << endl << "Ended " << structure << " for " << j << " size " << endl;
            }else {
                cout << endl << "Not found" << endl;
            }
            cout << "- IN PROGRESS..." << endl;
        }
        cout << "Task done" << endl;
    }

    saveResultsByRow(resultCsvName, results);
    return 0;
}