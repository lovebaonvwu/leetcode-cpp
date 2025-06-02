using LL = __int128;

class Solution
{
public:
    bool checkEqualPartitions(vector<int> &nums, long long target)
    {

        LL total = 1;
        for (LL n : nums)
        {
            total *= n;
        }

        if (total != (LL)target * target)
        {
            return false;
        }

        int n = nums.size();

        vector<int> visited(n);
        function<bool(LL)> dfs = [&](LL cur) -> bool
        {
            if (cur == target)
            {
                return true;
            }
            if (cur > target)
            {
                return false;
            }

            for (int i = 0; i < n; ++i)
            {
                if (!visited[i])
                {
                    visited[i] = true;

                    if (dfs(cur * nums[i]))
                    {
                        return true;
                    }

                    visited[i] = false;
                }
            }

            return false;
        };

        if (dfs(1) && any_of(begin(visited), end(visited), [](auto b)
                             { return !b; }))
        {
            return true;
        }

        return false;
    }
};
// Time: O(n * 2^n) for the DFS search
// Space: O(n) for the visited array