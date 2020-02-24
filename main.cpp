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

int main(){
  Node* stackHead = NULL;
  Node* par = NULL;
  Node* tree = NULL;
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
  int counter = 0;
  for (int i = 0; i < strlen(input); i++){
    if ('0' <= input[i] && input[i] <= '9'){//if char is a number
      counter = counter * 10 + (input[i] - '0'); //get number, considering past digit
    }
    else {
      if (input[i] == ' '){//if a space
	if(counter > 0){
	  char c = (char) counter; //push the counter to queue
	  char* cp = &c;
	  enqueue(queueHead, queueHead, cp);
	}
	counter = 0;//reset counter once done
      }
      if (input[i] == '('){//if left paren push onto operator stack
	char* cp = &input[i];
	push(stackHead, cp);
      }
      if (input[i] == ')'){//if right paren
	while (peek(stackHead) != '('){
	  enqueue(queueHead, queueHead, peek(stackHead));
	  pop(stackHead);
	}
	if (peek(stackHead) == ')'){
	  pop(stackHead);
	  delete peek(stackHead);
        }
      else{//if token is operator
	while(peek(stackHead) != ' ' && peek(stackHead) != '(' &&
	     ((precedence[input[i]] < precedence[peek(stackHead)]) ||
	     (precedence[input[i] == precedence[peek(stackHead)] &&
	      associativity[input[i]] == '1'))){
	        enqueue(queueHead, queueHead, peek(stackHead));
		pop(stackHead);
	        push(stackHead, input[i]);
	}
      }
    }
  }
    if (counter != 0){
      char c = (char) counter;
      char* cp = &c;
      enqueue(queueHead, queueHead, cp); 
  }
  while (stackHead->getNext() != NULL){
    enqueue(queueHead, queueHead, peek(stackHead));
    pop(stackHead);
  }
  return 0;
}

  void pop(Node* &stackHead){//remove head node
  Node* temp = stackHead;
  stackHead = stackHead->getNext();
  delete temp;
  temp = NULL;
}

 void push(Node* &stackHead, char* value){//add node to head
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

 void postfix(Node* head) {
  if (head) {
    //Recurse on left node
    printPostfix(head -> getLeft());
    //Recurse on right node
    printPostfix(head -> getRight());
    //Print this node 
    cout << head -> getValue() << " ";
  }
}
