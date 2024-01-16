class Solution {
  vector<int> buildLPSArray(const string& s) {
    int n = s.size();
    vector<int> lps(n);

    for (int i = 1, j = 0; i < n;) {
      if (s[i] == s[j]) {
        lps[i] = j + 1;
        ++i;
        ++j;
      } else {
        if (j > 0) {
          j = lps[j - 1];
        } else {
          lps[i] = 0;
          ++i;
        }
      }
    }

    return lps;
  }

  vector<int> KMP(const string& s, const string& pattern) {
    vector<int> lps = buildLPSArray(pattern);
    int n = s.size();
    int m = pattern.size();

    vector<int> index;

    for (int i = 0, j = 0; i < n;) {
      if (s[i] == pattern[j]) {
        ++i;
        ++j;
      } else {
        if (j > 0) {
          j = lps[j - 1];
        } else {
          ++i;
        }
      }

      if (j == m) {
        index.push_back(i - m);
        j = lps[j - 1];
      }
    }

    return index;
  }

 public:
  vector<int> beautifulIndices(string s, string a, string b, int k) {
    vector<int> indexA = KMP(s, a);
    vector<int> indexB = KMP(s, b);

    vector<int> ans;

    for (auto i : indexA) {
      auto it = lower_bound(begin(indexB), end(indexB), i - k);
      if (it != end(indexB) && abs(*it - i) <= k) {
        ans.push_back(i);
      }
    }

    return ans;
  }
};
// 221ms
// 87.20MB