#include <iostream>
#include "src/helpers/helpers.h"

int main() {
    BinarySearchTree aisles;
    initAisleTree(aisles);
    initAislesProductTree(aisles);
    aisles.fullInOrder();

    if(aisles.getNodeByAisleCode(1)->getProductAisleTreePointer()!= nullptr){
        cout << aisles.getNodeByAisleCode(1)->getProductAisleTreePointer()->getAVLRoot()->getData() << endl;
    }

//    aisles.insert(new BSNode(1, "Hola"));
//    aisles.insert(new BSNode(2, "Hola"));
//    aisles.insert(new BSNode(3, "Hola"));
//    aisles.insert(new BSNode(4, "Hola"));
//
//    aisles.inOrder();
//    AVLBinaryTree AVLNode;
//    AVLNode.setAVLRoot(AVLNode.insert(AVLNode.getAVLRoot(), 5));
//    AVLNode.setAVLRoot(AVLNode.insert(AVLNode.getAVLRoot(), 4));
//    AVLNode.setAVLRoot(AVLNode.insert(AVLNode.getAVLRoot(), 3));
//    AVLNode.inorder(AVLNode.getAVLRoot());

    return 0;
}