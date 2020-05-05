//验证二叉搜索树

/*
    给定一个二叉树，判断其是否是一个有效的二叉搜索树。
    假设一个二叉搜索树具有如下特征：
    节点的左子树只包含小于当前节点的数。
    节点的右子树只包含大于当前节点的数。
    所有左子树和右子树自身必须也是二叉搜索树。

    分析：
        中序遍历，是否有序
*/

 bool isValidBST(TreeNode* root) {
    //利用栈实现对二叉树的中序遍历
    stack<TreeNode*> st;
    long long index = LONG_MIN;
    
    while(!st.empty() || root != nullptr)
    {
        while(root != nullptr)
        {
            st.push(root);
            root = root->left;
        }

        root = st.top();
        st.pop();
        //判断条件
        if(root->val <= index) return false;
        //更新index值
        index = root->val;
        root = root->right;
    }
    return true;
 }