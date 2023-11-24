class Solution {
 public:
  int minMoves2(vector<int>& nums) {
    sort(begin(nums), end(nums));

    int median = nums[nums.size() / 2];

    int ans = 0;

    for (auto n : nums) {
      ans += abs(n - median);
    }

    return ans;
  }
};
// Runtime: 12 ms, faster than 58.64%
// Memory Usage: 10.9 MB, less than 53.09%