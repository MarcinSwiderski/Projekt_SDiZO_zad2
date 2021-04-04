//
// Created by Marcin on 21.03.2021.
//

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<chrono>
#include "OperationsOnStructures/List/ListOperations.h"
#include "OperationsOnStructures/Array/ArraysOperations.h"
#include "OperationsOnStructures/Queue/QueueOperations.h"
#include "OperationsOnStructures/Stack/StackOperations.h"
#include "StreamHandliing/Streams.h"

using namespace std;
vector<int> dataFromCsvVector;
vector<string> results;
vector<vector<string>> registers;
string dataCsvName = "";
const int dataCsvRegisters = 10000000;
string resultCsvName = "";
unsigned repeatsPerInstance = 30;
unsigned differenceInElementsPerInstance = 50000;

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
        string structure, operation, maxElementsInMaxInstance;
        fin >> structure >> operation >> maxElementsInMaxInstance;
        vector<string> task;
        task.push_back(structure);
        task.push_back(operation);
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
        string operation = registers[i][1];
        int maxElementsInMaxInstance = stoi(registers[i][2]);
        if (registers[i][0] == "array") {
            for (int j = 1; j <= maxElementsInMaxInstance; j += differenceInElementsPerInstance) {
                cout << "array-" << operation <<" "<< j << " ";
                if (operation == "create") {
                    arrayCreate(j, repeatsPerInstance, dataFromCsvVector, results);
                } else if (operation == "search") {
                    arraySearch(j, repeatsPerInstance, dataFromCsvVector, results);
                } else if (operation == "put") {
                    arrayPut(j, repeatsPerInstance, dataFromCsvVector, results);
                } else if (operation == "delete") {
                    arrayDelete(j, repeatsPerInstance, dataFromCsvVector, results);
                } else if (operation == "add") {
                    arrayAdd(j, repeatsPerInstance, dataFromCsvVector, results);
                } else {
                    cout << endl << "Not found" << endl;
                }
                cout << "- IN PROGRESS..." << endl;
            }
            cout << "Task done" << endl;
        } else if (registers[i][0] == "list") {
            for (int j = 1; j <= maxElementsInMaxInstance; j += differenceInElementsPerInstance) {
                cout << "list-" << operation <<" "<< j << " ";
                if (operation == "create") {
                    listCreate(j, repeatsPerInstance, dataFromCsvVector, results);
                } else if (operation == "search") {
                    listSearch(j, repeatsPerInstance, dataFromCsvVector, results);
                } else if (operation == "delete") {
                    listDelete(j, repeatsPerInstance, dataFromCsvVector, results);
                } else if (operation == "add") {
                    listAdd(j, repeatsPerInstance, dataFromCsvVector, results);
                } else {
                    cout << endl << "Not Found" << endl;
                }
                cout << "- IN PROGRESS..." << endl;
            }
            cout << "Done" << endl;
        } else if (registers[i][0] == "stack") {
            for (int j = 1; j <= maxElementsInMaxInstance; j += differenceInElementsPerInstance) {
                cout << "stock-" << operation <<" "<< j << " ";
                if (operation == "create") {
                    stackCreate(j, repeatsPerInstance, dataFromCsvVector, results);
                } else if (operation == "search") {
                    stackSearch(j, repeatsPerInstance, dataFromCsvVector, results);
                } else if (operation == "pop") {
                    stackPop(j, repeatsPerInstance, dataFromCsvVector, results);
                } else if (operation == "push") {
                    stackPush(j, repeatsPerInstance, dataFromCsvVector, results);
                } else {
                    cout << endl <<  "Not found" << endl;
                }
                cout << "- IN PROGRESS..." << endl;
            }
            cout << "Done" << endl;
        } else if (registers[i][0] == "queue") {
            for (int j = 1; j <= maxElementsInMaxInstance; j += differenceInElementsPerInstance) {
                cout << "queue-" << operation <<" "<< j << " ";
                if (operation == "create") {
                    queueCreate(j, repeatsPerInstance, dataFromCsvVector, results);
                } else if (operation == "search") {
                    queueSearch(j, repeatsPerInstance, dataFromCsvVector, results);
                } else if (operation == "forward") {
                    queueMovForward(j, repeatsPerInstance, dataFromCsvVector, results);
                } else if (operation == "backwords") {
                    queueMovBackwords(j, repeatsPerInstance, dataFromCsvVector, results);
                } else {
                    cout << endl << "Not found" << endl;
                }
                cout << "- IN PROGRESS..." << endl;
            }
            cout << "Done" << endl;
        }
    }
    saveResultsByRow(resultCsvName, results);
    return 0;
}