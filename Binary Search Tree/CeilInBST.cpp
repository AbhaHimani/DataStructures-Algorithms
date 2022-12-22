int find(Node *root, int input)
{
    int ans = NULL;
    while (root != NULL)
    {
        if (root->data == input)
        {
            ans = root->data;
            break;
        }
        else if (root->data < input)
        {

            root = root->right;
        }
        else
        {
            ans = root->data;
            root = root->left;
        }
    }
    return ans;
}
int findCeil(Node *root, int input)
{
    if (root == NULL)
        return -1;
    return find(root, input);

    // Your code here
}