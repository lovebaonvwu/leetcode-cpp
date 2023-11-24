class Solution {
 public:
  vector<long long> findPrefixScore(vector<int>& nums) {
    vector<long long> ans;

    long long curmax = 0;
    long long presum = 0;
    for (auto n : nums) {
      curmax = max<long long>(curmax, n);
      presum += n + curmax;
      ans.push_back(presum);
    }

    return ans;
  }
};
// Runtime 145 ms
// Memory 57.2 MB