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
    TreeNode *CreateNode(int data)
    {
        TreeNode *newNode = new TreeNodSSe();
        if (!newNode)
        {
            cout << "Memory error\n";
            return NULL;
        }
        newNode->val = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        TreeNode *x = NULL;
        if (root == NULL)
        {
            x = CreateNode(val);
            return x;
        }
        if (root->left == NULL && root->val > val)
        {
            root->left = CreateNode(val);
            return root;
        }
        if (root->right == NULL && root->val < val)
        {
            root->right = CreateNode(val);
            return root;
        }
        if (root->left == NULL && root->right == NULL)
        {
            if (root->val > val)
            {

                root->left = CreateNode(val);
                return root;
            }
            else if (root->val < val)
            {
                root->right = CreateNode(val);
                return root;
            }
        }

        TreeNode *temp = root;
        while (root != NULL)
        {
            TreeNode *temp2 = root;
            if (temp2->val > val)
            {

                root = temp2->left;
                if (root)
                {
                    if (root->val < val && root->right == NULL)
                    {
                        cout << "RIGHT";
                        root->right = CreateNode(val);
                        return temp;
                    }
                    else if (root->val > val && root->left == NULL)
                    {
                        cout << "left";
                        root->left = CreateNode(val);

                        return temp;
                    }
                }
            }

            else if (temp2->val < val)
            {

                root = temp2->right;
                if (root)
                {
                    if (root->val < val && root->right == NULL)
                    {
                        root->right = CreateNode(val);
                        return temp;
                    }
                    if (root->val > val && root->left == NULL)
                    {
                        root->left = CreateNode(val);
                        return temp;
                    }
                }
            }
        }
        return temp;
    }
};