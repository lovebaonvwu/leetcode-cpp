class Solution {
 public:
  string generateTheString(int n) {
    return n & 1 ? string(n, 'a') : string(n - 1, 'a') + 'b';
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8 MB, less than 100.00%

class Solution {
 public:
  string generateTheString(int n) {
    if (n & 1) {
      return string(n, 'a');
    } else {
      return string(n - 1, 'a') + 'b';
    }
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 7.9 MB, less than 100.00%