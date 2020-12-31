class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    int ans = 0;

    for (int i = 0; i < heights.size(); ++i) {
      int low = i;

      while (low - 1 >= 0) {
        if (heights[low - 1] < heights[i]) {
          break;
        }

        --low;
      }

      int high = i;

      while (high + 1 < heights.size()) {
        if (heights[high + 1] < heights[i]) {
          break;
        }

        ++high;
      }

      ans = max(ans, (high - low + 1) * heights[i]);
    }

    return ans;
  }
};
// Time Limit Exceeded