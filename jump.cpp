//跳跃游戏

/*
    给定一个非负整数数组，你最初位于数组的第一个位置。
    数组中的每个元素代表你在该位置可以跳跃的最大长度。
    你的目标是使用最少的跳跃次数到达数组的最后一个位置。

    分析：
        1.dp 记录到每一格的最小步数     时间复杂度：o(n^2) 空间复杂度 o(n)
        2.逆向贪心  从数组尾部开始，找到到达尾部的最远距离，迭代向前寻找  时间复杂度o(n^2)  空间复杂度o(1)
        3.正向贪心  找到可达的最远位置即max（nums[i] + i), i为现在的位置， nums[i]代表i的跳跃长度;     时间复杂度o(n) 空间复杂度 o(1)
*/

int jump(vector<int>& nums) {
    int max_index = 0, step = 0, end = 0;
    //max_index  当前可达最大位置
    //step 步数
    //end  每一步的最大位置
    for(int i=0; i<nums.size(); ++i)
    {
        if(max_index >= i)
        {
            max_index = max(max_index, i+nums[i])
            if(i == end)
            {
                end = max_index;
                ++step;
            }
        }
    }
    
    return step;
}
