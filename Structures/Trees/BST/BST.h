#include<iostream>

using namespace std;

class BST {

    struct node {
        int data;
        node *left;
        node *right;
        ~node(){
            delete left;
            delete right;
        }
    };

    node *root;
    node *temp;

    node *deleteTree(node *node) {
        if (node == NULL)
            return NULL;

        deleteTree(node->left);
        deleteTree(node->right);
        return NULL;
    }

    node *insert(int x, node *t) {
        if (t == NULL) {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        } else if (x < t->data)
            t->left = insert(x, t->left);
        else if (x > t->data)
            t->right = insert(x, t->right);
        return t;
    }

    node *findMin(node *t) {
        if (t == NULL)
            return NULL;
        else if (t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node *findMax(node *t) {
        if (t == NULL)
            return NULL;
        else if (t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    node *remove(int x, node *t) {
        node *tempx;
        if (t == NULL)
            return NULL;
        else if (x < t->data)
            t->left = remove(x, t->left);
        else if (x > t->data)
            t->right = remove(x, t->right);
        else if (t->left && t->right) {
            tempx = findMin(t->right);
            t->data = tempx->data;
            t->right = remove(t->data, t->right);
        } else {
            tempx = t;
            if (t->left == NULL)
                t = t->right;
            else if (t->right == NULL)
                t = t->left;
        }
        delete tempx;

        return t;
    }

    node *find(node *t, int x) {
        if (t == NULL)
            return NULL;
        else if (x < t->data)
            return find(t->left, x);
        else if (x > t->data)
            return find(t->right, x);
        else
            return t;
    }

public:
    BST() {
        root = NULL;
        temp = NULL;
    }

    ~BST() {
        temp = deleteTree(root);
        free(temp);
        delete root;
        delete temp;
    }

    void insert(int x) {
        temp = insert(x, root);
        free(temp);

    }

    void remove(int x) {
        temp = remove(x, root);
        free(temp);

    }

    void search(int x) {
        temp = find(root, x);
        free(temp);
    }
};