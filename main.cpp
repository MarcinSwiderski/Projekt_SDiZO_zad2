//
// Created by Marcin on 21.03.2021.
//

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<chrono>
//#include "OperationsOnStructures/OperationsOnTrees/SortOperations.h"
#include "StreamHandliing/Streams.h"
#include "OperationsOnStructures/TreeOperations.h"

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
        for (int j = 1000; j <= maxElementsInMaxInstance; j += differenceInElementsPerInstance) {
            if (structure == "binaryTreeCREATE") {
                binaryTreeCreateTimeMeasuring(j, dataFromCsvVector, results);
                saveResultsByRow(resultCsvName, results);
                cout << endl << "Ended " << structure << " for " << j << " size " << endl;
            } else if (structure == "avlTreeCREATE") {
                avlTreeCreateTimeMeasuring(j, dataFromCsvVector, results);
                saveResultsByRow(resultCsvName, results);
                cout << endl << "Ended " << structure << " for " << j << " size " << endl;
            } else if (structure == "binaryTreeSEARCH") {
                binaryTreeSearchTimeMeasuring(j, dataFromCsvVector, results);
                saveResultsByRow(resultCsvName, results);
                cout << endl << "Ended " << structure << " for " << j << " size " << endl;
            } else if (structure == "avlTreeSEARCH") {
                avlTreeSearchTimeMeasuring(j, dataFromCsvVector, results);
                saveResultsByRow(resultCsvName, results);
                cout << endl << "Ended " << structure << " for " << j << " size " << endl;
            } else if (structure == "binaryTreeDELETE") {
                binaryTreeDeleteTimeMeasuring(j, dataFromCsvVector, results);
                saveResultsByRow(resultCsvName, results);
                cout << endl << "Ended " << structure << " for " << j << " size " << endl;
            } else if (structure == "avlTreeDELETE") {
                avlTreeDeleteTimeMeasuring(j, dataFromCsvVector, results);
                saveResultsByRow(resultCsvName, results);
                cout << endl << "Ended " << structure << " for " << j << " size " << endl;
            } else if (structure == "binaryTreeINSERT") {
                binaryTreeInsertTimeMeasuring(j, dataFromCsvVector, results);
                saveResultsByRow(resultCsvName, results);
                cout << endl << "Ended " << structure << " for " << j << " size " << endl;
            } else if (structure == "avlTreeINSERT") {
                avlTreeInsertTimeMeasuring(j, dataFromCsvVector, results);
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