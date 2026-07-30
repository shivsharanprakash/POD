#include<iostream>
using namespace std;
struct TreeNode{  
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
    public :
       TreeNode *deleteNode(TreeNode *root,int key){
        if(root==NULL){
            return NULL;
        }
        if(root->val < key){
            root -> right = deleteNode(root->right,key);    
        }else if(root->val >key){
            root->right = deleteNode(root->left,key);
        }else{

            if(root->left ==NULL && root->right == NULL){
                delete root;
                return NULL;    
        }else if(root->left ==NULL){
            TreeNode * child = root->right;
            delete root;
            return child;
        }
        else if(root->right ==NULL){
            TreeNode * child = root->left;
            delete root;
            return child;
       }else{
           
        TreeNode *successor= root ->right ;
        while(successor->left != NULL){
            successor = successor->left;
        }

        root->val = successor->val;
            root->right = deleteNode(root->right,successor->val);
        }
       }
       return root ;
    }
};

int main(){
    
    Solution sol;
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int key;
    cout << "Enter the value to delete from the BST: ";
    cin >> key;

    root = sol.deleteNode(root, key);
    cout << "Value " << key << " deleted from the BST." << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}