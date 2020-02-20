#include <iostream>
#include "Node.h"
#include <vector>
#include <iterator>
#include <stack>
#include <map>
#include <vector>
#include <cstring>
#include <cctype>

using namespace std;

//STACK FUNCTIONS
void pop(Node* &);
void push(Node* &, char*);
char* peek(Node*);

//QUEUE FUNCTIONS
void enqueue(Node*&, Node*, char*);
void dequeue(Node*);

void infix(Node*);
void prefix(Node*);
void postfix(Node*);

bool checkInt(char*);

int main(){
  vector<char*> vinput;
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
    if (input[i] != ' '){
      temp[counter++] = input[i];
    }
    else {
      vinput.push_back(temp);
      temp = new char[strlen(input)]();
      counter = 0;
    }
  }
  if (temp != NULL){
    vinput.push_back(temp);
  }

  vector<char*> :: iterator it;
  for (it = vinput.begin(); it != vinput.end(); it++){
    if (isdigit(*it)){
      enqueue(queueHead, queueHead, *it);
    }
    if (strcmp(*it, "(") == 0){
      Node* temp = new Node(*it);
      push(stackHead, temp);
    }
    if (strcmp(*it, ")") == 0){
      while (strcmp(peek(stackHead), "(") != 0){
	enqueue(queueHead, queueHead, peek(stackHead));
	pop(stackHead);
      }
    }
    else {
      while ((precedence[*it] < precedence[peek(stackHead)])
	     ||(precedence[*it] == precedence[peek(stackHead)]
	     && associativity[*it] == 'a'))
	     && strcmp(peek(stackHead), " ") != 0
	     && strcmp(peek(stackHead), "(") != 0){
      enqueue(queueHead, queueHead, peek(stackHead));
      pop(stackHead);
    }
    /*Node* temp0 = new Node(*it);
    push(stackHead, temp0);
  }
  Node* node = NULL;
  while (peek(node) != NULL){
    enqueue(queueHead, pop(node));
  }
  while(dequeue(queueHead)){
    if (!isdigit(dequeue(queueHead)){
    Node* temp1 = new Node*/
  return 0;
}

void pop(Node* &stackHead){
  Node* temp = stackHead;
  stackHead = stackHead->getNext();
  delete temp;
  temp = NULL;
}

void push(Node* &stackHead, char* value){
  if (stackHead == NULL){
    Node* current = new Node(value);
    stackHead = current;
    return;
  }
  else{
    Node* current = new Node(value);
    Node* temp = stackHead;
    stackHead = current;
    current->setNext(temp);
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

void enqueue(Node* &queueHead, Node* node, char* value){//insert tail
   if (node == NULL){ //if node pointer does not exist
     Node* current = new Node(value); //make student the current node pointer
     head = current; //make current the head
     return;
   }
   if (node->getNext() == NULL){//if next node pointer does not exist
     Node* current = new Node(value);
     node->setNext(current); //set next node pointer as the current
     return;
   }
   enqueue(queueHead, node->getNext(), value); //recursive function returns itself
 }
      
void dequeue(Node* &queueHead){//remove head
  if (queueHead != NULL){
    Node* temp = queueHead;
    head = head->getNext();
    temp->setNext(NULL);
    delete temp;
  }
  else{
    return NULL;
  }
}
 
void infix(Node* node){
  if (node != NULL){
    if(node){
    }
  }
}
