#pragma once

#include <iostream>
#include "citiesNode.h"

class citiesList{
public:
    explicit citiesList(){firstNode = aux = nullptr;}
    void next();
    void printList();
    void appendAtEnd(citiesNode *newCitiesNode);
    bool isElementInList(const string &cityCode);

private:
    citiesNode *firstNode;
    citiesNode *aux;
};

void citiesList::next(){
    aux = aux->getNextNode();
}

void citiesList::printList() {
    aux = firstNode;
    while (aux!=nullptr){
        cout << "[" << aux->getCityCode() << ", " << aux->getCityName() << "]" << endl;
        next();
    }
}

void citiesList::appendAtEnd(citiesNode *newCitiesNode) {
    if (firstNode == nullptr){
        firstNode = newCitiesNode;
    } else {
        aux = firstNode;
        while (aux->getNextNode() != nullptr){
            next();
        }
        aux->setNextNode(newCitiesNode);
    }

}

bool citiesList::isElementInList(const string& cityCode){
    aux = firstNode;
    bool found = false;
    while (aux!= nullptr){
        if(aux->getCityCode() == cityCode){
            found = true;
            break;
        }
        next();
    }
    return found;
}