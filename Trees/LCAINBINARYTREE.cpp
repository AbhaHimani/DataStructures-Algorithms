/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root == p or root == q)
        {
            return root;
        }
        TreeNode *Rightroot = lowestCommonAncestor(root->right, p, q);
        TreeNode *Leftroot = lowestCommonAncestor(root->left, p, q);

        if (Rightroot != NULL and Leftroot != NULL)
            return root;
        if (Leftroot != NULL)
        {
            return Leftroot;
        }
        return Rightroot;
    }
};