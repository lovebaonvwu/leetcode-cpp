class Solution {
 public:
  int minElements(vector<int>& nums, int limit, int goal) {
    long long sum = accumulate(nums.begin(), nums.end(), 0LL);
    long long gap = abs(sum - goal);

    return (gap + limit - 1) / limit;
  }
};
// Runtime: 187 ms, faster than 50.73%
// Memory Usage: 73.4 MB, less than 82.22%
// 2022.6.27 at 奥盛大厦