#pragma once

#include "../nodeTypes/BSNode.h"

class BinarySearchTree {
public:
    explicit BinarySearchTree(){root= nullptr;highestVisitedValue=lowestVisitedValue=0;}


    BSNode *getRoot() const;
    BSNode *getNodeByAisleCode(int aisleCode);
    void insert(BSNode *node);
    void inOrder();
    void fullInOrder();
    void printAisleForPurchase();
    bool isEmpty();
    bool isAisleCodeInTree(int aisleCode);
    void generateAisles(string path);
    void generateMostVisitedAisleReport(string path);
    void generateLeastVisitedAisleReport(string path);
    string getAislesForClient();


    int highestVisitedValue;
    int lowestVisitedValue;

private:
    BSNode *root;
};

void BinarySearchTree::insert(BSNode *node){
    if(isEmpty()){
        root = node;
    }else{
        root->BSNodeInsert(node);
    }
}

bool BinarySearchTree::isEmpty() {
    return root == nullptr;
}

void BinarySearchTree::inOrder() {
    BSNode::inOrder(root);
}

void BinarySearchTree::fullInOrder(){
    BSNode::fullInorder(root);
}

bool BinarySearchTree::isAisleCodeInTree(int aisleCode) {
    return root->isAisleCodeInTree(root, aisleCode);
}

BSNode *BinarySearchTree::getRoot() const {
    return root;
}

BSNode *BinarySearchTree::getNodeByAisleCode(int aisleCode) {
    return root->getNodeByAisleCode(root, aisleCode);
}

void BinarySearchTree::printAisleForPurchase() {
    BSNode::printAisleForPurchase(root);
}

void BinarySearchTree::generateMostVisitedAisleReport(string path) {
    ofstream outfile (path);
    outfile << "Most visited aisle report. " << endl;
    BSNode::getMostVisitedValue(root, highestVisitedValue);
    BSNode::generateMostVisitedAisleReport(root, highestVisitedValue, outfile);

    outfile.flags();
    outfile.close();
    cout << "Report generated successfully..." << endl;
}

void BinarySearchTree::generateLeastVisitedAisleReport(string path) {
    ofstream outfile (path);
    outfile << "Least visited aisle report. " << endl;
    lowestVisitedValue = root->getVisits();
    BSNode::getLeastVisitedValue(root, lowestVisitedValue);
    BSNode::generateLeastVisitedAisleReport(root, lowestVisitedValue, outfile);

    outfile.flags();
    outfile.close();
    cout << "Report generated successfully..." << endl;
}

void BinarySearchTree::generateAisles(string path) {
    ofstream outfile (path);
    outfile << "Aisles List. " << endl;
    BSNode::generateAisles(root, outfile);

    outfile.flags();
    outfile.close();
    cout << "Report generated successfully..." << endl;
}

string BinarySearchTree::getAislesForClient() {
    string concat;
    return BSNode::getAislesForClient(root, concat);
}
