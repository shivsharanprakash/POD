#include<iostream>
using namespace std;
struct Node{
    int data ;
    Node *left ;
    Node *right ;
    Node(int val){
        data = val ;
        left = NULL ;
        right = NULL ;
    }
};

class Solution{
    public:
       int SumOFNodes(Node*root){
        if(root==NULL) return 0 ;
        
        int left = SumOFNodes(root->left) ;
        int right = SumOFNodes(root->right) ;
        return root->data + left + right ;
       }
};

int main(){
    Solution sol ;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout<<"Sum of nodes in the tree is : "<<sol.SumOFNodes(root)<<endl;
    return 0 ;
}