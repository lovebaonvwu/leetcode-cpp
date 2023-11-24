class Solution {
 public:
  string smallestSubsequence(string text) {
    int cnt[26] = {};
    int used[26] = {};

    for (auto ch : text) {
      ++cnt[ch - 'a'];
    }

    string ans;
    for (auto ch : text) {
      --cnt[ch - 'a'];

      if (used[ch - 'a']++ > 0) {
        continue;
      }

      while (!ans.empty() && ch < ans.back() && cnt[ans.back() - 'a'] > 0) {
        used[ans.back() - 'a'] = 0;
        ans.pop_back();
      }

      ans.push_back(ch);
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.5 MB, less than 100.00%