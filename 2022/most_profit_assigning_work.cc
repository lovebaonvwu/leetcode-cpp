class Solution {
 public:
  int maxProfitAssignment(vector<int>& difficulty,
                          vector<int>& profit,
                          vector<int>& worker) {
    vector<vector<int>> pd;

    int n = difficulty.size();
    for (int i = 0; i < n; ++i) {
      pd.push_back({profit[i], difficulty[i]});
    }

    sort(pd.begin(), pd.end(), [](auto& a, auto& b) {
      if (a[0] == b[0]) {
        return a[1] < b[1];
      } else {
        return a[0] > b[0];
      }
    });

    int ans = 0;
    for (auto w : worker) {
      for (int i = 0; i < n; ++i) {
        if (w >= pd[i][1]) {
          ans += pd[i][0];
          break;
        }
      }
    }

    return ans;
  }
};
// Runtime: 2090 ms, faster than 5.02%
// Memory Usage: 45.8 MB, less than 12.36%
// 2022.6.29 at 奥盛大厦

class Solution {
 public:
  int maxProfitAssignment(vector<int>& difficulty,
                          vector<int>& profit,
                          vector<int>& worker) {
    vector<vector<int>> pd;

    int n = difficulty.size();
    for (int i = 0; i < n; ++i) {
      pd.push_back({difficulty[i], profit[i]});
    }

    sort(pd.begin(), pd.end());
    sort(worker.begin(), worker.end());

    int ans = 0;
    int i = 0;
    int pt = 0;
    for (auto w : worker) {
      for (; i < n && w >= pd[i][0]; ++i) {
        pt = max(pt, pd[i][1]);
      }

      ans += pt;
    }

    return ans;
  }
};
// Runtime: 152 ms, faster than 27.43%
// Memory Usage: 45.9 MB, less than 12.36%
// 2022.6.29 at 奥盛大厦