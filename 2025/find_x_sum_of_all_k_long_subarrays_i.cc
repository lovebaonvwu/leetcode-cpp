class Solution
{
public:
    vector<int> findXSum(vector<int> &nums, int k, int x)
    {
        int n = nums.size();

        vector<int> ans;
        vector<int> cnt(51);

        for (int i = 0; i < n; ++i)
        {
            ++cnt[nums[i]];
            if (i >= k)
            {
                --cnt[nums[i - k]];
            }

            vector<int> indexs(51);
            iota(begin(indexs), end(indexs), 0);
            sort(begin(indexs), end(indexs), [cnt](auto &a, auto &b)
                 {
                if (cnt[a] == cnt[b]) {
                    return a > b;
                }

                return cnt[a] > cnt[b]; });

            int sum = 0;
            for (int k = 0; k < x; ++k)
            {
                sum += cnt[indexs[k]] * indexs[k];
            }

            if (i >= k - 1)
            {
                ans.push_back(sum);
            }
        }

        return ans;
    }
};
// Time: O(n * log(n))
// Space: O(n)