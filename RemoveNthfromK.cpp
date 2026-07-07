class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* first=head;
        ListNode* second=head;

        while(n>0 && second!=NULL){
            n--;
            second=second->next;
        }

        if(n!=0)
            return head;

        // remove first node
        if(second==NULL){

            ListNode* temp=head;
            head=head->next;

            delete temp;

            return head;
        }

        ListNode* prev=NULL;

        while(second!=NULL){

            prev=first;
            first=first->next;
            second=second->next;
        }

        prev->next=first->next;

        delete first;

        return head;
    }
};