class Solution {
 public:
  int mostWordsFound(vector<string>& sentences) {
    int ans = 0;

    for (auto& s : sentences) {
      int cnt = 1;

      for (auto c : s) {
        if (isspace(c)) {
          ++cnt;
        }
      }

      ans = max(ans, cnt);
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 96.11%
// Memory Usage: 9.7 MB, less than 80.08%
// 2021.12.29 at 奥盛大厦