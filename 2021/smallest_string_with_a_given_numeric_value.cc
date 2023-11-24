class Solution {
 public:
  string getSmallestString(int n, int k) {
    string ans = "";

    for (int i = 0; i < n; ++i) {
      int val = k - (n - i - 1) * 26;

      if (val <= 0) {
        k -= 1;
        ans += "a";
      } else {
        k -= val;
        ans += (val - 1) + 'a';
      }
    }

    return ans;
  }
};
// Runtime: 80 ms, faster than 33.33%
// Memory Usage: 27.5 MB, less than 8.33%

class Solution {
 public:
  string getSmallestString(int n, int k) {
    string ans(n, 'a');
    k -= n;

    while (k > 0) {
      ans[--n] += min(k, 25);
      k -= min(k, 25);
    }

    return ans;
  }
};
// Runtime: 64 ms, faster than 50.00%
// Memory Usage: 21.5 MB, less than 41.67%