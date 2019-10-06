#pragma once

#include "../nodeTypes/BSNode.h"

class BinarySearchTree {
public:
    explicit BinarySearchTree(){root= nullptr;}


    BSNode *getRoot() const;
    BSNode *getNodeByAisleCode(int aisleCode);
    void insert(BSNode *node);
    void inOrder();
    void fullInOrder();
    bool isEmpty();
    bool isAisleCodeInTree(int aisleCode);




private:
    BSNode *root;
};

void BinarySearchTree::insert(BSNode *node){
    if(isEmpty()){
        root = node;
    }else{
        root->BSNodeInsert(node);
    }
}

bool BinarySearchTree::isEmpty() {
    return root == nullptr;
}

void BinarySearchTree::inOrder() {
    BSNode::inOrder(root);
}

void BinarySearchTree::fullInOrder(){
    BSNode::fullInorder(root);
}

bool BinarySearchTree::isAisleCodeInTree(int aisleCode) {
    return root->isAisleCodeInTree(root, aisleCode);
}

BSNode *BinarySearchTree::getRoot() const {
    return root;
}

BSNode *BinarySearchTree::getNodeByAisleCode(int aisleCode) {
    return root->getNodeByAisleCode(root, aisleCode);
}
