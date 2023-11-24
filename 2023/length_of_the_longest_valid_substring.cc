class Solution {
 public:
  int longestValidSubstring(string word, vector<string>& forbidden) {
    int ans = 0;
    int n = word.size();
    unordered_set<string> fb(forbidden.begin(), forbidden.end());

    for (int i = 0, j = 0; j < n; ++j) {
      for (int k = j; k >= 0 && (j - k + 1 <= 10); --k) {
        if (fb.find(word.substr(k, j - k + 1)) != fb.end()) {
          i = max(i, k + 1);
          break;
        }
      }
      ans = max(ans, j - i + 1);
    }

    return ans;
  }
};
// 436ms
// 118.08mb