#include<iostream>
using namespace std ;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
    public :

      bool check(TreeNode* root, long minVal, long maxVal) {
          if (!root) return true;
          if (root->val <= minVal || root->val >= maxVal) return false;
          return check(root->left, minVal, root->val) && check(root->right, root->val, maxVal);
      }
      bool isValidBST(TreeNode* root) {
          return check(root, LONG_MIN, LONG_MAX);
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
    cout << solution.isValidBST(root) << endl;

    return 0;
}