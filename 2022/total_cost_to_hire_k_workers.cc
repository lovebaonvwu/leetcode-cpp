class Solution {
 public:
  long long totalCost(vector<int>& costs, int k, int candidates) {
    long long ans = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    cout << costs.size() << endl;
    int i = 0, j = costs.size() - 1;
    int cnt = 0;
    while (i <= j && cnt < candidates) {
      pq.push({costs[i], i});
      ++cnt;
      if (cnt == candidates) {
        break;
      }
      ++i;
    }

    cnt = 0;
    while (i < j && cnt < candidates) {
      pq.push({costs[j], j});
      ++cnt;
      if (cnt == candidates) {
        break;
      }
      --j;
    }

    while (k-- > 0) {
      auto [v, idx] = pq.top();
      pq.pop();

      ans += v;

      if (i < j - 1 && idx >= j) {
        --j;
        pq.push({costs[j], j});
      } else if (i < j - 1 && idx <= i) {
        ++i;
        pq.push({costs[i], i});
      }
    }

    return ans;
  }
};
// Runtime 225 ms
// Memory 75.8 MB
// 2022.11.10 at 奥盛大厦