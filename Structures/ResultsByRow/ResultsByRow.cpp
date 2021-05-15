//
// Created by Marcin on 22.03.2021.
//

#include <string>
#include "ResultsByRow.h"

ResultByRow::ResultByRow(string typeOfSort, int sizeOfStructure, double timeSpentOnInstance) {
    this->typeOfSort = typeOfSort;
    this->sizeOfStrucutre = sizeOfStructure;
    this->timeSpentOnInstance = timeSpentOnInstance;
}

string ResultByRow::toString() {
    return (typeOfSort + "," + to_string(sizeOfStrucutre) + "," + to_string(timeSpentOnInstance));
}