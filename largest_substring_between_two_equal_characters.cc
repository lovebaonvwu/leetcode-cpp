class Solution {
 public:
  int maxLengthBetweenEqualCharacters(string s) {
    int char_pos[26];

    memset(char_pos, -1, sizeof(char_pos));

    for (int i = 0; i < s.size(); ++i) {
      char_pos[s[i] - 'a'] = i;
    }

    int ans = -1;

    for (int i = 0; i < s.size(); ++i) {
      if (char_pos[s[i] - 'a'] > -1) {
        ans = max(ans, char_pos[s[i] - 'a'] - i - 1);
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.5 MB, less than 80.85%

class Solution {
 public:
  int maxLengthBetweenEqualCharacters(string s) {
    int idx[26] = {0};

    int ans = -1;

    for (int i = 0; i < s.size(); ++i) {
      if (idx[s[i] - 'a'] == 0) {
        idx[s[i] - 'a'] = i + 1;
      }

      ans = max(ans, i - idx[s[i] - 'a']);
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.6 MB, less than 80.85%