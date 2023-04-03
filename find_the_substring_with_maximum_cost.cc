class Solution {
 public:
  int maximumCostSubstring(string s, string chars, vector<int>& vals) {
    int A[26] = {0};
    iota(begin(A), end(A), 1);

    for (int i = 0; i < chars.size(); ++i) {
      A[chars[i] - 'a'] = vals[i];
    }

    int ans = 0;
    for (int i = 0, sum = 0; i < s.size(); ++i) {
      sum += A[s[i] - 'a'];
      if (sum < 0) {
        sum = 0;
      }

      ans = max(ans, sum);
    }

    return ans;
  }
};
// Runtime 23 ms
// Memory 32 MB