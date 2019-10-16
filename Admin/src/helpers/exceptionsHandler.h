//
// Created by sebas on 9/14/2019.
//

#pragma once
#include <iostream>
#include <exception>
using namespace std;

class indexOutOfBounds : public exception {
public:
    const char* what() const noexcept override{
        return "Provided index doesn't exist. Index is out of bounds";
    }
} indexOutOfBounds;

class elementNotFound : public exception{
public:
    const char* what() const noexcept override {
        return "Element not found with given parameters";
    }
} elementNotFound;