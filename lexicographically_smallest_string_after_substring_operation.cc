class Solution {
 public:
  string smallestString(string s) {
    int i = 0;
    int n = s.size();
    string ans;
    while (i < n && s[i] == 'a') {
      ans += s[i];
      ++i;
    }

    if (i == n) {
      s[s.size() - 1] = 'z';
      return s;
    }

    int j = i;
    while (j < n && s[j] != 'a') {
      ans += (s[j] - 1);
      ++j;
    }

    while (j < n) {
      ans += s[j++];
    }

    return ans;
  }
};
// Runtime 127 ms
// Memory 53.3 MB