#include <iostream>
#include "src/TreesHandlers/BinarySearchTree.h"

int main() {
    BinarySearchTree B;
    B.insert(new BSNode(3, "Hola"));
    B.insert(new BSNode(3, "Como"));
    B.insert(new BSNode(3, "Estas"));
    B.insert(new BSNode(3, "Puto"));
    B.inOrder();
}