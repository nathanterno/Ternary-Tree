#include "Tree.h"
#include "Node.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

Tree::Tree() {
    this->head = nullptr;
}

void Tree::setHead(Node* head) {
    this->head = head;
}

Node* Tree::getHead() {
    return this->head;
}

bool Tree::isEmpty() {
    if (this->head == nullptr) {
        return true;
    }
    return false;
}

//Inserts an integer into a node of the tree. If the integer belongs in a place
//where no node exists, a new node is created, the node is linked to the tree
//appropriately, and the integer is set as the new node's first value.
void Tree::insert(int newData) {
    if (this->isEmpty()) {
        Node* nodePointer = new Node();
        nodePointer->setData1(newData);
        this->head = nodePointer;
    }
    else {
        Node* current = this->head;
        bool cont = true;
        while (cont) {
            //Node is not full. new integer is added to the node, and the tw
            //values within the node are reordered if need be.
            if (current->isFull() == false) {
                if (current->getData1() <= newData) {
                    current->setData2(newData);
                }
                else {
                current->setData2(current->getData1());
                current->setData1(newData);
                }
                current->setFull();
                cont = false;
            }
            //The new integer is less than the first value of the node.
            else if (newData <= current->getData1()) {
                //The node has no left child, so a new one is created and the
                //new value is placed therin.
                if (current->getLeft() == nullptr) {
                    Node* nodePointer = new Node();
                    nodePointer->setData1(newData);
                    current->setLeft(nodePointer);
                    cont = false;
                }
                //The node does have a left child, so the function traverses
                //down the tree in that direction.
                else {
                    current = current->getLeft();
                }
            }
            //The new integer is greater than the second value of the node.
            else if (current->getData2() < newData) {
                //The node has no right child, so a new one is created and the
                //new value placed therein.
                if (current->getRight() == nullptr) {
                    Node* nodePointer = new Node();
                    nodePointer->setData1(newData);
                    current->setRight(nodePointer);
                    cont = false;
                }
                //The node does have a right child, so the function traverses
                //down the tree in that direction.
                else {
                    current = current->getRight();
                }
            }
            //The new integer is greater than the first value but less than the
            //second value of the node. The node has no middle child, so a new
            //one is created and the new value placed therein.
            else if (current->getMiddle() == nullptr) {
                Node* nodePointer = new Node();
                nodePointer->setData1(newData);
                current->setMiddle(nodePointer);
                cont = false;
            }
            //The node does have a middle child, so the function traverses down
            //the tree in that direction.
            else {
                current = current->getMiddle();
            }
        }
    }
}

//While this function is called "printTree", it really only sets up the
//printing. The first node to be considered, the head, is passed in as the
//intial value to the "continuePrint" function, which is recursive.
void Tree::printTree() {
    continuePrint(this->head);
    cout << endl;
}

//Recursively prints in the following order in reference to the node passed
//into the function: 1)The node's left child, 2)The first data value of the
//node, 3)The node's middle child, 4)The second value of the node, 5)The
//node's right child. 
void Tree::continuePrint(Node* current) {
    if (current->getLeft() != nullptr) {
        cout << "(";
        continuePrint(current->getLeft());
        cout << ") ";
    }
    cout << current->getData1();
    if (current->getMiddle() != nullptr) {
        cout << " (";
        continuePrint(current->getMiddle());
        cout << ")";
    }
    if (current->isFull() == true) {
        cout << " " << current->getData2();
    }
    if (current->getRight() != nullptr) {
        cout << " (";
        continuePrint(current->getRight());
        cout << ")";
    }
}

//Searched the tree for the value that was passed into the function - all the
//while outputting which path the function is taking along the way.
void Tree::searchTree(int value) {
    if (this->isEmpty()) {
        cout << "Tree is empty!" << endl;
    }
    else {
        Node* current = this->head;
        if (current->getData1() == value) {
            cout << value << " is in the head of the tree! " << value;
            cout << " is the head's first data value." << endl;
        }
        else if (current->getData2() == value) {
            cout << value << " is in the head of the tree! " << value;
            cout << " is the head's second data value." << endl;
        }
        else {
            int layer = 1;
            stringstream pathTaken;
            pathTaken << "Path taken:" << endl;
            bool cont = true;
            while (cont) {
                pathTaken << "Tree Layer #" << layer << " --> ";
                if (current->getData1() == value) {
                    pathTaken << value << " has been found! ";
                    pathTaken << value << " is the first value of the node.";
                    pathTaken << endl;
                    cout << pathTaken.str();
                    cont = false;
                }
                else if (current->getData2() == value) {
                    pathTaken << value << " has been found! ";
                    pathTaken << value << " is the second value of the node.";
                    pathTaken << endl;
                    cout << pathTaken.str();
                    cont = false;
                }
                //The sought-after integer is less than the first value of the
                //node.
                else if (value < current->getData1()) {
                    //The node has no left child.
                    if (current->getLeft() == nullptr) {
                        cout << value << " is not in the tree!" << endl;
                        cont = false;
                    }
                    //The node does have a left child, so the function
                    //traverses down the tree in that direction.
                    else {
                        current = current->getLeft();
                        pathTaken << "left child -->" << endl;
                        layer += 1;
                    }
                }
                //The new integer is greater than the second value of the
                //node.
                else if (current->getData2() < value) {
                    //The node has no right child.
                    if (current->getRight() == nullptr) {
                        cout << value << " is not in the tree!";
                        cont = false;
                    }
                    //The node does have a right child, so the function
                    //traverses down the tree in that direction.
                    else {
                        current = current->getRight();
                        pathTaken << "right child -->" << endl;
                        layer += 1;
                    }
                }
                //The new integer is greater than the first value but less
                //than the second value of the node. The node has no middle
                //child.
                else if (current->getMiddle() == nullptr) {
                cout << value << " is not in the tree!";
                cont = false;
                }
                //The node does have a middle child, so the function traverses
                //down the tree in that direction.
                else {
                    current = current->getMiddle();
                    pathTaken << "middle child -->" << endl;
                    layer += 1;
                }
            }
        }
    }
}