class Solution {
 public:
  vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    vector<int> ans(2);
    int n = grid.size();
    vector<int> cnt(n * n + 1);
    for (auto& g : grid) {
      for (auto& v : g) {
        ++cnt[v];
        if (cnt[v] > 1) {
          ans[0] = v;
        }
      }
    }

    for (int i = 1; i < cnt.size(); ++i) {
      if (cnt[i] == 0) {
        ans[1] = i;
        break;
      }
    }

    return ans;
  }
};
// 25ms
// 22.83MB