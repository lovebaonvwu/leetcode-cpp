class Solution {
 public:
  string licenseKeyFormatting(string S, int K) {
    string s;

    for (auto c : S) {
      if (c == '-') {
        continue;
      }

      s += toupper(c);
    }

    string ans = "";

    for (int i = s.size() - 1, k = K; i >= 0; --i, --k) {
      if (k == 0) {
        ans = "-" + ans;
        k = K;
      }

      ans = s[i] + ans;
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  string licenseKeyFormatting(string S, int K) {
    int cnt = 0;

    for (auto c : S) {
      if (isalnum(c)) {
        cnt++;
      }
    }

    if (cnt == 0) {
      return "";
    }

    int d = cnt / K;
    int r = cnt % K;

    int sz = cnt + d + (r ? 0 : -1);

    char* chs = (char*)malloc(sz);

    for (int i = S.size() - 1, j = sz - 1, k = K; i >= 0; --i) {
      if (isalnum(S[i])) {
        if (k == 0) {
          chs[j--] = '-';
          k = K;
        }
        chs[j--] = toupper(S[i]);
        --k;
      }
    }

    string ans(chs, sz);

    free(chs);

    return ans;
  }
};
// Runtime: 8 ms, faster than 94.00%
// Memory Usage: 8.3 MB, less than 89.42%