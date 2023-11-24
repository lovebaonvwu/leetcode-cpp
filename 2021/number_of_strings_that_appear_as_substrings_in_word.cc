class Solution {
 public:
  int numOfStrings(vector<string>& patterns, string word) {
    int ans = 0;

    for (auto& p : patterns) {
      if (word.find(p) != string::npos) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 93.01%
// Memory Usage: 8.8 MB, less than 70.55%
// 2021.8.25 at 奥盛大厦