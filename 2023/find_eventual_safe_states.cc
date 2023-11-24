class Solution {
  unordered_set<int> visited;
  vector<int> ans;

 public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    for (int i = 0; i < graph.size(); ++i) {
      visited.insert(i);
      if (dfs(graph, i)) {
        ans.push_back(i);
      }
      visited.clear();
    }

    return ans;
  }

  bool dfs(const vector<vector<int>>& g, int i) {
    for (auto next : g[i]) {
      if (visited.find(next) != visited.end()) {
        return false;
      }
      visited.insert(next);

      if (!dfs(g, next)) {
        return false;
      }
      visited.erase(next);
    }

    return true;
  }
};
// TLE

class Solution {
  unordered_set<int> visited;
  unordered_set<int> safe;
  vector<int> ans;

 public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    for (int i = 0; i < graph.size(); ++i) {
      visited.insert(i);
      if (dfs(graph, i)) {
        ans.push_back(i);
      }
      visited.clear();
    }

    return ans;
  }

  bool dfs(const vector<vector<int>>& g, int i) {
    if (safe.find(i) != safe.end()) {
      return true;
    }
    for (auto next : g[i]) {
      if (visited.find(next) != visited.end()) {
        return false;
      }
      visited.insert(next);

      if (!dfs(g, next)) {
        return false;
      }
      visited.erase(next);
    }

    safe.insert(i);
    return true;
  }
};
// Runtime 1027 ms
// Memory 146.6 MB

class Solution {
  unordered_map<int, bool> safe;
  vector<int> ans;

 public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    for (int i = 0; i < graph.size(); ++i) {
      if (dfs(graph, i)) {
        ans.push_back(i);
      }
    }

    return ans;
  }

  bool dfs(const vector<vector<int>>& g, int i) {
    if (safe.find(i) != safe.end()) {
      return safe[i];
    }

    safe[i] = false;
    for (auto next : g[i]) {
      if (!dfs(g, next)) {
        return safe[i];
      }
    }

    return safe[i] = true;
  }
};
// Runtime 183 ms
// Memory 54 MB