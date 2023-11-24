class Solution {
 public:
  int monotoneIncreasingDigits(int n) {
    vector<int> digits;

    while (n > 0) {
      digits.push_back(n % 10);
      n /= 10;
    }

    reverse(digits.begin(), digits.end());

    for (int i = 1; i < digits.size(); ++i) {
      if (digits[i] < digits[i - 1]) {
        int j = i - 1;

        while (j - 1 >= 0 && digits[j - 1] == digits[j]) {
          --j;
        }

        --digits[j++];

        while (j < digits.size()) {
          digits[j++] = 9;
        }
      }
    }

    int ans = 0;

    for (auto n : digits) {
      ans = ans * 10 + n;
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.2 MB, less than 14.88%
// 2022.2.18 at 奥盛大厦