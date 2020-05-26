class Solution {
 public:
  vector<string> simplifiedFractions(int n) {
    vector<string> ans;

    unordered_set<double> st;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j < i; ++j) {
        double d = static_cast<double>(j) / i;
        if (!st.count(d)) {
          ans.push_back(to_string(j) + "/" + to_string(i));
          st.insert(d);
        }
      }
    }

    return ans;
  }
};
// Runtime: 164 ms, faster than 65.16%
// Memory Usage: 29.5 MB, less than 100.00%

class Solution {
 public:
  vector<string> simplifiedFractions(int n) {
    vector<string> ans;

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j < i; ++j) {
        if (gcd(i, j) == 1) {
          ans.push_back(to_string(j) + "/" + to_string(i));
        }
      }
    }

    return ans;
  }
};
// Runtime: 108 ms, faster than 90.03%
// Memory Usage: 21.9 MB, less than 100.00%