class Solution {
  unordered_map<int, vector<int>> g;
  unordered_map<int, int> cnt;
  int n;
  int ans;

 public:
  int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
    n = vals.size();
    for (int i = 0; i < n; ++i) {
      ++cnt[vals[i]];
    }

    for (auto& e : edges) {
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }

    set<pair<int, int>> results;
    for (int i = 0; i < n; ++i) {
      if (cnt[vals[i]] < 2) {
        results.insert(make_pair(i, i));
        continue;
      }

      queue<int> q;
      q.push(i);
      int target = vals[i];
      unordered_set<int> visited;
      visited.insert(i);

      while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (vals[node] == target) {
          pair<int, int> result =
              node > i ? make_pair(i, node) : make_pair(node, i);
          results.insert(result);
        }

        if (vals[node] > target) {
          continue;
        }

        for (auto child : g[node]) {
          if (visited.find(child) == visited.end()) {
            visited.insert(child);
            q.push(child);
          }
        }
      }
    }

    return results.size();
  }
};
// Time Limit Exceeded

class UnionFind {
 private:
  vector<int> parent;
  vector<int> rank;

 public:
  UnionFind(int n) {
    for (int i = 0; i < n; ++i) {
      parent.push_back(i);
    }

    rank.resize(n, 0);
  }

  int Find(int x) {
    if (parent[x] != x) {
      parent[x] = Find(parent[x]);
    }

    return parent[x];
  }

  void Union(int x, int y) {
    int px = Find(x);
    int py = Find(y);

    if (px == py) {
      return;
    }

    if (rank[px] > rank[py]) {
      parent[py] = px;
    } else if (rank[px] < rank[py]) {
      parent[px] = py;
    } else {
      ++rank[px];
      parent[py] = px;
    }
  }
};

class Solution {
 public:
  int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
    int n = vals.size();
    unordered_map<int, vector<int>> g;
    for (auto& e : edges) {
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }

    map<int, vector<int>> nodes;
    for (int i = 0; i < n; ++i) {
      nodes[vals[i]].push_back(i);
    }

    int ans = 0;
    UnionFind uset(n);
    for (auto& [_, node] : nodes) {
      for (auto n : node) {
        for (auto neighbor : g[n]) {
          if (vals[neighbor] <= vals[n]) {
            uset.Union(neighbor, n);
          }
        }
      }

      unordered_map<int, int> group;
      for (auto n : node) {
        ++group[uset.Find(n)];
      }

      for (auto& [_, cnt] : group) {
        ans += (1 + cnt) * cnt / 2;
      }
    }

    return ans;
  }
};
// Runtime 853 ms
// Memory 250.1 MB
// 2023.1.15 at 茗筑美嘉