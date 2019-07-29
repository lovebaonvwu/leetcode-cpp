class Solution {
 public:
  int nextGreaterElement(int n) {
    if (n < 10) {
      return -1;
    }

    vector<int> nums;
    long ans = 0, m = n;

    while (n > 0) {
      nums.push_back(n % 10);
      n /= 10;
    }

    int i = 0;
    for (; i < nums.size() - 1 && nums[i] <= nums[i + 1]; ++i) {
    }
    if (i == nums.size() - 1) {
      return -1;
    }

    reverse(nums.begin(), nums.begin() + i + 1);

    for (int j = i + 1; j >= 0; --j) {
      if (nums[j] > nums[i + 1]) {
        swap(nums[j], nums[i + 1]);
        break;
      }
    }

    for (int i = nums.size() - 1; i >= 0; --i) {
      ans = ans * 10 + nums[i];
    }

    return ans == m || ans > INT_MAX ? -1 : ans;
  }
};  // 4ms