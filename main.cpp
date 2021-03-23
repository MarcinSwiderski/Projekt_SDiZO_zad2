#include<iostream>
#include<fstream>
#include<string>
#include<random>
#include<vector>
#include<conio.h>
#include<chrono>
#include<cstring>
#include<algorithm>
#include "Structures/Stack/Stack.h"
#include "Structures/Queue/Queue.h"
//#include "Structures/ResultsByRow/ResultsByRow.h"
#include "Structures/ResultsByRow/ResultsByRow.h"
#include "OperationsOnStructures/ListOperations.h"
#include "OperationsOnStructures/ArraysOperations.h"
#include "OperationsOnStructures/QueueOperations.h"
#include "OperationsOnStructures/StackOperations.h"

using namespace std;
vector<int> data_vector;
vector<string> results;
vector<vector<string>> tasks;
string data_file_name = "";
int data_amount = 0;
string results_file_name = "";

void generate_data(string file_name, int amount) {
    cout << "Generating " << amount << " numbers to data file " << file_name << endl;
    fstream fout;
    fout.open("data.csv", ios::out);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(-1000000, 1000000);
    for (int i = 0; i < amount; i++) {
        fout << dis(gen) << "\n";
    }
    cout << "Data generated correctly" << endl;
}

bool load_data(string file_name, int amount) {
    cout << "Loading data from " << file_name << " file" << endl;
    ifstream fin;
    fin.open(file_name, ios::in);
    if (fin.fail()) {
        cout << "Data file " << file_name << " not exist" << endl;
        return false;
    }
    string line;
    int data_loaded = 0;
    for (int i = 0; i < amount; i++) {
        fin >> line;
        if (!fin.eof()) {
            data_vector.push_back(stoi(line));
        } else {
            cout << "Not enough elements in data file " << file_name << endl;
            return false;
        }
        data_loaded++;
    }
    cout << "Loaded correctly " << data_loaded << " numbers" << endl;
    return true;
}

bool load_config() {
    cout << "Loading config.ini" << endl;
    ifstream fin;
    fin.open("config.ini", ios::in);
    if (fin.fail()) {
        cout << "Config.ini not found" << endl;
        return false;
    }
    vector<string> row;
    string line;
    fin >> data_file_name >> data_amount;
    fin >> results_file_name;
    while (!fin.eof()) {
        string structure, operation, start_range, end_range, step, time;
        fin >> structure >> operation >> start_range >> end_range >> step >> time;
        if (structure.size() == 0 || operation.size() == 0 || start_range.size() == 0 || end_range.size() == 0 ||
            step.size() == 0 || time.size() == 0) {
            break;
        }
        vector<string> task;
        task.push_back(structure);
        task.push_back(operation);
        task.push_back(start_range);
        task.push_back(end_range);
        task.push_back(step);
        task.push_back(time);
        tasks.push_back(task);
    }
    cout << "Config loaded correctly" << endl;
    return true;
}

void print_config() {
    cout << "data file: " << data_file_name << endl;
    cout << "data amount: " << data_amount << endl;
    cout << "results file: " << results_file_name << endl;
    cout << "number of tasks: " << tasks.size() << endl;
    cout << "tasks: " << endl;
    for (int i = 0; i < tasks.size(); i++) {
        cout << tasks[i][0] << " " << tasks[i][1] << " " << tasks[i][2] << " " << tasks[i][3] << " " << tasks[i][4]
             << " " << endl;
    }
}

void save_results(string results_file_name) {
    cout << "Saving results" << endl;
    fstream fout;
    fout.open(results_file_name, ios::out);
    fout << "data_structure,operation,size_of_structure,time_of_operation_s,averages_denominator" << endl;
    for (int i = 0; i < results.size(); i++) {
        fout << results[i] << endl;
    }
    cout << "Correctly saved " << results.size() << " results" << endl;
}

