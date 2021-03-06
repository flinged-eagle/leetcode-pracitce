//最低票价

/*
在一个火车旅行很受欢迎的国度，你提前一年计划了一些火车旅行。在接下来的一年里，你要旅行的日子将以一个名为 days 的数组给出。
每一项是一个从 1 到 365 的整数。
火车票有三种不同的销售方式：

    一张为期一天的通行证售价为 costs[0] 美元；
    一张为期七天的通行证售价为 costs[1] 美元；
    一张为期三十天的通行证售价为 costs[2] 美元。
通行证允许数天无限制的旅行。 例如，如果我们在第 2 天获得一张为期 7 天的通行证
那么我们可以连着旅行 7 天：第 2 天、第 3 天、第 4 天、第 5 天、第 6 天、第 7 天和第 8 天。
返回你想要完成在给定的列表 days 中列出的每一天的旅行所需要的最低消费。


    分析：
        动态规划： 类似背包问题

        递推式：
            逆向的，付款在后
            dp[i] = min(dp[i-1]+cost[0], dp[i-7]+costs[1], dp[i-30]+costs[2])

*/

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    //根据天数创建数组大小
    int end = days[days.size() - 1];
    vector<int> dp(end + 1, 0);

    int index = 0;
    for (int i = 1; i < end + 1; ++i)
    {
        if (i == days[index])
        {
            int _min = dp[i - 1] + costs[0];
            if (i - 7 >= 0)
            {
                _min = min(_min, dp[i - 7] + costs[1]);
            }
            else 
            {
                //还没有七天，买了七天的票
                _min = min(_min, costs[1]);
            }
            if (i - 30 >= 0)
            {
                _min = min(_min, dp[i - 30] + costs[2]);
            }
            else
            {
                //还没有30天，买了30天的票
                _min = min(_min, costs[2]);
            }
            dp[i] = _min;
            if (index < days.size() - 1)
            {
                ++index;
            }
        }
        else
        {
            dp[i] = dp[i - 1];
        }
    }
    return dp[end];
}