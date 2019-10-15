/*
 * C++ Program To Implement AA Tree
 */
#pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include "../nodeTypes/AANode.h"

using namespace std;

class AATree{
public:
    explicit AATree(){root = nullptr;}

    int lookup(AANode *aaNode);
    void skew(AANode *);
    bool split(AANode *);
    void rebal(AANode *);
    AANode *insert(AANode *,AANode *);
    void print(AANode *);
    int countAANode(AANode *);
    bool isDataPresent(string data);

    AANode *getRoot() const;

    void setRoot(AANode *root);

private:
    AANode *root;
};

AANode *AATree::getRoot() const {
    return root;
}

void AATree::setRoot(AANode *root) {
    AATree::root = root;
}


/*
 * Insert String into the Tree
 */
int AATree::lookup(AANode *aaNode)
{
    aaNode = insert(root, aaNode);
    return aaNode->getCount();
}

/*
 * Skew Tree
 */

void AATree::skew(AANode *temp){
    AANode *ptr = temp->getLeft();
    if (temp->getParent()->getLeft() == temp){
        temp->getParent()->setLeft(ptr);
    }
    else {
        temp->getParent()->setRight(ptr);
    }
    ptr->setParent(temp->getParent());
    temp->setParent(ptr);
    temp->setLeft(ptr->getRight());
    if (temp->getLeft() != nullptr) {
        temp->getLeft()->setParent(temp);
    }
    ptr->setRight(temp);
    temp->setLevel(temp->getLeft() ? temp->getLeft()->getLevel() + 1 : 1);
}

/*
 * Splitting of AA Tree
 */
bool AATree::split(AANode *temp){
    AANode *ptr = temp->getRight();
    if (ptr && ptr->getRight() && (ptr->getRight()->getLevel() == temp->getLevel())){
        if (temp->getParent()->getLeft() == temp){
            temp->getParent()->setLeft(ptr);
        }
        else {
            temp->getParent()->setRight(ptr);
        }
        ptr->setParent(temp->getParent());
        temp->setParent(ptr);
        temp->setRight(ptr->getLeft());
        if (temp->getRight() != nullptr){
            temp->getRight()->setParent(temp);
        }
        ptr->setLeft(temp);
        ptr->setLevel(temp->getLevel() + 1);
        return true;
    }
    return false;
}

/*
 * Rebalancing of AA Tree
 */
void AATree::rebal(AANode* temp)
{
    temp->setLeft(nullptr);
    temp->setRight(nullptr);
    temp->setLevel(1);
    for (temp = temp->getParent(); temp != root; temp = temp->getParent()){
        if (temp->getLevel() != (temp->getLeft() ? temp->getLeft()->getLevel() + 1 : 1 )){
            skew(temp);
            if (temp->getRight() == nullptr){
                temp = temp->getParent();
            }
            else if (temp->getLevel() != temp->getRight()->getLevel()){
                temp = temp->getParent();
            }
        }
        if (temp->getParent() != root){
            if (!split(temp->getParent())) {
                break;
            }
        }
    }
}

/*
 * Insert Function to insert string into the tree
 */
AANode* AATree::insert(AANode *R, AANode *ins){
    if (root == nullptr){
        ins->setCount(1);
        root = ins;
        return root;
    }
    if (ins->getKey() < R->getKey()){
        if (R->getLeft())
            return insert(R->getLeft(), ins);
        R->setLeft(ins);
        ins->setParent(R);
        ins->setCount(1);
        rebal(ins);
        return ins;
    }
    if (ins->getKey() > R->getKey()){
        if (R->getRight())
            return insert(R->getRight(), ins);
        R->setRight(ins);
        ins->setParent(R);
        ins->setCount(1);
        rebal(ins);
        return ins;
    }
    R->setCount(R->getCount()+1);
    delete ins;
    return R;
}

/*
 * Display Tree Elements
 */
void AATree::print(AANode* temp)
{
    if (!temp)
        return;
    print(temp->getLeft());
    cout <<"Value: "<<temp->getKey() << "  Count:" << temp->getCount();
    cout<<"  Level: "<<temp->getLevel()<<endl;
    print(temp->getRight());
}

/*
 * Count number of AANodes in AA Tree
 */
int AATree::countAANode(AANode* temp)
{
    if (!temp)
        return 0;
    int count = 1;
    count = count + countAANode(temp->getLeft());
    count = count + countAANode(temp->getRight());
    return count;
}

bool AATree::isDataPresent(string data) {
    return AANode::isCodeInTree(root, data);
}
