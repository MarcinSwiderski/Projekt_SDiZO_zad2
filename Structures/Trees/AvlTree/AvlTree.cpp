//
// Created by Marcin on 15.05.2021.
//

#include "AvlTree.h"

AvlTree::AvlTree() {
    root = NULL;
}
AvlTree::~AvlTree() {

}

//void AvlTree::destroy(AvlTree *pTree) {
//    pTree.~AvlTree();
//}

void AvlTree::insertInAvlTree(int x) {
    insert(x, root);
}

void AvlTree::removeFromAvlTree(int x) {
    remove(x, root);
}

void AvlTree::searchFromAvlTree(int x) {
    search(x, root);
}

void AvlTree::displayAvlTree() {
    inorder(root);
    cout << endl;
}