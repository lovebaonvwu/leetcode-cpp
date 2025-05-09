class Solution
{
public:
    int countBalancedPermutations(string num)
    {
        vector<int> cnt(10);
        int total = 0;

        for (auto n : num)
        {
            ++cnt[n - '0'];
            total += (n - '0');
        }

        if (total & 1)
        {
            return 0;
        }

        int target = total / 2;
        vector<int> psum(11);
        for (int i = 9; i >= 0; --i)
        {
            psum[i] = psum[i + 1] + cnt[i];
        }

        int n = num.size();
        int mod = 1e9 + 7;
        int maxEven = (n + 1) / 2;
        vector<vector<long long>> comb(maxEven + 1, vector<long long>(maxEven + 1));
        for (int i = 0; i <= maxEven; ++i)
        {
            comb[i][i] = comb[i][0] = 1;
            for (int j = 1; j < i; ++j)
            {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
            }
        }

        vector<vector<vector<long long>>> memo(10, vector<vector<long long>>(target + 1, vector<long long>(maxEven + 1, -1)));

        function<long long(int, int, int)> dfs = [&](int pos, int curr, int evenCnt) -> long long
        {
            if (evenCnt < 0 || psum[pos] < evenCnt || curr > target)
            {
                return 0;
            }

            if (pos > 9)
            {
                return curr == target && evenCnt == 0;
            }

            if (memo[pos][curr][evenCnt] != -1)
            {
                return memo[pos][curr][evenCnt];
            }

            long long ret = 0;
            int oddCnt = psum[pos] - evenCnt;

            for (int i = max(0, cnt[pos] - oddCnt); i <= min(cnt[pos], evenCnt); ++i)
            {
                long long ways = (comb[evenCnt][i] * comb[oddCnt][cnt[pos] - i]) % mod;
                ret = (ret + ways * dfs(pos + 1, curr + i * pos, evenCnt - i) % mod) % mod;
            }

            return memo[pos][curr][evenCnt] = ret;
        };

        return dfs(0, 0, maxEven);
    }
};
// Time: O(n^2 * target)
// Space: O(10 * target * maxEven)