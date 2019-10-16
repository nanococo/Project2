#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include "../nodeTypes/AVLNode.h"

using namespace std;

class AVLBinaryTree {
public:
    explicit AVLBinaryTree() { root = nullptr;}
    
    static int height(AVLNode *);
    static int difference(AVLNode *);
    AVLNode *rr_rotat(AVLNode *);
    AVLNode *ll_rotat(AVLNode *);
    AVLNode *lr_rotat(AVLNode*);
    AVLNode *rl_rotat(AVLNode *);
    AVLNode *balance(AVLNode *);
    AVLNode *insert(AVLNode *r, int prodCode, string name);
    AVLNode *getNodeByProdCode(int prodCode);
    AVLNode *getAVLRoot() const;
    void show(AVLNode*, int);
    void fullInorder(AVLNode *t);
    void printProductsForPurchase(AVLNode *);
    void inorder(AVLNode *);
    void preorder(AVLNode *);
    void postorder(AVLNode *);
    void setAVLRoot(AVLNode *newRoot);
    bool isProdCodeOnTree(int prodCode);

private:
    AVLNode *root;

};

AVLNode *AVLBinaryTree::getAVLRoot() const {
    return root;
}

void AVLBinaryTree::setAVLRoot(AVLNode *newRoot) {
    AVLBinaryTree::root = newRoot;
}

int AVLBinaryTree::height(AVLNode *t) {
    int h = 0;
    if (t != nullptr) {
        int l_height = height((AVLNode*) t->getLeftPointer());
        int r_height = height((AVLNode*) t->getRightPointer());
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}
int AVLBinaryTree::difference(AVLNode *t) {
    int l_height = height((AVLNode*) t->getLeftPointer());
    int r_height = height((AVLNode*) t->getRightPointer());
    int b_factor = l_height - r_height;
    return b_factor;
}
AVLNode *AVLBinaryTree::rr_rotat(AVLNode *parent) {
    AVLNode *t;
    t = (AVLNode*) parent->getRightPointer();
    parent->setRightPointer(t->getLeftPointer());
    t->setLeftPointer(parent);
    cout<<"Right-Right Rotation";
    return t;
}
AVLNode *AVLBinaryTree::ll_rotat(AVLNode *parent) {
    AVLNode *t;
    t = (AVLNode*) parent->getLeftPointer();
    parent->setLeftPointer(t->getRightPointer());
    t->setRightPointer(parent);
    cout<<"Left-Left Rotation";
    return t;
}
AVLNode *AVLBinaryTree::lr_rotat(AVLNode *parent) {
    AVLNode *t;
    t = (AVLNode*) parent->getLeftPointer();
    parent->setLeftPointer(rr_rotat(t));
    cout<<"Left-Right Rotation";
    return ll_rotat(parent);
}
AVLNode *AVLBinaryTree::rl_rotat(AVLNode *parent) {
    AVLNode *t;
    t = (AVLNode*) parent->getRightPointer();
    parent->setRightPointer(ll_rotat(t));
    cout<<"Right-Left Rotation";
    return rr_rotat(parent);
}
AVLNode *AVLBinaryTree::balance(AVLNode *t) {
    int bal_factor = difference(t);
    if (bal_factor > 1) {
        if (difference((AVLNode*) t->getLeftPointer()) > 0)
            t = ll_rotat(t);
        else
            t = lr_rotat(t);
    } else if (bal_factor < -1) {
        if (difference((AVLNode*) t->getRightPointer()) > 0)
            t = rl_rotat(t);
        else
            t = rr_rotat(t);
    }
    return t;
}
AVLNode *AVLBinaryTree::insert(AVLNode *r, int v, string name) {
    if (r == nullptr) {
        r = new AVLNode(v, name);
        return r;
    } else if (v < r->getData()) {
        r->setLeftPointer(insert((AVLNode*) r->getLeftPointer(), v, name));
        r = balance(r);
    } else if (v >= r->getData()) {
        r->setRightPointer(insert((AVLNode*) r->getRightPointer(), v, name));
        r = balance(r);
    } return r;
}
void AVLBinaryTree::show(AVLNode *p, int l) {
    int i;
    if (p != nullptr) {
        show((AVLNode*) p->getRightPointer(), l+ 1);
        cout<<" ";
        if (p == root)
            cout << "Root -> ";
        for (i = 0; i < l&& p != root; i++)
            cout << " ";
        cout << p->getData();
        show((AVLNode*) p->getLeftPointer(), l + 1);
    }
}
void AVLBinaryTree::inorder(AVLNode *t) {
    if (t == nullptr)
        return;
    inorder((AVLNode*) t->getLeftPointer());
    cout << "(" <<t->getData() << ", " << t->getName()  << ", " << t->getTimesSold() << " ) -";
    inorder((AVLNode*) t->getRightPointer());
}

void AVLBinaryTree::fullInorder(AVLNode *t) {
    if (t == nullptr)
        return;
    fullInorder((AVLNode*) t->getLeftPointer());
    cout << "(" <<t->getData() << ", " << t->getName()  << ", " << t->getTimesSold() << " ) -";
    if(t->getProductAisleBrandTreePointer()!= nullptr){
        cout << "Third tree inorder for: " << t->getData() << endl;
        t->getProductAisleBrandTreePointer()->inorder();
        cout << "End of Second Tree Inorder" << endl;
    }
    fullInorder((AVLNode*) t->getRightPointer());
}

void AVLBinaryTree::preorder(AVLNode *t) {
    if (t == nullptr)
        return;
    cout << t->getData() << " ";
    preorder((AVLNode*) t->getLeftPointer());
    preorder((AVLNode*) t->getRightPointer());
}
void AVLBinaryTree::postorder(AVLNode *t) {
    if (t == nullptr)
        return;
    postorder( (AVLNode*) t ->getLeftPointer());
    postorder((AVLNode*) t ->getRightPointer());
    cout << t->getData() << " ";
}

bool AVLBinaryTree::isProdCodeOnTree(int prodCode) {
    return root->isProdCodeInTree(root, prodCode);
}

AVLNode *AVLBinaryTree::getNodeByProdCode(int prodCode){
    return root->getNodeByProdCode(root, prodCode);
}

void AVLBinaryTree::printProductsForPurchase(AVLNode *t) {
    if (t == nullptr)
        return;
    printProductsForPurchase((AVLNode*) t->getLeftPointer());
    cout << "Product Code:" <<t->getData() << ", Product Name:" << t->getName() << endl;
    printProductsForPurchase((AVLNode*) t->getRightPointer());
}
