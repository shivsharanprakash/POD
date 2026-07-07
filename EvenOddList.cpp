#include<iostream>
using namespace std ;

struct Node{
    int val ;
    Node *next ;
    Node(int data){
        val =data ;
        next = NULL;
    }
};

class Solution {
    public:
      Node * OddEvenList(Node * head){
        if(head ==NULL || head->next==NULL) return head ;

        Node* odd = head ;
        Node* even = head->next ;
        Node* evenHead = even ;

        while(even!=NULL && even->next !=NULL){
            odd->next = even->next ;
            odd = odd->next;
            even->next = odd->next ;
            even = even->next ;
        }

        odd->next =evenHead;
        return head ;
      }
};

int main(){

    int n;

    cout<<"Enter number of nodes: ";
    cin>>n;

    if(n==0)
        return 0;

    int data;

    cout<<"Enter elements: ";

    cin>>data;
    Node* head=new Node(data);

    Node* temp=head;

    for(int i=1;i<n;i++){

        cin>>data;

        Node* newNode=new Node(data);

        temp->next=newNode;

        temp=temp->next;
    }

    Solution obj;

    head=obj.OddEvenList(head);

    return 0;
}