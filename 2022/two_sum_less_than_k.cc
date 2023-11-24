class Solution 
{
public:
    int twoSumLessThanK(vector<int>& nums, int k) 
    {
        int ans = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (nums[i] + nums[j] < k)
                {
                    ans = max(ans, nums[i] + nums[j]);
                }
            }
        }

        return ans;
    }
};
// Runtime 8 ms
// Memory 9.1 MB
// 2022.12.15 at 奥盛大厦