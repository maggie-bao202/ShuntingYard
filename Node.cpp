#include <iostream>
#include "Node.h"

using namespace std;

Node :: Node(char newvalue){
  value = newvalue;
  next = NULL;
  left = NULL;
  right = NULL;
  //check = newcheck;
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

/*bool Node :: getCheck(){
  return check;
  }*/

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

/*bool Node :: setCheck(bool newcheck){
  check = newcheck;
}*/

Node :: ~Node(){
  //delete value;
  //left = NULL;
  //right = NULL;
}
