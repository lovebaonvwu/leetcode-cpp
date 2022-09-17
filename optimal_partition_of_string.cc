class Solution {
 public:
  int partitionString(string s) {
    int ans = 1;
    unordered_set<char> seen;

    for (auto c : s) {
      if (seen.find(c) != seen.end()) {
        seen.clear();
        ++ans;
      }

      seen.insert(c);
    }

    return ans;
  }
};
// Runtime: 248 ms, faster than 66.24%
// Memory Usage: 44.5 MB, less than 60.13%
// 2022.9.17 at 茗筑美嘉