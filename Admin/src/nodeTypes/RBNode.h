#pragma once

#include "BaseBinaryNode.h"

enum Color {RED, BLACK};

using namespace std;
class RBNode : public BaseBinaryNode {
public:
    explicit RBNode(int data, string name, int amount, int price) : BaseBinaryNode (data){
        this->color = RED;
        this->parent = nullptr;
        this->name = name;
        this->amount = amount;
        this->price = price;
        this->timesSold = 0;
    }



    RBNode *getParent() const;
    RBNode *getBrandNode(RBNode *R, int i);
    void setParent(RBNode *newParent);
    void setColor(Color newColor);
    void setName(const string &newName);
    void setAmount(int newAmount);
    void setPrice(int newPrice);
    void setTimesSold(int newTimesSold);
    void generateBrand(RBNode *R, ofstream &outfile);
    bool getColor() const;
    bool isBrandCodeOnList(RBNode *R, int i);
    const string &getName() const;
    int getAmount() const;
    int getPrice() const;
    int getTimesSold() const;

    using BaseBinaryNode::getLeftPointer;
    using BaseBinaryNode::getRightPointer;
    using BaseBinaryNode::setRightPointer;
    using BaseBinaryNode::setLeftPointer;
    using BaseBinaryNode::getData;

    bool color;

private:
    string name;
    int amount;
    int price;
    int timesSold;
    RBNode *parent;
};

bool RBNode::getColor() const {
    return color;
}

void RBNode::setColor(Color newColor) {
    RBNode::color = newColor;
}

RBNode *RBNode::getParent() const {
    return parent;
}

void RBNode::setParent(RBNode *newParent) {
    RBNode::parent = newParent;
}

const string &RBNode::getName() const {
    return name;
}

void RBNode::setName(const string &newName) {
    RBNode::name = newName;
}

int RBNode::getAmount() const {
    return amount;
}

void RBNode::setAmount(int newAmount) {
    RBNode::amount = newAmount;
}

int RBNode::getPrice() const {
    return price;
}

void RBNode::setPrice(int newPrice) {
    RBNode::price = newPrice;
}

int RBNode::getTimesSold() const {
    return timesSold;
}

void RBNode::setTimesSold(int newTimesSold) {
    RBNode::timesSold = newTimesSold;
}

bool RBNode::isBrandCodeOnList(RBNode *R, int i) {
    if (R == nullptr){
        return false;
    } else {
        if(R->getData()==i){
            return true;
        } else{
            if (i>R->getData()){
                return isBrandCodeOnList((RBNode*) R->getRightPointer(), i);
            } else {
                return isBrandCodeOnList((RBNode*) R->getLeftPointer(), i);
            }
        }
    }
}

RBNode *RBNode::getBrandNode(RBNode *R, int i){
    if (R == nullptr){
        return R;
    } else {
        if(R->getData()==i){
            return R;
        } else{
            if (i>R->getData()){
                return getBrandNode((RBNode*) R->getRightPointer(), i);
            } else {
                return getBrandNode((RBNode*) R->getLeftPointer(), i);
            }
        }
    }
}

void RBNode::generateBrand(RBNode *R, ofstream &outfile) {
    if (R == nullptr)
        return;

    generateBrand((RBNode*) R->getLeftPointer(), outfile);
    outfile << "Brand Code: " << R->getData() << ", Brand Name: " << R->getName() << endl;
    generateBrand((RBNode*) R->getRightPointer(), outfile);
}
