class Solution {
 public:
  double calculateTax(vector<vector<int>>& brackets, int income) {
    double ans = 0;

    for (int i = 0, prev = 0; i < brackets.size() && income > 0; ++i) {
      double pay = min(income, brackets[i][0] - prev);
      ans += pay * brackets[i][1] / 100;

      income -= pay;
      prev = brackets[i][0];
    }

    return ans;
  }
};
// Runtime: 14 ms, faster than 86.69%
// Memory Usage: 13.5 MB, less than 26.63%
// 2022.6.18 at 茗筑美嘉