class Solution {
 public:
  int findSmallestInteger(vector<int>& nums, int value) {
    unordered_map<int, int> cnt;
    for (auto n : nums) {
      ++cnt[(value + (n % value)) % value];
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (cnt[i % value]-- == 0) {
        return i;
      }
    }

    return nums.size();
  }
};
// Runtime 281 ms
// Memory 120.9 MB