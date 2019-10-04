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

    void setVisits(int newName);
    void setName(const string &newName);
    void BSNodeInsert(BSNode *node);
    static void inOrder(BSNode *R);
    static bool isAisleCodeInTree(BSNode *R, int i);
    const string &getName() const;
    int getVisits() const;
    using BaseBinaryNode::getData;

private:
    string name;
    int visits;
};

const string &BSNode::getName() const {
    return name;
}

void BSNode::setName(const string &newName) {
    BSNode::name = newName;
}

int BSNode::getVisits() const {
    return visits;
}

void BSNode::setVisits(int newName) {
    BSNode::visits = newName;
}

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
    if(R == nullptr){
        return;
    }else{
        inOrder((BSNode*) R->getLeftPointer());
        cout<< "(" << R->getData()<< ", "<< R->getName() << ")" << " - ";
        inOrder((BSNode*) R->getRightPointer());
    }
}

bool BSNode::isAisleCodeInTree(BSNode *R, int i){
    if (R == nullptr){
        return false;
    } else {
        if(R->getData()==i){
            return true;
        } else{
            if (i>R->getData()){
                return isAisleCodeInTree((BSNode*) R->getRightPointer(), i);
            } else {
                return isAisleCodeInTree((BSNode*) R->getLeftPointer(), i);
            }
        }
    }
}