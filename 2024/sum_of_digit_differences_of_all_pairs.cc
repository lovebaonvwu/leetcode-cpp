class Solution {
 public:
  long long sumDigitDifferences(vector<int>& nums) {
    int cnt[10][10] = {0};
    int n = nums.size();
    for (auto num : nums) {
      int i = 0;
      while (num > 0) {
        cnt[i++][num % 10] += 1;
        num /= 10;
      }
    }

    long long ans = 0;
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        for (int k = j + 1; k < 10; ++k) {
          ans += 1LL * cnt[i][j] * cnt[i][k];
        }
      }
    }

    return ans;
  }
};
// 103 ms
// 103.09 MB