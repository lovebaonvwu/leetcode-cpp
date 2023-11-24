class Solution {
 public:
  bool hasAllCodes(string s, int k) {
    if (s.size() < k) {
      return false;
    }

    unordered_set<string> st;

    for (int i = 0; i <= s.size() - k; ++i) {
      st.insert(s.substr(i, k));
    }

    return st.size() >= pow(2, k);
  }
};
// Runtime: 640 ms, faster than 63.65%
// Memory Usage: 58.8 MB, less than 100.00%

class Solution {
 public:
  bool hasAllCodes(string s, int k) {
    int mask = (1 << k) - 1;
    int sum = 0;
    int ans = 0;

    vector<bool> cnt(1 << k);

    for (int i = 0; i < s.size(); ++i) {
      sum = mask & ((sum << 1) + s[i] - '0');

      if (i >= k - 1) {
        if (!cnt[sum]) {
          cnt[sum] = true;
          ++ans;
        }
      }
    }

    return cnt.size() == ans;
  }
};
// Runtime: 164 ms, faster than 97.87%
// Memory Usage: 18.4 MB, less than 100.00%