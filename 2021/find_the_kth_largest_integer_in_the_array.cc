class Solution {
 public:
  string kthLargestNumber(vector<string>& nums, int k) {
    sort(nums.begin(), nums.end(), [](auto& a, auto& b) {
      if (a.size() == b.size()) {
        return a > b;
      } else {
        return a.size() > b.size();
      }
    });

    return nums[k - 1];
  }
};
// Runtime: 220 ms, faster than 76.47%
// Memory Usage: 55.2 MB, less than 64.71%