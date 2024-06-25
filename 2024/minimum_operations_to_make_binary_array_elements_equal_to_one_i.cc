class Solution {
 public:
  int minOperations(vector<int>& nums) {
    int n = nums.size();
    vector<int> diff(n + 1);
    int cur = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      cur -= diff[i];

      if (nums[i] + cur % 2 == 1)
        continue;
      if (i + 3 - 1 >= n)
        return -1;
      ++cur;
      --diff[i + 3];
      ++ans;
    }

    return ans;
  }
};
// 116 ms
// 144.35 MB