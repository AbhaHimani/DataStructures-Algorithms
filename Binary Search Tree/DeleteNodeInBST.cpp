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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL; 
        }
        if(root->val==key){
            if(!root->left){
                if(!root->right){
                    return NULL;
                }
            }
        }
        if(root->val==key){
            if(root->left==NULL) return root->right;
            if(root->right==NULL) return root->left;
        }
        if(root){
        
        if(root->val==key){
            TreeNode* tem=root;
            TreeNode* ans=root->right;
            TreeNode* p= root->right;
            if(p){
            while(p->left!=NULL){
                p=p->left;
            }
             
            }
           
            p->left=root->left;
            delete tem;
            return ans;
        }
        }
        TreeNode* temp=root;
        TreeNode* temp2=root;
        while(root!=NULL){
           TreeNode* x=root;
           if(root->val==key){
               
           
               if(temp2){
               if(temp2->val>key){
                    TreeNode* m= root;
                   TreeNode* ex= temp2->left->left;
                   
                   temp2->left=ex;
                   if(ex){
                        while(ex->right!=NULL){
                            ex=ex->right;
                        }
                        ex->right=m->right;
                   }
                   else{
                       temp2->left=m->right;
                   }
                   
                      
                   delete root;
                   break;
               }

               else if(temp2->val<key){
                  
                   TreeNode* m= root;
                   TreeNode* ex= temp2->right->right;
                   
                   temp2->right=ex;
                   if(ex){
                        while(ex->left!=NULL){
                            ex=ex->left;
                        }
                        ex->left=m->left;
                   }
                   else{
                       temp2->right=m->left;
                   }
                      
                   delete root;
                   break;

                   }
               }
            }
            
           else if(root->val>key){
               root=root->left;
           }
           else{
               root=root->right;
           }
           temp2=x;
                      
        }

      
        return temp;

    }
};