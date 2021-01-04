class Solution {
 public:
  int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(),
         [](auto& a, auto& b) { return a[1] > b[1]; });

    int ans = 0;

    for (auto& b : boxTypes) {
      ans += b[1] * max(0, min(truckSize, b[0]));
      truckSize -= b[0];
    }

    return ans;
  }
};
// Runtime: 80 ms, faster than 33.33%
// Memory Usage: 16.3 MB, less than 66.67%

class Solution {
 public:
  int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(),
         [](auto& a, auto& b) { return a[1] > b[1]; });

    int ans = 0;

    for (int i = 0; i < boxTypes.size() && truckSize > 0; ++i) {
      ans += boxTypes[i][1] * min(truckSize, boxTypes[i][0]);
      truckSize -= boxTypes[i][0];
    }

    return ans;
  }
};
// Runtime: 72 ms, faster than 83.33%
// Memory Usage: 16.4 MB, less than 33.33%