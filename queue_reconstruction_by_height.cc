class Solution {
 public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), [](const auto& a, const auto& b) {
      if (a[0] == b[0]) {
        return a[1] < b[1];
      } else {
        return a[0] < b[0];
      }
    });

    size_t n = people.size();
    vector<vector<int>> ans(n);

    for (const auto& p : people) {
      for (int i = 0, h = p[0], k = p[1]; i < n; ++i) {
        if (!ans[i].empty()) {
          if (h <= ans[i][0]) {
            --k;
          }
        } else if (k > 0) {
          --k;
        } else {
          ans[i] = p;
          break;
        }
      }
    }

    return ans;
  }
};
// Runtime: 236 ms, faster than 68.23%
// Memory Usage: 11.8 MB, less than 75.21%

class Solution {
 public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), [](const auto& p1, const auto& p2) {
      return p1[0] > p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]);
    });

    vector<vector<int>> ans;

    for (const auto& p : people) {
      ans.insert(ans.begin() + p[1], p);
    }

    return ans;
  }
};
// Runtime: 360 ms, faster than 21.77%
// Memory Usage: 12.2 MB, less than 59.21%