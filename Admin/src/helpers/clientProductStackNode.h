//
// Created by sebas on 9/11/2019.
//

#pragma once

#include <string>

using namespace std;
class clientProductStackNode{
public:
    clientProductStackNode(const string &aisleCode, const string &prodCode, const string &brandCode, int amount){
        this->aisleCode = aisleCode;
        this->prodCode = prodCode;
        this->brandCode = brandCode;
        this->amount = amount;
        this->nextNode = nullptr;
    }

    const string &getAisleCode() const;

    void setAisleCode(const string &newAisleCode);

    const string &getProdCode() const;

    void setProdCode(const string &newProdCode);

    const string &getBrandCode() const;

    void setBrandCode(const string &newBrandCode);

    int getAmount() const;

    void setAmount(int newAmount);

    clientProductStackNode *getNextNode() const;

    void setNextNode(clientProductStackNode *newNextNode);

private:
    string aisleCode;
    string prodCode;
    string brandCode;
    int amount;

    clientProductStackNode *nextNode;
};

const string &clientProductStackNode::getAisleCode() const {
    return aisleCode;
}

void clientProductStackNode::setAisleCode(const string &newAisleCode) {
    clientProductStackNode::aisleCode = newAisleCode;
}

const string &clientProductStackNode::getProdCode() const {
    return prodCode;
}

void clientProductStackNode::setProdCode(const string &newProdCode) {
    clientProductStackNode::prodCode = newProdCode;
}

const string &clientProductStackNode::getBrandCode() const {
    return brandCode;
}

void clientProductStackNode::setBrandCode(const string &newBrandCode) {
    clientProductStackNode::brandCode = newBrandCode;
}

int clientProductStackNode::getAmount() const {
    return amount;
}

void clientProductStackNode::setAmount(int newAmount) {
    clientProductStackNode::amount = newAmount;
}

clientProductStackNode *clientProductStackNode::getNextNode() const {
    return nextNode;
}

void clientProductStackNode::setNextNode(clientProductStackNode *newNextNode) {
    clientProductStackNode::nextNode = newNextNode;
}
