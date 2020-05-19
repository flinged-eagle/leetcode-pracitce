//验证回文字符串Ⅱ

/*
    给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

    分析：
        双指针，从字符串的两边开始，当两个字符不相同时，因为只删除一个字符
        只存在两种可能，分别判断即可；
*/

bool same(string& s, int left, int right)
{
    while(left < right)
    {
        if(s[left] == s[right])
        {
            ++left;
            --right;
        }else
        {
            return false;
        }
    }
    return true;
}

bool validPalindrome(string s) {
    int left = 0,right = s.size()-1;

    while(left < right)
    {
        if(s[left] == s[right])
        {
            ++left;
            --right;
        }else
        {
            return same(s, left+1, right) || same(s, left, right-1);
        }
    }
    return true;
}