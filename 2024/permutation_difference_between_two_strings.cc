class Solution {
 public:
  int findPermutationDifference(string s, string t) {
    vector<int> sv(26);
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      sv[s[i] - 'a'] = i;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += abs(i - sv[t[i] - 'a']);
    }

    return ans;
  }
};
// 0 ms
// 8.57 MB