#ifndef NODE_H
#define NODE_H

#include <iostream>
//Includes the function prototypes for the node class. getters and setters for left and right node pointers are used in the binary expression tree.
using namespace std;

class Node{
public://functions
  Node(char newvalue);
  char getValue();
  Node* getNext();
  Node* getLeft();
  Node* getRight();
  void setValue(char newvalue);
  void setNext(Node* newnext);
  void setLeft(Node* newleft);
  void setRight(Node* newright);
  ~Node();
private://variables
  char value;
  Node* next;
  Node* left;
  Node* right;
};

#endif
