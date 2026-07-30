#include<iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
    public:
        int count =0;
        int ans =0;
       void inorder(TreeNode*root, int k){
          if(root==nullptr) return;
          inorder(root->left, k);
          count ++;
          if(count==k){
            ans = root->val;
            return;
          }
          inorder(root->right, k);
       }

       int kthSmallest(TreeNode* root, int k) {
            inorder(root, k);
            return ans;
        }
};

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    Solution solution;
    int k = 3;
    cout << solution.kthSmallest(root, k) << endl;

    return 0;
}