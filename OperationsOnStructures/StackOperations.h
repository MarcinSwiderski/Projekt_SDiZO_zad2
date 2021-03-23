//
// Created by Marcin on 22.03.2021.
//

#ifndef UNTITLED_STACKOPERATIONS_H
#define UNTITLED_STACKOPERATIONS_H
#include "Structures/Stack/Stack.h"

void stack_create_operation(int size_of_stack, int number_of_repeats,vector<int> &data_vector, vector<string> &results_parser) {
    using namespace std::chrono;
    high_resolution_clock::time_point t_start = high_resolution_clock::now();
    for (int repeat = 0; repeat < number_of_repeats; repeat++) {
        Stack test_stack = Stack();
        for (int i = 0; i < size_of_stack; i++) {
            test_stack.push(data_vector[i]);
        }
    }
    high_resolution_clock::time_point t_end = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t_end - t_start);
    Result stack_create_result = Result("stack", "create", size_of_stack, time_span.count(), number_of_repeats);
    results_parser.push_back(stack_create_result.toString());
}

void stack_search_operation(int size_of_stack, int number_of_repeats,vector<int> &data_vector, vector<string> &results_parser) {
    using namespace std::chrono;
    Stack test_stack = Stack();
    for (int i = 0; i < size_of_stack; i++) {
        test_stack.push(data_vector[i]);
    }
    high_resolution_clock::time_point t_start = high_resolution_clock::now();
    high_resolution_clock::time_point t_end = high_resolution_clock::now();
    duration<double> time_span = duration<double>(0);
    srand(time(NULL));
    for (int repeat = 0; repeat < number_of_repeats; repeat++) {
        int random_index = rand() % size_of_stack;
        int searched_value = data_vector[random_index];
        bool found = false;
        t_start = high_resolution_clock::now();
        int temp_stack_deep = 0;
        Stack temp_search_stack = Stack();
        for (int i = (size_of_stack - 1); i >= 0; i--) {
            if (test_stack.peek() == searched_value) {
                t_end = high_resolution_clock::now();
                found = true;
                break;
            } else {
                temp_search_stack.push(test_stack.pop());
                temp_stack_deep++;
            }
        }
        for (int i = 0; i < temp_stack_deep; i++) {
            test_stack.push(temp_search_stack.pop());
        }
        if (!found) {
            cout << "Stack searching error" << endl;
            t_end = high_resolution_clock::now();
        }
        time_span += duration_cast<duration<double>>(t_end - t_start);
    }
    Result stack_search_result = Result("stack", "search", size_of_stack, time_span.count(), number_of_repeats);
    results_parser.push_back(stack_search_result.toString());
}

void stack_push_operation(int size_of_stack, int number_of_repeats,vector<int> &data_vector, vector<string> &results_parser) {
    using namespace std::chrono;
    high_resolution_clock::time_point t_start = high_resolution_clock::now();
    high_resolution_clock::time_point t_end = high_resolution_clock::now();
    duration<double> time_span = duration<double>(0);
    for (int repeat = 0; repeat < number_of_repeats; repeat++) {
        Stack test_stack = Stack();
        for (int i = 0; i < size_of_stack; i++) {
            test_stack.push(data_vector[i]);
        }
        int random_value = rand() % 1000000;
        t_start = high_resolution_clock::now();
        test_stack.push(random_value);
        t_end = high_resolution_clock::now();
        time_span += duration_cast<duration<double>>(t_end - t_start);
    }
    Result stack_push_result = Result("stack", "push", size_of_stack, time_span.count(), number_of_repeats);
    results_parser.push_back(stack_push_result.toString());
}

void stack_pop_operation(int size_of_stack, int number_of_repeats,vector<int> &data_vector, vector<string> &results_parser) {
    using namespace std::chrono;
    high_resolution_clock::time_point t_start = high_resolution_clock::now();
    high_resolution_clock::time_point t_end = high_resolution_clock::now();
    duration<double> time_span = duration<double>(0);
    for (int repeat = 0; repeat < number_of_repeats; repeat++) {
        Stack test_stack = Stack();
        for (int i = 0; i < size_of_stack; i++) {
            test_stack.push(data_vector[i]);
        }
        t_start = high_resolution_clock::now();
        test_stack.pop();
        t_end = high_resolution_clock::now();
        time_span += duration_cast<duration<double>>(t_end - t_start);
    }
    Result stack_pop_result = Result("stack", "pop", size_of_stack, time_span.count(), number_of_repeats);
    results_parser.push_back(stack_pop_result.toString());
}

