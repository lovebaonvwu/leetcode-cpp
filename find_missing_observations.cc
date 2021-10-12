class Solution {
 public:
  vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    int m = rolls.size();

    int sum = accumulate(rolls.begin(), rolls.end(), 0);

    int total = (m + n) * mean;

    int diff = total - sum;

    vector<int> ans;

    if (diff < 1 * n || diff > 6 * n) {
      return ans;
    }

    dfs(ans, diff, n);

    return ans;
  }

  bool dfs(vector<int>& ans, int diff, int n) {
    if (diff < 0 || n < 0) {
      return false;
    }

    if (n == 0 && diff == 0) {
      return true;
    }

    for (int i = 6; i >= 1; --i) {
      if (diff < i) {
        continue;
      }

      ans.push_back(i);

      if (dfs(ans, diff - i, n - 1)) {
        return true;
      }

      ans.pop_back();
    }

    return false;
  }
};
// Time Limit Exceeded
// 2021.10.12 at 奥盛大厦

class Solution {
 public:
  vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    int m = rolls.size();

    int sum = accumulate(rolls.begin(), rolls.end(), 0);

    int total = (m + n) * mean;

    int diff = total - sum;

    if (diff < 1 * n || diff > 6 * n) {
      return {};
    }

    int base = diff / n;
    int rem = diff % n;

    vector<int> ans(n, base);

    for (int i = 0; i < rem; ++i) {
      ++ans[i];
    }

    return ans;
  }
};
// Runtime: 180 ms, faster than 54.45%
// Memory Usage: 113.7 MB, less than 65.26%
// 2021.10.12 at 奥盛大厦