#pragma once

#include <iostream>
#include "../TreesHandlers/AVLBinaryTree.h"

using namespace std;
class BSNode : public BaseBinaryNode {
public:
    explicit BSNode(int aisleCode, string name) : BaseBinaryNode(aisleCode){
        this->name = name;
        this->visits = 0;
        this->productAisleTreePointer = nullptr;
    }

    void setVisits(int newName);
    void setName(const string &newName);
    void BSNodeInsert(BSNode *node);
    static void inOrder(BSNode *R);
    static void fullInorder(BSNode *R);
    static bool isAisleCodeInTree(BSNode *R, int i);
    const string &getName() const;
    int getVisits() const;
    using BaseBinaryNode::getData;

    BSNode *getNodeByAisleCode(BSNode *R, int i);

    AVLBinaryTree *getProductAisleTreePointer() const;

    void setProductAisleTreePointer(AVLBinaryTree *newProductAisleTreePointer);

private:
    AVLBinaryTree *productAisleTreePointer;
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

AVLBinaryTree *BSNode::getProductAisleTreePointer() const {
    return productAisleTreePointer;
}

void BSNode::setProductAisleTreePointer(AVLBinaryTree *newProductAisleTreePointer) {
    BSNode::productAisleTreePointer = newProductAisleTreePointer;
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

BSNode *BSNode::getNodeByAisleCode(BSNode *R, int i) {
    if (R == nullptr){
        return nullptr;
    } else {
        if(R->getData()==i){
            return R;
        } else{
            if (i>R->getData()){
                return getNodeByAisleCode((BSNode*) R->getRightPointer(), i);
            } else {
                return getNodeByAisleCode((BSNode*) R->getLeftPointer(), i);
            }
        }
    }
}

void BSNode::fullInorder(BSNode *R) {
    if(R == nullptr){
        return;
    }else{
        fullInorder((BSNode*) R->getLeftPointer());
        cout<< "(" << R->getData()<< ", "<< R->getName() << ")" << " - ";
        if(R->getProductAisleTreePointer()!= nullptr){
            cout << "Second tree inorder for: " << R->getData() << endl;
            R->getProductAisleTreePointer()->inorder(R->getProductAisleTreePointer()->getAVLRoot());
            cout << "End of Second Tree Inorder" << endl;
        }
        fullInorder((BSNode*) R->getRightPointer());
    }
}
