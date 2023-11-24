class Solution {
 public:
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    int m = mat.size();
    int n = mat[0].size();

    vector<int> ans;
    vector<int> visited(101);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (!visited[j] && mat[j][i] == 0) {
          ans.push_back(j);
          visited[j] = 1;
          --i;
          break;
        }
      }

      if (ans.size() == k) {
        break;
      }
    }

    while (ans.size() < k) {
      for (int i = 0; i < m; ++i) {
        if (!visited[i]) {
          ans.push_back(i);
          visited[i] = 1;
          break;
        }
      }
    }

    return ans;
  }
};
// Runtime: 12 ms, faster than 83.32%
// Memory Usage: 10.1 MB, less than 100.00%

class Solution {
 public:
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    set<pair<int, int>> st;

    for (int i = 0; i < mat.size(); ++i) {
      int cnt = accumulate(begin(mat[i]), end(mat[i]), 0);
      st.insert({cnt, i});
    }

    vector<int> ans;

    for (auto it = st.begin(); k > 0; --k, ++it) {
      ans.push_back(it->second);
    }

    return ans;
  }
};
// Runtime: 12 ms, faster than 83.32%
// Memory Usage: 10.2 MB, less than 100.00%