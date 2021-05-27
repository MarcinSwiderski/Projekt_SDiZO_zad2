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

    void search(int key);

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

    node* deleteNode(node* root, int k)
    {
        // Base case
        if (root == NULL)
            return root;

        // Recursive calls for ancestors of
        // node to be deleted
        if (root->value > k) {
            root->left = deleteNode(root->left, k);
            return root;
        }
        else if (root->value < k) {
            root->right = deleteNode(root->right, k);
            return root;
        }

        // We reach here when root is the node
        // to be deleted.

        // If one of the children is empty
        if (root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }

            // If both children exist
        else {

            node* succParent = root;

            // Find successor
            node* succ = root->right;
            while (succ->left != NULL) {
                succParent = succ;
                succ = succ->left;
            }

            // Delete successor.  Since successor
            // is always left child of its parent
            // we can safely make successor's right
            // right child as left of its parent.
            // If there is no succ, then assign
            // succ->right to succParent->right
            if (succParent != root)
                succParent->left = succ->right;
            else
                succParent->right = succ->right;

            // Copy Successor Data to root
            root->value = succ->value;

            // Delete Successor and return root
            delete succ;
            return root;
        }
    }

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
