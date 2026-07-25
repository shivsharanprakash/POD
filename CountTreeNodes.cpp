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
    public :
    int countNodes(Node*root){
        if(root==NULL) return 0 ;

        int left = countNodes(root->left) ;
        int right = countNodes(root->right) ;
        return 1 + left + right ;
    }
};

int main(){
    Solution sol ;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout<<"Count of nodes in the tree is : "<<sol.countNodes(root)<<endl;
    return 0 ;
}