class Solution
{
public:
    int minRemoval(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(begin(nums), end(nums));

        vector<vector<int>> cached(n, vector<int>(n, -1));

        function<int(int, int)> dfs = [&](int left, int right) -> int
        {
            if (left == right)
            {
                return 0;
            }

            if (1LL * nums[right] <= 1LL * nums[left] * k)
            {
                return 0;
            }

            if (cached[left][right] != -1)
            {
                return cached[left][right];
            }

            return cached[left][right] = min(1 + dfs(left + 1, right), 1 + dfs(left, right - 1));
        };

        return dfs(0, n - 1);
    }
};
// Time: O(n^2)
// Space: O(n^2)

class Solution
{
public:
    int minRemoval(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(begin(nums), end(nums));

        int cnt = 0;
        for (int i = 0, j = 0; j < n; ++j)
        {
            while (1LL * nums[j] > 1LL * nums[i] * k)
            {
                ++i;
            }

            cnt = max(cnt, j - i + 1);
        }

        return n - cnt;
    }
};
// Time: O(nlogn)
// Space: O(1)