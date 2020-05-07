//另一个树的子树

/*
    给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。
    s 的一个子树包括 s 的一个节点和这个节点的！！所有子孙！！s 也可以看做它自身的一棵子树。

 *  Definition for a binary tree node.
 *  struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };

    分析：
        递归 + 判断： 如果 s->val == t->val 继续向下递归判断；否则向左右子树s->left 和 s->right;
*/

bool isSameTree(TreeNode *s, TreeNode *t)
{
    if (s == nullptr && t == nullptr)
    {
        return true;
    }
    else if (s == nullptr || t == nullptr)
    {
        return false;
    }
    if (s->val == t->val)
    {
        return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    }
    return false;
}

bool isSubtree(TreeNode *s, TreeNode *t)
{
    if (s == nullptr && t == nullptr)
    {
        return true;
    }
    else if (s == nullptr || t == nullptr)
    {
        return false;
    }

    if (!isSameTree(s, t))
    {
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }

    return true;
}