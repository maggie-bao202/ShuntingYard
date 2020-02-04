#include <iostream>

using namespace std;

class Node{
 public:
  Node(char* newvalue);
  char* getValue();
  Node* getLeft();
  Node* getRight();
  void setValue(char* newvalue);
  void setLeft(Node* newleft);
  void setRight(Node* newright);
  ~Node();
 private:
  char* value;
  Node* left;
  Node* right;
};
