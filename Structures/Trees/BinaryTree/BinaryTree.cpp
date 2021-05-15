//
// Created by Marcin on 15.05.2021.
//

#include "BinaryTree.h"

BinaryTree::BinaryTree(){

}
BinaryTree::~BinaryTree(){

}
void BinaryTree::insert(int key){
    if(root != NULL){
        insert(key, root);
    }else{
        root = new node;
        root->value = key;
        root->left = NULL;
        root->right = NULL;
    }
}
node* BinaryTree::search(int key){
    return search(key, root);
}
void BinaryTree::destroy_tree(){
    destroy_tree(root);
}
void BinaryTree::inorder_print(){
    inorder_print(root);
    std::cout << "\n";
}
void BinaryTree::postorder_print(){
    postorder_print(root);
    std::cout << "\n";
}
void BinaryTree::preorder_print(){
    preorder_print(root);
    std::cout << "\n";
}