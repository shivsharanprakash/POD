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
       int diameter = 0;
       int height(Node*root){
        if(root==NULL) return -1;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        diameter = max(diameter,leftHeight+rightHeight+2);
        return max(leftHeight,rightHeight)+1;
       }

         int diameterOfBinaryTree(Node*root){
          height(root);
          return diameter;
         }
};


int main(){
    Solution sol ;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout<<"Diameter of the binary tree is : "<<sol.diameterOfBinaryTree(root)<<endl;
    return 0 ;
}