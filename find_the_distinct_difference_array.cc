class Solution {
 public:
  vector<int> distinctDifferenceArray(vector<int>& nums) {
    int n = nums.size();

    unordered_set<int> lset, rset;
    vector<int> lvec(n), rvec(n);

    for (int i = 0; i < n; ++i) {
      lset.insert(nums[i]);
      rset.insert(nums[n - i - 1]);

      lvec[i] = lset.size();
      rvec[n - i - 1] = rset.size();
    }

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      ans.push_back(lvec[i] - (i + 1 < n ? rvec[i + 1] : 0));
    }

    return ans;
  }
};
// Runtime 48 ms
// Memory 94.4 MB