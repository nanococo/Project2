#pragma once

#include "../nodeTypes/BaseBinaryNode.h"
#include "../nodeTypes/BSNode.h"

class BinarySearchTree {
public:
    explicit BinarySearchTree(){root=aux=nullptr;}

    void insert(BSNode *node);
    bool isEmpty();
    void inOrder();
private:
    BSNode *root;
    BSNode *aux;
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

