class Solution {
 public:
  vector<int> countBits(int num) {
    vector<int> ans(num + 1, 0);

    int exp = 0;
    int j = 0;
    int base = 0;

    for (int i = 0; i <= num; ++i) {
      if (i == pow(2, exp)) {
        ans[i] = 1;
        base = i;

        ++exp;
        j = 1;
      } else {
        ans[i] = ans[base] + ans[j++];
      }
    }

    return ans;
  }
};  // 52ms

class Solution {
 public:
  vector<int> countBits(int num) {
    vector<int> ans(num + 1, 0);

    int exp = 0;
    int j = 0;
    int k = 0;

    for (int i = 0; i <= num; ++i) {
      if (i == pow(2, exp)) {
        ans[i] = 1;
        k = pow(2, exp);

        ++exp;
        j = 1;
      } else {
        ans[i] = ans[k] + ans[j++];
      }
    }

    return ans;
  }
};  // 56ms

class Solution {
 public:
  vector<int> countBits(int num) {
    if (num < 1) {
      return {0};
    }

    vector<int> ans(num + 1, 0);

    int exp = 0;
    int j = 0;

    for (int i = 1; i <= num; ++i) {
      if (i == pow(2, exp)) {
        ans[i] = 1;
        ++exp;
        j = 1;
      } else {
        ans[i] = ans[pow(2, exp - 1)] + ans[j++];
      }
    }

    return ans;
  }
};  // 64ms