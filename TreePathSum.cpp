#include<iostream>
#include<vector>
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
    bool hasPathsum(Node *root,int targetSum){
        if(root==NULL) return false ;

        if(root->left ==NULL && root->right==NULL){
            return root->data == targetSum ;
        }

        return hasPathsum(root->left,targetSum-root->data) || hasPathsum(root->right,targetSum-root->data) ;
    }
};

int main(){
    Solution sol ;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int targetSum ;
    cout<<"Enter the target sum : ";
    cin>>targetSum ;

    if(sol.hasPathsum(root,targetSum)){
        cout<<"There is a path with the given sum."<<endl;
    }else{
        cout<<"There is no path with the given sum."<<endl;
    }

    return 0 ;
}