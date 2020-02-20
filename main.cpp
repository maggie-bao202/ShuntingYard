#include <iostream>
#include "Node.h"
#include <vector>
#include <cctype.h>

using namespace std;

//STACK FUNCTIONS
void pop(Node*);
void push(Node* &, Node*);
char* peek(Node*);

//QUEUE FUNCTIONS
void enqueue(Node*, Node*);
void dequeue(Node*);

void infix(Node*);
void prefix(Node*);
void postfix(Node*);

int main(){
  vector<char*> vinput = new vector<char*>;
  Node* stackHead = NULL;
  Node* queueHead = NULL;
  char* input = new char[40];

  map<char, int> precedence;
	precedence['^'] = 3;
	precedence['*'] = 2;
	precedence['/'] = 2;
	precedence['+'] = 1;
	precedence['-'] = 1;

  map<char, char> associativity;
	associativity['^'] = 'a';
	associativity['*'] = 'b';
	associativity['/'] = 'b';
	associativity['+'] = 'b';
	associativity['-'] = 'b';

  cin.getline(input, 40, '\n');

  char* temp = new char[strlen(input)]();
  int counter = 0;
  for (int i = 0; i < strlen(input); i++){
    if (input[i] != " "){
      temp[counter++] = input[i];
    }
    else {
      vinput->push_back(temp);
      temp = new char[strlen(input)]();
      counter = 0;
    }
  }
  if (temp){
    vinput->push_back(temp);
  }

  vector<char*> :: iterator it;
  for (it = vinput->begin(); it != vinput->end(); it++){
    if (isdigit(*it)){
      enqueue(queueHead, *it);
    }
    if (strcmp(*it, "(") == 0){
      Node* temp = new Node(*it);
      push(stackHead, temp);
    }
    if (strcmp(*it, ")") == 0){
      while (strcmp(peek(stackHead), "(") != 0){
	pop(stackHead);
	enqueue(queueHead, pop(stackHead));
	//
      }
    }
    else {
      while ((precedence[*it] < precedence[peek(stackHead)])
	     ||(precedence[*it] == precedence[peek(stackHead)]
	     && associativity[*it] == 'a'))
	     && strcmp(peek(stackHead), " ") != 0
	     && strcmp(peek(stackHead), "(") != 0){
      enqueue(queueHead, );
      pop(stackHead);
      }
    Node* temp0 = new Node(*it);
    push(stackHead, temp0);
  }
  Node* node = NULL;
  while (peek(node) != NULL){
    enqueue(queueHead, pop(node));
  }
  while(dequeue(queueHead)){
    if (!isdigit(dequeue(queueHead)){
	Node* temp1 = new Node
  return 0;
}

void pop(Node* &stackHead){
  Node* current = stackHead;
  if (stackHead == NULL){
    return;
  }
  if (current->getNext()->getNext() != NULL){
    current = current->getNext();
  }
  //char* value = current->getNext()->getValue();
  Node* temp = current->getNext();
  current->setNext(NULL);
  delete temp;
  
}

void push(Node* &stackHead, Node* node){
  Node* current = stackHead;
  if (stackHead == NULL){
    stackHead = node;
    return;
  }
  while (current->getNext() != NULL){
    current = current->getNext();
  }
  current->setNext(node);
  return;
}

char* peek(Node* stackHead){
  if (stackHead == NULL){
    return NULL;
  }
  while (stackHead->getNext() != NULL){
    stackHead = stackHead->getNext();
  }
  char* value = stackHead->getValue();
  return value;
}

 void enqueue(Node* &queueHead, char* value){
   if (queueHead == NULL){
     queueHead = new Node(value);
     return;
   }
   if (queueHead->getNext() == NULL){
     Node* temp = new Node(value);
     head->setNext(value);
     return;
   }
   Node* temp = queueHead->getNext();
   enqueue(temp, value);
 }

void dequeue(Node* &queueHead){
  if (queueHead != NULL){
    Node* temp = head;
    head = head->getNext();
    delete temp;
  }
  else{
    return NULL;
  }
}

void infix(Node* node){
  if (node != NULL){
    if(parent
}
