class Solution {
 public:
  vector<int> buildArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);

    for (int i = 0; i < n; ++i) {
      ans[i] = nums[nums[i]];
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 100.00%
// Memory Usage: 16.2 MB, less than 33.33%
// 2021.7.5 at 奥盛大厦

class Solution {
 public:
  vector<int> buildArray(vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
      nums[i] += n * (nums[nums[i]] % n);
    }

    for (auto& num : nums) {
      num /= n;
    }

    return nums;
  }
};
// Runtime: 4 ms, faster than 100.00%
// Memory Usage: 16 MB, less than 100.00%
// 2021.7.5 at 奥盛大厦