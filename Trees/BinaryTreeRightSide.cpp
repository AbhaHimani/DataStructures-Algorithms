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
        return 1 + max(height(root->left), height(root->right));
    }
    vector<int> right(TreeNode *root, vector<int> &f, int level, int &maxLevel)
    {
        if (root == NULL)
        {
            return f;
        }
        if (maxLevel < level)
        {
            f.push_back(root->val);
            maxLevel = level;
        }
        right(root->right, f, level + 1, maxLevel);
        right(root->left, f, level + 1, maxLevel);
        return f;
    }
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        int maxLevel = -1;
        right(root, ans, 0, maxLevel);
        return ans;
    }
};