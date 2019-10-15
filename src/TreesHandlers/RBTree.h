#pragma once

#include "../nodeTypes/RBNode.h"
#include <bits/stdc++.h>
using namespace std;

// Class to represent Red-Black Tree
class RBTree{
private:
    RBNode *root;
protected:
    void rotateLeft(RBNode *&R, RBNode *&);
    void rotateRight(RBNode *&R, RBNode *&);
    void fixViolation(RBNode *&R, RBNode *&);
public:
    // Constructor
    RBTree() { root = nullptr; }
    void insert(const int &n, string name, int amount, int price);
    void inorder();
    void levelOrder();
    bool isBrandCodeOnList(int brandCode);
};

// A recursive function to do level order traversal
void inorderHelper(RBNode *root){
    if (root == nullptr)
        return;

    inorderHelper((RBNode*) root->getLeftPointer());
    cout << "(" <<root->getData() << ", " << root->getName()  << ", " << root->getAmount() << ", "  << root->getPrice() << ", " << root->getTimesSold() << " ) -";
    inorderHelper((RBNode*) root->getRightPointer());
}

/* A utility function to insert a new node with given key
in BST */
RBNode* BSTInsert(RBNode* root, RBNode *pt){
    /* If the tree is empty, return a new node */
    if (root == nullptr)
        return pt;

    /* Otherwise, recur down the tree */
    if (pt->getData() < root->getData())
    {
        root->setLeftPointer(BSTInsert((RBNode*) root->getLeftPointer(), pt));
        ((RBNode*) root->getLeftPointer())->setParent(root);
    }
    else if (pt->getData() > root->getData())
    {
        root->setRightPointer(BSTInsert((RBNode*) root->getRightPointer(), pt));
        ((RBNode*) root->getRightPointer())->setParent(root);
    }

    /* return the (unchanged) node pointer */
    return root;
}

// Utility function to do level order traversal
void levelOrderHelper(RBNode *root){
    if (root == nullptr)
        return;

    std::queue<RBNode *> q;
    q.push(root);

    while (!q.empty())
    {
        RBNode *temp = q.front();
        cout << temp->getData() << " ";
        q.pop();

        if (temp->getLeftPointer() != nullptr)
            q.push((RBNode*) temp->getLeftPointer());

        if (temp->getRightPointer() != nullptr)
            q.push((RBNode*) temp->getRightPointer());
    }
}

void RBTree::rotateLeft(RBNode *&R, RBNode *&pt)
{
    auto *pt_right = (RBNode*) pt->getRightPointer();

    pt->setRightPointer(pt_right->getLeftPointer());

    if (pt->getRightPointer() != nullptr)
        ((RBNode*) pt->getRightPointer())->setParent(pt);

    pt_right->setParent(pt->getParent());

    if (pt->getParent() == nullptr)
        R = pt_right;

    else if (pt == (RBNode*) pt->getParent()->getLeftPointer())
        pt->getParent()->setLeftPointer(pt_right);

    else
        pt->getParent()->setRightPointer(pt_right);

    pt_right->setLeftPointer(pt);
    pt->setParent(pt_right);
}

void RBTree::rotateRight(RBNode *&R, RBNode *&pt)
{
    auto *pt_left = (RBNode*) pt->getLeftPointer();

    pt->setLeftPointer(pt_left->getRightPointer());

    if (pt->getLeftPointer() != nullptr)
        ((RBNode*) pt->getLeftPointer())->setParent(pt);

    pt_left->setParent(pt->getParent());

    if (pt->getParent() == nullptr)
        R = pt_left;

    else if (pt == (RBNode*) pt->getParent()->getLeftPointer())
        pt->getParent()->setLeftPointer(pt_left);

    else
        pt->getParent()->setRightPointer(pt_left);

    pt_left->setRightPointer(pt);
    pt->setParent(pt_left);
}

// This function fixes violations caused by BST insertion
void RBTree::fixViolation(RBNode *&R, RBNode *&pt)
{
    RBNode *parent_pt = nullptr;
    RBNode *grand_parent_pt = nullptr;

    while ((pt != R) && (pt->getColor() != BLACK) &&
           (pt->getParent()->getColor() == RED))
    {

        parent_pt = pt->getParent();
        grand_parent_pt = pt->getParent()->getParent();

        /* Case : A
            Parent of pt is left child of Grand-parent of pt */
        if (parent_pt == (RBNode*) grand_parent_pt->getLeftPointer())
        {

            auto *uncle_pt = (RBNode*) grand_parent_pt->getRightPointer();

            /* Case : 1
            The uncle of pt is also red
            Only Recoloring required */
            if (uncle_pt != nullptr && uncle_pt->getColor() == RED)
            {
                grand_parent_pt->setColor(RED);
                parent_pt->setColor(BLACK);
                uncle_pt->setColor(BLACK);
                pt = grand_parent_pt;
            }

            else
            {
                /* Case : 2
                pt is right child of its parent
                Left-rotation required */
                if (pt == (RBNode*) parent_pt->getRightPointer())
                {
                    rotateLeft(R, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->getParent();
                }

                /* Case : 3
                pt is left child of its parent
                Right-rotation required */
                rotateRight(R, grand_parent_pt);


                swap(parent_pt->color,grand_parent_pt->color);


                pt = parent_pt;
            }
        }

            /* Case : B
            Parent of pt is right child of Grand-parent of pt */
        else
        {
            auto *uncle_pt = (RBNode*) grand_parent_pt->getLeftPointer();

            /* Case : 1
                The uncle of pt is also red
                Only Recoloring required */
            if ((uncle_pt != nullptr) && (uncle_pt->getColor() == RED))
            {
                grand_parent_pt->setColor(RED);
                parent_pt->setColor(BLACK);
                uncle_pt->setColor(BLACK);
                pt = grand_parent_pt;
            }
            else
            {
                /* Case : 2
                pt is left child of its parent
                Right-rotation required */
                if (pt == (RBNode*) parent_pt->getLeftPointer())
                {
                    rotateRight(R, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->getParent();
                }

                /* Case : 3
                pt is right child of its parent
                Left-rotation required */
                rotateLeft(R, grand_parent_pt);

                swap(parent_pt->color,grand_parent_pt->color);

                pt = parent_pt;
            }
        }
    }

    R->setColor(BLACK);
}

// Function to insert a new node with given data
void RBTree::insert(const int &data, string name, int amount, int price)
{
    auto *pt = new RBNode(data, name, amount, price);

    // Do a normal BST insert
    root = BSTInsert(root, pt);

    // fix Red Black Tree violations
    fixViolation(root, pt);
}

// Function to do inorder and level order traversals
void RBTree::inorder()	 { inorderHelper(root);}
void RBTree::levelOrder() { levelOrderHelper(root); }

bool RBTree::isBrandCodeOnList(int brandCode) {
    return root->isBrandCodeOnList(root, brandCode);
}


