class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0;

    for (int i = 0; i < 32; ++i) {
      int b = n & 1;
      n >>= 1;

      ans = ans * 2 + b;
    }

    return ans;
  }
};