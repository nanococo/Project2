#pragma once

#include <iostream>
#include <utility>

using namespace std;
// A BTreeClients node

class ClientData {
public:
    explicit ClientData(){
        this->name = "";
        this->email = "";
        this->phoneNumber = "";
        this->cityCode = "";
        this->amountSpent = 0;
        this->billingCount = 0;
    }

    explicit ClientData(string name, string cityCode, string phoneNumber, string email){
        this->name = name;
        this->email = email;
        this->phoneNumber = phoneNumber;
        this->cityCode = cityCode;
        this->amountSpent = 0;
        this->billingCount = 0;
    }

    const string &getName() const;

    void setName(const string &name);

    const string &getEmail() const;

    void setEmail(const string &email);

    const string &getPhoneNumber() const;

    void setPhoneNumber(const string &phoneNumber);

    const string &getCityCode() const;

    void setCityCode(const string &cityCode);

    float getAmountSpent() const;

    void setAmountSpent(float amountSpent);

    int getBillingCount() const;

    void setBillingCount(int billingCount);

    void incBillingCount();


private:
    string name;
    string email;
    string cityCode;
    string phoneNumber;
    float amountSpent;
    int billingCount;
};

float ClientData::getAmountSpent() const {
    return amountSpent;
}

void ClientData::setAmountSpent(float amountSpent) {
    ClientData::amountSpent = amountSpent;
}

int ClientData::getBillingCount() const {
    return billingCount;
}

void ClientData::setBillingCount(int billingCount) {
    ClientData::billingCount = billingCount;
}

const string &ClientData::getName() const {
    return name;
}

void ClientData::setName(const string &name) {
    ClientData::name = name;
}

const string &ClientData::getEmail() const {
    return email;
}

void ClientData::setEmail(const string &email) {
    ClientData::email = email;
}

const string &ClientData::getPhoneNumber() const {
    return phoneNumber;
}

void ClientData::setPhoneNumber(const string &phoneNumber) {
    ClientData::phoneNumber = phoneNumber;
}

const string &ClientData::getCityCode() const {
    return cityCode;
}

void ClientData::setCityCode(const string &cityCode) {
    ClientData::cityCode = cityCode;
}

class BTreeNode{
private:
    int *keys; // An array of keys
    int t;	 // Minimum degree (defines the range for number of keys)
    BTreeNode **C; // An array of child pointers
    int n;	 // Current number of keys
    bool leaf; // Is true when node is leaf. Otherwise false
    ClientData *clientDataArray;




public:
    BTreeNode(int t1, bool leaf1); // Constructor

    // A utility function to insert a new key in the subtree rooted with
    // this node. The assumption is, the node must be non-full when this
    // function is called
    void insertNonFull(int k, ClientData clientData);

    // A utility function to split the child y of this node. i is index of y in
    // child array C[]. The Child y must be full when this function is called
    void splitChild(int i, BTreeNode *y);

    // A function to traverse all nodes in a subtree rooted with this node
    void traverse();

    // A function to search a key in the subtree rooted with this node.
    BTreeNode *search(int k); // returns NULL if k is not present.
    ClientData searchClient(int k);

// Make BTreeClients friend of this so that we can access private members of this
// class in BTreeClients functions
    friend class BTreeClients;
};

// Constructor for BTreeNode class
BTreeNode::BTreeNode(int t1, bool leaf1)
{
    // Copy the given minimum degree and leaf property
    t = t1;
    leaf = leaf1;

    // Allocate memory for maximum number of possible keys
    // and child pointers
    keys = new int[2*t-1];
    clientDataArray = new ClientData[2*t-1];
    C = new BTreeNode *[2*t];

    // Initialize the number of keys as 0
    n = 0;
}

