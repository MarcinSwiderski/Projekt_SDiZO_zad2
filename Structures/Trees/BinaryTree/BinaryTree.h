//
// Created by Marcin on 15.05.2021.
//

#ifndef UNTITLED_BINARYTREE_H
#define UNTITLED_BINARYTREE_H
#include <iostream>

using namespace std;

struct node{
    int value;
    node *left;
    node *right;
};

class BinaryTree{
public:
    BinaryTree();
    ~BinaryTree();

    void insert(int key);
    node *search(int key);
    void destroy_tree();
    void inorder_print();
    void postorder_print();
    void preorder_print();

private:
    void destroy_tree(node *leaf);
    void insert(int key, node *leaf);
    node *search(int key, node *leaf);
    void inorder_print(node *leaf);
    void postorder_print(node *leaf);
    void preorder_print(node *leaf);

    node *root;
};

#endif //UNTITLED_BINARYTREE_H
