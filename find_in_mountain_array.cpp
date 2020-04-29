//山脉数组中查找目标值

/*
    给你一个 山脉数组 mountainArr，请你返回能够使得 mountainArr.get(index) 等于 target 最小 的下标 index 值。
    如果不存在这样的下标 index，就请返回 -1。
    何为山脉数组？如果数组 A 是一个山脉数组的话，那它满足如下条件：
    首先，A.length >= 3 其次，在 0 < i < A.length - 1 条件下，存在 i 使得：
    A[0] < A[1] < ... A[i-1] < A[i]
    A[i] > A[i+1] > ... > A[A.length - 1]

    你将不能直接访问该山脉数组，必须通过 MountainArray 接口来获取数据：
    MountainArray.get(k) - 会返回数组中索引为k 的元素（下标从 0 开始）
    MountainArray.length() - 会返回该数组的长度

    class MountainArray{
        int get(int index);
        int length();
    };

    3 <= mountain_arr.length() <= 10000
    对 MountainArray.get 发起超过 100 次调用的提交将被视为错误答案。

    显然复杂度为log n ~ 13.27

    首先想到二分查找，想要使用二分查找，首先要求数组有序，所以需要借助二分查找找到分界点，使其分为升序和降序两个数组；
    再对这两个数组进行进一步排序；
*/

 int findInMountainArray(int target, MountainArray &mountainArr) {
     //找到分界点
     int left = 0,right = mountainArr.length()-1;
     while(left < right)
     {
         int mid = left+(right-left)/2;
         if(mountainArr.get(mid) < mountainArr.get(mid+1))
         {
             left = mid+1;
         }else
         {
             right = mid;
         }
     }
    //分界点
    int index = left;

    int begin = 0;
    int end = index;
    //两次二分查找
    while(begin <= end)
    {
        int mid = begin+(end-begin)/2;
        if(mountainArr.get(mid) == target)
        {
            return mid;
        }
        if(mountainArr.get(mid) > target)
        {
            end = mid-1;
        }else
        {
            begin = mid+1;
        }        
    }
    begin = index+1; 
    end = mountainArr.length()-1;
    while(begin <= end)
    {
        int mid = begin+(end-begin)/2;
        if(mountainArr.get(mid) == target)
        {
            return mid;
        }
        if(mountainArr.get(mid) > target)
        {
            begin = mid+1;
        }else
        {
            end = mid-1;
        }
        
    }
    return -1;
 }