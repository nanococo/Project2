#pragma once

// C++ program for B-Tree insertion
#include<iostream>
#include "../nodeTypes/BNodeClient.h"

using namespace std;



// A BTreeClients
class BTreeClients
{
    BTreeNode *root; // Pointer to root node
    int t; // Minimum degree
public:
    // Constructor (Initializes tree as empty)
    explicit BTreeClients(int _t)
    { root = nullptr; t = _t; }

    // function to traverse the tree
    void traverse()
    { if (root != nullptr) root->traverse(); }

    // function to search a key in this tree
    BTreeNode* search(int k)
    { return (root == nullptr)? nullptr : root->search(k); }

    ClientData searchClient(int k){
        return root->searchClient(k);
    }

    // The main function that inserts a new key in this B-Tree
    void insert(int k, const ClientData& clientData);
};



// The main function that inserts a new key in this B-Tree
void BTreeClients::insert(int k, const ClientData& clientData)
{
    // If tree is empty
    if (root == nullptr)
    {
        // Allocate memory for root
        root = new BTreeNode(t, true);
        root->keys[0] = k; // Insert key
        root->clientDataArray[0]=clientData;
        root->n = 1; // Update number of keys in root
    }
    else // If tree is not empty
    {
        // If root is full, then tree grows in height
        if (root->n == 2*t-1)
        {
            // Allocate memory for new root
            auto *s = new BTreeNode(t, false);

            // Make old root as child of new root
            s->C[0] = root;

            // Split the old root and move 1 key to the new root
            s->splitChild(0, root);

            // New root has two children now. Decide which of the
            // two children is going to have new key
            int i = 0;
            if (s->keys[0] < k)
                i++;
            s->C[i]->insertNonFull(k, clientData);

            // Change root
            root = s;
        }
        else // If root is not full, call insertNonFull for root
            root->insertNonFull(k, clientData);
    }
}



