class Solution {
 public:
  int minimizeXor(int num1, int num2) {
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < 31; ++i) {
      if (num1 & (1 << i)) {
        ++cnt1;
      }

      if (num2 & (1 << i)) {
        ++cnt2;
      }
    }

    if (cnt1 == cnt2) {
      return num1;
    }

    if (cnt1 > cnt2) {
      int ans = 0;
      for (int i = 30; i >= 0 && cnt2 > 0; --i) {
        if (num1 & (1 << i)) {
          ans |= (1 << i);
          --cnt2;
        }
      }

      return ans;
    } else {
      int ans = num1;
      cnt2 -= cnt1;
      for (int i = 0; i < 31 && cnt2 > 0; ++i) {
        if (!(num1 & (1 << i))) {
          ans |= (1 << i);
          --cnt2;
        }
      }

      return ans;
    }
  }
};
// Runtime: 3 ms, faster than 53.28%
// Memory Usage: 5.9 MB, less than 52.79%
// 2022.10.5 at 茗筑美嘉