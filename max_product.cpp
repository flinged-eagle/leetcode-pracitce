//乘积最大数组

/*
    给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

    分析：
        考虑到一个问题，就是当前最优值，不一定是由前一个最优值得到的；
        不满足最优子结构；
        负数的存在，需要保存最小值， - * - = + ;
        max_num[i] = max{
            max_num[i-1]*nums[i]
            min_num[i-1]*nums[i]
            nums[i]
        }
        min_num[i] = min{
            min_num[i-1]*nums[i]
            max_num[i-1]*nums[i]
            nums[i]
        }

*/

int maxProduct(vector<int>& nums) {
    vector<int> _max(nums),_min(nums);

    for(int i=1; i<nums.size(); ++i)
    {
        _max[i] = max(max(_max[i-1]*nums[i], _min[i-1]*nums[i]), nums[i]);
        _min[i] = min(min(_min[i-1]*nums[i], _max[i-1]*nums[i]), nums[i]);
    }
    
    //返回数组中的最大值
    return *max_element(_max.begin(), _max.end());
}