#include <iostream>
#include "Node.h"
#include <vector>
#include <cctype.h>

using namespace std;

//STACK FUNCTIONS
void pop(Node*);
void push(Node*, vector<Node*>*);
void peek(Node*);

//QUEUE FUNCTIONS
void enqueue(Node*, Node*);
void dequeue(Node*);

int main(){
  vector<Node*> firstHead;
  Node* stackHead = NULL;
  Node* queueHead = NULL;
  while (true){
    char* op = new char[40];
    cin.getline(op, 40, '\n');
    Node* node = new Node(op);
    firstHead.push_back(node);
    cout << "Node added." << endl;
    push(stackHead, firstHead);
  }
  return 0;
}

void pop(Node* head){
  
}

void push(Node* stackHead, vector<Node*>* firstHead){
  vector<Node*>::iterator it; //create iterator
  for(it = firstHead.begin(); it != firstHead.end(); it++){
    if(isdigit((*it)->getValue())){
      Node* node = new Node((*it)->getValue());
      stackHead->setRight(node);
      node->setLeft(stackHead);
      
    }
  }
}

void peek(){
  
}

void enqueue(){
  
}

void dequeue(){
  
}
