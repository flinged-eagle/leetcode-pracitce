//数组中数字出现的次数

/*
    一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。
    请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

    分析：
        易知 数组中找一个单独出现的数字时，使用异或即可获得；
        由此可知，两个数字需要对数组进行分组异或；

        主体思想：
            获取 两个数字的异或值；将其分离，以第一个不为0的位分离；
*/

vector<int> singleNumbers(vector<int>& nums)
{
    //保存两个数的异或值
    int num = 0;
    for(auto&e : nums)
    {
        num ^= e;
    }
    //以第一个不为0的位分离
    int index = 1;
    while((num & index) == 0)
    {
        index <<= 1;
    }

    int ret1 = 0, ret2 = 0;

    for(auto&e : nums)
    {
        if(index & e)
        {
            ret1 ^= e;
        }else
        {
            ret2 ^= e;
        }
    }
    
    return {ret1,ret2};
}