void stack_put_operation(int size_of_stack, int number_of_repeats,vector<int> &data_vector, vector<string> &results_parser) {
    using namespace std::chrono;
    high_resolution_clock::time_point t_start = high_resolution_clock::now();
    high_resolution_clock::time_point t_end = high_resolution_clock::now();
    duration<double> time_span = duration<double>(0);
    for (int repeat = 0; repeat < number_of_repeats; repeat++) {
        Stack test_stack = Stack();
        for (int i = 0; i < size_of_stack; i++) {
            test_stack.push(data_vector[i]);
        }
        int random_deep = rand() % size_of_stack;
        int random_value = rand() % 1000000;
        t_start = high_resolution_clock::now();
        Stack temp_put_stack = Stack();
        for (int i = 0; i < random_deep; i++) {
            int temp = test_stack.pop();
            temp_put_stack.push(temp);
        }
        test_stack.push(random_value);
        for (int i = 0; i < random_deep; i++) {
            test_stack.push(temp_put_stack.pop());
        }
        t_end = high_resolution_clock::now();
        time_span += duration_cast<duration<double>>(t_end - t_start);
    }
    Result stack_pop_result = Result("stack", "put", size_of_stack, time_span.count(), number_of_repeats);
    results_parser.push_back(stack_pop_result.toString());
}

void stack_operations(int size_of_stack,vector<int> &data_vector, vector<string> &results_parser) {
    using namespace std::chrono;
    //CREATE OPERATION
    high_resolution_clock::time_point t_start = high_resolution_clock::now();
    Stack test_stack = Stack();
    for (int i = 0; i < size_of_stack; i++) {
        test_stack.push(data_vector[i]);
    }
    high_resolution_clock::time_point t_end = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t_end - t_start);
    Result stack_create_result = Result("stack", "create", size_of_stack, time_span.count());
    results_parser.push_back(stack_create_result.toString());
    //SEARCH OPERATION
    srand(time(NULL));
    int random_index = rand() % size_of_stack;
    int searched_value = data_vector[random_index];
    bool found = false;
    t_start = high_resolution_clock::now();
    int temp_stack_deep = 0;
    Stack temp_search_stack = Stack();
    for (int i = (size_of_stack - 1); i >= 0; i--) {
        if (test_stack.peek() == searched_value) {
            t_end = high_resolution_clock::now();
            found = true;
            break;
        } else {
            temp_search_stack.push(test_stack.pop());
            temp_stack_deep++;
        }
    }
    for (int i = 0; i < temp_stack_deep; i++) {
        test_stack.push(temp_search_stack.pop());
    }
    if (!found) {
        cout << "Stack searching error" << endl;
        t_end = high_resolution_clock::now();
    }
    time_span = duration_cast<duration<double>>(t_end - t_start);
    Result stack_search_result = Result("stack", "search", size_of_stack, time_span.count());
    results_parser.push_back(stack_search_result.toString());
    //PUSH OPERATION
    int random_value = rand() % 1000000;
    t_start = high_resolution_clock::now();
    test_stack.push(random_value);
    t_end = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(t_end - t_start);
    Result stack_push_result = Result("stack", "push", size_of_stack, time_span.count());
    results_parser.push_back(stack_push_result.toString());
    //POP OPERATION
    t_start = high_resolution_clock::now();
    test_stack.pop();
    t_end = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(t_end - t_start);
    Result stack_pop_result = Result("stack", "pop", size_of_stack, time_span.count());
    results_parser.push_back(stack_pop_result.toString());
    //PUT OPERATION
    srand(time(NULL));
    int random_deep = rand() % size_of_stack;
    random_value = rand() % 1000000;
    t_start = high_resolution_clock::now();
    Stack temp_put_stack = Stack();
    for (int i = 0; i < random_deep; i++) {
        int temp = test_stack.pop();
        temp_put_stack.push(temp);
    }
    test_stack.push(random_value);
    for (int i = 0; i < random_deep; i++) {
        test_stack.push(temp_put_stack.pop());
    }
    t_end = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(t_end - t_start);
    Result stack_put_result = Result("stack", "put", size_of_stack, time_span.count());
    results_parser.push_back(stack_put_result.toString());
}

#endif //UNTITLED_STACKOPERATIONS_H
