#include<iostream>
#include<vector>
using namespace std ;

struct ListNode{
    int val;
    ListNode*next;
    ListNode(int data){
        val=data;
        next=NULL;
    }
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {

        ListNode* slow=head;
        ListNode* fast=head;

        ListNode* newHeadList=NULL;

        while(fast!=NULL && fast->next!=NULL){

            ListNode* node=new ListNode(slow->val);
            node->next=newHeadList;
            newHeadList=node;

            slow=slow->next;
            fast=fast->next->next;
        }

        if(fast!=NULL){
            slow=slow->next;
        }

        while(slow!=NULL && newHeadList!=NULL){

            if(slow->val!=newHeadList->val)
                return false;

            slow=slow->next;
            newHeadList=newHeadList->next;
        }

        return true;
    }
};