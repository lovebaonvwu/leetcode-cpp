class Solution {
 public:
  vector<int> numberGame(vector<int>& nums) {
    sort(begin(nums), end(nums));

    vector<int> ans;
    for (int i = 0; i < nums.size() - 1; i += 2) {
      ans.push_back(nums[i + 1]);
      ans.push_back(nums[i]);
    }

    return ans;
  }
};
// 11ms
// 24.52MB