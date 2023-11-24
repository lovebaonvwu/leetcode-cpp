class Solution {
 public:
  string mergeAlternately(string word1, string word2) {
    string ans;

    int i = 0, j = 0;
    while (i < word1.size() || j < word2.size()) {
      if (i < word1.size()) {
        ans += word1[i++];
      }

      if (j < word2.size()) {
        ans += word2[j++];
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.2 MB, less than 100.00%