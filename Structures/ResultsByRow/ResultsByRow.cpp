//
// Created by Marcin on 22.03.2021.
//

#include <string>
#include "ResultsByRow.h"

ResultByRow::ResultByRow(string structure, string operation, int sizeOfStructure, double timeSpentOnInstance) {
    this->structure = structure;
    this->operation = operation;
    this->sizeOfStrucutre = sizeOfStructure;
    this->timeSpentOnInstance = timeSpentOnInstance;
}

string ResultByRow::toString() {
    return (structure + "," + operation + "," + to_string(sizeOfStrucutre) + "," + to_string(timeSpentOnInstance));
}