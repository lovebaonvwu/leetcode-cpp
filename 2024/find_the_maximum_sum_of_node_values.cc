class Solution {
 public:
  long long maximumValueSum(vector<int>& nums,
                            int k,
                            vector<vector<int>>& edges) {
    long long sum = accumulate(begin(nums), end(nums), 0LL);
    for (auto& n : nums) {
      int t = n ^ k;
      n = t - n;
    }

    sort(rbegin(nums), rend(nums));

    long long add = 0;
    int n = nums.size();
    for (int i = 0; i < n - 1; i += 2) {
      if (nums[i] + nums[i + 1] >= 0) {
        add += nums[i] + nums[i + 1];
      }
    }

    return sum + add;
  }
};
// 206 ms
// 127.84 MB