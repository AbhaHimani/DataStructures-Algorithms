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
class Solution {
    public:
    void traverse(TreeNode *root, int vertical, int level, map<int, map<int, multiset<int>>> &mp)
    {
        if(root == NULL) return;

        mp[vertical][level].insert(root->val);
        traverse(root->left, vertical-1, level+1, mp);
        traverse(root->right, vertical+1, level+1, mp);
        return;

    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> mp;

        traverse(root, 0, 0, mp);

        for(auto i: mp)
        {
            vector<int> currOrder;

            for(auto j: i.second)
            {
                for(auto num: j.second)
                    currOrder.push_back(num);
            }

            ans.push_back(currOrder);
        }

        return ans;

    }
};