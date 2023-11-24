class Solution {
 public:
  vector<int> grayCode(int n) {
    if (n == 0) {
      return {0};
    }

    vector<int> ans{0, 1};

    for (int i = 1; ans.size() < pow(2, n); ++i) {
      if (i & 1) {
        ans.push_back(ans[i] * 2 + 1);
        ans.push_back(ans[i] * 2);
      } else {
        ans.push_back(ans[i] * 2);
        ans.push_back(ans[i] * 2 + 1);
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 7 MB, less than 51.10%

class Solution {
 public:
  vector<int> grayCode(int n) {
    if (n == 0) {
      return {0};
    }

    vector<int> ans{0, 1};

    for (int k = 1; k < n; ++k) {
      for (int i = ans.size() - 1; i >= 0; --i) {
        ans.push_back(ans[i] + pow(2, k));
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 7.1 MB, less than 39.85%