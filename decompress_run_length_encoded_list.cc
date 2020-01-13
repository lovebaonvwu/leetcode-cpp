class Solution {
 public:
  vector<int> decompressRLElist(vector<int>& nums) {
    vector<int> ans;

    for (int i = 0; i < nums.size(); i += 2) {
      while (nums[i]-- > 0) {
        ans.push_back(nums[i + 1]);
      }
    }

    return ans;
  }
};
// Runtime: 44 ms, faster than 100.00%
// Memory Usage: 10.6 MB, less than 100.00%