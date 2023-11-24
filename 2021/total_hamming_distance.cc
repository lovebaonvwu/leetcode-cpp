class Solution {
  int hammingDistance(int a, int b) {
    int cnt = 0;

    for (int i = 0; i < 32; ++i) {
      cnt += ((a >> i) & 1) ^ ((b >> i) & 1);
    }

    return cnt;
  }

 public:
  int totalHammingDistance(vector<int>& nums) {
    int ans = 0;

    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        ans += hammingDistance(nums[i], nums[j]);
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int totalHammingDistance(vector<int>& nums) {
    int ans = 0;

    for (int i = 0, n = nums.size(); i < 32; ++i) {
      int b = 0;

      for (int j = 0; j < n; ++j) {
        if ((nums[j] >> i) & 1) {
          ++b;
        }
      }

      ans += b * (n - b);
    }

    return ans;
  }
};
// Runtime: 72 ms, faster than 89.65%
// Memory Usage: 19.5 MB, less than 6.05%