//散步问题

/*
    三步问题。有个小孩正在上楼梯，楼梯有n阶台阶，小孩一次可以上1阶、2阶或3阶。
    实现一种方法，计算小孩有多少种上楼梯的方式。结果可能很大，你需要对结果模1000000007。

    分析：
        基础的动态规划问题：
            递推式 step(n) = step(n-1) + step(n-2) + step(n-3)
*/

int waysToStep(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 2;
    if(n == 3) return 4;

    long step1 = 1, step2 = 2, step3 = 4;
    long step = 4;

    for(int i=3; i<n; ++i)
    {
        step = (step1+step2+step3)%1000000007;
        step1 = step2%1000000007;
        step2 = step3%1000000007;
        step3 = step%1000000007;
    }
    return step;
}