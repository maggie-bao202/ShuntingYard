#include <iostream>
#include "Node.h"

using namespace std;

Node :: Node(char newvalue){//Constructor requires a value. All pointers are set to NULL by default
  value = newvalue;
  next = NULL;
  left = NULL;
  right = NULL;
}

//getters

char Node :: getValue(){
  return value;
}

Node* Node :: getLeft(){
  return left;
}

Node* Node :: getRight(){
  return right;
}

Node* Node :: getNext(){
  return next;
}

//setters

void Node :: setValue(char newvalue){
  value = newvalue;
}

void Node :: setLeft(Node* newleft){
  left = newleft;
}

void Node :: setRight(Node* newright){
  right = newright;
}

void Node :: setNext(Node* newnext){
  next = newnext;
}

Node :: ~Node(){//Destructor
  //delete value;
  //left = NULL;
  //right = NULL;
}
