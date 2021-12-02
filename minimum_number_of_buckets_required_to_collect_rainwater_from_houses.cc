class Solution {
 public:
  int minimumBuckets(string street) {
    string& s = street;
    int n = s.size();

    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == 'H') {
        if (i > 0 && s[i - 1] == 'B') {
          continue;
        }

        if (i < n - 1 && s[i + 1] == '.') {
          s[i + 1] = 'B';
        } else if (i > 0 && s[i - 1] == '.') {
          s[i - 1] = 'B';
        } else {
          return -1;
        }
      }
    }

    return count(s.begin(), s.end(), 'B');
  }
};
// Runtime: 20 ms, faster than 88.59%
// Memory Usage: 10.3 MB, less than 92.96%
// 2021.12.2 at 奥盛大厦