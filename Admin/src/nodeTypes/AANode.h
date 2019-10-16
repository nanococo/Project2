#pragma once

#include <string>
#include <utility>
#include "BaseBinaryNode.h"

using namespace std;
class AANode {
public:
    explicit AANode(string key, int aisleCode, int prodCode, int brandCode, int stockAmount, bool isBasicProd, const string& name){
        this->key = std::move(key);
        this->aisleCode = aisleCode;
        this->prodCode = prodCode;
        this->brandCode = brandCode;
        this->stockAmount = stockAmount;
        this->isBasicProd = isBasicProd;
        this->name = name;
        this->count = 0;
        this->level = 1;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;

    }

    int getCount() const;

    void setCount(int count);

    int getLevel() const;

    void setLevel(int level);

    string getKey() const;

    void setKey(int key);

    int getProdCode() const;

    void setProdCode(int prodCode);

    int getBrandCode() const;

    void setBrandCode(int brandCode);

    int getStockAmount() const;

    void setStockAmount(int stockAmount);

    bool getIsBasicProd() const;

    void setIsBasicProd(bool isBasicProd);

    const string &getName() const;

    void setName(const string &name);

    AANode *getRight() const;

    void setRight(AANode *right);

    AANode *getLeft() const;

    void setLeft(AANode *left);

    AANode *getParent() const;

    void setParent(AANode *parent);

    static bool isCodeInTree(AANode *R, string i);

    void setKey(const string &key);

    static AANode *getNodeByAisleProdBrandCodeHelper(AANode *R, string i);
    static bool isBasicProductHelper(AANode *R, string i);


private:
    int count, level;
    string key;
    int aisleCode;
    int prodCode;
    int brandCode;
    int stockAmount;
    bool isBasicProd;
    string name;
    AANode *right;
    AANode *left;
    AANode *parent;
};

void AANode::setKey(const string &key) {
    AANode::key = key;
}

int AANode::getCount() const {
    return count;
}

void AANode::setCount(int count) {
    AANode::count = count;
}

int AANode::getLevel() const {
    return level;
}

void AANode::setLevel(int level) {
    AANode::level = level;
}

string AANode::getKey() const {
    return key;
}

void AANode::setKey(int key) {
    AANode::key = key;
}

int AANode::getProdCode() const {
    return prodCode;
}

void AANode::setProdCode(int prodCode) {
    AANode::prodCode = prodCode;
}

int AANode::getBrandCode() const {
    return brandCode;
}

void AANode::setBrandCode(int brandCode) {
    AANode::brandCode = brandCode;
}

int AANode::getStockAmount() const {
    return stockAmount;
}

void AANode::setStockAmount(int stockAmount) {
    AANode::stockAmount = stockAmount;
}

bool AANode::getIsBasicProd() const {
    return isBasicProd;
}

void AANode::setIsBasicProd(bool isBasicProd) {
    AANode::isBasicProd = isBasicProd;
}

const string &AANode::getName() const {
    return name;
}

void AANode::setName(const string &name) {
    AANode::name = name;
}

AANode *AANode::getRight() const {
    return right;
}

void AANode::setRight(AANode *right) {
    AANode::right = right;
}

AANode *AANode::getLeft() const {
    return left;
}

void AANode::setLeft(AANode *left) {
    AANode::left = left;
}

AANode *AANode::getParent() const {
    return parent;
}

void AANode::setParent(AANode *parent) {
    AANode::parent = parent;
}

bool AANode::isCodeInTree(AANode *R, string i) {
    if (R == nullptr){
        return false;
    } else {
        if(R->getKey()==i){
            return true;
        } else{
            if (i>R->getKey()){
                return isCodeInTree(R->getRight(), i);
            } else {
                return isCodeInTree(R->getLeft(), i);
            }
        }
    }
}

AANode *AANode::getNodeByAisleProdBrandCodeHelper(AANode *R, string i){
    if (R == nullptr){
        return R;
    } else {
        if(R->getKey()==i){
            return R;
        } else{
            if (i>R->getKey()){
                return getNodeByAisleProdBrandCodeHelper(R->getRight(), i);
            } else {
                return getNodeByAisleProdBrandCodeHelper(R->getLeft(), i);
            }
        }
    }
}

bool AANode::isBasicProductHelper(AANode *R, string i) {
    return getNodeByAisleProdBrandCodeHelper(R, i)->getIsBasicProd();
}

