class Solution {
 public:
  int largestVariance(string s) {
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int cnt[26] = {0};
      for (int j = i; j < n; ++j) {
        ++cnt[s[j] - 'a'];
        int maxcnt = 0, mincnt = INT_MAX;
        for (int k = 0; k < 26; ++k) {
          if (cnt[k] > 0) {
            maxcnt = max(maxcnt, cnt[k]);
            mincnt = min(mincnt, cnt[k]);
          }
        }
        ans = max(ans, maxcnt - mincnt);
      }
    }

    return ans;
  }
};
// TLE

class Solution {
 public:
  int largestVariance(string s) {
    int ans = 0;
    for (char a = 'a'; a <= 'z'; ++a) {
      for (char b = 'a'; b <= 'z'; ++b) {
        if (a == b) {
          continue;
        }

        int cnta = 0, cntb = 0;
        bool reset = false;
        for (auto c : s) {
          cnta += c == a;
          cntb += c == b;
          if (cntb > 0) {
            ans = max(ans, cnta - cntb);
          } else if (reset) {
            ans = max(ans, cnta - 1);
          }

          if (cnta < cntb) {
            cnta = 0;
            cntb = 0;
            reset = true;
          }
        }
      }
    }

    return ans;
  }
};
// Runtime 233 ms
// Memory 7 MB