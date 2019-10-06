#pragma once

#include <string>
#include "BaseBinaryNode.h"

using namespace std;
class AVLNode : public BaseBinaryNode {
public:
    explicit AVLNode(int prodCode, string name) : BaseBinaryNode(prodCode){
        this->name = name;
        this->timesSold = 0;
    }
    using BaseBinaryNode::getLeftPointer;
    using BaseBinaryNode::getRightPointer;
    using BaseBinaryNode::setRightPointer;
    using BaseBinaryNode::setLeftPointer;
    using BaseBinaryNode::getData;

    bool isProdCodeInTree(AVLNode *R, int prodCode);
    int getTimesSold() const;
    const string &getName() const;
    void setName(const string &newName);
    void setTimesSold(int newTimesSold);



private:
    string name;
    int timesSold;
};

const string &AVLNode::getName() const {
    return name;
}

void AVLNode::setName(const string &newName) {
    AVLNode::name = newName;
}

int AVLNode::getTimesSold() const {
    return timesSold;
}

void AVLNode::setTimesSold(int newTimesSold) {
    AVLNode::timesSold = newTimesSold;
}

bool AVLNode::isProdCodeInTree(AVLNode *R, int i) {
    if (R == nullptr){
        return false;
    } else {
        if(R->getData()==i){
            return true;
        } else{
            if (i>R->getData()){
                return isProdCodeInTree((AVLNode*) R->getRightPointer(), i);
            } else {
                return isProdCodeInTree((AVLNode*) R->getLeftPointer(), i);
            }
        }
    }
}
