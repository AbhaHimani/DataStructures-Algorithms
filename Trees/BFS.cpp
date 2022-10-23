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
    //Level order traveral

    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;
         if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int> l;
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode* s= q.front();

                if(s->left!=NULL) q.push(s->left);
                if(s->right!=NULL) q.push(s->right);
                l.push_back(s->val);
                q.pop();
            }
            ans.push_back(l);
        }
        return ans;



    }
};