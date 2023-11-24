class Solution {
 public:
  int minPartitions(string n) {
    int ans = 0;

    for (auto c : n) {
      ans = max(ans, c - '0');
    }

    return ans;
  }
};
// Runtime: 44 ms, faster than 82.79%
// Memory Usage: 13.9 MB, less than 9.89%