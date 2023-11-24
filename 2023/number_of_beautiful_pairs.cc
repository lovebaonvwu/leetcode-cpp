class Solution {
 public:
  int countBeautifulPairs(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int a = 0;
        int t = nums[i];
        while (t > 0) {
          a = t % 10;
          t /= 10;
        }
        int b = nums[j] % 10;
        if (__gcd(a, b) == 1) {
          ++ans;
        }
      }
    }

    return ans;
  }
};
// 48ms
// 67.96MB

class Solution {
 public:
  int countBeautifulPairs(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int a = 0;
      int t = nums[i];
      while (t > 0) {
        a = t % 10;
        t /= 10;
      }
      for (int j = i + 1; j < n; ++j) {
        int b = nums[j] % 10;
        if (__gcd(a, b) == 1) {
          ++ans;
        }
      }
    }

    return ans;
  }
};
// 36ms
// 67.96MB