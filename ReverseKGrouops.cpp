#include<iostream>
using namespace std ;

struct ListNode{
    int val ;
    ListNode *next ;
    ListNode(int data){
        val =data ;
        next = NULL;
    }
};

class Solution {
    public:
      ListNode * reverseKGroups(ListNode * head,int k){
        if(head ==NULL || head->next==NULL) return head ;
        
        ListNode * curr = head ;
        int count = 0 ;
        while(curr!=NULL && count <k){
            curr = curr->next ;
            count ++;

        }

        if(count < k) return head ;

        ListNode * prev = NULL;
        ListNode * next = NULL;
        ListNode * current = head;

        for( int i =0;i<k;i++){
            next = current->next ;
            current->next = prev ;
            prev = current;
            current=next ;
        }
        head->next = reverseKGroups(current,k);  
        
        return prev ;
      }
};

int main(){

    int n;

    cout<<"Enter number of ListNodes: ";
    cin>>n;

    if(n==0)
        return 0;

    int data;

    cout<<"Enter elements: ";

    cin>>data;
    ListNode* head=new ListNode(data);

    ListNode* temp=head;

    for(int i=1;i<n;i++){

        cin>>data;

        ListNode* newListNode=new ListNode(data);

        temp->next=newListNode;

        temp=temp->next;
    }

    Solution obj;

    head=obj.OddEvenList(head);

    return 0;
}