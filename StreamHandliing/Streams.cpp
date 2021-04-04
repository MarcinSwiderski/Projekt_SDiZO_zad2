//
// Created by Marcin on 04.04.2021.
//

#include <string>
#include <fstream>
#include <iostream>
#include<vector>
#include "Streams.h"
using namespace std;

bool loadDataFromDataCSV(string resultCsvName, int dataCsvRegisters, vector<int> &dataFromCsvVector) {
    ifstream fin;
    fin.open(resultCsvName, ios::in);
    if (fin.fail()) {
        cout<<"file does not exist";
        return false;
    }
    string line;
    int dataNumber = 0;
    for (int i = 0; i < dataCsvRegisters; i++) {
        fin >> line;
        if (!fin.eof()) {
            dataFromCsvVector.push_back(stoi(line));
        }
        dataNumber++;
    }
    cout << "Loaded correctly " << dataNumber << " numbers" << endl;
    return true;
}

void saveResultsByRow(string resultCsvName, vector<string> &results) {
    fstream fstream1;
    fstream1.open(resultCsvName, ios::out);
    fstream1 << "structure,operationOnStructure,maxElementsInMaxInstance,timeOfOperation" << endl;
    for (int i = 0; i < results.size(); i++) {
        fstream1 << results[i] << endl;
    }
}
