#pragma once

#include <iostream>
#include "BaseBinaryNode.h"
using namespace std;
class BSNode : BaseBinaryNode {
public:
    explicit BSNode(int num, string name) : BaseBinaryNode(num){
        this->name = name;
        this->visits = 0;
    }

    void BSNodeInsert(int num);
    void BSNodeInsert(BSNode *node);
    static void inOrder(BSNode *R);

private:
    string name;
    int visits;
};

void BSNode::BSNodeInsert(BSNode *node) {
    if(node->getData()<getData()){
        if(getLeftPointer() == nullptr){
            setLeftPointer(node);
        }else{
            ((BSNode*) getLeftPointer())->BSNodeInsert(node);
        }
    }else{
        if(getRightPointer() == nullptr){
            setRightPointer(node);
        }else{
            ((BSNode*) getRightPointer())->BSNodeInsert(node);
        }
    }
}

void BSNode::inOrder(BSNode *R){
    if(R== nullptr){
        return;
    }else{
        inOrder((BSNode*) R->getLeftPointer());
        cout<<R->getData()<<" - ";
        inOrder((BSNode*) R->getRightPointer());
    }
}
