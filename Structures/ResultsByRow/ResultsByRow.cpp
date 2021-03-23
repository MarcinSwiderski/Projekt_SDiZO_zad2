//
// Created by Marcin on 22.03.2021.
//

#include <string>
#include "ResultsByRow.h"

Result::Result(string data_structure, string operation, int size_of_strucutre, double time_span) {

        this->data_structure = data_structure;
        this->operation = operation;
        this->size_of_strucutre = size_of_strucutre;
        this->time_span = time_span;
        this->averages_denominator = 1;

}
Result::Result(string data_structure, string operation, int size_of_strucutre, double time_span, int averages_denominator){
this->data_structure = data_structure;
this->operation = operation;
this->size_of_strucutre = size_of_strucutre;
this->time_span = time_span;
this->averages_denominator = averages_denominator;
}
string Result::toString(){
    return(data_structure+","+operation+","+to_string(size_of_strucutre)+","+to_string(time_span)+","+to_string(averages_denominator));
}