// Function to traverse all nodes in a subtree rooted with this node
void BTreeNode::traverse()
{
    // There are n keys and n+1 children, travers through n keys
    // and first n children
    int i;
    for (i = 0; i < n; i++)
    {
        // If this is not leaf, then before printing key[i],
        // traverse the subtree rooted with child C[i].
        if (!leaf)
            C[i]->traverse();
        cout << " " << keys[i];
    }

    // Print the subtree rooted with last child
    if (!leaf)
        C[i]->traverse();
}

// Function to search key k in subtree rooted with this node
BTreeNode *BTreeNode::search(int k)
{
    // Find the first key greater than or equal to k
    int i = 0;
    while (i < n && k > keys[i])
        i++;

    // If the found key is equal to k, return this node
    if (keys[i] == k)
        return this;

    // If key is not found here and this is a leaf node
    if (leaf)
        return nullptr;

    // Go to the appropriate child
    return C[i]->search(k);
}

ClientData BTreeNode::searchClient(int k) {
    // Find the first key greater than or equal to k
    int i = 0;
    while (i < n && k > keys[i])
        i++;

    // If the found key is equal to k, return this node
    if (keys[i] == k)
        return clientDataArray[i];

    // If key is not found here and this is a leaf node
    if (leaf){
        cout << "C MAMO" << endl;
        return ClientData("ERROR", "ERROR", "ERROR", "ERROR");
    }

    // Go to the appropriate child
    return C[i]->searchClient(k);
}

// A utility function to insert a new key in this node
// The assumption is, the node must be non-full when this
// function is called
void BTreeNode::insertNonFull(int k, ClientData clientData)
{
    // Initialize index as index of rightmost element
    int i = n-1;

    // If this is a leaf node
    if (leaf)
    {
        // The following loop does two things
        // a) Finds the location of new key to be inserted
        // b) Moves all greater keys to one place ahead
        while (i >= 0 && keys[i] > k)
        {
            clientDataArray[i+1] = clientDataArray[i];
            keys[i+1] = keys[i];
            i--;
        }

        // Insert the new key at found location
        keys[i+1] = k;
        clientDataArray[i+1] = clientData;
        n = n+1;
    }
    else // If this node is not leaf
    {
        // Find the child which is going to have the new key
        while (i >= 0 && keys[i] > k)
            i--;

        // See if the found child is full
        if (C[i+1]->n == 2*t-1)
        {
            // If the child is full, then split it
            splitChild(i+1, C[i+1]);

            // After split, the middle key of C[i] goes up and
            // C[i] is splitted into two. See which of the two
            // is going to have the new key
            if (keys[i+1] < k)
                i++;
        }
        C[i+1]->insertNonFull(k, clientData);
    }
}

// A utility function to split the child y of this node
// Note that y must be full when this function is called
void BTreeNode::splitChild(int i, BTreeNode *y)
{
    // Create a new node which is going to store (t-1) keys
    // of y
    auto *z = new BTreeNode(y->t, y->leaf);
    z->n = t - 1;

    // Copy the last (t-1) keys of y to z
    for (int j = 0; j < t-1; j++){
        z->keys[j] = y->keys[j+t];
        z->clientDataArray[j]=y->clientDataArray[j+t];
    }

    // Copy the last t children of y to z
    if (!y->leaf)
    {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j+t];
    }

    // Reduce the number of keys in y
    y->n = t - 1;

    // Since this node is going to have a new child,
    // create space of new child
    for (int j = n; j >= i+1; j--)
        C[j+1] = C[j];

    // Link the new child to this node
    C[i+1] = z;

    // A key of y will move to this node. Find the location of
    // new key and move all greater keys one space ahead
    for (int j = n-1; j >= i; j--){
        keys[j+1] = keys[j];
        clientDataArray[j+1] = clientDataArray[j];
    }

    // Copy the middle key of y to this node
    keys[i] = y->keys[t-1];
    clientDataArray[i] = y->clientDataArray[t-1];

    // Increment count of keys in this node
    n = n + 1;
}

void ClientData::incBillingCount() {
    billingCount++;
}