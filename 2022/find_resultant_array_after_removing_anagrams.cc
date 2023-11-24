class Solution {
 public:
  vector<string> removeAnagrams(vector<string>& words) {
    words.push_back("");
    vector<string> ans;
    for (int i = 0, j = i + 1; i < words.size() - 1 && j < words.size();) {
      string s = words[i];
      string t = words[j];

      sort(s.begin(), s.end());
      sort(t.begin(), t.end());

      if (s == t) {
        ++j;
      } else {
        ans.push_back(words[i]);
        i = j;
        ++j;
      }
    }

    return ans;
  }
};
// Runtime: 12 ms, faster than 75.11%
// Memory Usage: 12.2 MB, less than 97.65%
// 2022.6.4 at 茗筑美嘉