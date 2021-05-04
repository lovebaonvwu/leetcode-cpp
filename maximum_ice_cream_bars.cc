class Solution {
 public:
  int maxIceCream(vector<int>& costs, int coins) {
    sort(costs.begin(), costs.end());

    int ans = 0;

    for (auto c : costs) {
      if (coins < c) {
        break;
      }

      coins -= c;
      ++ans;
    }

    return ans;
  }
};
// Runtime: 152 ms, faster than 83.27%
// Memory Usage: 76.5 MB, less than 12.19%