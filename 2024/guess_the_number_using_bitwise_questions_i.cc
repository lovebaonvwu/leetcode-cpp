/**
 * Definition of commonSetBits API.
 * int commonSetBits(int num);
 */

class Solution {
 public:
  int findNumber() {
    int ans = 0;
    for (int i = 0; i < 31; ++i) {
      if (commonSetBits(1 << i)) {
        ans |= 1 << i;
      }
    }

    return ans;
  }
};
// 7 ms
// 7.40 MB