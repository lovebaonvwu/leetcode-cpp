class Solution {
 public:
  long long maximumTripletValue(vector<int>& nums) {
    long long ans = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        for (int k = j + 1; k < n; ++k) {
          ans = max(ans, 1LL * (nums[i] - nums[j]) * nums[k]);
        }
      }
    }

    return ans;
  }
};
// 14ms
// 17.84MB

class Solution {
 public:
  long long maximumTripletValue(vector<int>& nums) {
    long long ans = 0;
    int n = nums.size();
    vector<int> rmax(n);
    rmax[n - 1] = nums.back();
    for (int i = n - 2; i >= 0; --i) {
      rmax[i] = max(nums[i], rmax[i + 1]);
    }
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n - 1; ++j) {
        if (nums[i] > nums[j]) {
          ans = max(ans, 1LL * (nums[i] - nums[j]) * rmax[j + 1]);
        }
      }
    }

    return ans;
  }
};
// 3ms
// 18.30MB