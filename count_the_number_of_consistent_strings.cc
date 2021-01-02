class Solution {
 public:
  int countConsistentStrings(string allowed, vector<string>& words) {
    int cnt[26] = {0};

    for (auto c : allowed) {
      cnt[c - 'a'] = 1;
    }

    int ans = 0;
    for (auto& w : words) {
      bool cons = true;
      for (auto c : w) {
        if (!cnt[c - 'a']) {
          cons = false;
        }
      }

      if (cons) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 88 ms, faster than 79.78%
// Memory Usage: 30.3 MB, less than 99.84%