class Solution {
 public:
  vector<int> memLeak(int memory1, int memory2) {
    int i = 1;

    while (true) {
      if (memory1 >= memory2) {
        if (memory1 < i) {
          break;
        }

        memory1 -= i;
      } else {
        if (memory2 < i) {
          break;
        }

        memory2 -= i;
      }

      ++i;
    }

    return {i, memory1, memory2};
  }
};
// Runtime: 4 ms, faster than 92.98%
// Memory Usage: 6.2 MB, less than 32.37%

class Solution {
 public:
  vector<int> memLeak(int memory1, int memory2) {
    int i = 1;

    while (memory1 >= i || memory2 >= i) {
      if (memory1 >= memory2) {
        memory1 -= i;
      } else {
        memory2 -= i;
      }

      ++i;
    }

    return {i, memory1, memory2};
  }
};
// Runtime: 4 ms, faster than 92.98%
// Memory Usage: 6.2 MB, less than 32.37%