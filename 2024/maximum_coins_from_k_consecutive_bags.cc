class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        sort(begin(coins), end(coins));
        int n = coins.back()[1];
        vector<int> cnt(n + 1);
        for (auto& coin : coins) {
            for (int i = coin[0]; i <= coin[1]; ++i) {
                cnt[i] = coin[2];
            }
        }

        long long ans = 0;
        long long sum = 0;
        for (int i = 0; i <= n; ++i) {
            sum += cnt[i];

            if (i >= k) {
                sum -= cnt[i - k];
            }

            ans = max(ans, sum);
        }

        return ans;
    }
};
// Memory Limit Exceeded

class Solution {
    long long helper(vector<vector<int>>& coins, int k) {
        int n = coins.size();
        long long ret = 0;
        long long sum = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            int end = coins[i][0] + k - 1;

            while (j < n && coins[j][1] <= end) {
                sum += 1LL * (coins[j][1] - coins[j][0] + 1) * coins[j][2];
                ++j;
            }

            long long extra = 0;
            if (j < n && coins[j][0] <= end) {
                extra = 1LL * (end - coins[j][0] + 1) * coins[j][2];
            }

            ret = max(ret, sum + extra);

            sum -= 1LL * (coins[i][1] - coins[i][0] + 1) * coins[i][2];
        }

        return ret;
    }
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        long long ans = 0;
        sort(begin(coins), end(coins));
        ans = helper(coins, k);

        for (auto& coin : coins) {
            int l = coin[0];
            int r = coin[1];

            coin[0] = -r;
            coin[1] = -l;
        }
        sort(begin(coins), end(coins));

        ans = max(ans, helper(coins, k));

        return ans;
    }
};
// 134 ms
// 157.79 MB
