class Solution {
 public:
  int minMoves(vector<int>& nums) {
    int min_num = *min_element(nums.begin(), nums.end());

    int ans = 0;

    for (auto n : nums) {
      ans += n - min_num;
    }

    return ans;
  }
};
// Runtime: 36 ms, faster than 63.16%
// Memory Usage: 28.2 MB, less than 99.23%