class Solution {
 public:
  int minSteps(string s, string t) {
    int vs[26]{0};
    int vt[26]{0};

    for (int i = 0; i < s.size(); ++i) {
      ++vs[s[i] - 'a'];
      ++vt[t[i] - 'a'];
    }

    int s2t = 0;
    int t2s = 0;
    for (int i = 0; i < 26; ++i) {
      if (vs[i] > vt[i]) {
        s2t += vs[i] - vt[i];
      } else if (vs[i] < vt[i]) {
        t2s += vt[i] - vs[i];
      }
    }

    return max(s2t, t2s);
  }
};
// Runtime: 84 ms, faster than 94.93%
// Memory Usage: 18.9 MB, less than 100.00%

class Solution {
 public:
  int minSteps(string s, string t) {
    int cnt[26]{0};

    for (int i = 0; i < s.size(); ++i) {
      --cnt[s[i] - 'a'];
      ++cnt[t[i] - 'a'];
    }

    int ans = 0;
    for (int i = 0; i < 26; ++i) {
      if (cnt[i] > 0) {
        ans += cnt[i];
      }
    }

    return ans;
  }
};
// Runtime: 96 ms, faster than 48.43%
// Memory Usage: 18.7 MB, less than 100.00%

class Solution {
 public:
  int minSteps(string s, string t) {
    int vs[26]{0};
    int vt[26]{0};

    for (int i = 0; i < s.size(); ++i) {
      ++vs[s[i] - 'a'];
      ++vt[t[i] - 'a'];
    }

    int ans = 0;
    for (int i = 0; i < 26; ++i) {
      if (vt[i] > vs[i]) {
        ans += vt[i] - vs[i];
      }
    }

    return ans;
  }
};
// Runtime: 104 ms, faster than 41.57%
// Memory Usage: 18.8 MB, less than 100.00%