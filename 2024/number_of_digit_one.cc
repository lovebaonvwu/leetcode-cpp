class Solution {
 public:
  int countDigitOne(int n) {
    vector<int> digits;

    int t = n;
    while (t > 0) {
      digits.push_back(t % 10);
      t /= 10;
    }

    int ans = 0;
    int sz = digits.size();
    for (int i = 0; i < sz; ++i) {
      if (digits[i] == 0) {
        int major = 0;
        for (int j = sz - 1; j > i; --j) {
          major = major * 10 + digits[j];
        }

        ans += major * pow(10, i);
      } else if (digits[i] == 1) {
        int major = 0;
        for (int j = sz - 1; j > i; --j) {
          major = major * 10 + digits[j];
        }

        ans += major * pow(10, i);

        int minor = 0;
        for (int j = i - 1; j >= 0; --j) {
          minor = minor * 10 + digits[j];
        }

        ans += minor + 1;
      } else {
        int major = 0;
        for (int j = sz - 1; j > i; --j) {
          major = major * 10 + digits[j];
        }

        ans += (major + 1) * pow(10, i);
      }
    }

    return ans;
  }
};
// 1 ms
// 7.39 MB