#pragma once

#include <string>
#include "BaseBinaryNode.h"
#include "../TreesHandlers/RBTree.h"

using namespace std;
class AVLNode : public BaseBinaryNode {
public:
    explicit AVLNode(int prodCode, string name) : BaseBinaryNode(prodCode){
        this->name = name;
        this->timesSold = 0;
        this->productAisleBrandTreePointer = nullptr;
    }
    using BaseBinaryNode::getLeftPointer;
    using BaseBinaryNode::getRightPointer;
    using BaseBinaryNode::setRightPointer;
    using BaseBinaryNode::setLeftPointer;
    using BaseBinaryNode::getData;

    bool isProdCodeInTree(AVLNode *R, int prodCode);
    int getTimesSold() const;
    const string &getName() const;
    static void getMostBoughtValue(AVLNode *R, int &highestValue);
    static void generateMostBoughtProd(AVLNode *R, int highestValue, ofstream &outfile);
    static void generateProductsList(AVLNode *R, ofstream &outfile);
    void setName(const string &newName);
    void setTimesSold(int newTimesSold);
    AVLNode *getNodeByProdCode(AVLNode *R, int i);

    RBTree *getProductAisleBrandTreePointer() const;

    void setProductAisleBrandTreePointer(RBTree *newProductAisleBrandTreePointer);


private:
    string name;
    int timesSold;
    RBTree *productAisleBrandTreePointer;

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

RBTree *AVLNode::getProductAisleBrandTreePointer() const {
    return productAisleBrandTreePointer;
}

void AVLNode::setProductAisleBrandTreePointer(RBTree *newProductAisleBrandTreePointer) {
    AVLNode::productAisleBrandTreePointer = newProductAisleBrandTreePointer;
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

AVLNode *AVLNode::getNodeByProdCode(AVLNode *R, int i){
    if (R == nullptr){
        return R;
    } else {
        if(R->getData()==i){
            return R;
        } else{
            if (i>R->getData()){
                return getNodeByProdCode((AVLNode*) R->getRightPointer(), i);
            } else {
                return getNodeByProdCode((AVLNode*) R->getLeftPointer(), i);
            }
        }
    }
}

void AVLNode::getMostBoughtValue(AVLNode *R, int &highestValue){
    if(R == nullptr){
        return;
    }else{
        getMostBoughtValue((AVLNode*) R->getLeftPointer(), highestValue);

        if(R->getTimesSold() >= highestValue){
            highestValue = R->getTimesSold();
        }

        getMostBoughtValue((AVLNode*) R->getRightPointer(), highestValue);
    }
}

void AVLNode::generateMostBoughtProd(AVLNode *R, int highestValue, ofstream &outfile){
    if(R == nullptr){
        return;
    }else{
        generateMostBoughtProd((AVLNode*) R->getLeftPointer(), highestValue, outfile);

        if(R->getTimesSold() <= highestValue){
            outfile << "Prod Code: " << R->getData() << " Prod Name: " << R->getName() << " Times bought: " << R->getTimesSold() << endl;
        }

        generateMostBoughtProd((AVLNode*) R->getRightPointer(), highestValue, outfile);
    }
}

void AVLNode::generateProductsList(AVLNode *R, ofstream &outfile) {
    if(R == nullptr){
        return;
    }else{
        generateProductsList((AVLNode*) R->getLeftPointer(), outfile);
        outfile << "Prod Code: " << R->getData() << " Prod Name: " << R->getName() << " Times bought: " << R->getTimesSold() << endl;
        generateProductsList((AVLNode*) R->getRightPointer(), outfile);
    }
}
