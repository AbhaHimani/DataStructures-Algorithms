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
    bool isValid(TreeNode *root, long minV = -9999999999999, long maxV = 99999999999999)
    {
        if (root == NULL)
            return true;
        if (root->val >= maxV || root->val <= minV)
            return false;
        return isValid(root->left, minV, root->val) && isValid(root->right, root->val, maxV);
    }
    bool isValidBST(TreeNode *root)
    {
        return isValid(root, -99999999999, 9999999999999);
    }
};