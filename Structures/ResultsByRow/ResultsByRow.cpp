//
// Created by Marcin on 22.03.2021.
//

#include <string>
#include "ResultsByRow.h"


ResultByRow::ResultByRow(string structure, string operation, int size_of_strucutre, double timeSpentOnInstance){
this->structure = structure;
this->operation = operation;
this->size_of_strucutre = size_of_strucutre;
this->timeSpentOnInstance = timeSpentOnInstance;
}
string ResultByRow::toString(){
    return(structure+","+operation+","+to_string(size_of_strucutre)+","+to_string(timeSpentOnInstance));
}