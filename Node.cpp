#include <iostream>
#include "Node.h"

using namespace std;

Node :: Node(char newvalue){
  value = newvalue;
  next = NULL;
  left = NULL;
  right = NULL;
}

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

Node :: ~Node(){
  //delete value;
  //left = NULL;
  //right = NULL;
}
