#pragma once

class BaseBinaryNode {
protected:
    explicit BaseBinaryNode(int data){
        this->leftPointer = nullptr;
        this->rightPointer = nullptr;
        this->data = data;
    }

    BaseBinaryNode *getLeftPointer() const;
    BaseBinaryNode *getRightPointer() const;
    void setLeftPointer(BaseBinaryNode *newLeftPointer);
    void setRightPointer(BaseBinaryNode *newRightPointer);
    void setData(int newData);
    int getData() const;

private:
    BaseBinaryNode *leftPointer;
    BaseBinaryNode *rightPointer;
    int data;
};

BaseBinaryNode *BaseBinaryNode::getLeftPointer() const {
    return leftPointer;
}

void BaseBinaryNode::setLeftPointer(BaseBinaryNode *newLeftPointer) {
    BaseBinaryNode::leftPointer = newLeftPointer;
}

BaseBinaryNode *BaseBinaryNode::getRightPointer() const {
    return rightPointer;
}

void BaseBinaryNode::setRightPointer(BaseBinaryNode *newRightPointer) {
    BaseBinaryNode::rightPointer = newRightPointer;
}

int BaseBinaryNode::getData() const {
    return data;
}

void BaseBinaryNode::setData(int newData) {
    BaseBinaryNode::data = newData;
}
