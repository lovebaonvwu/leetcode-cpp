class Solution {
 public:
  int pivotIndex(vector<int>& nums) {
    if (nums.empty()) {
      return -1;
    }

    size_t n = nums.size();

    vector<int> sum(n, 0);

    sum[n - 1] = nums[n - 1];

    for (int i = n - 2; i >= 0; --i) {
      sum[i] = nums[i] + sum[i + 1];
    }

    int tmp = 0;
    for (int i = 0; i < nums.size(); ++i) {
      tmp += nums[i];

      if (tmp == sum[i]) {
        return i;
      }
    }

    return -1;
  }
};  // 24ms

class Solution {
 public:
  int pivotIndex(vector<int>& nums) {
    size_t n = nums.size();

    for (int i = 0; i < n; ++i) {
      int left = 0;
      int right = 0;

      for (int j = 0; j < i; ++j) {
        left += nums[j];
      }

      for (int j = i + 1; j < n; ++j) {
        right += nums[j];
      }

      if (left == right) {
        return i;
      }
    }

    return -1;
  }
};  // 1052ms