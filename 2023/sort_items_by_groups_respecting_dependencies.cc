class Solution {
 public:
  vector<int> sortItems(int n,
                        int m,
                        vector<int>& group,
                        vector<vector<int>>& beforeItems) {
    int group_id = m;
    for (int i = 0; i < group.size(); ++i) {
      if (group[i] == -1) {
        group[i] = group_id++;
      }
    }

    vector<vector<int>> item_graph(n);
    vector<int> item_indegree(n);
    vector<vector<int>> group_graph(group_id);
    vector<int> group_indegree(group_id);

    for (int cur = 0; cur < n; ++cur) {
      for (auto prev : beforeItems[cur]) {
        item_graph[prev].push_back(cur);
        ++item_indegree[cur];

        if (group[prev] != group[cur]) {
          group_graph[group[prev]].push_back(group[cur]);
          ++group_indegree[group[cur]];
        }
      }
    }

    auto topologicalSort = [&](vector<vector<int>>& g,
                               vector<int>& in) -> vector<int> {
      queue<int> q;
      for (int i = 0; i < in.size(); ++i) {
        if (in[i] == 0) {
          q.push(i);
        }
      }

      vector<int> sorted;
      while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        sorted.push_back(cur);
        for (auto next : g[cur]) {
          --in[next];
          if (in[next] == 0) {
            q.push(next);
          }
        }
      }

      return sorted.size() == g.size() ? sorted : vector<int>();
    };

    auto itemSorted = topologicalSort(item_graph, item_indegree);
    auto groupSorted = topologicalSort(group_graph, group_indegree);

    if (itemSorted.empty() || groupSorted.empty()) {
      return vector<int>();
    }

    vector<vector<int>> groups(group_id);
    for (auto item : itemSorted) {
      groups[group[item]].push_back(item);
    }

    vector<int> ans;
    for (auto group : groupSorted) {
      ans.insert(ans.end(), groups[group].begin(), groups[group].end());
    }

    return ans;
  }
};
// 79ms
// 45.33MB