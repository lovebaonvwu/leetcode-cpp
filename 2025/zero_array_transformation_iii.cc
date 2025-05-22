class Solution
{
public:
    int maxRemoval(vector<int> &nums, vector<vector<int>> &queries)
    {
        sort(begin(queries), end(queries), [](auto &a, auto &b)
             { return a[0] < b[0]; });

        priority_queue<int> pq;
        int n = nums.size();
        int m = queries.size();
        vector<int> diff(n + 1);
        for (int i = 0, j = 0, cnt = 0; i < n; ++i)
        {
            cnt += diff[i];
            while (j < m && queries[j][0] == i)
            {
                pq.push(queries[j][1]);
                ++j;
            }

            while (cnt < nums[i] && !pq.empty() && pq.top() >= i)
            {
                ++cnt;
                --diff[pq.top() + 1];
                pq.pop();
            }

            if (cnt < nums[i])
            {
                return -1;
            }
        }

        return pq.size();
    }
};
// Time: O(n + m * log(m))
// Space: O(n + m)