class Solution {
 public:
  string reorganizeString(string S) {
    int cnt[26] = {0};

    for (auto c : S) {
      ++cnt[c - 'a'];
    }

    string ans = "";
    while (ans.size() < S.size()) {
      char prev = ans.size() > 0 ? ans.back() : ' ';
      int idx = -1;

      for (int i = 0, most = 0; i < 26; ++i) {
        if ((i + 'a') != prev && cnt[i] > 0) {
          if (cnt[i] > most) {
            most = cnt[i];
            idx = i;
          }
        }
      }

      if (idx < 0) {
        return "";
      }

      --cnt[idx];
      ans += (idx + 'a');
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.5 MB, less than 76.59%

class Solution {
 public:
  string reorganizeString(string S) {
    int cnt[26] = {0};

    for (auto c : S) {
      ++cnt[c - 'a'];
    }

    string ans = "";
    while (ans.size() < S.size()) {
      char prev = ans.size() > 0 ? ans.back() : ' ';
      int idx = -1;

      for (int i = 0; i < 26; ++i) {
        if ((i + 'a') == prev || cnt[i] == 0) {
          continue;
        }

        if (idx < 0 || cnt[i] > cnt[idx]) {
          idx = i;
        }
      }

      if (idx < 0) {
        return "";
      }

      --cnt[idx];
      ans += (idx + 'a');
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.3 MB, less than 91.40%