//和可被K整除的子数组

/*
    给定一个整数数组 A，返回其中元素之和可被 K 整除的（连续、非空）子数组的数目。

    分析：
        前缀和数组 P
        前缀法： 当 P[j] % K = P[i] % K;  为一个可行子数组
            特殊 P[i] % K == 0; 本身为一个可行子数组
*/

int subarraysDivByK(vector<int> &A, int K)
{
    //前缀法
    unordered_map<int, int> mp{{0, 1}};
    int sum = 0, ans = 0;

    for (auto &e : A)
    {
        sum += e;
        //将取余的值转化为取模的值
        int mod = (sum % K + K) % K;

        if (mp.count(mod))
        {
            ans += mp[mod];
        }
        ++mp[mod];
    }

    return ans;
}