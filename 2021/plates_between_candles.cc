class Solution {
 public:
  vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
    int n = queries.size();

    vector<int> ans(n);

    for (int k = 0; k < queries.size(); ++k) {
      int i = queries[k][0];
      int j = queries[k][1];

      while (i <= j && s[i] != '|') {
        ++i;
      }

      while (i <= j && s[j] != '|') {
        --j;
      }

      int cnt = 0;

      while (i <= j) {
        if (s[i++] == '|') {
          ans[k] += cnt;
          cnt = 0;
        } else {
          ++cnt;
        }
      }

      ans[k] += cnt;
    }

    return ans;
  }
};
// Time Limit Exceeded
// 2021.11.2 at 奥盛大厦

class Solution {
 public:
  vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
    int n = queries.size();

    vector<int> ans(n);
    vector<int> candles;

    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '|') {
        candles.push_back(i);
      }
    }

    for (int k = 0; k < queries.size(); ++k) {
      int i = queries[k][0];
      int j = queries[k][1];

      auto l = lower_bound(candles.begin(), candles.end(), i) - candles.begin();
      auto r =
          upper_bound(candles.begin(), candles.end(), j) - candles.begin() - 1;

      if (l < r) {
        ans[k] = (candles[r] - candles[l] - 1) - (r - l - 1);
      }
    }

    return ans;
  }
};
// Runtime: 428 ms, faster than 81.47%
// Memory Usage: 137.6 MB, less than 95.82%
// 2021.11.2 at 奥盛大厦