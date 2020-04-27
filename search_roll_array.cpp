//搜索旋转数组

/*
    假设按照升序排序的数组在预先未知的某个点上进行了旋转。
    (例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2])。
    搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
    你可以假设数组中不存在重复的元素。你的算法时间复杂度必须是 O(log n) 级别。
    分析：
        二分查找的变形  !!!左右两边一定一端有序!!!
        某一端有序，判断是否在这一端
        主体逻辑
        //左端有序
        if(nums[mid] >= nums[left])
        {
            if(target <nums[mid] && target >= nums[left])
            {
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        //右端有序
        else
        {
            if(target > nums[mid] && target <= nums[right])
            {
                left = mid+1;
            }else
            {
                right = mid-1;
            }
        }
*/

int search(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size()-1;
    int mid = 0;

    while(left <= right)
    {
        mid = (right-left)/2 + left;
        if(target == nums[mid])
        {
            return mid;
        }
        if(nums[mid] >= nums[left])
        {
            if(target <nums[mid] && target >= nums[left])
            {
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        //右端有序
        else
        {
            if(target > nums[mid] && target <= nums[right])
            {
                left = mid+1;
            }else
            {
                right = mid-1;
            }
        }
    }
    return -1;
}