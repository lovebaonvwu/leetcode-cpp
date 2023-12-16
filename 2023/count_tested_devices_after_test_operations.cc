class Solution {
 public:
  int countTestedDevices(vector<int>& batteryPercentages) {
    int ans = 0;
    int n = batteryPercentages.size();
    for (int i = 0; i < n; ++i) {
      if (batteryPercentages[i] > 0) {
        ++ans;
        for (int j = i + 1; j < n; ++j) {
          batteryPercentages[j] = max(batteryPercentages[j] - 1, 0);
        }
      }
    }

    return ans;
  }
};
// 15ms
// 17.71MB

class Solution {
 public:
  int countTestedDevices(vector<int>& batteryPercentages) {
    int ans = 0;
    int n = batteryPercentages.size();
    for (int i = 0; i < n; ++i) {
      if (batteryPercentages[i] - ans > 0) {
        ++ans;
      }
    }

    return ans;
  }
};
// 4ms
// 17.71MB