class Solution {
 public:
  int beautySum(string s) {
    int ans = 0;

    for (int i = 0; i < s.size(); ++i) {
      int cnt[26] = {0};

      for (int j = i; j < s.size(); ++j) {
        ++cnt[s[j] - 'a'];

        int most_freq = INT_MIN;
        int least_freq = INT_MAX;

        for (int k = 0; k < 26; ++k) {
          most_freq = max(most_freq, cnt[k]);

          if (cnt[k] > 0) {
            least_freq = min(least_freq, cnt[k]);
          }
        }

        ans += most_freq - least_freq;
      }
    }

    return ans;
  }
};
// Runtime: 124 ms, faster than 100.00%
// Memory Usage: 6.4 MB, less than 83.33%