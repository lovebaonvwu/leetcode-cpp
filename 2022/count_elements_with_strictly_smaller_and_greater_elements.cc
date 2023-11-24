class Solution {
 public:
  int countElements(vector<int>& nums) {
    auto minmax = minmax_element(nums.begin(), nums.end());

    int ans = 0;
    for (auto n : nums) {
      if (n > *minmax.first && n < *minmax.second) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 7 ms, faster than 48.17%
// Memory Usage: 9.2 MB, less than 43.71%
// 2022.1.28 at 奥盛大厦