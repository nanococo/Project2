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

    void setProductAisleTreePointer(AVLBinaryTree *newProductAisleTreePointer);
    void setName(const string &newName);
    void BSNodeInsert(BSNode *node);
    void setVisits(int newName);
    void incVisits();
    static void inOrder(BSNode *R);
    static void fullInorder(BSNode *R);
    static void printAisleForPurchase(BSNode *R);
    static void getMostVisitedValue(BSNode *R, int &highestValue);
    static void getLeastVisitedValue(BSNode *R, int &lowestValue);
    static void generateAisles(BSNode *R, ofstream &outfile);
    static void generateMostVisitedAisleReport(BSNode *R, int highestValue, ofstream &outfile);
    static void generateLeastVisitedAisleReport(BSNode *R, int highestValue, ofstream &outfile);
    static bool isAisleCodeInTree(BSNode *R, int i);
    const string &getName() const;
    int getVisits() const;
    using BaseBinaryNode::getData;
    BSNode *getNodeByAisleCode(BSNode *R, int i);
    AVLBinaryTree *getProductAisleTreePointer() const;



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

void BSNode::incVisits(){
    BSNode::visits++;
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
            R->getProductAisleTreePointer()->fullInorder(R->getProductAisleTreePointer()->getAVLRoot());
            cout << "End of Second Tree Inorder" << endl;
        }
        fullInorder((BSNode*) R->getRightPointer());
    }
}

void BSNode::printAisleForPurchase(BSNode *R) {
    if(R == nullptr){
        return;
    }else{
        printAisleForPurchase((BSNode*) R->getLeftPointer());
        cout << "Aisle Code: " << R->getData()<< " Name:"<< R->getName() << endl;
        printAisleForPurchase((BSNode*) R->getRightPointer());
    }
}

void BSNode::getMostVisitedValue(BSNode *R, int &highestValue) {
    if(R == nullptr){
        return;
    }else{
        getMostVisitedValue((BSNode*) R->getLeftPointer(), highestValue);

        if(R->getVisits() >= highestValue){
            highestValue = R->getVisits();
        }

        getMostVisitedValue((BSNode*) R->getRightPointer(), highestValue);
    }
}

void BSNode::getLeastVisitedValue(BSNode *R, int &lowestValue) {
    if(R == nullptr){
        return;
    }else{
        getLeastVisitedValue((BSNode*) R->getLeftPointer(), lowestValue);

        if(R->getVisits() <= lowestValue){
            lowestValue = R->getVisits();
        }

        getLeastVisitedValue((BSNode*) R->getRightPointer(), lowestValue);
    }
}

void BSNode::generateMostVisitedAisleReport(BSNode *R, int highestValue, ofstream &outfile) {
    if(R == nullptr){
        return;
    }else{
        generateMostVisitedAisleReport((BSNode*) R->getLeftPointer(), highestValue, outfile);

        if(R->getVisits() >= highestValue){
            outfile << "Aisle Code: " << R->getData() << " Aisle Name: " << R->getName() << " Visits: " << R->getVisits() << endl;
        }

        generateMostVisitedAisleReport((BSNode*) R->getRightPointer(), highestValue, outfile);
    }
}

void BSNode::generateLeastVisitedAisleReport(BSNode *R, int highestValue, ofstream &outfile) {
    if(R == nullptr){
        return;
    }else{
        generateMostVisitedAisleReport((BSNode*) R->getLeftPointer(), highestValue, outfile);

        if(R->getVisits() <= highestValue){
            outfile << "Aisle Code: " << R->getData() << " Aisle Name: " << R->getName() << " Visits: " << R->getVisits() << endl;
        }

        generateMostVisitedAisleReport((BSNode*) R->getRightPointer(), highestValue, outfile);
    }
}

void BSNode::generateAisles(BSNode *R, ofstream &outfile) {
    if(R == nullptr){
        return;
    }else{
        generateAisles((BSNode*) R->getLeftPointer(), outfile);
        outfile << "Aisle Code: " << R->getData() << " Aisle Name: " << R->getName() << " Visits: " << R->getVisits() << endl;
        generateAisles((BSNode*) R->getRightPointer(), outfile);
    }
}
