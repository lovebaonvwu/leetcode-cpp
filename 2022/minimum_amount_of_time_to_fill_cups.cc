class Solution {
 public:
  int fillCups(vector<int>& amount) {
    int ans = 0;

    int& a = amount[0];
    int& b = amount[1];
    int& c = amount[2];

    while (a > 0 || b > 0 || c > 0) {
      sort(amount.rbegin(), amount.rend());

      if (b > 0) {
        ++ans;
        a--;
        b--;
      } else {
        ans += a;
        break;
      }
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 32.69%
// Memory Usage: 11.7 MB, less than 88.39%
// 2022.7.17 at 茗筑美嘉