#pragma once

// C++ program for B-Tree insertion
#include<iostream>
#include "../nodeTypes/BNodeClient.h"

using namespace std;



// A BTreeClients
class BTreeClients{
    BTreeNode *root; // Pointer to root node
    int t; // Minimum degree
public:
    // Constructor (Initializes tree as empty)
    explicit BTreeClients(int _t){ root = nullptr; t = _t;highestBoughtValue=0.0;mostBoughtValue=0;}

    // function to traverse the tree
    void traverse();

    void generateMostExpensiveBill(const string &path);
    void generateMostBilledClient(const string &path);
    void generateLeastExpensiveBill(const string &path);
    void generateLeastBilledClient(const string &path);
    void generateClients(const string &path);

    // function to search a key in this tree
    BTreeNode* search(int k);

    ClientData searchClient(int k);

    // The main function that inserts a new key in this B-Tree
    void insert(int k, const ClientData& clientData);

    float highestBoughtValue;
    int mostBoughtValue;
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

void BTreeClients::traverse(){
    if (root != nullptr){
        root->traverse();
    }
}

BTreeNode* BTreeClients::search(int k){
    return (root == nullptr)? nullptr : root->search(k);
}

ClientData BTreeClients::searchClient(int k) {
    return root->searchClient(k);
}

void BTreeClients::generateMostExpensiveBill(const string &path) {
    ofstream outfile (path);
    outfile << "Most expensive bill report. " << endl;

    root->getHighestBoughtValue(highestBoughtValue);
    root->generateMostExpensiveBill(highestBoughtValue, outfile);

    outfile.flags();
    outfile.close();
    cout << "Report generated successfully..." << endl;
}

void BTreeClients::generateMostBilledClient(const string &path){
    ofstream outfile (path);
    outfile << "Most billed client report. " << endl;

    root->getMostBoughtValue(mostBoughtValue);
    root->generateMostBilledClient(mostBoughtValue, outfile);

    outfile.flags();
    outfile.close();
    cout << "Report generated successfully..." << endl;
}

void BTreeClients::generateLeastExpensiveBill(const string &path) {
    ofstream outfile (path);
    outfile << "Least expensive bill report. " << endl;

    highestBoughtValue = root->searchClient(root->keys[0]).getAmountSpent();
    root->getLowestBoughtValue(highestBoughtValue);
    root->generateLeastExpensiveBill(highestBoughtValue, outfile);

    outfile.flags();
    outfile.close();
    cout << "Report generated successfully..." << endl;
}

void BTreeClients::generateClients(const string &path) {
    ofstream outfile (path);
    outfile << "Clients List. " << endl;

    root->generateClients(outfile);

    outfile.flags();
    outfile.close();
    cout << "Report generated successfully..." << endl;
}

void BTreeClients::generateLeastBilledClient(const string &path) {
    ofstream outfile (path);
    outfile << "Least expensive bill report. " << endl;

    mostBoughtValue = root->searchClient(root->keys[0]).getAmountSpent();
    root->getLeastBoughtValue(mostBoughtValue);
    root->generateLeastBilledClient(mostBoughtValue, outfile);

    outfile.flags();
    outfile.close();
    cout << "Report generated successfully..." << endl;
}





