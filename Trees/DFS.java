//Preorder Traversal-> recursive
import java.util.*;
void preorder(TreeNode* root){
        if(root==null) return null;
        System.out.println(root.val);
        preorder(root->left);
        preorder(root->right);
        }
//Inorder Traversal ->Recursion
        void inorder(TreeNode* root){
        if(root==null) return null;
        inorder(root.left);
        System.out.println(root.val);
        inorder(root.right);
        }
//Postorder Traversal -> recursion
        void postorder(TreeNode* root){
        if(root==null) return null;
        postorder(root.left);
        postorder(root.right);
        System.out.println(root.val);
        }