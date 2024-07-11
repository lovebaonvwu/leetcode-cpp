class Solution {
 public:
  int minimumSwaps(vector<int>& nums) {
    int min_val = INT_MAX;
    int min_pos = -1;
    int max_val = INT_MIN;
    int max_pos = -1;

    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (nums[i] < min_val) {
        min_val = nums[i];
        min_pos = i;
      }

      if (nums[i] >= max_val) {
        max_val = nums[i];
        max_pos = i;
      }
    }

    return min_pos + (n - 1 - max_pos) - (min_pos > max_pos);
  }
};
// 56 ms
// 52.22 MB
