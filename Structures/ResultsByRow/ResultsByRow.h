//
// Created by Marcin on 22.03.2021.
//

#ifndef UNTITLED_RESULTSBYROW_H
#define UNTITLED_RESULTSBYROW_H


//
// Created by Marcin on 23.03.2021.
//
using namespace std;

struct Result {
    string data_structure;
    string operation;
    int size_of_strucutre;
    double time_span;
    int averages_denominator;

    Result(string data_structure, string operation, int size_of_strucutre, double time_span, int averages_denominator);

    Result(string data_structure, string operation, int size_of_strucutre, double time_span);

    string toString();
};


#endif //UNTITLED_RESULTSBYROW_H
