class Solution {
 public:
  int maxDistance(vector<int>& colors) {
    int ans = 0;

    for (int i = 0; i < colors.size(); ++i) {
      for (int j = i + 1; j < colors.size(); ++j) {
        if (colors[i] != colors[j]) {
          ans = max(ans, j - i);
        }
      }
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 72.73%
// Memory Usage: 8.8 MB, less than 90.91%
// 2021.11.21 at 茗筑美嘉

class Solution {
 public:
  int maxDistance(vector<int>& colors) {
    int ans = 0;

    for (int i = 1, n = colors.size(); i < n; ++i) {
      if (colors[i] != colors[0]) {
        ans = max(ans, i);
      }

      if (colors[i] != colors[n - 1]) {
        ans = max(ans, n - 1 - i);
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 9 MB, less than 9.09%
// 2021.11.21 at 茗筑美嘉