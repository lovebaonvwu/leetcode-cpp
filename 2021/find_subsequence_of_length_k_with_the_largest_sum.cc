class Solution {
 public:
  vector<int> maxSubsequence(vector<int>& nums, int k) {
    vector<int> tmp(nums.begin(), nums.end());

    nth_element(tmp.begin(), tmp.begin() + k - 1, tmp.end(), greater<int>());

    int cnt = count(tmp.begin(), tmp.begin() + k, tmp[k - 1]);

    vector<int> ans;

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > tmp[k - 1] || (nums[i] == tmp[k - 1] && cnt-- > 0)) {
        ans.push_back(nums[i]);
      }
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 94.53%
// Memory Usage: 9.2 MB, less than 92.57%
// 2021.12.22 at 奥盛大厦