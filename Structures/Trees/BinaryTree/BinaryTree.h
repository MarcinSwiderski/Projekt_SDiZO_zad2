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

    void deleteElement(int key);

    void destroy_tree();

    void inorder_print();

    void postorder_print();

    void preorder_print();

private:
    struct node* minValueNode(struct node* node)
    {
        struct node* current = node;

        /* loop down to find the leftmost leaf */
        while (current && current->left != NULL)
            current = current->left;

        return current;
    }

//    struct node* deleteNode(struct node* root, int key)
//    {
//        // base case
//        if (root == NULL)
//            return root;
//
//        // If the value to be deleted is
//        // smaller than the root's
//        // value, then it lies in left subtree
//        if (key < root->value)
//            root->left = deleteNode(root->left, key);
//
//            // If the value to be deleted is
//            // greater than the root's
//            // value, then it lies in right subtree
//        else if (key > root->value)
//            root->right = deleteNode(root->right, key);
//
//            // if value is same as root's value, then This is the node
//            // to be deleted
//        else {
//            // node has no child
//            if (root->left==nullptr and root->right==nullptr) {
//                return nullptr;
//            }
//            // node with only one child or no child
//            else if (root->left == nullptr) {
//                struct node* temp = root->right;
//                free(root);
//                return temp;
//            }
//            else if (root->right == nullptr) {
//                struct node* temp = root->left;
//                free(root);
//                return temp;
//            }
//
//            // node with two children: Get the inorder successor
//            // (smallest in the right subtree)
//            struct node *temp;
//            temp = minValueNode(root->right);
//
//            // Copy the inorder successor's content to this node
//            root->value = temp->value;
//
//            // Delete the inorder successor
//            root->right = deleteNode(root->right, temp->value);
//        }
//        return root;
//    }

    void destroy_tree(node *leaf) {
        if (leaf != NULL) {
            destroy_tree(leaf->left);
            destroy_tree(leaf->right);
            delete leaf;
        }
    }

    //cos zle
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
