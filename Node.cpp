#include <iostream>
#include "Node.h"

using namespace std;

Node :: Node(char* newvalue){
  value = newvalue;
  left = NULL;
  right = NULL;
}

Node :: getValue(){
  return value;
}

Node :: getLeft(){
  return left;
}

Node :: getRight(){
  return right;
}

Node :: setValue(char* newvalue){
  value = newvalue;
}

Node :: setLeft(char* newleft){
  left = newleft;
}

Node :: setRight(char* newright){
  right = newright;
}

Node :: ~Node(){
  delete value;
  left = NULL;
  right = NULL;
}
