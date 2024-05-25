class Solution {
 public:
  bool isArraySpecial(vector<int>& nums) {
    int n = nums.size();
    vector<int> cnt;
    for (int i = 0; i < n - 1; ++i) {
      if (nums[i] % 2 != nums[i + 1] % 2)
        cnt.push_back(1);
      else
        cnt.push_back(0);
    }

    vector<int> presum(n);
    for (int i = 1; i < n; ++i) {
      presum[i] = presum[i - 1] + cnt[i - 1];
    }

    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        if (j - i != presum[j] - presum[i])
          return false;
      }
    }

    return true;
  }
};
// 12 ms
// 27.77 MB