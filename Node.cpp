#include <iostream>
#include "Node.h"

using namespace std;

Node :: Node(char* newvalue){
  value = newvalue;
  left = NULL;
  right = NULL;
}

char* Node :: getValue(){
  return value;
}

Node* Node :: getLeft(){
  return left;
}

Node* Node :: getRight(){
  return right;
}

void Node :: setValue(char* newvalue){
  value = newvalue;
}

void Node :: setLeft(Node* newleft){
  left = newleft;
}

void Node :: setRight(Node* newright){
  right = newright;
}

Node :: ~Node(){
  delete value;
  left = NULL;
  right = NULL;
}
