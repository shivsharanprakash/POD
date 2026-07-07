#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode(int data){
        val = data;
        next = NULL;
    }
};

class Solution{
public:

    ListNode* SortedInsert(ListNode* head, int key){

        ListNode* newNode = new ListNode(key);

        ListNode* prev = NULL;
        ListNode* temp = head;

        while(temp != NULL){

            if(temp->val >= key){
                break;
            }

            prev = temp;
            temp = temp->next;
        }

        if(prev == NULL){
            newNode->next = head;
            head = newNode;
        }
        else{
            newNode->next = prev->next;
            prev->next = newNode;
        }

        return head;
    }
};

// Function to print linked list
void display(ListNode* head){

    while(head != NULL){
        cout << head->val << " -> ";
        head = head->next;
    }

    cout << "NULL" << endl;
}

int main(){

    // Creating sorted list: 10 -> 20 -> 30 -> 40

    ListNode* head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);

    cout << "Original List: ";
    display(head);

    int key;
    cout << "Enter value to insert: ";
    cin >> key;

    Solution obj;

    head = obj.SortedInsert(head,key);

    cout << "Updated List: ";
    display(head);

    return 0;
}