//爬楼梯

/*
    假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
    每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
    注意：给定 n 是一个正整数。
*/

int climbStairs(int n)
{
    if(n < 4)
    {
        return n;
    }

    int num1 = 0;
    int num2 = 1;
    int ans = 2;
    for(int i=3; i<=n; ++i)
    {
        num1 = num2;
        num2 = ans;
        ans = num1 +num2;
    }

    return ans;
}