#include<iostream>
using namespace std ;

struct Node{
  int val ;
  Node*next ;
  //Node(int data){
  //  val=data ;
  //  next=NULL ;
  //}
};

class SinglyLinkedList{
  private:
   Node *start;

  public:
    SinglyLinkedList(){
      start = NULL ;
    }

    void insertAtFirst(int data){
      Node *newNode = new Node();
      newNode->val=data;
      newNode->next=start;
      start=newNode;
    }

    void insertAtLast(int data){

    Node* newNode = new Node();
    newNode->val = data;
    newNode->next = NULL;

    if(start==NULL){
        start = newNode;
        return;
    }

    Node* temp = start;

    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=newNode;
}

    void deleteFirst(){

    if(start==NULL)
        return;

    Node* temp=start;
    start=start->next;
    delete temp;
}

    void deleteLast(){

    if(start==NULL)
        return;

    if(start->next==NULL){
        delete start;
        start=NULL;
        return;
    }

    Node* temp=start;

    while(temp->next->next!=NULL){
        temp=temp->next;
    }

    delete temp->next;
    temp->next=NULL;
}

void addAtPosition(int data ,int pos){
  Node *newNode = new Node(data);
  if(pos==1){
    newNode->next=start;
    start=newNode;
  }

  Node *temp =start;
  for(int i =1;i<pos-1;i++){
    temp=temp->next;
  }
  newNode->next=temp->next;
  temp->next=newNode;
}

void deleteAtPosition(int pos){
  if(pos==1){
    Node*temp =start ;
    start=start->next;
    delete temp;
  }

  Node *temp =start ;
  for(int i =1;i<pos-1;i++){
    temp=temp->next;
  }

  Node*delNode =temp->next;
  temp->next=delNode->next;
  delete delNode;
}
    void printList(){
      Node *temp = start ;
      while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
      }
    }
};


int main(){

  SinglyLinkedList sll ;
  sll.insertAtFirst(10);
  sll.insertAtFirst(20);
  sll.insertAtLast(30);
  sll.insertAtLast(40);
  sll.printList();
  cout<<endl;
  sll.deleteFirst();
  sll.printList();
  cout<<endl;
  sll.deleteLast();
  sll.printList();
  cout<<endl;
  sll.addAtPosition(50, 2);
  sll.printList();
  cout<<endl;
  sll.deleteAtPosition(2);
  sll.printList();


  return 0 ;
}