//打家劫舍

/*
    你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
    如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
    给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

    典型dp
*/

int rob(vector<int> &nums)
{
    if (nums.empty())
    {
        return 0;
    }
    vector<int> dp(nums.size() + 1, 0);
    int n = dp.size();
    for (int i = 1; i < n; ++i)
    {
        dp[i] = nums[i - 1];
    }
    for (int i = 3; i < n; ++i)
    {
        dp[i] += max(dp[i - 2], dp[i - 3]);
    }

    return max(dp[n - 1], dp[n - 2]);
}