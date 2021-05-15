//
// Created by Marcin on 15.05.2021.
//

#ifndef UNTITLED_BINARYTREE_H
#define UNTITLED_BINARYTREE_H

#include <cstddef>
#include <iostream>

struct node {
    int value;
    node *left;
    node *right;
};

class BinaryTree {
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
    void destroy_tree(node *leaf) {
        if (leaf != NULL) {
            destroy_tree(leaf->left);
            destroy_tree(leaf->right);
            delete leaf;
        }
    }

    void insert(int key, node *leaf) {

        if (key < leaf->value) {
            if (leaf->left != NULL) {
                insert(key, leaf->left);
            } else {
                leaf->left = new node;
                leaf->left->value = key;
                leaf->left->left = NULL;
                leaf->left->right = NULL;
            }
        } else if (key >= leaf->value) {
            if (leaf->right != NULL) {
                insert(key, leaf->right);
            } else {
                leaf->right = new node;
                leaf->right->value = key;
                leaf->right->right = NULL;
                leaf->right->left = NULL;
            }
        }

    }

    node *search(int key, node *leaf) {
        if (leaf != NULL) {
            if (key == leaf->value) {
                return leaf;
            }
            if (key < leaf->value) {
                return search(key, leaf->left);
            } else {
                return search(key, leaf->right);
            }
        } else {
            return NULL;
        }
    }

    void inorder_print(node *leaf) {
        if (leaf != NULL) {
            inorder_print(leaf->left);
            std::cout << leaf->value << ",";
            inorder_print(leaf->right);
        }
    }

    void postorder_print(node *leaf) {
        if (leaf != NULL) {
            inorder_print(leaf->left);
            inorder_print(leaf->right);
            std::cout << leaf->value << ",";
        }
    }

    void preorder_print(node *leaf) {
        if (leaf != NULL) {
            std::cout << leaf->value << ",";
            inorder_print(leaf->left);
            inorder_print(leaf->right);
        }
    }

    node *root;
};


#endif //UNTITLED_BINARYTREE_H
