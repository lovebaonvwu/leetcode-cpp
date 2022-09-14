class Solution {
 public:
  int minOperationsMaxProfit(vector<int>& customers,
                             int boardingCost,
                             int runningCost) {
    int ans = -1, maxprofit = 0;
    int n = customers.size();
    for (int i = 0, wait = 0, profit = 0, onboard = 0; i < n || wait > 0; ++i) {
      if (i < n) {
        wait += customers[i];
      }

      onboard += min(wait, 4);
      wait -= min(wait, 4);
      profit = onboard * boardingCost - (i + 1) * runningCost;
      if (profit > maxprofit) {
        ans = i + 1;
        maxprofit = profit;
      }
    }

    return ans;
  }
};
// Runtime: 274 ms, faster than 17.31%
// Memory Usage: 81.5 MB, less than 40.38%
// 2022.9.14 at 奥盛大厦