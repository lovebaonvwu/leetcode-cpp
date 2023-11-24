class Solution {
 public:
  vector<double> getCollisionTimes(vector<vector<int>>& cars) {
    vector<int> stk;

    int n = cars.size();

    vector<double> ans(n, -1);

    for (int i = n - 1; i >= 0; --i) {
      int p = cars[i][0], s = cars[i][1];

      while (!stk.empty()) {
        int j = stk.back(), p2 = cars[j][0], s2 = cars[j][1];

        if (s <= s2 || 1.0 * (p2 - p) / (s - s2) >= ans[j] && ans[j] > 0) {
          stk.pop_back();
        } else {
          break;
        }
      }

      if (!stk.empty()) {
        ans[i] = 1.0 * (cars[stk.back()][0] - p) / (s - cars[stk.back()][1]);
      }

      stk.push_back(i);
    }

    return ans;
  }
};
// 2021.10.3 at 茗筑美嘉