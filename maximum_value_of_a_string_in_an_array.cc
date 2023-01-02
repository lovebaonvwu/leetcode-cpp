class Solution {
 public:
  int maximumValue(vector<string>& strs) {
    int ans = 0;
    for (auto& s : strs) {
      int sum = 0, i = 0;
      ;
      for (; i < s.size(); ++i) {
        if (!isdigit(s[i])) {
          ans = max(ans, static_cast<int>(s.size()));
          break;
        } else {
          sum = sum * 10 + (s[i] - '0');
        }
      }

      if (i == s.size()) {
        ans = max(ans, sum);
      }
    }

    return ans;
  }
};
// Runtime 3 ms
// Memory 7.8 MB
// 2023.1.2 at 茗筑美嘉