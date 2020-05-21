//最长回文字符串

/*
    给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

    方法：
        中心扩展
        dp
            使用dp[i][j] 代表 s[i] ~ s[j] 是否回文
            dp[i][j] = dp[i+1][j-1]&&s[i]==s[j]
*/

string longestPalindrome(string s)
{
    int begin = 0;
    int len = 0;

    int size = s.size();
    int i = 0;

    while (i < size)
    {
        int start = 0, end = 0;
        start = end = i;

        while (end + 1 < size && s[end] == s[end + 1])
        {
            ++end;
        }
        i = end + 1;
        while (start - 1 >= 0 && end + 1 < size && s[start - 1] == s[end + 1])
        {
            --start;
            ++end;
        }

        if (end - start + 1 > len)
        {
            len = end - start + 1;
            begin = start;
        }
    }

    return s.substr(begin, len);
}
