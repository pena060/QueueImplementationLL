// Using linked list to implement a queue data structure (C++) 
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Node{
  public:
    int value;
    Node* next = NULL;
};

class Queue{
  public:
    Node* head = new Node; // front of queue
    Node* tail = new Node; // end of queue
    int length = 0; // current length of queue

  void peek(){ // check the front of queue
    cout << "PEEK: " << head->value << endl;
  }

  void enqueue(int item){ // add to the end of the queue
    Node* newNode = new Node;
    newNode->value = item;

    if(length == 0){
      head = newNode;
      tail = newNode;
    }else{
      tail->next = newNode;
      tail = newNode;
    }

    length++;
  }

  void dequeue(){ // remove from front of queue

    if(length <=0){
      cout << "ERROR: UNDERFLOW DETECTED!" << endl;
    }

    if(head == tail){
      tail = NULL;
    }

    Node* temp;

    temp = head;

    head = head->next;

    free(temp);
    temp = NULL;

    length--;

  }

  void printQueue(){ // print queue
    Node* currentNode;

    currentNode = head;

    cout << "QUEUE:" << endl;
    cout << "-------" << endl;

    cout << "Head: " << head->value << endl;
    cout << "Tail: " << tail->value << endl;

    while(currentNode != NULL){
      cout << currentNode->value << endl;

      currentNode = currentNode->next;
    }

    cout << endl;

  }

  ~Queue(){ // destructor
    free(head);
    free(tail);

    head = NULL;
    tail = NULL;
  }

};

int main() {
  Queue* myQueue = new Queue;

  myQueue->enqueue(6);
  myQueue->enqueue(10);
  myQueue->enqueue(2);
  myQueue->enqueue(500);

  myQueue->printQueue();

  myQueue->dequeue();
  myQueue->enqueue(45);
  myQueue->printQueue();


  myQueue->peek();

}