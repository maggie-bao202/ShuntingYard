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
void dequeue(Node*);

void infix(Node*);
void prefix(Node*);
void postfix(Node*);

int main(){
  Node* stackHead = NULL;
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
	  enqueue(queueHead, queueHead, c);
	}
	counter = 0;//reset counter once done
      }
      if (input[i] == '('){//if left paren push onto operator stack
	push(stackHead, input[i]);
      }
      if (input[i] == ')'){//if right paren
	while (stackHead && peek(stackHead) != '('){
	  //
	  enqueue(queueHead, queueHead, peek(stackHead));
	  pop(stackHead);
	}
	if (peek(stackHead) == ')'){
	  pop(stackHead);
        }
      else{//if token is operator
	while(peek(stackHead) != ' ' && peek(stackHead) != '(' &&
	     ((precedence[input[i]] < precedence[peek(stackHead)]) ||
	     (precedence[input[i] == precedence[peek(stackHead)] &&
			 associativity[input[i]] == 'a']))){
	        enqueue(queueHead, queueHead, peek(stackHead));
		pop(stackHead);
	        push(stackHead, input[i]);
	}
      }
    }
  }
  }
    if (counter != 0){
      char c = (char) counter;
      enqueue(queueHead, queueHead, c); 
  }
  while (stackHead->getNext() != NULL){
    enqueue(queueHead, queueHead, peek(stackHead));
    pop(stackHead);
  }
  return 0;
}

  void pop(Node* &stackHead){//remove head node
    if (stackHead == NULL){
      cout << "Nothing" << endl;
    }
    else{
      Node* temp = stackHead;
      stackHead = stackHead->getNext();
      delete temp;
      temp = NULL;
    }
}

 void push(Node* &stackHead, char value){//add node to head
  if (stackHead == NULL){
    stackHead = new Node(value);
    return;
  }
  else{
    Node* temp = stackHead;
    stackHead = new Node(value);
    stackHead->setNext(temp);
    return;
  }
 }

 char peek(Node* stackHead){
  if (stackHead == NULL){
    return NULL;
  }
  else{
    return stackHead->getValue();
  }
 }
 
 /*char* tail(Node* stackHead){
   if (
    
  while (stackHead->getNext() != NULL){
    stackHead = stackHead->getNext();
  }
  char* value = stackHead->getValue();
  return value;
}*/

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
    temp->setNext(NULL);
    delete temp;
  }
  else{
    cout << "Nothing" << endl;
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
    postfix(head -> getLeft());
    //Recurse on right node
    postfix(head -> getRight());
    //Print this node 
    cout << head -> getValue() << " ";
  }
}
