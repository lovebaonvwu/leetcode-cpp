class Solution {
 public:
  int numberOfBeams(vector<string>& bank) {
    int ans = 0;

    int a = 0, b = 0;
    for (auto c : bank[0]) {
      if (c == '1') {
        ++a;
      }
    }

    for (int i = 1; i < bank.size(); ++i) {
      for (int j = 0; j < bank[i].size(); ++j) {
        if (bank[i][j] == '1') {
          ++b;
        }
      }

      if (b == 0) {
        continue;
      }

      ans += a * b;
      a = b;
      b = 0;
    }

    return ans;
  }
};
// Runtime: 179 ms, faster than 16.67%
// Memory Usage: 23 MB, less than 100.00%
// 2022.1.2 at 茗筑美嘉