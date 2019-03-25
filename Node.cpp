#include "Node.h"

Node::Node() {
    this->data1 = 0;
    this->data2 = 0;
    this->isNodeFull = false;
    this->left = nullptr;
    this->middle = nullptr;
    this->right = nullptr;
}

void Node::setData1(int data1) {
    this->data1 = data1;
}

void Node::setData2(int data2) {
    this->data2 = data2;
}

//Sets the node's possesing two values to true
void Node::setFull() {
    this->isNodeFull = true;
}

void Node::setLeft(Node* left){
    this->left = left;
}

void Node::setMiddle(Node* middle) {
    this->middle = middle;
}

void Node::setRight(Node* right) {
    this->right = right;
}

int Node::getData1() {
    return this->data1;
}

int Node::getData2() {
    return this->data2;
}

//Returns true if the node possesses two integer values, and false
//if empty or possesses only one integer value
bool Node::isFull() {
    return this->isNodeFull;
}

Node* Node::getLeft() {
    return this->left;
}

Node* Node::getMiddle() {
    return this->middle;
}

Node* Node::getRight() {
    return this->right;
}