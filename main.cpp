#include <iostream>
#include "Node.h"
#include <iterator>
#include <map>
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

Node* createTree(Node*, Node*&);
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

	cout << "Enter: ";
  cin.getline(input, 40);
  cout << "Postfix: ";
  for (int i = 0; i < strlen(input); i++){
    if (input[i] != ' '){
      if (isdigit(input[i])){//if a space
	cout << input[i] << " ";
	  enqueue(queueHead, queueHead, input[i]);
      }
      else if (input[i] == '('){//if left paren, push onto operator stack
	push(stackHead, input[i]);
      }
      else if (input[i] == ')'){//if right paren
	Node* temp = stackHead;
	while (peek(temp) != '('){
	  cout << peek(temp) << " ";
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
	  cout << peek(stackHead) << " ";
	  enqueue(queueHead, queueHead, peek(stackHead));
	  pop(stackHead);
	}
	push(stackHead, input[i]);
      }
    }
  }
  while (stackHead != NULL){
    cout << peek(stackHead) << " ";
    enqueue(queueHead, queueHead, peek(stackHead));
    pop(stackHead);
  }
  cout << endl;
  expression = createTree(queueHead, stackHead);
  cout << "prefix: ";
  prefix(expression);
  cout << "postfix: ";
  postfix(expression);
  cout << "infix:  ";
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

/*Node* tail(Node* node){
  if (node == NULL){
    return NULL;
  }
  while (node->getNext() != NULL){
    node = node->getNext();
   }
  return node;
  }
  */
  

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
    if (queueHead->getNext() != NULL){
      queueHead = queueHead->getNext();
      delete temp;
    }
    else{
      delete temp;
      queueHead = NULL;
    }
  }
}
 
Node* createTree(Node* queueHead, Node* &stackHead) {
  while (queueHead != NULL){
    if (peek(queueHead) >= '0' && peek(queueHead) <= '9'){
      Node* t = new Node(peek(queueHead));
      push(stackHead, t->getValue());
    }
    else {
      Node* t = new Node(peek(queueHead));
      Node* right = new Node(peek(stackHead));
      cout << peek(stackHead) << endl;
      cout << "right" << peek(right);
      pop(stackHead);
      Node* left = new Node(peek(stackHead));
      cout << peek(stackHead) << endl;
      cout <<"left"<< peek(left);
      pop(stackHead);
      t->setRight(right);
      t->setLeft(left);
      push(stackHead, peek(t));
    }
    queueHead = queueHead->getNext();
  }
  Node* t = new Node(peek(stackHead));
  pop(stackHead);
  return t;
}

void infix(Node* stackHead) {
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

void prefix(Node* stackHead) {
	if (stackHead != NULL) {
		cout << peek(stackHead) << " ";
		prefix(stackHead->getLeft());
		prefix(stackHead->getRight());
	}
}

void postfix(Node* stackHead) {
	if (stackHead != NULL) {
		postfix(stackHead->getLeft());
		postfix(stackHead->getRight());
		cout << peek(stackHead) << " ";
	}

}
