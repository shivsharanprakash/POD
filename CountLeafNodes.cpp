#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    int countLeafNodes(Node *root)
    {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return 1;

        int left = countLeafNodes(root->left);
        int right = countLeafNodes(root->right);
        return left + right;
    }
};

int main()
{
    Solution sol;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Number of leaf nodes in the tree is : " << sol.countLeafNodes(root) << endl;
    return 0;
}