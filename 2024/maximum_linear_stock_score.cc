class Solution {
 public:
  long long maxScore(vector<int>& prices) {
    int n = prices.size();
    vector<int> diff(n);
    for (int i = 0; i < n; ++i) {
      diff[i] = prices[i] - (i + 1);
    }

    unordered_map<int, long long> mp;
    for (int i = 0; i < n; ++i) {
      mp[diff[i]] += prices[i];
    }

    long long ans = 0LL;
    for (auto [_, val] : mp) {
      ans = max(ans, val);
    }

    return ans;
  }
};
// 175 ms
// 129.86 MB