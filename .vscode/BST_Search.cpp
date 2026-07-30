#include<iostream>
using namespace std;
struct TreeNode{   
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
 TreeNode *searchBST(TreeNode* root, int val) {
        if (root == NULL || root->val == val) {
            return root;
        }
        if (val < root->val) {
            return searchBST(root->left, val);
        } else {
            return searchBST(root->right, val);
        }
    }
};

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int val;
    cout << "Enter the value to search in the BST: ";
    cin >> val;

    TreeNode* result = sol.searchBST(root, val);
    if (result != NULL) {
        cout << "Value " << val << " found in the BST." << endl;
    } else {
        cout << "Value " << val << " not found in the BST." << endl;
    }

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}