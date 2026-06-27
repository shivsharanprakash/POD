#include<iostream>
using namespace std ;
struct Node {
    int data ;
    Node*next ;
    Node(int val){
        data = val;
        next = NULL;
    }
};

class Solution{
    public :
     Node*AddTwoNumbers(Node*l1, Node*l2){
        Node*head = NULL ;
        Node*temp = NULL ;
        int carry = 0;
        while(l1!=NULL || l2!=NULL||carry!=0){
            int val1 = (l1==NULL)? 0 : l1->data;
            int val2= (l2==NULL) ? 0 : l2->data;
            int value = val1 + val2 + carry;

            Node*newNode = new Node(value%10);
            carry = value/10;

            if(head==NULL){
                head = newNode;
                temp = newNode;
            }else{
                temp->next = newNode;
                temp = temp->next;
            }

            if(l1!=NULL){
                l1=l1->next;
            }
            if(l2!=NULL){
                l2=l2->next;
            }
        }

        return head;
     }
};

int main(){

    // 342 represented as 2->4->3
    Node* l1 = new Node(2);
    l1->next = new Node(4);
    l1->next->next = new Node(3);

    // 465 represented as 5->6->4
    Node* l2 = new Node(5);
    l2->next = new Node(6);
    l2->next->next = new Node(4);

    Solution s;

    Node* result = s.AddTwoNumbers(l1,l2);

    while(result!=NULL){
        cout << result->data << " ";
        result = result->next;
    }

    return 0;
}

