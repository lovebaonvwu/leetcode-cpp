class Solution {
 public:
  int minFlipsMonoIncr(string S) {
    int flip_cnt = 0;
    int one_cnt = 0;

    for (auto c : S) {
      if (c == '1') {
        ++one_cnt;
      } else {
        flip_cnt = min(flip_cnt + 1, one_cnt);
      }
    }

    return flip_cnt;
  }
};
// Runtime: 4 ms, faster than 99.16%
// Memory Usage: 7.3 MB, less than 5.04%

class Solution {
 public:
  int minFlipsMonoIncr(string S) {
    int n = S.size();
    vector<int> l2r(n + 1);
    vector<int> r2l(n + 1);

    for (int i = 1; i < l2r.size(); ++i) {
      l2r[i] = l2r[i - 1] + (S[i - 1] == '1');
    }

    for (int i = r2l.size() - 2; i >= 0; --i) {
      r2l[i] = r2l[i + 1] + (S[i + 1] == '0');
    }

    int ans = INT_MAX;

    for (int i = 0; i < l2r.size(); ++i) {
      ans = min(ans, l2r[i] + r2l[i]);
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 71.85%
// Memory Usage: 8.9 MB, less than 5.04%