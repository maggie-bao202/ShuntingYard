#include <iostream>

using namespace std;

class Node{
 public:
  Node(int newvalue);
  int getValue();
  Node* getLeft(Node* newleft);
  Node* getRight(Node* newright);
  ~Node();
 private:
  int value;
  Node* left;
  Node* right;
};
