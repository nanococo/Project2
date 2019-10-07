#pragma once

#include <fstream>
#include "../TreesHandlers/BinarySearchTree.h"


using namespace std;

/**
 * Splits file contents into formats to be inserted in doubleListAisle list
 * @param aisles Is the given list object where to be inserted
 * @param fullString Is the txt full line string to be segmented
 * @param delimiter Is the character to be used as cut of string
 * **/
void splitIntoAisleTree(BinarySearchTree &aisles, const string& fullString, char delimiter){

    string data1;
    string data2;
    int dataCount = 0;
    for (auto x : fullString) {
        switch (dataCount) {
            case 0:
                if (x == delimiter) {
                    //cout << data1 << endl;
                    dataCount++;
                } else {
                    data1 += x;
                }
                break;
            case 1:
                if (x == delimiter) {
                    //cout << data2 << endl;
                    dataCount++;
                } else {
                    data2 += x;
                }
                break;
            default:
                dataCount = 0;
                data1 = "";
                data2 = "";
                break;
        }
    }
    try {

        int data1Num = stoi(data1);
        if (!aisles.isAisleCodeInTree(data1Num)) {
            aisles.insert(new BSNode(data1Num, data2));
        }

    }catch (std::invalid_argument& e) {
        cout << "******************************************************************************************************" << endl;
        cout << "Number values could not be converted to integer for ids: " << data1 << endl;
        cout << "******************************************************************************************************" << endl;
    }

}

/**
 *
 * Splits file contents into formats to be inserted in doubleListAisle list
 * @param aislesProds Is the given list object where to be inserted
 * @param fullString Is the txt full line string to be segmented
 * @param delimiter Is the character to be used as cut of string
 *
 * **/
void splitIntoListAisleProduct(BinarySearchTree &aislesProds, const string& fullString, char delimiter){
    string data1;
    string data2;
    string data3;
    int dataCount = 0;
    for (auto x : fullString){
        switch(dataCount){
            case 0:
                if(x==delimiter){
                    //cout << data1 << endl;
                    dataCount++;
                } else {
                    data1+=x;
                }
                break;
            case 1:
                if(x==delimiter){
                    //cout << data2 << endl;
                    dataCount++;
                } else {
                    data2+=x;
                }
                break;
            case 2:
                if(x==delimiter){
                    //cout << data3 << endl;
                    dataCount++;
                } else {
                    data3+=x;
                }
                break;
            default:
                dataCount=0;
                data1 = "";
                data2 = "";
                data3 = "";
                break;
        }
    }

    try{
        int data1Int = stoi(data1);
        int data2Int = stoi(data2);
        if(aislesProds.isAisleCodeInTree(data1Int)){
            //If aisle code does exists then proceed
            BSNode *aisleNode = aislesProds.getNodeByAisleCode(data1Int);
            if(aisleNode->getProductAisleTreePointer() == nullptr){
                aisleNode->setProductAisleTreePointer(new AVLBinaryTree());
                aisleNode->getProductAisleTreePointer()->setAVLRoot(aisleNode->getProductAisleTreePointer()->insert(aisleNode->getProductAisleTreePointer()->getAVLRoot(), data2Int, data3));

            } else {
                if(!aisleNode->getProductAisleTreePointer()->isProdCodeOnTree(data2Int)){
                    aisleNode->getProductAisleTreePointer()->setAVLRoot(aisleNode->getProductAisleTreePointer()->insert(aisleNode->getProductAisleTreePointer()->getAVLRoot(), data2Int, data3));
                }
            }
        }
    }catch (std::invalid_argument& e) {
        cout << "******************************************************************************************************" << endl;
        cout << "Number values could not be converted to integer for ids: " << data1 << data2 << endl;
        cout << "******************************************************************************************************" << endl;
    }

}

/**
 * Splits file contents into formats to be inserted in doubleListAisle list
 * @param aisles Is the given list object where to be inserted
 * @param fullString Is the txt full line string to be segmented
 * @param delimiter Is the character to be used as cut of string
 * **/
