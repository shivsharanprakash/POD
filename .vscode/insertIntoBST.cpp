#include<iostream>
using namespace std;
using namespace std;
struct TreeNode{   
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
    public :
       TreeNode * insertIntoBST(TreeNode *root,int val ){
        if(root==NULL){
            return new TreeNode(val);
        }

        if(root->val > val){
            root->left = insertIntoBST(root->left,val);
        }else{
            root->right = insertIntoBST(root->right,val);
        }
        return root;
       }
};

int main(){
    
    Solution sol;
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int val;
    cout << "Enter the value to insert into the BST: ";
    cin >> val;

    root = sol.insertIntoBST(root, val);
    cout << "Value " << val << " inserted into the BST." << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}