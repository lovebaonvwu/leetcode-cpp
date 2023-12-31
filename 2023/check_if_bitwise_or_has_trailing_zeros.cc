class Solution {
 public:
  bool hasTrailingZeros(vector<int>& nums) {
    int cnt = 0;
    for (auto n : nums) {
      cnt += n % 2 == 0;
    }

    return cnt >= 2;
  }
};
// 19ms
// 25.55MB