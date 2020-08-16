class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int firstBuy = INT_MAX;
    int firstStockProfit = 0;
    int secondBuy = INT_MAX;
    int secondStockProfit = 0;

    for (auto p : prices) {
      firstBuy = min(firstBuy, p);
      firstStockProfit = max(firstStockProfit, p - firstBuy);
      secondBuy = min(secondBuy, p - firstStockProfit);
      secondStockProfit = max(secondStockProfit, p - secondBuy);
    }

    return secondStockProfit;
  }
};
// Runtime: 16 ms, faster than 59.39%
// Memory Usage: 13.2 MB, less than 67.38%