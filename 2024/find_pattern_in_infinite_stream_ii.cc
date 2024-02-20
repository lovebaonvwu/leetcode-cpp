/**
 * Definition for an infinite stream.
 * class InfiniteStream {
 * public:
 *     InfiniteStream(vector<int> bits);
 *     int next();
 * };
 */
class Solution {
  vector<int> buildLPS(const vector<int>& s) {
    int n = s.size();
    vector<int> lps(n);

    for (int len = 0, i = 1; i < n;) {
      if (s[i] == s[len]) {
        lps[i] = ++len;
        ++i;
      } else {
        if (len > 0) {
          len = lps[len - 1];
        } else {
          lps[i] = 0;
          ++i;
        }
      }
    }

    return lps;
  }

 public:
  int findPattern(InfiniteStream* stream, vector<int>& pattern) {
    vector<int> lps = buildLPS(pattern);

    int i = 0;
    int j = 0;
    bool readnext = true;
    int c = 0;

    while (i < 100000) {
      if (readnext)
        c = stream->next();

      if (c == pattern[j]) {
        ++i;
        ++j;
        readnext = true;
      } else {
        if (j > 0) {
          j = lps[j - 1];
          readnext = false;
        } else {
          ++i;
          readnext = true;
        }
      }

      if (j == lps.size()) {
        break;
      }
    }

    return i - j;
  }
};
// 313 ms
// 289.58 MB