cmake_minimum_required(VERSION 3.14)
project(Project2)

set(CMAKE_CXX_STANDARD 14)
MAKE_DIRECTORY(${CMAKE_CURRENT_BINARY_DIR}/data)
add_executable(Project2 main.cpp src/TreesHandlers/BinarySearchTree.h src/nodeTypes/BSNode.h src/helpers/helpers.h src/TreesHandlers/AVLBinaryTree.h src/nodeTypes/AVLNode.h src/TreesHandlers/RBTree.h src/nodeTypes/RBNode.h src/helpers/test.h src/helpers/test.h src/helpers/test.h)