int main() {
    load_config();
    if (!load_data(data_file_name, data_amount)) {
        generate_data(data_file_name, data_amount);
        load_data(data_file_name, data_amount);
    }
    for (int i = 0; i < tasks.size(); i++) {
        string structure = tasks[i][0];
        string operation = tasks[i][1];
        int start_range = stoi(tasks[i][2]);
        int end_range = stoi(tasks[i][3]);
        int step = stoi(tasks[i][4]);
        int time_repeat = stoi(tasks[i][5]);
        cout << "Task " << operation << " on " << structure << " in range from " << start_range << " to " << end_range
             << " with step " << step << " made " << time_repeat << " times" << endl;
        if (start_range < 1 || end_range > data_vector.size() || time_repeat < 1) {
            cout << "Cannot execute task in this range" << endl;
        } else {
            if (tasks[i][0] == "array") {
                for (int j = start_range; j <= end_range; j += step) {
                    cout << "Array operation " << operation << " with " << j << " elements ";
                    if (operation == "create") {
                        array_create_operation(j, time_repeat, data_vector, results);
                    } else if (operation == "search") {
                        array_search_operation(j, time_repeat, data_vector, results);
                    } else if (operation == "put") {
                        array_put_operation(j, time_repeat, data_vector, results);
                    } else if (operation == "delete") {
                        array_delete_operation(j, time_repeat, data_vector, results);
                    } else if (operation == "add") {
                        array_add_operation(j, time_repeat, data_vector, results);
                    } else {
                        cout << endl << "Operation not recognized" << endl;
                    }
                    cout << "done" << endl;
                }
                cout << "Task done" << endl;
            } else if (tasks[i][0] == "list") {
                for (int j = start_range; j <= end_range; j += step) {
                    cout << "List operation " << operation << " with " << j << " elements ";
                    if (operation == "create") {
                        list_create_operation(j, time_repeat, data_vector, results);
                    } else if (operation == "search") {
                        list_search_operation(j, time_repeat, data_vector, results);

                    } else if (operation == "delete") {
                        list_delete_operation(j, time_repeat, data_vector, results);

                    } else if (operation == "add") {
                        list_add_operation(j, time_repeat, data_vector, results);
                    } else {
                        cout << endl << "Operation not recognized" << endl;
                    }
                    cout << "done" << endl;
                }
                cout << "Task done" << endl;
            } else if (tasks[i][0] == "stack") {
                for (int j = start_range; j <= end_range; j += step) {
                    cout << "Stack operation " << operation << " with " << j << " elements ";
                    if (operation == "create") {
                        stack_create_operation(j, time_repeat, data_vector, results);
                    } else if (operation == "search") {
                        stack_search_operation(j, time_repeat, data_vector, results);
                    } else if (operation == "put") {
                        stack_put_operation(j, time_repeat, data_vector, results);
                    } else if (operation == "pop") {
                        stack_pop_operation(j, time_repeat, data_vector, results);
                    } else if (operation == "push") {
                        stack_push_operation(j, time_repeat, data_vector, results);
                    } else {
                        cout << endl << "Operation not recognized" << endl;
                    }
                    cout << "done" << endl;
                }
                cout << "Task done" << endl;
            } else if (tasks[i][0] == "queue") {
                for (int j = start_range; j <= end_range; j += step) {
                    cout << "Queue operation " << operation << " with " << j << " elements ";
                    if (operation == "create") {
                        queue_create_operation(j, time_repeat, data_vector, results);
                    } else if (operation == "search") {
                        queue_search_operation(j, time_repeat, data_vector, results);
                    } else if (operation == "queue") {
                        queue_enqueue_operation(j, time_repeat, data_vector, results);
                    } else if (operation == "dequeue") {
                        queue_dequeue_operation(j, time_repeat, data_vector, results);
                    } else {
                        cout << endl << "Operation not recognized" << endl;
                    }
                    cout << "done" << endl;
                }
                cout << "Task done" << endl;
            } else {
                cout << "Cannot recognize " << tasks[i][0] << " structure";
            }
        }
    }
    save_results(results_file_name);
    cout << "Press any key to continue...";
    getch();
    return 0;
}