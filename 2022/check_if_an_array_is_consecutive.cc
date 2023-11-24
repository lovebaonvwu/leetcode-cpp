class Solution 
{
public:
    bool isConsecutive(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] != nums[i - 1] + 1)
            {
                return false;
            }
        }

        return true;
    }
};
// Runtime 153 ms
// Memory 60.1 MB
// 2022.12.15 at 奥盛大厦