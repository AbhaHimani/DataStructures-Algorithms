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
    vector<int> level(TreeNode *root, int k, vector<int> &f)
    {
        if (root == NULL)
        {
            return f;
        }
        if (k == 1)
        {
            f.push_back(root->val);
            return f;
        }
        level(root->left, k - 1, f);
        level(root->right, k - 1, f);
        return f;
    }
    vector<vector<int>> levelOrder(TreeNode *root)
    {

        vector<vector<int>> ans;
        if (root == NULL)
        {
            return ans;
        }
        int k = height(root);

        vector<int> m;

        for (int i = 1; i <= k; i++)
        {
            level(root, i, m);
            ans.push_back(m);
            m.clear();
            level(root->left, i, m);
            level(root->right, i, m);

            m.clear();
        }

        return ans;
    }
};