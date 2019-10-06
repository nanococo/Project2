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
    AVLNode *getAVLRoot() const;
    void show(AVLNode*, int);
    void inorder(AVLNode *);
    void preorder(AVLNode *);
    void postorder(AVLNode*);
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
//int main() {
//    int c, i;
//    AVLBinaryTree AVLNode;
//    while (1) {
//        cout << "1.Insert Element into the tree" << endl;
//        cout << "2.show Balanced AVL Tree" << endl;
//        cout << "3.InOrder traversal" << endl;
//        cout << "4.PreOrder traversal" << endl;
//        cout << "5.PostOrder traversal" << endl;
//        cout << "6.Exit" << endl;
//        cout << "Enter your Choice: ";
//        cin >> c;
//        switch (c) {
//            case 1:
//                cout << "Enter value to be inserted: ";
//                cin >> i;
//                root = AVLNode.insert(root, i);
//                break;
//            case 2:
//                if (root == NULL) {
//                    cout << "Tree is Empty" << endl;
//                    continue;
//                }
//                cout << "Balanced AVL Tree:" << endl;
//                AVLNode.show(root, 1);
//                cout<<endl;
//                break;
//            case 3:
//                cout << "Inorder Traversal:" << endl;
//                AVLNode.inorder(root);
//                cout << endl;
//                break;
//            case 4:
//                cout << "Preorder Traversal:" << endl;
//                AVLNode.preorder(root);
//                cout << endl;
//                break;
//            case 5:
//                cout << "Postorder Traversal:" << endl;
//                AVLNode.postorder(root);
//                cout << endl;
//                break;
//            case 6:
//                exit(1);
//                break;
//            default:
//                cout << "Wrong Choice" << endl;
//        }
//    }
//    return 0;
//}