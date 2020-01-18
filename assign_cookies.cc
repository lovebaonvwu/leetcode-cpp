class Solution {
 public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int i = 0;
    int j = 0;

    int ans = 0;
    while (i < g.size() && j < s.size()) {
      if (s[j] >= g[i]) {
        ++i, ++ans;
      }

      ++j;
    }

    return ans;
  }
};
// Runtime: 44 ms, faster than 50.05%
// Memory Usage: 10.3 MB, less than 100.00%