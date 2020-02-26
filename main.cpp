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
	
do {//condition starts false, so use do while to run one time first
    Node* stackHead = NULL;
    Node* queueHead = NULL;
    cout << "Enter in an expression, using operators '+', '-', '*', '/', and '^', seperated by spaces: " << endl;
    cin.getline(input, 40);
    cout << "Postfix: ";

    /*To create postfix expression, followed the pseudocode/algorithm on wikipedia--"Shunting-yard algorithm". */
    
    for (int i = 0; i < strlen(input); i++){//search through each token of input
      if (input[i] != ' '){//ignore spaces
	if (isdigit(input[i])){//if number
	  cout << input[i] << " ";
	  enqueue(queueHead, queueHead, input[i]);//put into queue
	}
	else if (input[i] == '('){//if left paren
	  push(stackHead, input[i]);//push to operator stack
	}
	else if (input[i] == ')'){//if right paren
	  Node* temp = stackHead;
	  while (peek(temp) != '('){//search for the left paren without losing stackhead, then put into queue while removing it from stack
	    cout << peek(temp) << " ";
	    enqueue(queueHead, queueHead, peek(temp));
	    pop(temp);
	  }
	  stackHead = temp->getNext();
	  delete temp;//discard temporary node
	}
	else{//if token is operator
	  while(peek(stackHead) != '(' && peek(stackHead) != ' ' &&
	     ((precedence[input[i]] < precedence[peek(stackHead)]) ||
	     (precedence[input[i] == precedence[peek(stackHead)] &&
			 associativity[input[i]] == 'a']))){//meets specific set of conditions
	    cout << peek(stackHead) << " ";
	    enqueue(queueHead, queueHead, peek(stackHead));//put stackhead into queue
	    pop(stackHead);//remove from stack
	  }
	  push(stackHead, input[i]);//push operator tokens to stack
	}
      }
    }
    while (stackHead != NULL){//while still operator tokens on stack
      cout << peek(stackHead) << " ";//print remaining
      enqueue(queueHead, queueHead, peek(stackHead));//add to queue
      pop(stackHead);//remove from stack, until stack should be empty
    }
   cout << endl;
   createTree(stackHead, queueHead);//build tree given the postfix/queue
   cout << "- - - " << endl;
   cout << "Binary Expression Tree Created." << endl;
   cout << "- - - " << endl;
  //TESTING
  /*cout << "INFIX" << endl;
  infix(stackHead);
  cout << endl;
  cout << "PREFIX" << endl;
  prefix (stackHead);
  cout << endl;
  cout << "POSTFIX" << endl;
  postfix(stackHead);
  cout << endl;*/
   bool again = true;//will continue prompting for keyword until QUIT or NEW
   while(again == true){
     cout << endl;
     cout << "Enter a keyword to display \"INFIX\", \"PREFIX\", or \"POSTFIX\". Enter \"NEW\" to input a new expression. Enter \"QUIT\" to exit."<< endl;
     cin.get(input, 10); //put into array of 10. Extra char will be ignored
     cin.clear(); //clear, ignore fixes null bug
     cin.ignore(9999, '\n');
     if (strcmp(input, "INFIX") == 0){//if keyword char pointer matches with str
       infix(stackHead);//recursive infix print
     }
     else if (strcmp(input, "PREFIX") == 0){
       prefix(stackHead);//recursive prefix print
     }
     else if (strcmp(input, "POSTFIX") == 0){
       postfix(stackHead);//recursive postfix print
     }
     else if(strcmp(input, "NEW") == 0){
       stillPlaying = true;//condition in do while is true, so go back to top
       again = false;
     }
     else if (strcmp(input, "QUIT") == 0){
       cout << "Have a nice day!" << endl;
       stillPlaying = false;
       again = false;//exit program
     }
     else{
       cout << "Make sure the keyword is capitalized." << endl;
     }
   }
 } while(stillPlaying == true);
  return 0;
}

void pop(Node* &stackHead){//removes head node
  if (stackHead != NULL){//create temporary node to delete head, make head the next node of the stack instead
    Node* temp = stackHead;
    stackHead = stackHead->getNext();
    delete temp;//clear value in node
  }
  else {
    return;
  }
}

