class Solution {
 public:
  int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
    vector<vector<pair<int, int>>> g(n);
    for (auto& highway : highways) {
      g[highway[0]].push_back({highway[1], highway[2]});
      g[highway[1]].push_back({highway[0], highway[2]});
    }

    vector<vector<bool>> visited(n, vector<bool>(discounts + 1));
    vector<vector<int>> dists(n, vector<int>(discounts + 1, INT_MAX));

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<>>
        pq;
    pq.push(make_tuple(0, 0, 0));

    while (!pq.empty()) {
      int curCost, curCity, discountUsed;
      tie(curCost, curCity, discountUsed) = pq.top();
      pq.pop();

      if (visited[curCity][discountUsed]) {
        continue;
      }

      visited[curCity][discountUsed] = true;

      for (auto& [nextCity, toll] : g[curCity]) {
        if (curCost + toll < dists[nextCity][discountUsed]) {
          dists[nextCity][discountUsed] = curCost + toll;
          pq.push({curCost + toll, nextCity, discountUsed});
        }

        if (discountUsed < discounts) {
          if (curCost + toll / 2 < dists[nextCity][discountUsed + 1]) {
            dists[nextCity][discountUsed + 1] = curCost + toll / 2;
            pq.push({curCost + toll / 2, nextCity, discountUsed + 1});
          }
        }
      }
    }

    int ans = *min_element(dists[n - 1].begin(), dists[n - 1].end());

    return ans == INT_MAX ? -1 : ans;
  }
};
// 368 ms
// 27.83 MB