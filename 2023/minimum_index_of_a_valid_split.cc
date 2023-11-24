class Solution {
 public:
  int minimumIndex(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> mp;
    int x = nums[0], cnt = 1;
    for (int i = 0; i < n; ++i) {
      ++mp[nums[i]];
      if (mp[nums[i]] > cnt) {
        x = nums[i];
        cnt = mp[nums[i]];
      }
    }

    vector<int> presum(n + 1);
    for (int i = 1; i <= n; ++i) {
      if (nums[i - 1] == x) {
        presum[i] = 1 + presum[i - 1];
      } else {
        presum[i] = presum[i - 1];
      }
    }

    for (int i = 0; i < n; ++i) {
      int a = presum[i + 1] - presum[0];
      int b = presum[n] - presum[i + 1];
      if ((2 * a > (i + 1)) && (2 * b > (n - i - 1))) {
        return i;
      }
    }

    return -1;
  }
};
// 247 ms
// 96.9 MB