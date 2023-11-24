class Solution {
 public:
  vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
    sort(items.begin(), items.end(), [](auto& a, auto& b) {
      if (a[0] == b[0]) {
        return a[1] > b[1];
      } else {
        return a[0] < b[0];
      }
    });

    for (int i = 1; i < items.size(); ++i) {
      items[i][1] = max(items[i][1], items[i - 1][1]);
    }

    vector<int> ans;

    for (auto q : queries) {
      int lo = 0, hi = items.size();

      while (lo < hi) {
        int md = lo + (hi - lo) / 2;

        if (items[md][0] > q) {
          hi = md;
        } else {
          lo = md + 1;
        }
      }

      if (hi == 0) {
        ans.push_back(0);
      } else {
        ans.push_back(items[hi - 1][1]);
      }
    }

    return ans;
  }
};
// Runtime: 368 ms, faster than 73.04%
// Memory Usage: 88.5 MB, less than 90.67%
// 2021.11.18 at 奥盛大厦