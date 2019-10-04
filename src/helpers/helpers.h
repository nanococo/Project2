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
void splitIntoListAisle(BinarySearchTree &aisles, const string& fullString, char delimiter){

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
 * Initializes a list with values from file
 * @param aisles By reference. Is the list to be initiliazed
 * **/
void initAisleTree(BinarySearchTree &aisles){
    string line;
    ifstream arch1("data/Pasillos.txt");

    while (getline(arch1, line)) {
        if(!line.empty()){
            splitIntoListAisle(aisles, line, ';');
        }
    }
}