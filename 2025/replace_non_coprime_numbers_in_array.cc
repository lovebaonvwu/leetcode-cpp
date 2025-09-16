class Solution
{
public:
    vector<int> replaceNonCoprimes(vector<int> &nums)
    {
        vector<int> stk;
        stk.push_back(nums[0]);

        int n = nums.size();

        for (int i = 1; i < n; ++i)
        {
            int cur = nums[i];
            while (!stk.empty())
            {
                int prev = stk.back();

                if (gcd(cur, prev) == 1)
                {
                    break;
                }

                cur = lcm(cur, prev);
                stk.pop_back();
            }

            stk.push_back(cur);
        }

        return stk;
    }
};
// Time: O(n)
// Space: O(n)