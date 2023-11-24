class Solution {
 public:
  int maximalNetworkRank(int n, vector<vector<int>>& roads) {
    vector<unordered_set<int>> cnt(101);
    for (auto& r : roads) {
      cnt[r[0]].insert(r[1]);
      cnt[r[1]].insert(r[0]);
    }

    int ans = 0;
    for (int i = 0; i < cnt.size(); ++i) {
      if (!cnt[i].empty()) {
        for (int j = i + 1; j < cnt.size(); ++j) {
          if (!cnt[j].empty()) {
            int p = cnt[i].size() + cnt[j].size() - cnt[j].count(i);
            ans = max(ans, p);
          }
        }
      }
    }

    return ans;
  }
};
// 90ms
// 39.05mb