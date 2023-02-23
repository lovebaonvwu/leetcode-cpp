class Solution {
 public:
  int shipWithinDays(vector<int>& weights, int days) {
    int lo = *max_element(weights.begin(), weights.end());
    int hi = accumulate(weights.begin(), weights.end(), 0);

    while (lo < hi) {
      int md = (lo + hi) / 2;
      int cnt = 0;
      int sum = 0;
      for (int i = 0; i < weights.size();) {
        int sum = 0;
        while (i < weights.size() && (sum + weights[i]) <= md) {
          sum += weights[i++];
        }
        ++cnt;
      }

      if (cnt <= days) {
        hi = md;
      } else {
        lo = md + 1;
      }
    }

    return lo;
  }
};
// Runtime 182 ms
// Memory 26.1 MB
// 2023.2.22 at 奥盛大厦