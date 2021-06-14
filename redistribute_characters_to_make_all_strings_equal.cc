class Solution {
 public:
  bool makeEqual(vector<string>& words) {
    int cnt[26] = {0};

    for (auto& w : words) {
      for (auto c : w) {
        ++cnt[c - 'a'];
      }
    }

    for (int i = 0; i < 26; ++i) {
      if (cnt[i] > 0 && cnt[i] % words.size() != 0) {
        return false;
      }
    }

    return true;
  }
};
// Runtime: 12 ms, faster than 100.00%
// Memory Usage: 11.6 MB, less than 66.67%