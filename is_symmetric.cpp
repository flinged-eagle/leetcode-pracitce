//对称二叉树

/*
    给定一个二叉树，检查它是否是镜像对称的。
*/

bool isSame(TreeNode* left, TreeNode* right)
{
    if(left == nullptr && right == nullptr)
    {
        return true;
    }else if(left == nullptr || right == nullptr)
    {
        return false;
    }

    if(left->val == right->val)
    {
        return isSame(left->left, right->right) && isSame(left->right, right->left);
    }
    return false;
}

bool isSymmetric(TreeNode* root) 
{
    if(root == nullptr)
    {
        return true;
    }
    return isSame(root,root);
}