class Solution {
 public:
  int leastBricks(vector<vector<int>>& wall) {
    unordered_map<int, int> mp;

    for (auto& row : wall) {
      for (int j = 0, w = 0; j < row.size() - 1; ++j) {
        w += row[j];
        ++mp[w];
      }
    }

    int ans = wall.size();

    for (auto [k, v] : mp) {
      ans = min(ans, static_cast<int>(wall.size()) - v);
    }

    return ans;
  }
};
// Runtime: 48 ms, faster than 41.90%
// Memory Usage: 21.7 MB, less than 50.69%