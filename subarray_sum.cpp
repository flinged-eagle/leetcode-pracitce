//和为k的子数组

/*
    给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。
    分析：
        暴力解法 : O(n^2)
        优化： 前缀法
            依序保存，数组的和至 array， 则将问题转化为 查找 array[i] - array[j] == k，时间复杂度未变
            利用hash表进行优化，将数组的值插入到hashtable中，可以以O(1)的时间复杂度查找到想要的值，使用val代表可达到key值的子数组的个数；
            map[i-k] 就为当前数字i可扩展子数组得到k的个数；
*/

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> _m;
    //初始化 _m[0] = 1 当pre等于k时，边界处理
    _m[0] = 1;
    int num = 0, pre = 0;
    
    for(auto&e : nums)
    {
        pre += e;
        if(_m.find(pre-k) != _m.end())
        {
            num += _m[pre-k];
        }
        _m[pre]++;
    }
    return num;
}

