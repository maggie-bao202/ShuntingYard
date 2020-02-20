#include <iostream>

using namespace std;

class Node{
 public:
  Node(char* newvalue);
  char* getValue();
  Node* getNext();
  Node* getLeft();
  Node* getRight();
  void setValue(char* newvalue);
  void setNext(char* newnext);
  void setLeft(Node* newleft);
  void setRight(Node* newright);
  ~Node();
 private:
  char* value;
  Node* next;
  Node* left;
  Node* right;
};
