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
void push(Node* &, char);
char peek(Node*);

//QUEUE FUNCTIONS
void enqueue(Node*&, Node*, char);
void dequeue(Node*&);

void tree(Node*, Node*&);
void infix(Node*);
void prefix(Node*);
void postfix(Node*);

//Node* tail(Node*);

int main(){
  Node* stackHead = NULL;
  Node* expression = NULL;
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
	
  cin.getline(input, 40);
  for (int i = 0; i < strlen(input); i++){
    if (input[i] != ' '){
      if (isdigit(input[i])){//if a space
	  enqueue(queueHead, queueHead, input[i]);
      }
      else if (input[i] == '('){//if left paren, push onto operator stack
	push(stackHead, input[i]);
      }
      else if (input[i] == ')'){//if right paren
	Node* temp = stackHead;
	while (peek(temp) != '('){
	  enqueue(queueHead, queueHead, peek(temp));
	  pop(temp);
	}
	stackHead = temp->getNext();
	delete temp;
      }
      else{//if token is operator
	while(peek(stackHead) != ' ' && peek(stackHead) != '(' &&
	     ((precedence[input[i]] < precedence[peek(stackHead)]) ||
	     (precedence[input[i] == precedence[peek(stackHead)] &&
			 associativity[input[i]] == 'a']))){
	        enqueue(queueHead, queueHead, peek(stackHead));
		pop(stackHead);
	}
	push(stackHead, input[i]);
      }
    }
  }
  while (stackHead != NULL){
    enqueue(queueHead, queueHead, peek(stackHead));
    pop(stackHead);
  }
  char* postfix = new char[100];
	int num = 0;
	while (queueHead != NULL) { // Empty queue into a char array.
		char qHead = peek(queueHead);
		dequeue(queueHead);
		postfix[num] = qHead;
		postfix[num+1] = ' ';
		num += 2;
	}
	postfix[num] = '\0';
	cout << postfix << endl;
  tree(queueHead, stackHead);
  prefix(expression);
  postfix(expression);
  infix(expression);
  return 0;
}

  void pop(Node* &stackHead){//remove head node
    if (stackHead != NULL){
      Node* temp = stackHead;
      stackHead = stackHead->getNext();
      delete temp;
    }
    else {
      return;
    }
}
/*
Node* tail(Node* node){
  if (node == NULL){
    return NULL;
  }
  while (node->getNext() != NULL){
    node = node->getNext();
   }
  return node;
  }*/
  
  

 void push(Node* &stackHead, char value){//add node to head
   if (stackHead != NULL){
     Node* temp = stackHead;
     stackHead = new Node(value);
     stackHead->setNext(temp);
   }
   else{
     stackHead = new Node(value);
   }
 }

 char peek(Node* stackHead){
   if (stackHead != NULL){
    return stackHead->getValue();
  }
 }

void enqueue(Node* &queueHead, Node* node, char value){//insert tail
   if (node == NULL){ //if node pointer does not exist
     Node* current = new Node(value); //make student the current node pointer
     queueHead = current; //make current the head
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
    queueHead = queueHead->getNext();
    delete temp;
  }
}
 
void* tree(Node* queueHead, Node* &stackHead) { // Create binary expression tree.
  while (tail(queueHead) != NULL){
    if (peek(queueHead) >= '0' && peek(queueHead) <= '9'){
      push(stackHead, peek(queueHead));
    }
    else {
      Node* node = new Node(peek(queueHead));
      dequeue(queueHead);
      node->setLeft(tail(stackHead));
      pop(stackHead);
      node->setRight(tail(stackHead));
      pop(stackHead);
      push(stackHead, peek(queueHead));
    }
  }
}

void infix(Node* stackHead) { // Traverse through with parentheses for PEMAS.
	if (stackHead != NULL) {
		if (!isdigit(peek(stackHead))) {
			cout << "(" << " ";
		}
		infix(stackHead->getLeft());
		cout << peek(stackHead) << " ";
		infix(stackHead->getRight());
		if (!isdigit(peek(stackHead))) {
			cout << ")" << " ";
		}
	}
}

void prefix(Node* stackHead) { // Print prefix, print before continuing.
	if (stackHead != NULL) {
		cout << peek(stackHead) << " ";
		prefix(stackHead->getLeft());
		prefix(stackHead->getRight());
	}
}

void postfix(Node* stackHead) { // Print postfix, print after continuing.
	if (stackHead != NULL) {
		postfix(stackHead->getLeft());
		postfix(stackHead->getRight());
		cout << peek(stackHead) << " ";
	}

}
