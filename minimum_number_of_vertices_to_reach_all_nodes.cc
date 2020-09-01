class Solution {
 public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    unordered_set<int> to;

    for (auto& e : edges) {
      to.insert(e[1]);
    }

    vector<int> ans;

    for (int i = 0; i < n; ++i) {
      if (!to.count(i)) {
        ans.push_back(i);
      }
    }

    return ans;
  }
};
// Runtime: 1264 ms, faster than 21.96%
// Memory Usage: 100.3 MB, less than 57.77%

class Solution {
 public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    vector<int> to(n);

    for (auto& e : edges) {
      to[e[1]] = 1;
    }

    vector<int> ans;

    for (int i = 0; i < n; ++i) {
      if (!to[i]) {
        ans.push_back(i);
      }
    }

    return ans;
  }
};
// Runtime: 668 ms, faster than 77.11%
// Memory Usage: 94.6 MB, less than 65.32%