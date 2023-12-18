class Solution {
 public:
  vector<vector<int>> divideArray(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;
    int n = nums.size();
    for (int i = 2; i < n; i += 3) {
      if (nums[i] - nums[i - 2] <= k) {
        ans.push_back({nums[i - 2], nums[i - 1], nums[i]});
      } else {
        return vector<vector<int>>();
      }
    }

    return ans;
  }
};
// 136ms
// 115.20MB