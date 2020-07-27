class Solution {
 public:
  int numSplits(string s) {
    int left[26] = {};
    int right[26] = {};
    int cnt_left = 0;
    int cnt_right = 0;

    for (auto c : s) {
      ++right[c - 'a'];

      if (right[c - 'a'] == 1) {
        ++cnt_right;
      }
    }

    int ans = 0;

    for (int i = 0; i < s.size(); ++i) {
      ++left[s[i] - 'a'];

      if (left[s[i] - 'a'] == 1) {
        ++cnt_left;
      }

      --right[s[i] - 'a'];

      if (right[s[i] - 'a'] == 0) {
        --cnt_right;
      }

      if (cnt_left == cnt_right) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 36 ms, faster than 94.96%
// Memory Usage: 8.4 MB, less than 100.00%

class Solution {
 public:
  int numSplits(string s) {
    int left[26] = {};
    int right[26] = {};
    int cnt_left = 0;
    int cnt_right = 0;

    for (auto c : s) {
      cnt_right += ++right[c - 'a'] == 1;
    }

    int ans = 0;

    for (int i = 0; i < s.size(); ++i) {
      cnt_left += ++left[s[i] - 'a'] == 1;

      cnt_right -= --right[s[i] - 'a'] == 0;

      ans += cnt_left == cnt_right;
    }

    return ans;
  }
};
// Runtime: 32 ms, faster than 98.61%
// Memory Usage: 8.3 MB, less than 100.00%