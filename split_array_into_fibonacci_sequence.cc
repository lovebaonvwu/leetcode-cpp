class Solution {
 public:
  vector<int> splitIntoFibonacci(string num) {
    vector<int> ans;

    return dfs(num, 0, ans) ? ans : vector<int>();
  }

  bool dfs(string& num, int i, vector<int>& ans) {
    if (i == num.size() && ans.size() > 2) {
      return true;
    }

    for (int j = 1; j + i <= num.size(); ++j) {
      string t = num.substr(i, j);
      if (t.size() > 1 && t[0] == '0') {
        return false;
      }

      long long n = std::stoll(t);
      if (n > INT_MAX) {
        return false;
      }

      if (ans.size() < 2 ||
          n == ((long long)ans[ans.size() - 2] + ans.back())) {
        ans.push_back(n);
        if (dfs(num, i + j, ans)) {
          return true;
        }
        ans.pop_back();
      } else if (n > ((long long)ans[ans.size() - 2] + ans.back())) {
        return false;
      }
    }

    return false;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.5 MB, less than 81.41%
// 2022.7.6 at 奥盛大厦