class Solution {
 public:
  int longestBeautifulSubstring(string word) {
    int ans = 0;

    for (int i = 0, j = 0, cnt = 0; j < word.size(); ++j) {
      if (cnt == 0 && word[j] != 'a') {
        continue;
      }

      if (cnt == 0) {
        cnt = 1;
        i = j;
      }

      if (cnt > 0) {
        if (j > 0 && word[j] > word[j - 1]) {
          ++cnt;
        } else if (j > 0 && word[j] < word[j - 1]) {
          if (word[j] == 'a') {
            cnt = 1;
            i = j;
          } else {
            cnt = 0;
          }
        }
      }

      if (cnt == 5) {
        ans = max(ans, j - i + 1);
      }
    }

    return ans;
  }
};
// Runtime: 100 ms, faster than 50.00%
// Memory Usage: 26.7 MB, less than 83.33%

class Solution {
 public:
  int longestBeautifulSubstring(string word) {
    int ans = 0;

    for (int i = 0, j = 0, cnt = 0; j < word.size(); ++j) {
      if (j == 0 && word[j] == 'a' || j > 0 && word[j] > word[j - 1]) {
        ++cnt;
      } else if (j > 0 && word[j] < word[j - 1]) {
        while (j < word.size() && word[j] != 'a') {
          ++j;
        }

        i = j;
        cnt = 1;
      }

      if (cnt == 5) {
        ans = max(ans, j - i + 1);
      }
    }

    return ans;
  }
};
// Runtime: 88 ms, faster than 100.00%
// Memory Usage: 26.8 MB, less than 50.00%