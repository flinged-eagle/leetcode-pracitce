//每个元音包含偶数次的最长字符串

/*
    给你一个字符串 s ，请你返回满足以下条件的最长子字符串的长度：
    每个元音字母，即 'a'，'e'，'i'，'o'，'u' ，在子字符串中都恰好出现了偶数次。

    分析：
        思路，查找连续子串中的相同元音出现偶数次        前缀和 表示原因出现次数
        奇数/偶数  XOR
        只有有限个元音，可使用状态压缩 位图bitmap
*/

int findTheLongestSubstring(string s)
{
    int ans = 0, status = 0, n = s.length();
    //status 每位代表元音的奇偶
    vector<int> pos(1 << 5, -1);
    //保存对应状态出现的最早位置
    pos[0] = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'a')
        {
            status ^= 1 << 0;
        }
        else if (s[i] == 'e')
        {
            status ^= 1 << 1;
        }
        else if (s[i] == 'i')
        {
            status ^= 1 << 2;
        }
        else if (s[i] == 'o')
        {
            status ^= 1 << 3;
        }
        else if (s[i] == 'u')
        {
            status ^= 1 << 4;
        }
        if (~pos[status])
        {
            ans = max(ans, i + 1 - pos[status]);
        }
        else
        {
            //如果pos[status]未被初始化
            pos[status] = i + 1;
        }
    }
    return ans;
}