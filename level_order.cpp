//二叉树的层序遍历

/*
    给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
*/

 vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int> > _ret;
    if(root == nullptr)
    {
        return _ret;
    }
    vector<int> _v;
    queue<TreeNode*> _queue;
    _queue.push(root);
    int level_num = 1;
 
    while(!_queue.empty())
    {
        TreeNode* cur = _queue.front();
        _queue.pop();
        --level_num;
        _v.push_back(cur->val);

        if(cur->left != nullptr)
        {
            _queue.push(cur->left);
        }
        if(cur->right != nullptr)
        {
            _queue.push(cur->right);
        }

        if(level_num == 0)
        {
            _ret.push_back(_v);
            _v.clear();
            level_num = _queue.size();
        }
    }
    return _ret;
 }