class Solution {
 public:
  bool isOneBitCharacter(vector<int>& bits) {
    int i = 0;
    while (i < bits.size() - 1) {
      if (bits[i] == 0) {
        ++i;
      } else {
        i += 2;
      }
    }

    return (i == bits.size() - 1) && bits.back() == 0;
  }
};
// Runtime: 8 ms, faster than 39.79%
// Memory Usage: 9.7 MB, less than 64.79%
// 2022.6.24 at 奥盛大厦