class Solution {
 public:
  bool checkArray(vector<int>& nums, int k) {
    int n = nums.size();
    for (int i = 0; i <= n - k; ++i) {
      if (nums[i] == 0) {
        continue;
      }

      if (nums[i] < 0) {
        return false;
      }

      int val = nums[i];
      for (int j = 0; j < k; ++j) {
        nums[i + j] -= val;
      }
    }

    return count(nums.begin(), nums.end(), 0) == nums.size();
  }
};
// TLE

class Solution {
 public:
  bool checkArray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> diff(n + 1);

    diff[0] += nums[0];
    diff[k] -= nums[0];

    for (int i = 1; i < n; ++i) {
      diff[i] += diff[i - 1];

      if (diff[i] == nums[i]) {
        continue;
      }

      if (diff[i] > nums[i] || i + k - 1 >= n) {
        return false;
      }

      int d = nums[i] - diff[i];
      diff[i] += d;
      diff[i + k] -= d;
    }

    return true;
  }
};
// 171ms
// 97.62mb