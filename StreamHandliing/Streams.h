//
// Created by Marcin on 04.04.2021.
//

#ifndef UNTITLED_STREAMS_H
#define UNTITLED_STREAMS_H

using namespace std;

bool loadDataFromDataCSV(string resultCsvName, int dataCsvRegisters, vector<int> &dataFromCsvVector);

void saveResultsByRow(string resultCsvName, vector<string> &results);


#endif //UNTITLED_STREAMS_H
