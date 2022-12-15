class Solution 
{
public:
    bool isMajorityElement(vector<int>& nums, int target) 
    {
        int cnt = 0;
        for (auto n : nums)
        {
            cnt += n == target;
        }

        return cnt > nums.size() / 2;
    }
};
// Runtime 7 ms
// Memory 7.7 MB
// 2022.12.15 at 奥盛大厦