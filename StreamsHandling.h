//
// Created by Marcin on 23.03.2021.
//

#ifndef UNTITLED_STREAMSHANDLING_H
#define UNTITLED_STREAMSHANDLING_H

bool loadDataFromDataCSV(string resultCsvName, int dataCsvRegisters, vector<int> &dataFromCsvVector) {
    cout << "Loading data from " << resultCsvName << " file" << endl;
    ifstream fin;
    fin.open(resultCsvName, ios::in);
    if (fin.fail()) {
        cout << "Data file " << resultCsvName << " not exist" << endl;
        return false;
    }
    string line;
    int data_loaded = 0;
    for (int i = 0; i < dataCsvRegisters; i++) {
        fin >> line;
        if (!fin.eof()) {
            dataFromCsvVector.push_back(stoi(line));
        } else {
            cout << "Not enough elements in data file " << resultCsvName << endl;
            return false;
        }
        data_loaded++;
    }
    cout << "Loaded correctly " << data_loaded << " numbers" << endl;
    return true;
}

void saveResultsByRow(string resultCsvName, vector<string> &results) {
    fstream fstream1;
    fstream1.open(resultCsvName, ios::out);
    fstream1 << "structure,operation,maxElementsInMaxInstance,timeOfOperation" << endl;
    for (int i = 0; i < results.size(); i++) {
        fstream1 << results[i] << endl;
    }
}

#endif //UNTITLED_STREAMSHANDLING_H
