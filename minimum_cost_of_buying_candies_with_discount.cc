class Solution {
 public:
  int minimumCost(vector<int>& cost) {
    sort(cost.rbegin(), cost.rend());

    int ans = 0;

    for (int i = 0, j = 1; i < cost.size(); ++i, ++j) {
      if (j % 3 == 0) {
        continue;
      }

      ans += cost[i];
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 51.38%
// Memory Usage: 10.8 MB, less than 35.76%
// 2022.1.31 at 茗筑美嘉