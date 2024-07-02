class Solution {
 public:
  vector<int> orArray(vector<int>& nums) {
    vector<int> ans;
    for (int i = 0; i < nums.size() - 1; ++i) {
      ans.push_back(nums[i] | nums[i + 1]);
    }

    return ans;
  }
};
// 18 ms
// 41.68 MB
