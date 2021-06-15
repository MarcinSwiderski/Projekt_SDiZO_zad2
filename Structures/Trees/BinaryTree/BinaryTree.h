#include <iostream>

using namespace std;

class BTreeNode {
    int *value;
    int degree;
    BTreeNode **C;
    int n;
    bool leaf;

public:
    BTreeNode(int _t, bool _leaf);
    ~BTreeNode();

    void deleteTree();

    int findKey(int k);

    void insertNonFull(int k);

    void splitChild(int i, BTreeNode *y);

    void deletion(int k);

    void removeFromLeaf(int index);

    void removeFromNonLeaf(int index);

    int getPredecessor(int idx);

    int getSuccessor(int idx);

    void fill(int index);

    void borrowFromPrev(int index);

    void borrowFromNext(int index);

    void merge(int index);

    friend class BinaryTree;
};

class BinaryTree {
    BTreeNode *root;
    int t;

public:
    BinaryTree(int _t) {
        root = NULL;
        t = _t;
    }

    void insertion(int k);

    void deletion(int k);

    ~BinaryTree() {
        root->deleteTree();
    }
};

BTreeNode::BTreeNode(int t1, bool leaf1) {
    degree = t1;
    leaf = leaf1;

    value = new int[2 * degree - 1];
    C = new BTreeNode *[2 * degree];

    n = 0;
}
BTreeNode::~BTreeNode(){
    delete value;
    delete C;
}

int BTreeNode::findKey(int k) {
    int index = 0;
    while (index < n && value[index] < k)
        ++index;
    return index;
}

void BTreeNode::deletion(int k) {
    int index = findKey(k);

    if (index < n && value[index] == k) {
        if (leaf)
            removeFromLeaf(index);
        else
            removeFromNonLeaf(index);
    } else {
        if (leaf)
            return;

        bool flag = ((index == n) ? true : false);

        if (C[index]->n < degree)
            fill(index);

        if (flag && index > n)
            C[index - 1]->deletion(k);
        else
            C[index]->deletion(k);
    }
    return;
}

void BTreeNode::removeFromLeaf(int index) {
    for (int i = index + 1; i < n; ++i)
        value[i - 1] = value[i];

    n--;

    return;
}

void BTreeNode::removeFromNonLeaf(int index) {
    int k = value[index];

    if (C[index]->n >= degree) {
        int predecessor = getPredecessor(index);
        value[index] = predecessor;
        C[index]->deletion(predecessor);
    } else if (C[index + 1]->n >= degree) {
        int successor = getSuccessor(index);
        value[index] = successor;
        C[index + 1]->deletion(successor);
    } else {
        merge(index);
        C[index]->deletion(k);
    }
    return;
}

int BTreeNode::getPredecessor(int idx) {
    BTreeNode *current = C[idx];
    while (!current->leaf)
        current = current->C[current->n];

    return current->value[current->n - 1];
}

int BTreeNode::getSuccessor(int idx) {
    BTreeNode *current = C[idx + 1];
    while (!current->leaf)
        current = current->C[0];

    return current->value[0];
}

void BTreeNode::fill(int index) {
    if (index != 0 && C[index - 1]->n >= degree)
        borrowFromPrev(index);

    else if (index != n && C[index + 1]->n >= degree)
        borrowFromNext(index);

    else {
        if (index != n)
            merge(index);
        else
            merge(index - 1);
    }
    return;
}

void BTreeNode::borrowFromPrev(int index) {
    BTreeNode *child = C[index];
    BTreeNode *sibling = C[index - 1];

    for (int i = child->n - 1; i >= 0; --i)
        child->value[i + 1] = child->value[i];

    if (!child->leaf) {
        for (int i = child->n; i >= 0; --i)
            child->C[i + 1] = child->C[i];
    }

    child->value[0] = value[index - 1];

    if (!child->leaf)
        child->C[0] = sibling->C[sibling->n];

    value[index - 1] = sibling->value[sibling->n - 1];

    child->n += 1;
    sibling->n -= 1;

    return;
}

void BTreeNode::borrowFromNext(int index) {
    BTreeNode *child = C[index];
    BTreeNode *sibling = C[index + 1];

    child->value[(child->n)] = value[index];

    if (!(child->leaf))
        child->C[(child->n) + 1] = sibling->C[0];

    value[index] = sibling->value[0];

    for (int i = 1; i < sibling->n; ++i)
        sibling->value[i - 1] = sibling->value[i];

    if (!sibling->leaf) {
        for (int i = 1; i <= sibling->n; ++i)
            sibling->C[i - 1] = sibling->C[i];
    }

    child->n += 1;
    sibling->n -= 1;

    return;
}

void BTreeNode::merge(int index) {
    BTreeNode *child = C[index];
    BTreeNode *sibling = C[index + 1];

    child->value[degree - 1] = value[index];

    for (int i = 0; i < sibling->n; ++i)
        child->value[i + degree] = sibling->value[i];

    if (!child->leaf) {
        for (int i = 0; i <= sibling->n; ++i)
            child->C[i + degree] = sibling->C[i];
    }

    for (int i = index + 1; i < n; ++i)
        value[i - 1] = value[i];

    for (int i = index + 2; i <= n; ++i)
        C[i - 1] = C[i];

    child->n += sibling->n + 1;
    n--;

    delete (sibling);
    return;
}

void BinaryTree::insertion(int k) {
    if (root == NULL) {
        root = new BTreeNode(t, true);
        root->value[0] = k;
        root->n = 1;
    } else {
        if (root->n == 2 * t - 1) {
            BTreeNode *s = new BTreeNode(t, false);

            s->C[0] = root;

            s->splitChild(0, root);

            int i = 0;
            if (s->value[0] < k)
                i++;
            s->C[i]->insertNonFull(k);

            root = s;
        } else
            root->insertNonFull(k);
    }
}

void BTreeNode::insertNonFull(int k) {
    int i = n - 1;

    if (leaf == true) {
        while (i >= 0 && value[i] > k) {
            value[i + 1] = value[i];
            i--;
        }

        value[i + 1] = k;
        n = n + 1;
    } else {
        while (i >= 0 && value[i] > k)
            i--;

        if (C[i + 1]->n == 2 * degree - 1) {
            splitChild(i + 1, C[i + 1]);

            if (value[i + 1] < k)
                i++;
        }
        C[i + 1]->insertNonFull(k);
    }
}

void BTreeNode::splitChild(int i, BTreeNode *y) {
    BTreeNode *z = new BTreeNode(y->degree, y->leaf);
    z->n = degree - 1;

    for (int j = 0; j < degree - 1; j++)
        z->value[j] = y->value[j + degree];

    if (y->leaf == false) {
        for (int j = 0; j < degree; j++)
            z->C[j] = y->C[j + degree];
    }

    y->n = degree - 1;

    for (int j = n; j >= i + 1; j--)
        C[j + 1] = C[j];

    C[i + 1] = z;

    for (int j = n - 1; j >= i; j--)
        value[j + 1] = value[j];

    value[i] = y->value[degree - 1];

    n = n + 1;
}

void BTreeNode::deleteTree() {
    int i;
    for (i = 0; i < n; i++) {
        if (leaf == false)
            C[i]->deleteTree();
    }
    if (leaf == false)
        C[i]->deleteTree();
    delete this;
}

void BinaryTree::deletion(int k) {
    if (!root) {
        return;
    }
    root->deletion(k);

    if (root->n == 0) {
        BTreeNode *tmp = root;
        if (root->leaf)
            root = NULL;
        else
            root = root->C[0];
        delete tmp;
    }
    return;
}