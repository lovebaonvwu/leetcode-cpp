class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    unordered_map<int, int> mp;
    int max = INT_MIN;

    for (int& n : nums) {
      mp[n] = 1;
      if (n > max) {
        max = n;
      }
    }

    if (max < 0) {
      return 1;
    }

    for (int i = 1; i < max; ++i) {
      if (!mp[i]) {
        return i;
      }
    }

    return max + 1;
  }
};  // 4ms