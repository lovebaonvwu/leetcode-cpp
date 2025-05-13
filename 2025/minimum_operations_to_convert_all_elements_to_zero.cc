class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        stack<int> stk;
        int ans = 0;

        for (auto n : nums)
        {
            while (!stk.empty() && n < stk.top())
            {
                stk.pop();
            }

            if (stk.empty() || n > stk.top())
            {
                if (n > 0)
                {
                    ++ans;
                }

                stk.push(n);
            }
        }

        return ans;
    }
};
// Time: O(n)
// Space: O(n)