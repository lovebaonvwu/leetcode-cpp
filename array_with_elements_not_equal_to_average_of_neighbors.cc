class Solution {
 public:
  vector<int> rearrangeArray(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int n = nums.size();

    vector<int> ans(n);

    int i = 0;
    for (int j = 0; j < ans.size(); j += 2) {
      ans[j] = nums[i++];
    }

    for (int j = 1; i < nums.size(); j += 2) {
      ans[j] = nums[i++];
    }

    return ans;
  }
};
// Runtime: 353 ms, faster than 47.18%
// Memory Usage: 123.3 MB, less than 42.21%
// 2022.2.23 at 茗筑美嘉