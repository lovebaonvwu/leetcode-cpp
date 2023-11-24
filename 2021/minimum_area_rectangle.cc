class Solution {
 public:
  int minAreaRect(vector<vector<int>>& points) {
    unordered_map<int, set<int>> mp;

    for (auto& p : points) {
      mp[p[0]].insert(p[1]);
    }

    int ans = INT_MAX;

    for (auto i = mp.begin(); i != mp.end(); ++i) {
      for (auto j = next(i); j != mp.end(); ++j) {
        if (i->second.size() < 2 || j->second.size() < 2) {
          continue;
        }

        vector<int> y;

        set_intersection(begin(i->second), end(i->second), begin(j->second),
                         end(j->second), back_inserter(y));

        for (int k = 1; k < y.size(); ++k) {
          ans = min(ans, abs(i->first - j->first) * (y[k] - y[k - 1]));
        }
      }
    }

    return ans == INT_MAX ? 0 : ans;
  }
};
// Runtime: 208 ms, faster than 82.20%
// Memory Usage: 47 MB, less than 50.00%

class Solution {
 public:
  int minAreaRect(vector<vector<int>>& points) {
    unordered_map<int, unordered_set<int>> mp;

    for (auto& p : points) {
      mp[p[0]].insert(p[1]);
    }

    int ans = INT_MAX;

    for (int i = 0; i < points.size() - 1; ++i) {
      for (int j = i + 1; j < points.size(); ++j) {
        auto p1 = points[i];
        auto p2 = points[j];

        if (p1[0] == p2[0] || p1[1] == p2[1]) {
          continue;
        }

        if (mp[p1[0]].count(p2[1]) && mp[p2[0]].count(p1[1])) {
          ans = min(ans, abs(p1[0] - p2[0]) * abs(p1[1] - p2[1]));
        }
      }
    }

    return ans == INT_MAX ? 0 : ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int minAreaRect(vector<vector<int>>& points) {
    set<vector<int>> st(points.begin(), points.end());

    int ans = INT_MAX;

    for (auto& p1 : st) {
      for (auto& p2 : st) {
        if (p1[0] == p2[0] || p1[1] == p2[1]) {
          continue;
        }

        if (st.count({p1[0], p2[1]}) && st.count({p2[0], p1[1]})) {
          ans = min(ans, abs(p1[0] - p2[0]) * abs(p1[1] - p2[1]));
        }
      }
    }

    return ans == INT_MAX ? 0 : ans;
  }
};
// Time Limit Exceeded