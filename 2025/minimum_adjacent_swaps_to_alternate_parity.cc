class Solution
{

    int swaps(const vector<int> &nums, const vector<int> &pos)
    {
        if (pos.size() < (nums.size() + 1) / 2)
        {
            return INT_MAX;
        }

        int ret = 0;
        for (int i = 0, j = 0; i < nums.size(); i += 2, ++j)
        {
            ret += abs(pos[j] - i);
        }

        return ret;
    }

public:
    int minSwaps(vector<int> &nums)
    {
        vector<int> odd;
        vector<int> even;

        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] & 1)
            {
                odd.push_back(i);
            }
            else
            {
                even.push_back(i);
            }
        }

        if (abs((int)odd.size() - (int)even.size()) > 1)
        {
            return -1;
        }

        return min(swaps(nums, odd), swaps(nums, even));
    }
};
// Time: O(n)
// Space: O(n)