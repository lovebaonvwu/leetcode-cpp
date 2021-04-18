class Solution {
 public:
  int findNthDigit(int n) {
    long base = 9, digit = 1;

    while (base * digit < n) {
      n -= base * digit;

      base *= 10;
      ++digit;
    }

    int index = (n - 1) % digit;
    int offset = (n - 1) / digit;

    int start = pow(10, digit - 1);

    return to_string(start + offset)[index] - '0';
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.2 MB, less than 16.94%