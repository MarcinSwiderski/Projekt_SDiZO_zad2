#include "AVLTree.h"

AVL::AVL()
{
    root = nullptr;
}

AVL::~AVL()
{
    root = deleteTree(root);
}

void AVL::insert(int data)
{
    root= insertNode(root, data);
}

void AVL::remove(int data)
{
    root=deleteNode(root, data);
}

bool AVL::search(int data)
{
    Node* v = find(data, root);

    if (v == nullptr)
        return false;
    else
        return true;
}