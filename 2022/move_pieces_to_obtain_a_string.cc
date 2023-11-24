class Solution {
 public:
  bool canChange(string start, string target) {
    int n = target.size();
    int i = 0, j = 0;

    for (; i < n || j < n; ++i, ++j) {
      while (i < n && start[i] == '_') {
        ++i;
      }
      while (j < n && target[j] == '_') {
        ++j;
      }

      if (i == n || j == n) {
        break;
      }

      if (start[i] != target[j]) {
        break;
      }

      if (start[i] == 'L' && i < j) {
        break;
      }

      if (start[i] == 'R' && i > j) {
        break;
      }
    }

    return i == n && j == n;
  }
};
// Runtime: 91 ms, faster than 77.95%
// Memory Usage: 19.2 MB, less than 67.56%
// 2022.7.16 at 奥盛大厦