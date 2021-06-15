#include <iostream>
#include <vector>

class AVL {

public:
    AVL();

    ~AVL();

    void insert(int data);

    void remove(int data);

    bool search(int data);

private:
    struct Node {
        int value;
        Node *left;
        Node *right;
        int height;
    };

    Node *root;

    int height(Node *N) {
        if (N == nullptr)
            return 0;
        return N->height;
    }

    Node *deleteNode(Node *root, int key) {

        if (root == nullptr)
            return root;

        if (key < root->value)
            root->left = deleteNode(root->left, key);

        else if (key > root->value)
            root->right = deleteNode(root->right, key);

        else {
            if ((root->left == nullptr) ||
                (root->right == nullptr)) {
                Node *temp = root->left ?
                             root->left :
                             root->right;
                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else
                    *root = *temp;
                free(temp);
            } else {
                Node *temp = minValueNode(root->right);
                root->value = temp->value;
                root->right = deleteNode(root->right,
                                         temp->value);
            }
        }
        if (root == nullptr)
            return root;
        root->height = 1 + max(height(root->left),
                               height(root->right));
        int balance = getBalance(root);

        if (balance > 1 &&
            getBalance(root->left) >= 0)
            return rightRotate(root);

        if (balance > 1 &&
            getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 &&
            getBalance(root->right) <= 0)
            return leftRotate(root);
        if (balance < -1 &&
            getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    Node *leftRotate(Node *x) {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left),
                        height(x->right)) + 1;
        y->height = max(height(y->left),
                        height(y->right)) + 1;

        return y;
    }

    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    Node *newNode(int key) {
        Node *node = new Node();
        node->value = key;
        node->left = nullptr;
        node->right = nullptr;
        node->height = 1;

        return (node);
    }

    Node *rightRotate(Node *y) {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left),
                        height(y->right)) + 1;
        x->height = max(height(x->left),
                        height(x->right)) + 1;

        return x;
    }

    int getBalance(Node *N) {
        if (N == nullptr)
            return 0;
        return height(N->left) - height(N->right);
    }

    Node *insertNode(Node *node, int key) {
        if (node == nullptr)
            return (newNode(key));

        if (key < node->value)
            node->left = insertNode(node->left, key);
        else if (key > node->value)
            node->right = insertNode(node->right, key);
        else
            return node;

        node->height = 1 + max(height(node->left),
                               height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && key < node->left->value)
            return rightRotate(node);

        if (balance < -1 && key > node->right->value)
            return leftRotate(node);

        if (balance > 1 && key > node->left->value) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && key < node->right->value) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node *minValueNode(Node *node) {
        Node *current = node;

        while (current->left != nullptr)
            current = current->left;

        return current;
    }


    Node *find(int data, Node *node) {
        if (node == nullptr)
            return nullptr;
        else if (data < node->value)
            return find(data, node->left);
        else if (data > node->value)
            return find(data, node->right);
        else
            return node;
    }

    Node *deleteTree(Node *node) {
        if (node == nullptr)
            return nullptr;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
        return nullptr;
    }

};
