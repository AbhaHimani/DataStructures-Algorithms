int find(Node *root, int x)
{
    int ans = -1;
    while (root != NULL)
    {
        if (root->data == x)
        {
            ans = root->data;
            break;
        }
        else if (root->data > x)
        {
            root = root->left;
        }
        else if (root->data < x)
        {
            ans = root->data;
            root = root->right;
        }
    }
    return ans;
}
int floor(Node *root, int x)
{
    if (root == NULL)
        return -1;

    return find(root, x);
}