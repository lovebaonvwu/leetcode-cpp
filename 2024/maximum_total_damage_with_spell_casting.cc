class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, int> mp;
        for (auto p : power) {
            ++mp[p];
        }
        vector<pair<int, int>> spell;
        for (auto [k, v] : mp) {
            spell.push_back({k, v});
        }

        sort(begin(spell), end(spell));

        int n = spell.size();
        vector<long long> dp(n);
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                dp[i] = dp[i - 1];
            }
            dp[i] = max(dp[i], 1LL * spell[i].first * spell[i].second);
            if (i > 0 && spell[i].first - spell[i - 1].first > 2) {
                dp[i] = max(dp[i], dp[i - 1] + spell[i].first * spell[i].second);
            } else if (i > 1 && spell[i].first - spell[i - 2].first > 2) {
                dp[i] = max(dp[i], dp[i - 2] + spell[i].first * spell[i].second);
            } else if (i > 2) {
                dp[i] = max(dp[i], dp[i - 3] + spell[i].first * spell[i].second);
            }
        }


        return dp[n - 1];
    }
};
// 463 ms
// 207.48 MB

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, int> mp;
        for (auto p : power) {
            ++mp[p];
        }
        vector<pair<int, int>> spell;
        for (auto [k, v] : mp) {
            spell.push_back({k, v});
        }

        sort(begin(spell), end(spell));

        int n = spell.size();
        vector<long long> dp(n);
        dp[0] = 1LL * spell[0].first * spell[0].second;
        for (int i = 1; i < n; ++i) {
            long long damage = 1LL * spell[i].first * spell[i].second;
            if (i > 0 && spell[i].first - spell[i - 1].first > 2) {
                damage += dp[i - 1];
            } else if (i > 1 && spell[i].first - spell[i - 2].first > 2) {
                damage += dp[i - 2];
            } else if (i > 2) {
                damage += dp[i - 3];
            }

            dp[i] = max(dp[i - 1], damage);
        }


        return dp[n - 1];
    }
};
// 424 ms
// 207.40 MB

