/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool checkTree(TreeNode *root)
    {
        int x = 0;
        if (root)
        {
            x = root->val;
        }
        int y = 0;
        if (root->left)
        {
            y = root->left->val;
        }
        int z = 0;
        if (root->right)
        {
            z = root->right->val;
        }
        if (x == z + y)
            return true;
        return false;
    }
};