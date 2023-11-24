class Solution {
 public:
  string removeDuplicateLetters(string s) {
    int cnt[26] = {};
    int seen[26] = {};

    for (auto ch : s) {
      ++cnt[ch - 'a'];
    }

    string ans;

    for (auto ch : s) {
      --cnt[ch - 'a'];

      if (seen[ch - 'a']++ > 0) {
        continue;
      }

      while (!ans.empty() && ch < ans.back() && cnt[ans.back() - 'a'] > 0) {
        seen[ans.back() - 'a'] = 0;
        ans.pop_back();
      }

      ans.push_back(ch);
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 31.08%
// Memory Usage: 8.7 MB, less than 77.78%