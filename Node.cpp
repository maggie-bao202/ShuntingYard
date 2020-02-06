#include <iostream>
#include "Node.h"

using namespace std;

Node :: Node(char* newvalue){
  value = newvalue;
  left = NULL;
  right = NULL;
}

Node* Node :: getValue(){
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

void Node :: setLeft(char* newleft){
  left = newleft;
}

void Node :: setRight(char* newright){
  right = newright;
}

Node :: ~Node(){
  delete value;
  left = NULL;
  right = NULL;
}
