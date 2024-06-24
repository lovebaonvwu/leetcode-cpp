class Solution {
 public:
  int minKBitFlips(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> diff(n + 1);
    int cnt = 0;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
      cnt += diff[i];
      if (nums[i] + cnt % 2 == 1)
        continue;
      if (i + k - 1 >= n)
        return -1;
      ++cnt;
      diff[i + k] -= 1;
      ++ans;
    }

    return ans;
  }
};
// 79 ms
// 113.26 MB