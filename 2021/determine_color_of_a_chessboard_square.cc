class Solution {
 public:
  bool squareIsWhite(string coordinates) {
    return ((coordinates[0] - 'a') + (coordinates[1] - '1')) & 1;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 5.9 MB, less than 62.40%