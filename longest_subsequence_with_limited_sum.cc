class Solution {
 public:
  vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    int m = queries.size();

    vector<int> presum(n);
    presum[0] = nums[0];
    for (int i = 1; i < n; ++i) {
      presum[i] = nums[i] + presum[i - 1];
    }

    vector<int> ans;
    for (auto q : queries) {
      auto it = upper_bound(presum.begin(), presum.end(), q);
      int pos = 0;
      if (it != presum.begin()) {
        pos = it - presum.begin();
      }
      ans.push_back(pos);
    }

    return ans;
  }
};
// Runtime: 13 ms, faster than 100.00%
// Memory Usage: 14.1 MB, less than 20.00%
// 2022.8.28 at 茗筑美嘉