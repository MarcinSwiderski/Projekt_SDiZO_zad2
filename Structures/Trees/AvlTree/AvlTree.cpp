//
// Created by Marcin on 15.05.2021.
//

#include "AvlTree.h"

AvlTree::AvlTree() {
    root = NULL;
}

void AvlTree::insertInAvlTree(int x) {
    root = insert(x, root);
}

void AvlTree::removeFromAvlTree(int x) {
    root = remove(x, root);
}

void AvlTree::displayAvlTree() {
    inorder(root);
    cout << endl;
}