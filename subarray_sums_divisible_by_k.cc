class Solution {
 public:
  int subarraysDivByK(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> presum(n + 1);
    for (int i = 1; i <= n; ++i) {
      presum[i] = nums[i - 1] + presum[i - 1];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        if ((presum[j + 1] - presum[i]) % k == 0) {
          ++ans;
        }
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int subarraysDivByK(vector<int>& nums, int k) {
    vector<int> group(k);
    int rem = 0;
    int ans = 0;
    group[0] = 1;

    for (auto n : nums) {
      rem = (rem + n % k + k) % k;
      ans += group[rem]++;
    }

    return ans;
  }
};
// Runtime 55 ms
// Memory 30.1 MB
// 2023.1.19 at 奥盛大厦