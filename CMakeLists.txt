cmake_minimum_required(VERSION 3.14)
project(Project2)

set(CMAKE_CXX_STANDARD 14)
MAKE_DIRECTORY(${CMAKE_CURRENT_BINARY_DIR}/data)
add_executable(Project2 main.cpp src/TreesHandlers/BinarySearchTree.h src/nodeTypes/BSNode.h src/helpers/helpers.h src/TreesHandlers/AVLBinaryTree.h src/nodeTypes/AVLNode.h src/TreesHandlers/RBTree.h src/nodeTypes/RBNode.h src/TreesHandlers/BTreeClients.h src/nodeTypes/BNodeClient.h src/TreesHandlers/BTreeAdmins.h src/nodeTypes/BNodeAdmin.h src/TreesHandlers/AATree.h src/nodeTypes/AANode.h src/helpers/test.h)