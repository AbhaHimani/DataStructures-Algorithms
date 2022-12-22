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
    int ans;
    void solve(TreeNode *root, int k, int &idx)
    {
        if (!root)
            return;
        solve(root->left, k, idx);
        if (k == idx)
        {
            ans = root->val;
            idx++;
            return;
        }
        else
            idx++;
        solve(root->right, k, idx);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        int idx = 1;
        ans = -1;
        solve(root, k, idx);
        return ans;
    }
};