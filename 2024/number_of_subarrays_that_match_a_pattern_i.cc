class Solution {
 public:
  int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
    int ans = 0;
    int n = nums.size();
    int m = pattern.size();
    for (int i = 0; i < n - m; ++i) {
      int j = 0;
      while (j < m) {
        if (pattern[j] == 1 && nums[i + j] < nums[i + j + 1]) {
          ++j;
        } else if (pattern[j] == 0 && nums[i + j] == nums[i + j + 1]) {
          ++j;
        } else if (pattern[j] == -1 && nums[i + j] > nums[i + j + 1]) {
          ++j;
        } else {
          break;
        }
      }

      ans += j == m;
    }

    return ans;
  }
};
// 18 ms
// 42.49 MB