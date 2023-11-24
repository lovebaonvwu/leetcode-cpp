class Solution {
 public:
  int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
    int n = nums.size();
    vector<int> presum(n + 1);
    for (int i = 1; i <= n; ++i) {
      presum[i] = presum[i - 1] + nums[i - 1];
    }

    int ans = 0;

    function<void(int, int)> sum = [&](int firstLen, int secondLen) -> void {
      for (int i = 0; i < n - firstLen; ++i) {
        int sum1 = presum[i + firstLen] - presum[i];
        for (int j = i + firstLen; j <= n - secondLen; ++j) {
          int sum2 = presum[j + secondLen] - presum[j];
          ans = max(ans, sum1 + sum2);
        }
      }
    };

    sum(firstLen, secondLen);
    sum(secondLen, firstLen);

    return ans;
  }
};
// 3ms
// 9.01MB