void splitIntoListAisleProductBrand(BinarySearchTree &aisles, const string& fullString, char delimiter){
    string data1;
    string data2;
    string data3;
    string data4;
    string data5;
    string data6;
    int dataCount = 0;
    for (auto x : fullString){
        switch(dataCount){
            case 0:
                if(x==delimiter){
                    //cout << data1 << endl;
                    dataCount++;
                } else {
                    data1+=x;
                }
                break;
            case 1:
                if(x==delimiter){
                    //cout << data2 << endl;
                    dataCount++;
                } else {
                    data2+=x;
                }
                break;
            case 2:
                if(x==delimiter){
                    //cout << data3 << endl;
                    dataCount++;
                } else {
                    data3+=x;
                }
                break;
            case 3:
                if(x==delimiter){
                    //cout << data3 << endl;
                    dataCount++;
                } else {
                    data4+=x;
                }
                break;
            case 4:
                if(x==delimiter){
                    //cout << data3 << endl;
                    dataCount++;
                } else {
                    data5+=x;
                }
                break;
            case 5:
                if(x==delimiter){
                    //cout << data3 << endl;
                    dataCount++;
                } else {
                    data6+=x;
                }
                break;
            default:
                dataCount=0;
                data1 = "";
                data2 = "";
                data3 = "";
                data4 = "";
                data5 = "";
                data6 = "";
                break;
        }
    }
    try{
        int data1Num = stoi(data1);
        int data2Num = stoi(data2);
        int data3Num = stoi(data3);
        int data5Num = stoi(data5);
        int data6Num = stoi(data6);



        if(aisles.isAisleCodeInTree(data1Num)){
            //If aisle code does exists then proceed

            BSNode *aisleNode = aisles.getNodeByAisleCode(data1Num);
            if(aisleNode->getProductAisleTreePointer()->isProdCodeOnTree(data2Num)){
                AVLNode *prodNode = aisleNode->getProductAisleTreePointer()->getNodeByProdCode(data2Num);

                if(prodNode->getProductAisleBrandTreePointer() == nullptr){
                    prodNode->setProductAisleBrandTreePointer(new RBTree);
                    prodNode->getProductAisleBrandTreePointer()->insert(data3Num, data4, data5Num, data6Num);

                } else {
                    if (!prodNode->getProductAisleBrandTreePointer()->isBrandCodeOnList(data3Num)){
                        prodNode->getProductAisleBrandTreePointer()->insert(data3Num, data4, data5Num, data6Num);
                    }
                }

            }

        }

    } catch(std::invalid_argument& e){
        cout << "******************************************************************************************************" << endl;
        cout << "Number values could not be converted to integer for ids: " << data1 << ";" << data2 << ";" << data3 << endl;
        cout << "Provided numbers are: " << data4 << " and " << data5 << endl;
        cout << "******************************************************************************************************" << endl;
    }
}


/**
 * Initializes a list with values from file
 * @param aisles By reference. Is the list to be initiliazed
 * **/
void initAisleTree(BinarySearchTree &aisles){
    string line;
    ifstream arch1("data/Pasillos.txt");

    while (getline(arch1, line)) {
        if(!line.empty()){
            splitIntoAisleTree(aisles, line, ';');
        }
    }
}

/**
 * Initializes a list with values from file
 * @param aisleList is the aisleList value to check for IDs
 * **/
void initAislesProductTree(BinarySearchTree &aisles){
    string line;
    ifstream arch1("data/ProductosPasillos.txt");

    while (getline(arch1, line)) {
        if(!line.empty()){
            splitIntoListAisleProduct(aisles, line, ';');
        }
    }


}

/**
 * Initializes a list with values from file
 * @param aisles is the aisleList value to check for IDs
 * **/
void initAislesProductBrandTree(BinarySearchTree &aisles){
    string line;
    ifstream arch1("data/MarcasProductos.txt");

    while (getline(arch1, line)) {
        if(!line.empty()){
            splitIntoListAisleProductBrand(aisles, line, ';');
        }
    }
}