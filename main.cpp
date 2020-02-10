#include <iostream>
#include "Node.h"
#include <vector>

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
    vector<Node*>::iterator it; //create iterator
    for(it = firstHead.begin(); it != firstHead.end(); it++){
      cout << (it)->getValue();
    }
  }
  return 0;
}

void pop(Node* head){
  
}

void push(){
  
}

void peek(){
  
}

void enqueue(){
  
}

void dequeue(){
  
}
