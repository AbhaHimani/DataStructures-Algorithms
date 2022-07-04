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
    bool helper(TreeNode *root, long minV = -9999999999999, long maxV = 99999999999999)
    {
        if (root == NULL)
        {
            return true;
        }
        if (root->right != NULL)
        {
            if (root->right->val < root->val)
            {
                return false;
            }
        }
        if (root->left != NULL)
        {
            if (root->left->val > root->val)
            {
                return false;
            }
        }

        if (root->left != NULL)
        {
            if (root->val == root->left->val)
            {
                return false;
            }
        }
        if (root->right != NULL)
        {
            if (root->val == root->right->val)
            {
                return false;
            }
        }

        if (root->val > minV && root->val < maxV && helper(root->left, minV, root->val) && helper(root->right, root->val, maxV))
        {
            return true;
        }
        return false;
    }
    bool isValidBST(TreeNode *root)
    {
        if (helper(root, -99999999999, 9999999999999))
        {
            return true;
        }
        return false;
    }
};