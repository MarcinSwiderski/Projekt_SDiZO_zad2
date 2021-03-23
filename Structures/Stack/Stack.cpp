//
// Created by Marcin on 22.03.2021.
//

#include "Stack.h"

Stack::Stack() {
    top=-1;
    num = new int[10000000];
}
Stack::~Stack() {
    delete[] num;
}
