//
// Created by sebas on 9/15/2019.
//

#pragma once

#include <string>

using namespace std;
class salesNode{
public:
    explicit salesNode(const string& aisleNode, const string& prodCode, const string& brandCode, int amountSold){
        this->aisleCode = aisleNode;
        this->prodCode = prodCode;
        this->brandCode = brandCode;
        this->amountSold = amountSold;
        this->nextNode = nullptr;
    }

    const string &getAisleCode() const {
        return aisleCode;
    }

    void setAisleCode(const string &newAisleCode) {
        salesNode::aisleCode = newAisleCode;
    }

    const string &getProdCode() const {
        return prodCode;
    }

    void setProdCode(const string &newProdCode) {
        salesNode::prodCode = newProdCode;
    }

    const string &getBrandCode() const {
        return brandCode;
    }

    void setBrandCode(const string &newBrandCode) {
        salesNode::brandCode = newBrandCode;
    }

    int getAmountSold() const {
        return amountSold;
    }

    void setAmountSold(int newAmountSold) {
        salesNode::amountSold = newAmountSold;
    }

    salesNode *getNextNode() const {
        return nextNode;
    }

    void setNextNode(salesNode *newNextNode) {
        salesNode::nextNode = newNextNode;
    }

private:
    string aisleCode;
    string prodCode;
    string brandCode;
    int amountSold;
    salesNode *nextNode;
};
