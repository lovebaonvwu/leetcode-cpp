class Solution {
 public:
  int sumDistance(vector<int>& nums, string s, int d) {
    int mod = 1e9 + 7;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      nums[i] += s[i] == 'L' ? -d : d;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        ans = (ans + abs(nums[i] * 1LL - nums[j] * 1LL) % mod) % mod;
      }
    }

    return ans;
  }
};
// TLE

class Solution {
 public:
  int sumDistance(vector<int>& nums, string s, int d) {
    int mod = 1e9 + 7;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      nums[i] += s[i] == 'L' ? -d : d;
    }

    sort(nums.begin(), nums.end());
    int ans = 0;
    long long presum = 0;
    for (int i = 0; i < n; ++i) {
      presum += nums[i];
      ans = (ans + ((i + 1) * 1LL * nums[i] - presum)) % mod;
    }

    return ans;
  }
};
// Runtime 176 ms
// Memory 93.4 MB