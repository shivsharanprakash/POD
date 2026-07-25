#include<iostream>
using namespace std;

struct TreeNode{
    int data ;
    TreeNode *left ;
    TreeNode *right ;
    TreeNode(int val){
        data = val ;
        left = NULL ;
        right = NULL ;
    }
};

class Solution {
public:

    int height(TreeNode*root){
        if(root==nullptr) return 0;

        int left = height(root->left);
        if(left==-1)return -1;

        int right = height(root->right);
        if(right==-1)return -1;

        if(abs(left-right)>1)return -1;

        return 1 + max(left,right);

    }
    bool isBalanced(TreeNode* root) {
        return height(root) !=-1;
    }
};


int main(){
    Solution sol ;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    if(sol.isBalanced(root)){
        cout<<"The tree is balanced."<<endl;
    }else{
        cout<<"The tree is not balanced."<<endl;
    }

    return 0 ;
}