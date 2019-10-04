#include <iostream>
#include "src/TreesHandlers/BinarySearchTree.h"
#include "src/helpers/helpers.h"

int main() {
    BinarySearchTree aisles;
    initAisleTree(aisles);

//    aisles.insert(new BSNode(1, "Hola"));
//    aisles.insert(new BSNode(2, "Hola"));
//    aisles.insert(new BSNode(3, "Hola"));
//    aisles.insert(new BSNode(4, "Hola"));
//
    aisles.inOrder();

}