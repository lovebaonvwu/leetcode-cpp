class Solution {
 public:
  bool isPossibleToSplit(vector<int>& nums) {
    vector<int> cnt(101);
    for (auto n : nums) {
      ++cnt[n];
      if (cnt[n] > 2)
        return false;
    }

    return true;
  }
};
// 7 ms
// 24.14 MB