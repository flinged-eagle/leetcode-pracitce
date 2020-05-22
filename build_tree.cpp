//从前序和中序遍历序列中构造二叉树

/*
    根据一棵树的前序遍历与中序遍历构造二叉树。

    分析：
        递归创建，按照二叉树 前序和中序的性质
*/

TreeNode *recursive(vector<int> &preorder, int &begin, vector<int> &inorder, int start, int end)
{
    if (begin >= preorder.size() || start > end)
        return nullptr;
    TreeNode *root = new TreeNode(preorder[begin]);

    int mid = start;

    for (int i = start; i <= end; ++i)
    {
        if (inorder[i] == preorder[begin])
        {
            mid = i;
        }
    }
    ++begin;
    root->left = recursive(preorder, begin, inorder, start, mid - 1);
    root->right = recursive(preorder, begin, inorder, mid + 1, end);

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    if (preorder.size() == 0)
    {
        return nullptr;
    }
    TreeNode *root = new TreeNode(preorder[0]);
    int begin = 1;
    int mid = 0;

    for (int i = 0; i < inorder.size(); ++i)
    {
        if (inorder[i] == preorder[0])
        {
            mid = i;
        }
    }

    root->left = recursive(preorder, begin, inorder, 0, mid - 1);
    root->right = recursive(preorder, begin, inorder, mid + 1, inorder.size() - 1);

    return root;
}