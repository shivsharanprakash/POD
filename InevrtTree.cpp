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
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr) return nullptr;

        swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

int main(){
    Solution sol ;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    sol.invertTree(root);

    return 0 ;
}