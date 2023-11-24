class Solution {
 public:
  long long subArrayRanges(vector<int>& nums) {
    long long ans = 0;

    int n = nums.size();

    for (int i = 0; i < n; ++i) {
      int biggest = nums[i], smallest = nums[i];

      for (int j = i; j < n; ++j) {
        biggest = max(biggest, nums[j]);
        smallest = min(smallest, nums[j]);

        ans += biggest - smallest;
      }
    }

    return ans;
  }
};
// Runtime: 84 ms, faster than 27.27%
// Memory Usage: 10.5 MB, less than 18.18%
// 2021.12.13 at 奥盛大厦