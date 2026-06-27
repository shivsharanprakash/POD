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
     Node * SwapPairs(Node*head){
        if(head==NULL || head->next==NULL)return head;

        Node * first = head ;
        Node * second = head->next ;
        Node *prev = NULL;
        while(first!=NULL && second!=NULL){
            first->next = second->next;
            second->next=first;
            if(prev==NULL){
                head =second;
            }else{
                prev->next=second;
            }
            prev = first ;
            first =prev->next;

            if(first!=NULL){
                second = first->next;
            }else{
                second=NULL;
            }
        }
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
    Node*newHead=s.SwapPairs(head);

    Node*curr=newHead;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
    return 0;
}