class Solution {
 public:
  vector<int> findDuplicates(vector<int>& nums) {
    vector<int> ans;

    int n = nums.size();

    for (int i = 0; i < n; ++i) {
      while (nums[i] != nums[nums[i] - 1]) {
        swap(nums[i], nums[nums[i] - 1]);
      }
    }

    for (int i = 0; i < n; ++i) {
      if (nums[i] != i + 1) {
        ans.push_back(nums[i]);
      }
    }

    return ans;
  }
};  // 112ms