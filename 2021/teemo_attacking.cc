class Solution {
 public:
  int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    if (timeSeries.empty()) {
      return 0;
    }

    int ans = 0;

    for (int i = 0; i < timeSeries.size() - 1; ++i) {
      if (timeSeries[i] + duration <= timeSeries[i + 1]) {
        ans += duration;
      } else {
        ans += timeSeries[i + 1] - timeSeries[i];
      }
    }

    return ans + duration;
  }
};
// Runtime: 80 ms, faster than 98.23%
// Memory Usage: 26.2 MB, less than 11.11%