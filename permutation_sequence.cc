class Solution {
  vector<string> ans;

 public:
  string getPermutation(int n, int k) {
    vector<bool> used(n);

    dfs(n, used, "");

    return ans[k - 1];
  }

  void dfs(int n, vector<bool>& used, string s) {
    if (n == 0) {
      ans.push_back(s);
      return;
    }

    for (int i = 0; i < used.size(); ++i) {
      if (!used[i]) {
        used[i] = true;

        string t = s + to_string(i + 1);
        dfs(n - 1, used, t);

        used[i] = false;
      }
    }
  }
};
// Time Limit Exceeded

class Solution {
 public:
  string getPermutation(int n, int k) {
    string pool;

    for (int i = 0; i < n; ++i) {
      pool += to_string(i + 1);
    }

    vector<int> factorial(n + 1, 1);

    for (int i = 1; i <= n; ++i) {
      factorial[i] = i * factorial[i - 1];
    }

    k -= 1;

    string ans;
    while (n > 0) {
      int i = k / factorial[n - 1];

      k -= i * factorial[n - 1];
      --n;

      ans += pool[i];
      pool.erase(i, 1);
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.2 MB, less than 20.08%