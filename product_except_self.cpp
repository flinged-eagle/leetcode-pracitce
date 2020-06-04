//出自身外数组的乘积

/*
    给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

    分析:
        当前的数 = 左边乘积 * 右边乘积
*/


vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ret(nums);

    //保存所有左边的和
    for(int i=1; i<nums.size()-1; ++i)
    {
        ret[i] *= ret[i-1];
    }
    //保存右边的和
    int right = 1;
    for(int j = nums.size()-1; j>0; --j)
    {
        ret[j] = ret[j-1]*right;
        right *= nums[j];
    }
    ret[0] = right;

    return ret;
}