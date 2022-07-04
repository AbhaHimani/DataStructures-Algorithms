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
    int height(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return max(height(root->left), height(root->right)) + 1;
    }

    int helper(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int h1 = height(root->left);
        int h2 = height(root->right);
        int ans1 = h1 + h2;
        int diameterL = helper(root->left);
        int diameterR = helper(root->right);

        int fin = max(diameterR, max(ans1, diameterL));
        return fin;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        return helper(root);
    }
};