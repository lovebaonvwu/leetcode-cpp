class Graph {
  unordered_map<int, vector<pair<int, int>>> g;
  int n;

 public:
  Graph(int n, vector<vector<int>>& edges) : n(n) {
    for (auto& e : edges) {
      g[e[0]].push_back({e[1], e[2]});
    }
  }

  void addEdge(vector<int> edge) { g[edge[0]].push_back({edge[1], edge[2]}); }

  int shortestPath(int node1, int node2) {
    vector<int> dist(n, INT_MAX);
    dist[node1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push({0, node1});

    while (!pq.empty()) {
      auto [cur_dist, cur] = pq.top();
      pq.pop();

      if (cur == node2) {
        return cur_dist;
      }

      for (auto& [neighber, neighber_dist] : g[cur]) {
        int new_dist = cur_dist + neighber_dist;
        if (new_dist < dist[neighber]) {
          dist[neighber] = new_dist;
          pq.push({new_dist, neighber});
        }
      }
    }

    return -1;
  }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
// 150ms
// 76.12MB