#include<iostream>
using namespace std;
struct Node{
    int data;
    Node*next;
    Node(int val){
        data=val;
        next=NULL;
    }
};

class Solution{
    public:
    Node* deleteMiddleNode(Node* head) {
        Node*slow=head;
        Node*fast=head;
        Node*prev=NULL;
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow = slow->next;
            fast= fast->next->next;
        }
        prev->next=slow->next;
        delete slow;
        return head;
    }
};

int main(){
    Node*head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    head->next->next->next->next->next=new Node(6);
    Solution s;
    Node*newHead=s.deleteMiddleNode(head);

    Node*curr=newHead;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}