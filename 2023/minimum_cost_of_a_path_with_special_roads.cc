class Solution {
 public:
  int minimumCost(vector<int>& start,
                  vector<int>& target,
                  vector<vector<int>>& specialRoads) {
    vector<vector<int>> roads;
    for (auto& r : specialRoads) {
      int a = r[0], b = r[1], c = r[2], d = r[3], cost = r[4];
      if (abs(a - c) + abs(b - d) > cost) {
        roads.push_back(r);
      }
    }

    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>>
        pq;
    pq.push({0, start[0], start[1]});

    unordered_map<long long, int> dist;
    dist[getKey(start[0], start[1])] = 0;

    while (!pq.empty()) {
      auto [cur_dist, x, y] = pq.top();
      pq.pop();

      for (auto& r : roads) {
        int a = r[0], b = r[1], c = r[2], d = r[3], cost = r[4];
        long long key = getKey(c, d);
        int new_dist = cur_dist + abs(x - a) + abs(y - b) + cost;
        if (dist.find(key) == dist.end() || new_dist < dist[key]) {
          dist[key] = new_dist;
          pq.push({new_dist, c, d});
        }
      }
    }

    int ans = abs(target[0] - start[0]) + abs(target[1] - start[1]);
    for (auto& r : roads) {
      int a = r[0], b = r[1], c = r[2], d = r[3], cost = r[4];
      ans = min(ans,
                dist[getKey(c, d)] + abs(target[0] - c) + abs(target[1] - d));
    }

    return ans;
  }

 private:
  long long getKey(int x, int y) {
    long long offset = 1000000LL;

    return x * offset + y;
  }
};
// Runtime 162 ms
// Memory 72.8 MB