void push(Node* &stackHead, char value){//add the new node as the head
  if (stackHead != NULL){
    Node* temp = stackHead; //make temp to keep place of stackhead node
    stackHead = new Node(value); //create a node w value and assign it to stackhead
    stackHead->setNext(temp);
  }
  else{//if there is nothing in the list
    stackHead = new Node(value);
  }
}

char peek(Node* stackHead){//gets the value of head. Could just use stackHead-.getValue() directly tbh
  if (stackHead != NULL){
    return stackHead->getValue();
  }
}

void enqueue(Node* &queueHead, Node* node, char value){//insert node at tail, taken from my linkedlist assignment
  if (node == NULL){
    Node* temp = new Node(value);
    queueHead = temp; //make current the head
    return;
  }
  if (node->getNext() == NULL){//if next node pointer does not exist
    Node* temp = new Node(value);
    node->setNext(temp);
    return;
  }
  enqueue(queueHead, node->getNext(), value);
}
      
void dequeue(Node* &queueHead){//remove head of list
  if (queueHead != NULL){
    Node* temp = queueHead;//create temp
    queueHead = queueHead->getNext();//make head the next node
    delete temp;//clear data of original
  }
}

/*createTree follows the description of "Construction of an expression tree" in the wikipedia artice on the Binary expression tree, as well as the algorithm of constructTree on geeksforgeeks. It starts with a queue containing the postfix and an empty stack. */

void createTree(Node* &stackHead, Node* queueHead) {//return modified stack
  while (queueHead != NULL){
    if (isdigit(peek(queueHead))){//if it is an operand/number
      push(stackHead, peek(queueHead));//push onto the stack--one node trees are created
    }
    else{//if it is an operator
      Node* b = new Node(peek(stackHead));//create a new node from the operand on the stack
      //make the pointers in b point to wherever the stackHead is pointing (node or null)
      b->setLeft(stackHead->getLeft());
      b->setRight(stackHead->getRight());
      pop(stackHead);//remove the operand from stack, so we can access the next number in stack
      
      Node* a = new Node(peek(stackHead));//create new node from next operand in stack
      //set pointers in node a
      a->setLeft(stackHead->getLeft());
      a->setRight(stackHead->getRight());
      pop(stackHead);//remove operand from stack

      //make operator into new head node in stack, then set the pointers to create tree
      push(stackHead, peek(queueHead));
      stackHead->setRight(b);
      stackHead->setLeft(a);
    }
    queueHead = queueHead->getNext();//traverse through queue
  }
}

/*Infix, prefix, and postfix print functions are taken from the wikipedia article's algorithms on the Binary expression tree. */

void infix(Node* stackHead) {//opening and closing parenthesis added to beginning and end of expression.
  if (stackHead != NULL) {
    if (!isdigit(peek(stackHead))) {//Whenever a node in stack is operator
      cout << "( ";//print out left paren
    }
    infix(stackHead->getLeft()); //go though the left pointer's node first
    cout << peek(stackHead) << " "; //print out either operand at the bottom of tree, or operator
    infix(stackHead->getRight());//after, go through right pointer's node
    if (!isdigit(peek(stackHead))) {//whenever a node in stack is operator and processed all children
      cout << ") ";
    }
  }
}

void prefix(Node* stackHead) {//postorder traversal, operators precede operands
  if (stackHead != NULL) {
    cout << peek(stackHead) << " "; //will alternate between operators and operands depending on tree construction; will print operators in process of getting to operands
    prefix(stackHead->getLeft());//to get left operand print
    prefix(stackHead->getRight());//to get right operand print
  }
}

void postfix(Node* stackHead) {//postorder traversal, operands, then operators
  if (stackHead != NULL) {
    postfix(stackHead->getLeft());//go to bottom of tree from left pointers, then print operand
    postfix(stackHead->getRight());//go to bottom of tree from right pointers, then print operand
    cout << peek(stackHead) << " "; //print operators and operands, but after all operands are printed should print only operators
  }
}
