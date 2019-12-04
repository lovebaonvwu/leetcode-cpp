class Solution {
 public:
  int maxArea(vector<int>& height) {
    int ans = 0;

    for (int i = 0, j = height.size() - 1; i < j;) {
      int water = min(height[i], height[j]) * (j - i);

      ans = max(ans, water);

      if (height[i] < height[j]) {
        ++i;
      } else {
        --j;
      }
    }

    return ans;
  }
};
// Runtime: 16 ms, faster than 96.08%
// Memory Usage: 9.9 MB, less than 62.89%

class Solution {
 public:
  int maxArea(vector<int>& height) {
    int ans = 0;

    for (int i = 0; i < height.size() - 1; ++i) {
      for (int j = i + 1; j < height.size(); ++j) {
        int water = min(height[j], height[i]) * (j - i);
        ans = water > ans ? water : ans;
      }
    }

    return ans;
  }
};
// Runtime: 1200 ms, faster than 12.75%
// Memory Usage: 9.8 MB, less than 78.35%