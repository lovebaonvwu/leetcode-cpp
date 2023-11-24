class Solution {
 public:
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ans;

    if (nums.empty()) {
      return ans;
    }

    nums.push_back(nums.back());

    for (int i = 1, s = nums[0], e = nums[0]; i < nums.size(); ++i) {
      if (nums[i] - 1 != e) {
        if (s == e) {
          ans.push_back(to_string(e));
        } else {
          ans.push_back(to_string(s) + "->" + to_string(e));
        }

        s = nums[i];
      }

      e = nums[i];
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 7 MB, less than 100.00%