//最长连续序列

/*
    给定一个未排序的整数数组，找出最长连续序列的长度。
    要求算法的时间复杂度为 O(n)。
    
    使用哈希表去重，判断；
*/

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> _set;
    
    for(const auto&e : nums)
    {
        _set.insert(e);
    }

    int longest = 0;

    for(const auto& e : nums)
    {
        //未被检索过
        if(!_set.count(e-1))
        {
            int cur = e;
            int len = 1;

            while(_set.count(cur+1))
            {
                ++cur;
                ++len;
            }

            longest = max(longest, len);
        }
    }
    
    return longest;
}