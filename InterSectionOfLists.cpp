#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if(headA == NULL || headB == NULL)
            return NULL;

        ListNode* s1 = headA;
        ListNode* s2 = headB;

        while(s1 != s2){
            s1 = (s1 == NULL) ? headB : s1->next;
            s2 = (s2 == NULL) ? headA : s2->next;
        }

        return s1;
    }
};

int main() {

    /*
        Create common part:
        8 -> 4 -> 5
    */

    ListNode* common = new ListNode(8);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);

    /*
        List A:
        4 -> 1 -> 8 -> 4 -> 5
    */

    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;

    /*
        List B:
        5 -> 6 -> 1 -> 8 -> 4 -> 5
    */

    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;

    Solution obj;

    ListNode* ans = obj.getIntersectionNode(headA, headB);

    if(ans != NULL)
        cout << "Intersection Node = "
             << ans->val << endl;
    else
        cout << "No intersection found";

    return 0;
}