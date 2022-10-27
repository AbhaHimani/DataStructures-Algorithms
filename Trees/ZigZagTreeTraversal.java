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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        bool f=true;

        while(!q.empty()){
            int size=q.size();
            vector<int>l(size);

            for(int i=0;i<size;i++){
                TreeNode* s= q.front();
                q.pop();
                int index= (f)?i:(size-1-i);
                l[index]=s->val;
                if(s->left) q.push(s->left);
                if(s->right) q.push(s->right);

            }
            f=!f;
            ans.push_back(l);

        }
        return ans;
    }
};