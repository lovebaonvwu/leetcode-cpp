class Solution {
 public:
  vector<int> findEvenNumbers(vector<int>& digits) {
    vector<int> cnt(10);

    for (auto d : digits) {
      ++cnt[d];
    }

    vector<int> ans;

    for (int i = 100; i <= 999; ++i) {
      if (i & 1) {
        continue;
      }

      int n = i;

      vector<int> tmp = cnt;
      bool flag = true;

      while (n > 0) {
        if (tmp[n % 10] == 0) {
          flag = false;
          break;
        }

        --tmp[n % 10];
        n /= 10;
      }

      if (flag) {
        ans.push_back(i);
      }
    }

    return ans;
  }
};
// Runtime: 17 ms, faster than 69.36%
// Memory Usage: 12 MB, less than 22.62%
// 2021.12.18 at 茗筑美嘉