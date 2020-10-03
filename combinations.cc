class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> c;
    c.push_back({});

    for (int i = 1; i <= n; ++i) {
      int size = c.size();
      for (int j = 0; j < size; ++j) {
        auto e = c[j];
        e.push_back(i);

        c.push_back(e);
      }
    }

    vector<vector<int>> ans;
    for (auto& e : c) {
      if (e.size() == k) {
        ans.push_back(e);
      }
    }

    return ans;
  }
};
// Runtime: 1516 ms, faster than 5.06%
// Memory Usage: 370.5 MB, less than 5.01%

class Solution {
  vector<vector<int>> ans;

 public:
  vector<vector<int>> combine(int n, int k) {
    dfs(1, n, k, {});

    return ans;
  }

  void dfs(int start, int n, int k, vector<int> c) {
    if (k == 0) {
      ans.push_back(c);
    }

    for (int i = start; i <= n; ++i) {
      c.push_back(i);

      dfs(i + 1, n, k - 1, c);

      c.pop_back();
    }
  }
};
// Runtime: 968 ms, faster than 5.34%
// Memory Usage: 168.6 MB, less than 5.01%

class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> p(k);

    for (int i = 0; i >= 0;) {
      ++p[i];

      if (p[i] > n) {
        --i;
      } else if (i == k - 1) {
        ans.push_back(p);
      } else {
        ++i;
        p[i] = p[i - 1];
      }
    }

    return ans;
  }
};
// Runtime: 52 ms, faster than 46.98%
// Memory Usage: 8.9 MB, less than 94.69%