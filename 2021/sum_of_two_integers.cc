class Solution {
 public:
  int getSum(int a, int b) {
    while (b != 0) {
      int carry = a & b;
      a = a ^ b;

      b = (unsigned int)carry << 1;
    }

    return a;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.1 MB, less than 9.59%