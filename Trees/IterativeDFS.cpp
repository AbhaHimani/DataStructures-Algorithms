//We use stack-> preorder
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode* x=st.top();
            st.pop();
            if(x->right!=NULL) st.push(x->right);
            if(x->left!=NULL) st.push(x->left);
            ans.push_back(x->val);
        }
        return ans;

    }
};

//Inorder->iterative
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
    // vector<int> inorder(TreeNode* root,vector<int> &res){
    //     if(root){
    //     inorder(root->left,res);
    //     res.push_back(root->val);
    //     inorder(root->right,res);
    //     }
    //     return res;
    // }

    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int>ans;
        TreeNode* node=root;

        while(true){
            if(node!=NULL){
                st.push(node);
                node=node->left;
            }
            else{
                if(st.empty()) break;
                node=st.top();
                st.pop();
                ans.push_back(node->val);
                node=node->right;
            }

        }
        return ans;
    }
};




