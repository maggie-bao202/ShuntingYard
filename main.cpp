#include <iostream>
#include "Node.h"
#include <map>
#include <cstring>
#include <cctype>

using namespace std;
/*Author: Maggie Bao. Description: Shuntingyard takes an expression from input, and prints out the infix, prefix, and/or postfix by converting it into a binary expression tree.*/

//STACK FUNCTIONS
void pop(Node* &);
void push(Node* &, char);
char peek(Node*);

//QUEUE FUNCTIONS
void enqueue(Node*&, Node*, char);
void dequeue(Node*&);

void createTree(Node*&, Node*);

//RECURSIVE PRINTS
void infix(Node*);
void prefix(Node*);
void postfix(Node*);

int main(){
  char* input = new char[40];
  bool stillPlaying = false;

  //Maps used to rank order of operators.
  
  map<char, int> precedence;
        precedence['^'] = 2;
        precedence['*'] = 1;
        precedence['/'] = 1;
        precedence['+'] = 0;
        precedence['-'] = 0;

  map<char, char> associativity;
	associativity['-'] = 'b';
	associativity['+'] = 'b';
	associativity['*'] = 'b';
	associativity['/'] = 'b';
	associativity['^'] = 'a';
	
  do {
  Node* stackHead = NULL;
  Node* queueHead = NULL;
  cout << "Enter in an expression, using operators '+', '-', '*', '/', and '^': " << endl;
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
	while(peek(stackHead) != '(' && peek(stackHead) != ' ' &&
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
  createTree(stackHead, queueHead);
  cout << endl;
  cout << "Binary Expression Tree Created." << endl;
  cout << "INFIX" << endl;
  infix(stackHead);
  cout << endl;
  cout << "PREFIX" << endl;
  prefix (stackHead);
  cout << endl;
  cout << "POSTFIX" << endl;
  postfix(stackHead);
  cout << endl;
  bool again = true;//will continue prompting for keyword until quit
  while(again == true){
    cout << endl;
     cout << "Enter a keyword to display \"INFIX\", \"PREFIX\", or \"POSTFIX\". Enter \"NEW\" to input a new expression. Enter \"QUIT\" to exit."<< endl;
    cin.get(input, 10); //put into array of 10. Extra char will be ignored
    cin.clear(); //clear, ignore fixes null bug
    cin.ignore(9999, '\n');
    if (strcmp(input, "INFIX") == 0){//if keyword char pointer matches with str
      infix(stackHead);
    }
    else if (strcmp(input, "PREFIX") == 0){
      prefix(stackHead);
    }
    else if (strcmp(input, "POSTFIX") == 0){
      postfix(stackHead);
    }
    else if(strcmp(input, "NEW") == 0){
      stillPlaying = true;
      again = false;
    }
    else if (strcmp(input, "QUIT") == 0){
      cout << "Have a nice day!" << endl;
      stillPlaying = false;
      again = false;
    }
    else{
      cout << "Make sure the keyword is capitalized." << endl;
    }
  }
  }while(stillPlaying == true);
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

/*Node* tail(Node* &stackHead){
  Node* current = stackHead;
  while (stackHead != NULL){
    while (current->getNext() != NULL){
      current = current->getNext();
    }
    return current;
}*/
 
void createTree(Node* &stackHead, Node* queueHead) {
  while (queueHead != NULL){
    if (isdigit(peek(queueHead))){//if it is a number
      push(stackHead, peek(queueHead));//push onto the stack
    }
    else{//if operator
      Node* b = new Node(peek(stackHead));//pointers a and b are popped from stack
      b->setLeft(stackHead->getLeft());
      b->setRight(stackHead->getRight());
      pop(stackHead);
      Node* a = new Node(peek(stackHead));
      a->setLeft(stackHead->getLeft());
      a->setRight(stackHead->getRight());
      pop(stackHead);
      push(stackHead, peek(queueHead));
      stackHead->setRight(b);
      stackHead->setLeft(a);
    }
      queueHead = queueHead->getNext();
  }
}

void infix(Node* stackHead) {
  if (stackHead != NULL) {
    if (!isdigit(peek(stackHead))) {
      cout << "( ";
    }
    infix(stackHead->getLeft());
    cout << peek(stackHead) << " ";
    infix(stackHead->getRight());
    if (!isdigit(peek(stackHead))) {
      cout << ") ";
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
