class Solution {
  bool isSub(const string& s, const string& w, int n) {
    string t;

    while (n-- > 0) {
      t += w;
    }

    return s.find(t) != string::npos;
  }

 public:
  int maxRepeating(string sequence, string word) {
    int ans = sequence.size() / word.size();

    while (ans > 0) {
      if (isSub(sequence, word, ans)) {
        break;
      }

      --ans;
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 23.27%
// Memory Usage: 6.4 MB, less than 12.19%
// 2021.11.17 at 奥盛大厦

class Solution {
 public:
  int maxRepeating(string sequence, string word) {
    int n = sequence.size();

    int ans = 0;

    for (int i = 0; i < n; ++i) {
      if (sequence[i] != word[0]) {
        continue;
      }

      int j = 0, cnt = 0, m = word.size();

      while (i + j < n && sequence[i + j] == word[j % m]) {
        ++j;

        if (j % m == 0) {
          ++cnt;
        }
      }

      ans = max(ans, cnt);
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.2 MB, less than 58.45%
// 2021.11.17 at 奥盛大厦