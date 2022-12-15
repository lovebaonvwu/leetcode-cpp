class Solution 
{
public:
    int countElements(vector<int>& arr) 
    {
        int nums[1001] = {0};
        for (auto n : arr)
        {
            ++nums[n];
        }

        int ans = 0;
        for (int i = 0; i < 1000; ++i)
        {
            if (nums[i] > 0 && nums[i + 1] > 0)
            {
                ans += nums[i];
            }
        }

        return ans;
    }
};
// Runtime 0 ms
// Memory 7.8 MB
// 2022.12.15 at 奥盛大厦