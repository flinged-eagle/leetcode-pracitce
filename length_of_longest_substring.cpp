//无重复字符的最长子串

/*
    给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
    分析：
        使用begin标记头部位置；
        当字符s[i]在begin ~ i-1之间重复时，移动begin到重复位置的后一位置；
        否则 无重复，比较最长子串的长度；
*/

int lengthOfLongestSubstring(string s) {
    int begin = 0;
    int _max = 0;

    for(int i=0; i<s.size(); ++i)
    {
        int index = s.find(s[i],begin);
        if(index < i)
        {
            begin = s.find(s[i],begin)+1;
        }else if(index == i)
        {
            _max = max(i-begin+1, _max);
        }
    }
    return _max;
}