//后继者

/*
    设计一个算法，找出二叉搜索树中指定节点的“下一个”节点（也即中序后继）。  
    如果指定节点没有对应的“下一个”节点，则返回null。

    分析：
        最简单中序遍历，找到下一节点

        分情况：
            当结点右子树存在时，为右子树的最左结点；
            右子树不存在 路径上大于该节点值的结点；
                ！！二叉搜索树，并不平衡！！；
                    0
                        1
                            2
                                3
                                    4
                    p=4 无下一节点；
                     
*/

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    //第一种情况
    if(p->right != nullptr)
    {
        p = p->right;
        while(p->left != nullptr)
        {
            p = p->left;
        }
        return p;
    }

    TreeNode* ret = nullptr;

    while(root != p)
    {
        if(root->val > p->val)
        {
            ret = root;
            root = root->left;
        }
        else
        {
            
            root = root->right;
        }
        
    }
    return ret;
}