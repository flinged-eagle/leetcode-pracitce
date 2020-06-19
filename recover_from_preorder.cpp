//从先序遍历还原二叉树

/*
    我们从二叉树的根节点 root 开始进行深度优先搜索。
    在遍历中的每个节点处，我们输出 D 条短划线（其中 D 是该节点的深度），然后输出该节点的值。
    （如果节点的深度为 D，则其直接子节点的深度为 D + 1。根节点的深度为 0）。
    如果节点只有一个子节点，那么保证该子节点为左子节点。
    给出遍历输出 S，还原树并返回其根节点 root。
*/

//递归方法
TreeNode* dfs(string str, int& index, int depth)
{
    if(index == str.size())
    {
        return nullptr;
    }
    int level = 0;
    int num = 0;
    while(str[index] == '-')
    {
        ++index;
        ++level;
    }
    if(level != depth)
    {
        index -= level;
        return nullptr;
    }
    while(index < str.size() && str[index] != '-')
    {
        num = num*10 + str[index]-'0';
        ++index;
    }

    TreeNode* root = new TreeNode(num);

    root->left = dfs(str, index, level+1);
    root->right = dfs(str, index, level+1);

    return root;
}

TreeNode* recoverFromPreorder(string S)
{
    if (S.size() == 0)
        return nullptr;
    int index = 0;
    return dfs(S, index, 0);
}


//迭代方法
//关键: 栈的深度代表树的深度

TreeNode* recoverFromPreorder(string S)
{
    stack<TreeNode*> s;
    int index = 0;
    int len = S.size();

    while(index < len)
    {
        int level = 0;
        int num = 0;
        while(S[index] == '-')
        {
            ++index;
            ++level;
        }

        while(index < len && S[index] != '-')
        {
            num = num * 10 + S[index]-'0';
            ++index;
        }
        TreeNode* node = new TreeNode(num);
        if(level == s.size())
        {
            if(!s.empty())
            {
                s.top()->left = node;
            }
        }else
        {
            while(s.size() != level)
            {
                s.pop();
            }
            s.top()->right = node;
        }
        s.push(node);
    }

    while(s.size() > 1)
    {
        s.pop();
    }

    return s.top();
}