class Solution {
 public:
  int minOperations(vector<int>& nums) {
    int n = nums.size();
    int g = nums[0];
    int oneCnt = nums[0] == 1;
    for (int i = 1; i < n; ++i) {
      g = __gcd(g, nums[i]);
      oneCnt += nums[i] == 1;
    }

    if (g != 1) {
      return -1;
    }

    if (oneCnt) {
      return n - oneCnt;
    }

    int cnt = INT_MAX;
    for (int i = 0; i < n; ++i) {
      int g = nums[i];
      for (int j = i; j < n; ++j) {
        g = __gcd(g, nums[j]);
        if (g == 1) {
          cnt = min(cnt, j - i);
        }
      }
    }

    return n - 1 + cnt;
  }
};
// Runtime 4 ms
// Memory 27.6 MB