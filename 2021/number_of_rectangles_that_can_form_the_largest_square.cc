class Solution {
 public:
  int countGoodRectangles(vector<vector<int>>& rectangles) {
    int ans = 0, maxLen = 0;

    for (auto& rect : rectangles) {
      int len = min(rect[0], rect[1]);

      if (len > maxLen) {
        maxLen = len;
        ans = 1;
      } else if (len == maxLen) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 40 ms, faster than 100.00%
// Memory Usage: 18.2 MB, less than 100.00%