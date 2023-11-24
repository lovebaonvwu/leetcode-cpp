class Solution {
 public:
  int largestAltitude(vector<int>& gain) {
    int ans = 0;
    int altitude = 0;

    for (auto n : gain) {
      altitude += n;
      ans = max(ans, altitude);
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 66.67%
// Memory Usage: 8 MB, less than 100.00%