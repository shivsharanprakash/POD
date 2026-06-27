#include<iostream>
using namespace std ;
struct Node{
    int val ;
    Node*next ;
    Node *prev;
    Node(int data){
        val=data;
        next=NULL ;
        prev=NULL;
    }
};

class DoublyLinedList{
    private:
     Node*start;
    public :
     DoublyLinedList(){
        start=NULL;
     } 

     void insertAtFirst(int data){
        Node *newNode= new Node(data);
        if(start==NULL){
            start=newNode;
            return;
        }

        newNode->next=start;
        start->prev=newNode;
        start=newNode;
        newNode->prev=NULL;
     }

     void insertAtLast(int data){
        Node *newNode= new Node(data);
        if(start==NULL){
            start =newNode;
            return;
        }

        Node*temp =start;
        while(temp->next!=NULL){
            temp =temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
        temp=newNode;
     }

     void insertAtPosition(int data,int pos){
        Node *newNode=new Node(data);
        if(pos==1){
            newNode->next=start;
            if(start!=NULL){
                start->prev=newNode;
            }
            start=newNode;
            return;
        }

        Node *temp =start;
        for(int i =1;i<pos-1;i++){
            if(temp==NULL){
                cout<<"Out of Bounds"<<endl;
                return ;
            }
            temp=temp->next;
        }
        newNode->next=temp->next;
        if(temp->next!=NULL){
            temp->next->prev=newNode;
        }
        else{
            newNode->next=NULL;
        }
        temp->next=newNode;
        newNode->prev=temp;
     }

     void deleteFirst(){
        if(start==NULL){
            return;
        }
        Node *temp=start ;
        start=start->next;
        start->prev=NULL;
        delete temp;
     }

     void deleteLast(){
        if(start==NULL){
            return ;
        }

        if(start->next==NULL){
            delete start;
            start=NULL;
            return ;
        }

        Node *temp =start ;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->prev->next=NULL;
        delete temp;
     }

     void deleteAtPosition(int pos){
        if(start==NULL){
            return ;
        }

        if(pos==1){
            Node *temp =start;
            start =start->next;
            if(start!=NULL){
                start->prev=NULL;
            }
            delete temp;
            return;
        }
        Node *temp =start;
        for(int i =1;i<pos;i++){
            if(temp==NULL){
                cout<<"Out of Bounds"<<endl;
                return;
            }
            temp=temp->next;
        }
        temp->prev->next=temp->next;
        if(temp->next!=NULL){
            temp->next->prev=temp->prev;
        }
        delete temp;
     }


     void prinList(){
        Node *temp =start;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
     }
};

int main(){
    DoublyLinedList dll;
    dll.insertAtFirst(10);
    dll.insertAtFirst(20);
    dll.insertAtLast(30);
    dll.insertAtLast(40);
    dll.insertAtPosition(25,3);
    dll.prinList();
    cout<<endl;
    dll.deleteFirst();
    dll.prinList();
    cout<<endl;
    dll.deleteLast();
    dll.prinList();
    cout<<endl;
    dll.deleteAtPosition(2);
    dll.prinList();
}