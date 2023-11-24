class Solution {
 public:
  int finalValueAfterOperations(vector<string>& operations) {
    int ans = 0;

    for (auto& oper : operations) {
      ans += oper[1] == '+' ? 1 : -1;
    }

    return ans;
  }
};
// Runtime: 12 ms, faster than 51.03%
// Memory Usage: 14.1 MB, less than 10.90%
// 2021.9.21 at 茗筑美嘉