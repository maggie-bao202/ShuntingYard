#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

class Node{
 public:
  Node(char newvalue);
  char getValue();
  Node* getNext();
  Node* getLeft();
  Node* getRight();
  //bool getCheck();
  void setValue(char newvalue);
  void setNext(Node* newnext);
  void setLeft(Node* newleft);
  void setRight(Node* newright);
  //bool setCheck(bool newcheck);
  ~Node();
 private:
  char value;
  Node* next;
  Node* left;
  Node* right;
  //bool check;
};

#endif
