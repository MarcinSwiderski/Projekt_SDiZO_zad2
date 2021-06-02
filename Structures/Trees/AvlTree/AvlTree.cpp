////
//// Created by Marcin on 15.05.2021.
////
//
//#include "AvlTree.h"
//
//AvlTree::AvlTree() {
//    root = NULL;
//    temp = NULL;
//}
//AvlTree::~AvlTree() {
//    temp = deleteTree(root);
//    delete temp;
//
//}
//
////void AvlTree::destroy(AvlTree *pTree) {
////    pTree.~AvlTree();
////}
//
//void AvlTree::insertInAvlTree(int x) {
//    temp = insert(x, root);
//    free(temp);
//}
//
//void AvlTree::removeFromAvlTree(int x) {
//    temp = remove(x, root);
//    free(temp);
//}
//
//void AvlTree::searchFromAvlTree(int x) {
//    temp = search(x, root);
//    free(temp);
//}
//
//void AvlTree::displayAvlTree() {
//    inorder(root);
//    cout << endl;
//}