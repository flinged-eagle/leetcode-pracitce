//最长公共前缀

/*
    编写一个函数来查找字符串数组中的最长公共前缀。
    如果不存在公共前缀，返回空字符串 ""。
*/

string longestCommonPrefix(vector<string> &strs)
{

    if (strs.size() == 0)
    {
        return {};
    }
    sort(strs.begin(), strs.end());

    string ans = strs[0];

    for (auto &e : strs)
    {
        int i = 0;
        while (i < ans.size())
        {
            if (e[i] == ans[i])
            {
                ++i;
            }
            else
            {
                break;
            }
        }
        ans = e.substr(0, i);
    }

    return ans;
}