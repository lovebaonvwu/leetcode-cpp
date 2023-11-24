// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
 public:
  int rand10() {
    int x = rand7() - 1;
    int y = rand7() - 1;

    while (7 * x + y > 39) {
      x = rand7() - 1;
      y = rand7() - 1;
    }

    return (7 * x + y) % 10 + 1;
  }
};
// Runtime: 72 ms, faster than 76.92%
// Memory Usage: 7.3 MB, less than 77.26%