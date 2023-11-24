class Solution {
 public:
  int minDeletions(string s) {
    vector<int> cnt(26);

    for (const auto c : s) {
      ++cnt[c - 'a'];
    }

    unordered_map<int, int> mp;
    for (auto c : cnt) {
      if (c > 0) {
        ++mp[c];
      }
    }

    sort(cnt.begin(), cnt.end(), greater<int>());

    int ans = 0;
    for (auto c : cnt) {
      if (c > 0 && mp[c] > 1) {
        int i = c - 1;
        for (; i >= 0; --i) {
          if (i == 0 || mp.count(i) == 0) {
            mp[i] = 1;
            --mp[c];
            break;
          }
        }

        ans += c - i;
      }
    }

    return ans;
  }
};
// Runtime: 68 ms, faster than 85.71%
// Memory Usage: 17.8 MB, less than 85.71%

class Solution {
 public:
  int minDeletions(string s) {
    int cnt[26] = {0};

    for (const auto c : s) {
      ++cnt[c - 'a'];
    }

    unordered_map<int, bool> used;

    int ans = 0;

    for (auto c : cnt) {
      for (int i = c; i > 0; --i, ++ans) {
        if (!used[i]) {
          used[i] = true;
          break;
        }
      }
    }

    return ans;
  }
};
// Runtime: 56 ms, faster than 100.00%
// Memory Usage: 17.8 MB, less than 85.71%