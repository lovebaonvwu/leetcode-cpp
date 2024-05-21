class Solution {
 public:
  vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
    vector<int> arr;
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
      if (nums[i] % 2 != nums[i + 1] % 2) {
        arr.push_back(1);
      } else {
        arr.push_back(0);
      }
    }

    vector<int> presum(n);
    for (int i = 1; i < n; ++i) {
      presum[i] = presum[i - 1] + arr[i - 1];
    }

    vector<bool> ans;
    for (auto& q : queries) {
      if (q[1] - q[0] == presum[q[1]] - presum[q[0]])
        ans.push_back(true);
      else
        ans.push_back(false);
    }

    return ans;
  }
};
// 195 ms
// 128.37 MB