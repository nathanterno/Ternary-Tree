#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include <vector>

using namespace std;

class Tree {
public:
    Tree();
    void setHead(Node* head);
    void setCurrent(Node* current);
    Node* getHead();
    Node* getCurrent();
    bool isEmpty();
    void insert(int newData);
    void printTree();
    void continuePrint(Node* current);
    void searchTree(int value);

private:
    Node* head;
    vector<Node> nodeVector;
};

#endif   /* TREE_H */