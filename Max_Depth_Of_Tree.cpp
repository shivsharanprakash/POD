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
    int maxDepth(Node *root){
        if(root==NULL){
            return 0;
        }

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left,right)+1;
    }
};

int main(){
    Solution sol ;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout<<"Max Depth of the tree is : "<<sol.maxDepth(root)<<endl;
    return 0 ;
}

