//二叉树的最近公共祖先

/*
    给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
    对于有根树 T 的两个结点 p、q最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大
    （一个节点也可以是它自己的祖先）

    分析：
        1.dfs 存储路径
        2.dfs 递归结点查找
*/

/*
    dfs 存储路径
bool dfs(TreeNode* root, TreeNode* target, stack<TreeNode*>& _s)
{
    if(root == nullptr)
        return false;
    _s.push(root);
    if(root == target)
    {
        return true;
    }
    if(dfs(root->left, target, _s))
    {
        return true;
    }
    if(dfs(root->right, target, _s))
    {
        return true;
    }
    _s.pop();
    return false;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //dfs存储路径
    stack<TreeNode*> _sp;
    stack<TreeNode*> _sq;

    dfs(root, p, _sp);
    dfs(root, q, _sq);

    while(_sp.size() != _sq.size())
    {
        if(_sp.size() > _sq.size())
        {
            _sp.pop();
        }else
        {
            _sq.pop();
        }    
    }

    while(_sp.top() != _sq.top())
    {
        _sp.pop();
        _sq.pop();
    }
    return _sp.top();
}

*/

//dfs 递归查找

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == p || root == q)
    {
        return root;
    }
    
    if(root != nullptr)
    {
        //判断是否在一边区间
        TreeNode* lnode = lowestCommonAncestor(root->left, p, q);
        TreeNode* rnode = lowestCommonAncestor(root->right, p, q);
        if(lnode !=nullptr && rnode != nullptr)
        {
            return root;
        }else if(lnode == nullptr)
        {
            //全部在右子树
            return lowestCommonAncestor(rnode,p,q);
        }else
        {
            //全部在左子树
            return lowestCommonAncestor(lnode, p,q);
        }
    }
    return nullptr;
}