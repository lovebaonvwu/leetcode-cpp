class Solution {
 public:
  int findRadius(vector<int>& houses, vector<int>& heaters) {
    int n = houses.size();

    vector<int> rhs(n, INT_MAX), lhs(n, INT_MAX);

    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());

    for (int i = 0, j = 0; i < n && j < heaters.size();) {
      if (heaters[j] >= houses[i]) {
        rhs[i] = min(rhs[i], heaters[j] - houses[i]);
        ++i;
      } else {
        ++j;
      }
    }

    for (int i = n - 1, j = heaters.size() - 1; i >= 0 && j >= 0;) {
      if (heaters[j] <= houses[i]) {
        lhs[i] = min(lhs[i], houses[i] - heaters[j]);
        --i;
      } else {
        --j;
      }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = max(ans, min(lhs[i], rhs[i]));
    }

    return ans;
  }
};
// Runtime: 56 ms, faster than 91.58%
// Memory Usage: 26.3 MB, less than 10.08%
// 2022.3.25 at 奥盛大厦