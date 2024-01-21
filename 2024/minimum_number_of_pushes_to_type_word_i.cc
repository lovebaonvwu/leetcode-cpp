class Solution {
 public:
  int minimumPushes(string word) {
    int n = word.size();

    if (n <= 8) {
      return n;
    } else if (n <= 16) {
      return 8 + (n - 8) * 2;
    } else if (n <= 24) {
      return 8 + 8 * 2 + (n - 16) * 3;
    } else {
      return 8 + 8 * 2 + 8 * 3 + (n - 24) * 4;
    }
  }
};
// 3ms
// 7.54MB
