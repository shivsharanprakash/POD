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
    bool isCycle(ListNode* head) {

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next;
            while(fast == slow){
                return true ;
            }
        }
        return false;
    }
};

