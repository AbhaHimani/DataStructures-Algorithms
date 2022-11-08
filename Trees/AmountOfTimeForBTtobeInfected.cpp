class Solution
{
private:
    TreeNode *createMapping(TreeNode *root, int start, map<TreeNode *, TreeNode *> &nodeToParent)
    {
        TreeNode *ans = NULL;
        queue<TreeNode *> q;
        q.push(root);
        nodeToParent[root] = NULL;

        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();

            if (front->val == start)
                ans = front;

            if (front->left)
            {
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            if (front->right)
            {
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return ans;
    }

    void solve(TreeNode *root, map<TreeNode *, TreeNode *> &nodeToParent, int &time)
    {
        map<TreeNode *, bool> visited;
        queue<TreeNode *> q;
        q.push(root);
        visited[root] = 1;

        while (!q.empty())
        {
            int size = q.size();
            bool flag = false;

            for (int i = 0; i < size; i++)
            {
                TreeNode *front = q.front();
                q.pop();

                if (front->left && !visited[front->left])
                {
                    flag = true;
                    visited[front->left] = 1;
                    q.push(front->left);
                }
                if (front->right && !visited[front->right])
                {
                    flag = true;
                    visited[front->right] = 1;
                    q.push(front->right);
                }
                if (nodeToParent[front] && !visited[nodeToParent[front]])
                {
                    flag = true;
                    visited[nodeToParent[front]] = 1;
                    q.push(nodeToParent[front]);
                }
            }
            if (flag == true)
                time++;
        }
    }

public:
    int amountOfTime(TreeNode *root, int start)
    {
        // step 1 : create node to parent mapping and find the start node.
        map<TreeNode *, TreeNode *> nodeToParent;
        TreeNode *target = createMapping(root, start, nodeToParent);

        // step 2 : burn the tree.
        int time = 0;
        solve(target, nodeToParent, time);
        return time;
    }
};