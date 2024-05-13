class Solution {
 public:
  int maximumEnergy(vector<int>& energy, int k) {
    int n = energy.size();
    int ans = INT_MIN;
    for (int i = 0; i < k; ++i) {
      int sum = INT_MIN / 2;
      for (int j = i; j < n; j += k) {
        if (sum + energy[j] < energy[j]) {
          sum = energy[j];
        } else {
          sum += energy[j];
        }
      }

      ans = max(ans, sum);
    }

    return ans;
  }
};
// 148 ms
// 143.84 MB