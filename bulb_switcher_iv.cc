class Solution {
 public:
  int minFlips(string target) {
    int ans = 0;

    for (int i = 0, state = 0; i < target.size(); ++i) {
      if (target[i] - '0' != state) {
        state = !state;
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 44 ms, faster than 89.76%
// Memory Usage: 9.5 MB, less than 60.76%