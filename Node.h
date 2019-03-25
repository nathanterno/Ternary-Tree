#ifndef NODE_H
#define NODE_H

using namespace std;

class Node {
public:
    Node();
    void setData1(int data1);
    void setData2(int data2);
    void setFull();
    void setLeft(Node* left);
    void setMiddle(Node* middle);
    void setRight(Node* right);
    int getData1();
    int getData2();
    bool isFull();
    Node* getLeft();
    Node* getMiddle();
    Node* getRight();

private:
    int data1;
    int data2;
    bool isNodeFull;
    Node* left;
    Node* middle;
    Node* right;
};

#endif   /* NODE_H */