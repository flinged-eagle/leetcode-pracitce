//打家劫舍 Ⅱ

/*
    你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。
    同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
    给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

    分析:
        将环形链表拆为两个单链表进行比较
        一个包含头节点，不包含尾结点， 一个包含为尾结点，不含头节点；保证了头尾不同时被偷窃；
*/

int rob(vector<int> &nums)
{
    if (nums.empty())
    {
        return 0;
    }
    if (nums.size() == 1)
    {
        return nums[0];
    }

    return max(myrob(vector<int>(nums.begin(), nums.end() - 1)), myrob(vector<int>(nums.begin() + 1, nums.end())));
}

int myrob(vector<int> nums)
{
    if (nums.empty())
    {
        return 0;
    }
    vector<int> dp(nums.size() + 1, 0);
    for (int i = 1; i < dp.size(); ++i)
    {
        dp[i] = nums[i - 1];
    }

    for (int i = 3; i < dp.size(); ++i)
    {
        dp[i] += max(dp[i - 2], dp[i - 3]);
    }

    return max(dp[nums.size()], dp[nums.size() - 1]);
}