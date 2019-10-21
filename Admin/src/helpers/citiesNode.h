#pragma once

#include <string>
#include <utility>

using namespace std;
class citiesNode {
public:
    explicit citiesNode(string cityCode, string cityName){
        this->cityCode = std::move(cityCode);
        this->cityName = std::move(cityName);
        this->nextNode = nullptr;
    }

    const string &getCityCode() const;

    void setCityCode(const string &newCityCode);

    const string &getCityName() const;

    void setCityName(const string &newCityName);

    citiesNode *getNextNode() const;

    void setNextNode(citiesNode *newNextNode);

private:
    string cityCode;
    string cityName;
    citiesNode *nextNode;
};

const string &citiesNode::getCityCode() const {
    return cityCode;
}

void citiesNode::setCityCode(const string &newCityCode) {
    citiesNode::cityCode = newCityCode;
}

const string &citiesNode::getCityName() const {
    return cityName;
}

void citiesNode::setCityName(const string &newCityName) {
    citiesNode::cityName = newCityName;
}

citiesNode *citiesNode::getNextNode() const {
    return nextNode;
}

void citiesNode::setNextNode(citiesNode *newNextNode) {
    citiesNode::nextNode = newNextNode;
}
