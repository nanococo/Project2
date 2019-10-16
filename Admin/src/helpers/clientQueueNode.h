//
// Created by sebas on 9/11/2019.
//

#pragma once

#include <string>
#include "clientProductStackNode.h"

using namespace std;
class clientQueueNode{
public:

    explicit clientQueueNode(const string &clientId){
        this->clientId = clientId;
        this->nextNode = nullptr;
        this->firstClientProd = nullptr;
    }

    explicit clientQueueNode(const string &clientId, clientQueueNode *nextNode){
        this->clientId = clientId;
        this->nextNode = nextNode;
        this->firstClientProd = nullptr;
    }

    const string &getClientId() const;
    void setClientId(const string &newClientId);
    clientProductStackNode *getFirstClientProd() const;
    void setFirstClientProd(clientProductStackNode *newFirstClientProd);

    clientQueueNode *getNextNode() const;

    void setNextNode(clientQueueNode *newNextNode);

private:
    string clientId;
    clientProductStackNode *firstClientProd;
    clientQueueNode *nextNode;
};

clientQueueNode *clientQueueNode::getNextNode() const {
    return nextNode;
}

void clientQueueNode::setNextNode(clientQueueNode *newNextNode) {
    clientQueueNode::nextNode = newNextNode;
}

const string &clientQueueNode::getClientId() const {
    return clientId;
}

void clientQueueNode::setClientId(const string &newClientId) {
    clientQueueNode::clientId = newClientId;
}

clientProductStackNode *clientQueueNode::getFirstClientProd() const {
    return firstClientProd;
}

void clientQueueNode::setFirstClientProd(clientProductStackNode *newFirstClientProd) {
    clientQueueNode::firstClientProd = newFirstClientProd;
}
