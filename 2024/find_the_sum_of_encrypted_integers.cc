class Solution {
 public:
  int sumOfEncryptedInt(vector<int>& nums) {
    int ans = 0;
    for (auto n : nums) {
      int maxDigit = 0;
      int len = 0;
      while (n > 0) {
        maxDigit = max(maxDigit, n % 10);
        n /= 10;
        ++len;
      }

      int encrypt = 0;
      for (int i = 0; i < len; ++i) {
        encrypt = encrypt * 10 + maxDigit;
      }

      ans += encrypt;
    }

    return ans;
  }
};
// 4 ms
// 26.66 MB