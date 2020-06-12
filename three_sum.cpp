//三数之和

/*
    给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c 
    使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
    注意：答案中不可以包含重复的三元组。

    枚举一个数后，对撞指针 进行判断统计；
*/

vector<vector<int>> threeSum(vector<int> &nums)
{
    //枚举一个数后， 对撞指针
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; ++i)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int l = i + 1;
        int r = n - 1;

        while (l < r)
        {
            int num = nums[l] + nums[r] + nums[i];

            if (num == 0)
            {
                ans.push_back({nums[i], nums[l], nums[r]});
                ++l;
                while (l < n && nums[l] == nums[l - 1])
                {
                    ++l;
                }
                --r;
                while (r > 0 && nums[r] == nums[r + 1])
                {
                    --r;
                }
                if (l >= r)
                {
                    break;
                }
            }
            else if (num > 0)
            {
                --r;
            }
            else
            {
                ++l;
            }
        }
    }

    return ans;
}