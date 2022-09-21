class Solution {
 public:
  int totalFruit(vector<int>& fruits) {
    unordered_map<int, int> type;

    int ans = 0;
    int n = fruits.size();
    for (int i = 0, j = 0; j < n; ++j) {
      ++type[fruits[j]];

      while (i < n && type.size() > 2) {
        --type[fruits[i]];
        if (type[fruits[i]] == 0) {
          type.erase(fruits[i]);
        }
        ++i;
      }

      ans = max(ans, j - i + 1);
    }

    return ans;
  }
};
// Runtime: 400 ms, faster than 13.19%
// Memory Usage: 71.3 MB, less than 45.48%
// 2022.9.21 at 奥盛大厦