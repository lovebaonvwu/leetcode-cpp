class Solution {
 public:
  vector<int> finalPrices(vector<int>& prices) {
    vector<int> ans(prices.size());

    for (int i = 0; i < prices.size(); ++i) {
      bool find = false;
      for (int j = i + 1; j < prices.size(); ++j) {
        if (prices[j] <= prices[i]) {
          ans[i] = prices[i] - prices[j];
          find = true;
          break;
        }
      }

      if (!find) {
        ans[i] = prices[i];
      }
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 85.31%
// Memory Usage: 9.9 MB, less than 100.00%

class Solution {
 public:
  vector<int> finalPrices(vector<int>& prices) {
    stack<int> stk;

    for (int i = 0; i < prices.size(); ++i) {
      while (!stk.empty() && prices[stk.top()] >= prices[i]) {
        prices[stk.top()] -= prices[i];
        stk.pop();
      }
      stk.push(i);
    }

    return prices;
  }
};
// Runtime: 8 ms, faster than 85.31%
// Memory Usage: 10.1 MB, less than 33.33%