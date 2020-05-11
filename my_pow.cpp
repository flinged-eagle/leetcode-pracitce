//Pow(x,n)

/*
    实现 pow(x, n) ，即计算 x 的 n 次幂函数。
*/

double quick_mul(double x, long long n)
{
    if (n == 0)
    {
        return 1.0;
    }
    if (n == 1)
    {
        return x;
    }
    double y = quick_mul(x, n / 2);
    return n % 2 == 0 ? y * y : y * y * x;
}
double myPow(double x, int n)
{
    //使用long long 边界处理 -2147483648无法转成int 类型的正数
    long long N = n;
    return N >= 0 ? quick_mul(x, N) : 1 / quick_mul(x, -N);
}