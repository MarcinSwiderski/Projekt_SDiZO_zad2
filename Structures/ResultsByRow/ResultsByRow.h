//
// Created by Marcin on 22.03.2021.
//

#ifndef UNTITLED_RESULTSBYROW_H
#define UNTITLED_RESULTSBYROW_H

using namespace std;

struct ResultByRow {
    string structure;
    string operation;
    int size_of_strucutre;
    double timeSpentOnInstance;
    ResultByRow(string data_structure, string operation, int size_of_strucutre, double time_span);
    string toString();
};


#endif //UNTITLED_RESULTSBYROW_H
